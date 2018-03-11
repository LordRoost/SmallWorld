#include "../Headers/Players.h"

Player::Player() {		
	dice = new DieRoller();
}

//Getters-------------------------------------------------------------------------
DieRoller Player::getDieRoller() {
	return *dice;
}

PowerBadge* Player::getPowerBadge() {
	return currentBadge;
}

RaceToken Player::getToken() {
	return currentRace;
}

std::list<VictoryCoin> Player::getVictoryCoin1s() {
	return owned1s;
}

std::list<VictoryCoin> Player::getOtherCoins() {
	return ownedOtherCoins;
}

RaceBanner* Player::getRacebanner() {
	return currentRaceBanner;
}

int Player::getNbOfUsableTokens() {
	return nbOfUseableTokens;
}

std::vector<MapRegion> Player::getOwnedRegions() { // ?????
	return *ownedRegions;
}

//setters ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Player::setPowerBadge(PowerBadge *badge) {
	currentBadge = badge;
}

void Player::setDieRoller(DieRoller *die) {
	dice = die;
}

void Player::setRaceToken(RaceToken tokens) {
	currentRace = tokens;
}

void Player::setRaceBanner(RaceBanner *banner) {
	currentRaceBanner = banner;
}

void Player::setNbOfUsableTokens(int tokenAmount) {
	nbOfUseableTokens = tokenAmount;
}

void Player::addVictoryCoin(VictoryCoin coins) {
	ownedOtherCoins.push_back(coins);
}

void Player::addVictoryCoin1s(VictoryCoin ones) {
	owned1s.push_back(ones);
}

void Player::addOwnedRegion(MapRegion *region) { //????
	ownedRegions->push_back(*region);
}

