#include "../Headers/Players.h"

typedef graph_traits<Graph>::vertex_descriptor vertex_t;

//Player constructor
Player::Player() {		
	dice = new DieRoller();
	declinedRaceBanner = NULL;
	lastAttack = false;
	wealthyClaimed = false;
	occupiedRegionCounter = 0;
    inDecline=true;
}

bool Player::getInDecline(){
    return inDecline;
}

void Player::setInDecline(bool _inDecline){
    inDecline=_inDecline;
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

std::vector<MapRegion*> Player::getOwnedRegions() { // ?????
	return ownedRegions;
}

int Player::getRedeployableTokens() {
	return redeployableTokens;
}

bool Player::getIfClaimedWealthy() {
	return wealthyClaimed;
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

void Player::setRedeployableTokens(int amount) {
	redeployableTokens = amount;
}

void Player::setIfClaimedWealthy(bool claim) {
	wealthyClaimed = claim;
}

void Player::addVictoryCoin(VictoryCoin coins) {
	ownedOtherCoins.push_back(coins);
}

void Player::addVictoryCoin1s(VictoryCoin ones) {
	owned1s.push_back(ones);
}

void Player::addOwnedRegion(MapRegion *region) { //????
	ownedRegions.push_back(region);
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

extern Map gameMap;

void Player::conquers() { //Need to make sure cant attack previously attacked territories
	occupiedRegionCounter = 0;
	vertex_t theChoice;

	if (this->getOwnedRegions().size() == 0 || inDecline) {
        inDecline=false;
		firstConquest();
	}
	
	while (nbOfUseableTokens > 0 && lastAttack == false) {
		std::cout << "Choose a territory to attack: " << std::endl;

	/*	gameMap.getAdgacentTerritories(choiceOfRegion);
		vector<MapRegion*> adjacent = gameMap.adgacentMapRegions;
		
		for (int i = 0; i < adjacent.size(); i++) {
			std::cout << i << " ";
			
		}
		
		std::cout << std::endl;
		std::cin >> theChoice;
		MapRegion * adjTerritory = adjacent[theChoice];
		choiceOfRegion = adjTerritory;
			
		attackTerritory(adjTerritory);*/

		gameMap.getAdgacentTerritories(choiceOfRegion);

		std::cout << std::endl;
		std::cin >> theChoice;
		Graph tempGraph = *gameMap.getGraph();
		MapRegion *adjTerritory = tempGraph[theChoice];
        
		choiceOfRegion = adjTerritory; 

		attackTerritory(adjTerritory);
	}
    
	redeploy();
}

//First attack of the user, which must be on a border region
void Player::firstConquest() {

	int playerChoice;
	std::cout << "Select a territory to attack. Your first attack must be on a region that is a border: (Enter the number)" << std::endl;

	gameMap.getAllBorders();
	vector<MapRegion*> borders = gameMap.borderRegions;

	for (size_t i = 0; i < gameMap.borderRegions.size(); i++) {
		std::cout << i << " ";
	}
	
	std::cout << std::endl;
	std::cin >> playerChoice;
    //MapRegion *borderTerritory = &gameMap.getMap()[playerChoice];
	MapRegion *borderTerritory = borders[playerChoice];
	choiceOfRegion = borderTerritory;

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
	if (region->getOwner() != NULL || region->hasLostTribe()) {
		occupiedRegionCounter++;
	}
	removeEnemyTokens(region);
	region->setOwner(this);
	region->addRaceTokens(this->getToken(), attackingAmount);
	addOwnedRegion(region);

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

//Lets a user redeploy his tokens
void Player::redeploy() {
	std::cout << "Redeployment phase" << endl;
	int temp = 0;
	int responseRegion, responseAdd;

	for (size_t i = 0; i < getOwnedRegions().size(); i++) {
		temp = (getOwnedRegions()[i]->getNbTokens())-1;
		getOwnedRegions()[i]->setNbTokens(1);
		redeployableTokens += temp;
	}
	redeployableTokens += getNbOfUsableTokens();

	while (redeployableTokens > 0) {
		std::cout << "You have " << redeployableTokens << " tokens to redeploy" << std::endl;
		std::cout << "Choose a region to add tokens to: " << std::endl;
		for (size_t i = 0; i < getOwnedRegions().size(); i++) {
			std::cout << getOwnedRegions()[i]->getIndexOfVertex() << std::endl;
		}

		bool breakFree = false;
		bool bogusInputs = true;
		bool stuffHappened = false;

		while (breakFree == false) {
			std::cin >> responseRegion;
			for (size_t i = 0; i < getOwnedRegions().size(); i++) {
				if (responseRegion == getOwnedRegions()[i]->getIndexOfVertex()) {
					std::cout << "Enter the number of tokens that you want to add here: " << std::endl;
					std::cin >> responseAdd;

					while (bogusInputs) {
						if (responseAdd > redeployableTokens) {
							std::cout << "Please enter a number that isn't bigger than the amount of tokens you have to redistribute!" << std::endl;
							std::cin >> responseAdd;
						}
						else if (responseAdd < 0) {
							std::cout << "Oh no!! What is you doing! Do not enter negative numbers!" << std::endl;
							std::cin >> responseAdd;
						}
						else
							bogusInputs = false;
					}
					getOwnedRegions()[i]->addRaceTokens(this->getToken(), responseAdd);
					redeployableTokens -= responseAdd;
					breakFree = true;
					stuffHappened = true;
					break;
				}
			}
			if(stuffHappened == false)
				std::cout << "Please enter a correct region." << std::endl;
		}
		
	}
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
		for (size_t i = 0; i < formerOwner->getOwnedRegions().size(); i++) {
			if (region == formerOwner->getOwnedRegions()[i]) {
				formerOwner->getOwnedRegions().erase(formerOwner->getOwnedRegions().begin()+i); //remove the region from former owner's owned
			}
		}
	}
}

void Player::declineRace(){
    
    inDecline=true;
    declinedRace=currentRace;
    declinedRaceBanner=currentRaceBanner;
    currentBadge=NULL;
    setRaceBanner(NULL);
    
    for (std::vector<int>::size_type i = 0; i != ownedRegions.size(); i++) {
        MapRegion* pointer = ownedRegions[i];
        
        //Take out previous declined race
        if(declinedRace.getRace()==pointer->getRaceToken().getRace()){
            pointer->setOwnershipStatus(false);
            pointer->setOwner(NULL);
            pointer->setNbTokens(0);
            ownedRegions.erase(ownedRegions.begin()+i);
        }
        pointer->setNbTokens(1);
    
    }
}

////////////////////////////////////////////////////////////////////////////////

void Player::scores(CoinBank *bank) { //Later need to add how it is affected by powers 
	bank->deal1s(this, ownedRegions.size());
	std::cout << "You have scored " << ownedRegions.size() << " points from your regions this turn." << std::endl;

	int bonusCoins;

	switch (getPowerBadge()->getPower()) {
		case POWER_ALCHEMIST:
			bank->deal1s(this, ALCHEMIST_NUM_COINS);
			std::cout << "You have scored " << ALCHEMIST_NUM_COINS << " extra coins from your " << getPowerBadge()->getPowerName() << " power!" << endl;
			break;

		case POWER_FOREST:
			bonusCoins = 0;
			for (size_t i = 0; i < getOwnedRegions().size(); i++) {
				if (getOwnedRegions()[i]->getType() == REGION_TYPE_FOREST) {
					bonusCoins++;
				}
			}
			bank->deal1s(this, bonusCoins);
			std::cout << "You have scored " << bonusCoins<< " extra coins from your " << getPowerBadge()->getPowerName() <<" power!" << endl;
			break;

		case POWER_HILL:
			bonusCoins = 0;
			for (size_t i = 0; i < getOwnedRegions().size(); i++) {
				if (getOwnedRegions()[i]->getType() == REGION_TYPE_HILL) {
					bonusCoins++;
				}
			}
			bank->deal1s(this, bonusCoins);
			std::cout << "You have scored " << bonusCoins << " extra coins from your " << getPowerBadge()->getPowerName() << " power!" << endl;
			break;

		case POWER_MERCHANT:
			bank->deal1s(this, ownedRegions.size());
			std::cout << "You have scored " << ownedRegions.size() << " extra coins from your " << getPowerBadge()->getPowerName() << " power!" << endl;
			break;

		case POWER_PILLAGING:
			bank->deal1s(this, occupiedRegionCounter);
			std::cout << "You have scored " << occupiedRegionCounter << " extra coins from your " << getPowerBadge()->getPowerName() << " power!" << endl;
			break;

		case POWER_SWAMP:
			bonusCoins = 0;
			for (size_t i = 0; i < getOwnedRegions().size(); i++) {
				if (getOwnedRegions()[i]->getType() == REGION_TYPE_SWAMP) {
					bonusCoins++;
				}
			}
			bank->deal1s(this, bonusCoins);
			std::cout << "You have scored " << bonusCoins << " extra coins from your " << getPowerBadge()->getPowerName() << " power!" << endl;
			break;

		case POWER_WEALTHY:
			if (wealthyClaimed == false) {
				bank->deal1s(this, WEALTHY_NUM_COINS);
				std::cout << "You have scored " << WEALTHY_NUM_COINS << " extra coins from your " << getPowerBadge()->getPowerName() << " power!" << endl;
				wealthyClaimed = true; //must set back to false after geting rid of power
			}
			break;
		default:
			break;
	}
		
	std::cout << "You have " << this->getVictoryCoin1s().size() << " total coins" << std::endl;
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
