#include "../Headers/Players.h"

Player::Player() {		
	dice = new DieRoller();
}

DieRoller Player::getDieRoller() {
	return *dice;
}

PowerBadge* Player::getPowerBadge() {
	return currentBadge;
}

RaceToken* Player::getToken() {
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

void Player::setPowerBadge(PowerBadge *badge) {
	currentBadge = badge;
}

void Player::setDieRoller(DieRoller *die) {
	dice = die;
}

void Player::setRaceToken(RaceToken *tokens) {
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

	std::cout << "You have chosen: ";
	std::cout << getPowerBadge()->getPowerName();
	std::cout << " : ";
	std::cout << getRacebanner()->getName() << std::endl;
	std::cout << "Amount of tokens of ";
	std::cout << getRacebanner()->getName();
	std::cout << " received: " << std::endl;
	std::cout << getNbOfUsableTokens() << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
/*Conquest related methods*/

void Player::conquers() {
	//firstConquest();
}

void Player::firstConquest() {
	//make sure territory options are only the border ones
	//player chooses one 
}

void Player::attackTerritory(MapRegion *region) {
	
	if (region->getOwnershipStatus() == false) {

	}
}

bool Player::finalAttack(MapRegion *region) {
	int rolled = dice->rollDice();

	if (rolled + nbOfUseableTokens > calculateAttackThreshold(region)) {
		return true;
	}

	return false;
}

void Player::redeploy() {

}

int Player::calculateAttackThreshold(MapRegion *region) {
	return 0;
}

////////////////////////////////////////////////////////////////////////////////

//void Player::scores(CoinBank *bank) { //Later need to add how it is affected by powers 
//	bank->deal1s(this, ownedRegions->size());
//	std::cout << "You have scored ";
//	std::cout << ownedRegions->size();
//	std::cout << " points this turn." << std::endl;
//}

void Player::calculateUsableTokens() {
	
	int amountFromPower, amountFromRace;
	amountFromPower = getPowerBadge()->getAmountTokensReceived();
	amountFromRace = getRacebanner()->getAmountTokensReceived();

	setNbOfUsableTokens(amountFromPower + amountFromRace);
}

void Player::printAmountTokens() {
	std::cout << "Tokens in hand: ";
	std::cout << getNbOfUsableTokens() << std::endl;
}

void Player::printCurrentMoney() {
	std::cout << "Money in hand: " << std::endl;
	std::cout << getVictoryCoin1s().size(); 
	std::cout << " Ones" << std::endl;
	std::cout << getOtherCoins().size();
	std::cout << " Others" << std::endl;
}

void Player::printCurrentBanner() {
	std::cout << "Current Race: ";
	std::cout << getRacebanner()->getName() << std::endl;
}

void Player::printCurrentPower() {
	std::cout << "Current Power: ";
	std::cout << getPowerBadge()->getPowerName() << std::endl;
}