//Need to add fact that one must spend tokens to get further combos
void Player::picks_race(RacePicker *picker) { 
	
	picker->printOptions();
	std::cout << "Choose your race: " << std::endl;
	int answer;
	std::cin >> answer;

	if ((answer != 1) && (answer != 2) && (answer != 3) && (answer != 4) && (answer != 5) && (answer != 6)) {
		std::cout << "Please enter a number from 1 to 6" <<std::endl;
		std::cin >> answer;
	}

	setPowerBadge(picker->getPickablePowers(answer - 1));
	setRaceBanner(picker->getPickableRaces(answer - 1));
	picker->replaceChoices(answer - 1);
	calculateUsableTokens();

	std::cout << "You have chosen: " << getPowerBadge()->getPowerName() << " : " << getRacebanner()->getName() << std::endl;
	std::cout << "Amount of tokens of " << getRacebanner()->getName() << " received: " << std::endl;
	std::cout << getNbOfUsableTokens() << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
//Conquest related methods

void Player::conquers() { //UNFINISHED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	MapRegion *chosenForAttack = NULL;
	
	firstConquest();
	while (nbOfUseableTokens > 0 && lastAttack == false) {
		std::cout << "Choose a territory to attack: " << std::endl;
		//List territories that they can attack
		 //chosenForAttack = choice that player picked above

		attackTerritory(chosenForAttack);
	}

	redeploy();
}

void Player::firstConquest() {//UNFINISHED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	std::cout << "Select a territory to attack. Your first attack must be on a region that is a border: " << std::endl;
	//make sure territory options are only the border ones
	//player chooses one
	MapRegion *borderTerritory = NULL; //= choice that player picked above

	attackTerritory(borderTerritory);
}

void Player::attackTerritory(MapRegion *region) { //should have user confirm attacks or something somewhere
	
	int attackingAmount = calculateAttackThreshold(region);

	if (nbOfUseableTokens == 0) {
		std::cout << "Something went wrong, you shouldn't be here, you can't attack with no tokens" << std::endl;
		return;
	}
	else if (nbOfUseableTokens < attackingAmount) {
		if (finalAttack(region) == false) {
			std::cout << "You have failed your attack on this region." << std::endl;
			return;
		}
	}

	std::cout << "You have succeeded in your attack!" << std::endl;
	removeEnemyTokens(region);
	region->setOwner(this);
	region->addRaceTokens(this->getToken(), attackingAmount);

	std::cout << "You have " << calculateCurrentNbUsableTokens(attackingAmount) << " " << getRacebanner()->getName() << " tokens left to attack with." << std::endl;	
}

//method for the dice roll attack of the conquering phase
bool Player::finalAttack(MapRegion *region) {

	lastAttack = true;
	if (dice->rollDice() + nbOfUseableTokens > calculateAttackThreshold(region)) {
		return true;
	}

	return false;
}

void Player::redeploy() {
	//pick a region
	//pick add or remove
	//pick how many tokens you wanna move (have to at least leave 1)
	//keep doing until satisfied
}

//method to determine how many tokens a user needs to succesfully conquer a region
int Player::calculateAttackThreshold(MapRegion *region) {

	if (region->hasLostTribe()) {
		int threshold = 3 + region->getDefensiveStructures().size(); 
		//cout << threshold << " tribes"<<endl; //debugging methods
		return threshold;
	}
	else
	{
		int threshold = region->getNbTokens() + 2 + region->getDefensiveStructures().size(); 
		//cout << threshold << " not tribes" <<endl; //debugging methods
		return threshold;
	}
}

//to be called after a successful attack CHECK CORRECTNESS IN ALL CASES
void Player::removeEnemyTokens(MapRegion *region) {
	
	if (region->hasLostTribe()) {
		region->setLostTribeToken(NULL); //need to properly remove the piece
	}
	else if (region->getOwnershipStatus() == true) {
		Player *formerOwner = region->getOwner(); 
		formerOwner->returnTokensToHand(region->getNbTokens()-1);
	}
}

////////////////////////////////////////////////////////////////////////////////

void Player::scores(CoinBank *bank) { //Later need to add how it is affected by powers 
	bank->deal1s(this, ownedRegions->size());
	std::cout << "You have scored " << ownedRegions->size() << " points this turn." << std::endl;
	//std::cout << ownedRegions->size();
	//std::cout << " points this turn." << std::endl;
}


//utility functions ------------------------------------------------------------------------------------

void Player::returnTokensToHand(int returnedTokens) {
	setNbOfUsableTokens(nbOfUseableTokens + returnedTokens);
}

int Player::calculateCurrentNbUsableTokens(int subtracted) {
	setNbOfUsableTokens(nbOfUseableTokens - subtracted);
	return nbOfUseableTokens;
}

void Player::calculateUsableTokens() {
	
	int amountFromPower, amountFromRace;
	amountFromPower = getPowerBadge()->getAmountTokensReceived();
	amountFromRace = getRacebanner()->getAmountTokensReceived();

	setNbOfUsableTokens(amountFromPower + amountFromRace);
}

//void Player::calculateUsableTokens(PowerBadge power, RaceBanner banner) {
//
//	int amountFromPower, amountFromRace;
//	amountFromPower = power.getAmountTokensReceived();
//	amountFromRace = banner.getAmountTokensReceived();
//
//	setNbOfUsableTokens(amountFromPower + amountFromRace);
//}

void Player::printAmountTokens() {
	std::cout << "Tokens in hand: " << getNbOfUsableTokens() << std::endl;
}

void Player::printCurrentMoney() {
	std::cout << "Money in hand: " << std::endl;
	std::cout << getVictoryCoin1s().size() << " Ones" << std::endl;
	std::cout << getOtherCoins().size() << " Others" << std::endl;
}

void Player::printCurrentBanner() {
	std::cout << "Current Race: " << getRacebanner()->getName() << std::endl;
}

void Player::printCurrentPower() {
	std::cout << "Current Power: " << getPowerBadge()->getPowerName() << std::endl;
}