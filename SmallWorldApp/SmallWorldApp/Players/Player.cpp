#include "../Headers/Players.h"

typedef graph_traits<Graph>::vertex_descriptor vertex_t;

//Player constructor
Player::Player() {		
	dice = new DieRoller();
	declinedRaceBanner = NULL;
	lastAttack = false;
	wealthyClaimed = false;
	occupiedRegionCounter = 0;
	redeployableTokens = 0;
    inDecline = false;
	previousDeclinedRace = RACE_NONE;
	declinedRace = RACE_NONE;
	currentRace = RACE_NONE;
	choiceOfRegion = NULL;
    aiStrategy=NULL;
}

//Player constructor
Player::Player(AI *_aiStrategy) {
    dice = new DieRoller();
    declinedRaceBanner = NULL;
    lastAttack = false;
    wealthyClaimed = false;
    occupiedRegionCounter = 0;
    redeployableTokens = 0;
    inDecline = false;
    previousDeclinedRace = RACE_NONE;
    declinedRace = RACE_NONE;
    currentRace = RACE_NONE;
    choiceOfRegion = NULL;
    aiStrategy=_aiStrategy;
}

AI *Player::getAIStrategy(){
    return aiStrategy;
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

RaceToken Player::getRaceToken() {
	return currentRaceToken;
}

races Player::getCurrentRace() {
	return currentRace;
}

races Player::getDeclinedRace() {
	return declinedRace;
}

races Player::getPreviouslyDeclinedRace() {
	return previousDeclinedRace;
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
	currentRaceToken = tokens;
}

void Player::setCurrentRace(races race) {
	currentRace = race;
}

void Player::setDeclinedRace(races race) {
	declinedRace = race;
}

void Player::setPreviouslyDeclinedRace(races race) {
	previousDeclinedRace = race;
}

void Player::setRaceBanner(RaceBanner *banner) {
	currentRaceBanner = banner;
	if (banner == NULL)
		setCurrentRace(RACE_NONE);
	else
		setCurrentRace(banner->getRace());
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
    
    if(aiStrategy==NULL){
        std::cin >> answer;
    }
    else{
        cout<< aiStrategy->getName()<<endl;
        answer=aiStrategy->pickPowerRace(picker->getAllPickableRaces(),picker->getAllPickablePowers());
    }

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

void Player::conquers() { 
	occupiedRegionCounter = 0; //counter to see if the region was previously occupied and how many a player conquered in a turn
	vertex_t theChoice;

	if (this->getOwnedRegions().size() == 0 || inDecline) {
        inDecline=false;
		firstConquest();
	}
	
	while (nbOfUseableTokens > 0 && lastAttack == false) {
		vector<int> tempVector;
		std::cout << "Choose a territory to attack: " << std::endl;

		gameMap.getAdgacentTerritories(choiceOfRegion);

		std::cout << std::endl;

		for (size_t i = 0; i < gameMap.adgacentMapRegions.size(); i++) {
			tempVector.push_back(gameMap.adgacentMapRegions[i]->getIndexOfVertex());
		}

		bool breakFree = false;

		bool stuffHappened = false;

		while (breakFree == false) {
            
            if(aiStrategy==NULL){
                std::cin >> theChoice;
            }
            else{
                theChoice=aiStrategy->aiConquers(this, gameMap.adgacentMapRegions);
            }
			for (size_t i = 0; i < tempVector.size(); i++) {
				if (theChoice == tempVector[i]) {
					Graph tempGraph = *gameMap.getGraph();
					MapRegion *adjTerritory = tempGraph[theChoice];

					choiceOfRegion = adjTerritory;

					if (attackTerritory(adjTerritory) == -1) { //If there were issues with attacking
						break;
					}

					breakFree = true;
					stuffHappened = true;
					break;
				}
			}
			if (stuffHappened == false)
				std::cout << "Please enter a correct region." << std::endl;
		}

		/*
		Graph tempGraph = *gameMap.getGraph();
		MapRegion *adjTerritory = tempGraph[theChoice];
        
		choiceOfRegion = adjTerritory; 

		attackTerritory(adjTerritory);
		*/
	}
	lastAttack = false;
	redeploy();
}

//First attack of the user, which must be on a border region
void Player::firstConquest() { //what if firstconquest is also last??

	int playerChoice;
	std::vector<int> tempVector;

	std::cout << "Select a territory to attack. Your first attack must be on a region that is a border: (Enter the number)" << std::endl;

	for (size_t i = 0; i < gameMap.borderRegions.size(); i++) {
		tempVector.push_back(gameMap.borderRegions[i]->getIndexOfVertex());
		std::cout << gameMap.borderRegions[i]->getIndexOfVertex() << " ";
	}
	
	std::cout << std::endl;

	bool breakFree = false;

	bool stuffHappened = false;

	while (breakFree == false) {
        if(aiStrategy==NULL){
            std::cin >> playerChoice;
        }
        else{
            playerChoice=aiStrategy->aiConquers(this, gameMap.borderRegions);
        }
        
		for (size_t i = 0; i < tempVector.size(); i++) {
			if (playerChoice == tempVector[i]) {
				Graph tempGraph = *gameMap.getGraph();
				MapRegion *borderTerritory = tempGraph[playerChoice];

				choiceOfRegion = borderTerritory;

				if (attackTerritory(borderTerritory) == -1) { //If there were issues with attacking
					break;
				}

				breakFree = true;
				stuffHappened = true;
				break;
			}
		}
		if (stuffHappened == false)
			std::cout << "Please enter a correct region. It must be a border." << std::endl;
	}

	/*
	Graph tempGraph = *gameMap.getGraph();
	MapRegion *borderTerritory = tempGraph[playerChoice];
    //MapRegion *borderTerritory = &gameMap.getMap()[playerChoice];
	//MapRegion *borderTerritory = borders[playerChoice];
	choiceOfRegion = borderTerritory;

	attackTerritory(borderTerritory);
	*/
}

int Player::attackTerritory(MapRegion *region) { //should have user confirm attacks or something somewhere
	
	if (region->getOwner() == this) {
		std::cout << "You can't attack your own regions! Please enter another region!" << std::endl;
		return -1;
	}

	int attackingAmount = calculateAttackThreshold(region);

	if (nbOfUseableTokens == 0) {
		std::cout << "Something went wrong, you shouldn't be here, you can't attack with no tokens" << std::endl;
		return -1;
	}
	else if (nbOfUseableTokens < attackingAmount) {

		//int leftOverTokens = nbOfUseableTokens;

		if (finalAttack(region) == false) { //if the dice roll failed
			std::cout << "You have failed your attack on this region." << std::endl;
			return 0;
		}
		else {
			std::cout << "You have succeeded in your attack!" << std::endl;
			if (region->getOwner() != NULL || region->hasLostTribe()) {
				occupiedRegionCounter++;
			}
			removeEnemyTokens(region);
			region->setOwner(this);
			region->setRaceOfOccupants(this->getCurrentRace());
			region->addRaceTokens(this->getRaceToken(), nbOfUseableTokens);
			std::cout << "You have placed " << nbOfUseableTokens << " tokens."<< std::endl;
			addOwnedRegion(region);
			std::cout << "You have " << calculateCurrentNbUsableTokens(attackingAmount) << " " << getRacebanner()->getName() << " tokens left to attack with." << std::endl;
			return 1;
		}
	}

	std::cout << "You have succeeded in your attack!" << std::endl;
	if (region->getOwner() != NULL || region->hasLostTribe()) {
		occupiedRegionCounter++;
	}
	removeEnemyTokens(region);
	region->setOwner(this);
	region->setRaceOfOccupants(this->getCurrentRace());
	region->addRaceTokens(this->getRaceToken(), attackingAmount);
	std::cout << "You have placed " << attackingAmount << " tokens." << std::endl;
	addOwnedRegion(region);

	//cout << "NbOfTokens: " << region->getNbTokens() << endl;

	std::cout << "You have " << calculateCurrentNbUsableTokens(attackingAmount) << " " << getRacebanner()->getName() << " tokens left to attack with." << std::endl;	
	return 1;
}

//method for the dice roll attack of the conquering phase
bool Player::finalAttack(MapRegion *region) {
	int result = dice->rollDice();

	std::cout << "You have rolled the dice. Your result is: " << result << std::endl;
	lastAttack = true;
	if (result + nbOfUseableTokens > calculateAttackThreshold(region)) {
		return true;
	}

	return false;
}

void Player::readyTroops() {
	std::cout << "Readying troops" << std::endl;
	
	int temp = 0;

	for (size_t i = 0; i < getOwnedRegions().size(); i++) {
		temp = (getOwnedRegions()[i]->getNbTokens()) - 1;
		getOwnedRegions()[i]->setNbTokens(1);
		redeployableTokens += temp;
	}
	redeployableTokens += getNbOfUsableTokens();
	setNbOfUsableTokens(redeployableTokens);
	redeployableTokens = 0;

	std::cout << "You have " << nbOfUseableTokens << " tokens to attack with." << std::endl;
}

//Lets a player redeploy their tokens
void Player::redeploy() {
	std::cout << "Redeployment phase" << std::endl;

	std::cout << "Do you wish to redeploy your units? (y or n)" << std::endl;
	char userAnswer;

	std::cin >> userAnswer;

	if (userAnswer == 'n') {
		placeAllTokensOnMap();
		return;
	}
	else if (userAnswer == 'y') {
		int temp = 0;
		//int responseRegion, responseAdd;
		setRedeployableTokens(0);

		vector<stack<int>> answers;
    
		if(aiStrategy!=NULL){
			cout<<endl;
			answers=aiStrategy->aiRedeploy(this,redeployableTokens, getOwnedRegions());
			cout<<endl;
		}

		for (size_t i = 0; i < getOwnedRegions().size(); i++) {
			temp = (getOwnedRegions()[i]->getNbTokens()) - 1;
			getOwnedRegions()[i]->setNbTokens(1);
			redeployableTokens += temp;
		}
		redeployableTokens += getNbOfUsableTokens();
		setNbOfUsableTokens(0);

		deployment(redeployableTokens);
		
	}
	else {
		std::cout << "please enter y or n!" << std::endl;
	}
}

//method to determine how many tokens a user needs to succesfully conquer a region
int Player::calculateAttackThreshold(MapRegion *region) {

	if (region->hasLostTribe()) {
		int threshold = 3 + region->getDefensiveStructures().size(); 
		return threshold;
	}
	else
	{
		int threshold = region->getNbTokens() + 2 + region->getDefensiveStructures().size(); 
		return threshold;
	}
}

//to be called after a successful attack
void Player::removeEnemyTokens(MapRegion *region) {
	
	if (region->hasLostTribe()) {
		region->setLostTribeToken(NULL); //need to properly remove the piece
	}
	else if (region->getOwnershipStatus() == true) {
		Player *formerOwner = region->getOwner(); 
		formerOwner->returnTokensToHand(region->getNbTokens()-1);
		region->setNbTokens(0);

		formerOwner->removeOwnedRegion(region);
		
	}
}

void Player::removeOwnedRegion(MapRegion *region) {
	
	for (size_t i = 0; i < ownedRegions.size(); i++) {
		if (region == ownedRegions[i]) {

			ownedRegions.erase(ownedRegions.begin() + i); //remove the region from former owner's owned
			//cout << "I am erasing at " << i << endl;
		}
	}
}

void Player::declineRace(){

	cout << "Declining " << this->getRacebanner()->getName() <<endl;

	for (std::vector<int>::size_type i = 0; i < ownedRegions.size(); i++) {
		MapRegion* tempRegion = ownedRegions[i];

		//Take out previous declined race
		if (declinedRace == tempRegion->getRaceOfOccupants()) {
			tempRegion->setOwnershipStatus(false);
			tempRegion->setOwner(NULL);
			tempRegion->setNbTokens(0);
			ownedRegions.erase(ownedRegions.begin() + i);
		}
		else
			tempRegion->setNbTokens(1);
	}

    inDecline = true;
	if (declinedRace != RACE_NONE) {
		previousDeclinedRace = declinedRace;
	}
	setDeclinedRace(currentRace);
    declinedRaceToken = currentRaceToken;
    declinedRaceBanner = currentRaceBanner;
	currentRace = RACE_NONE;
    setPowerBadge(NULL);
    setRaceBanner(NULL);

	cout << "Decline end" << endl;
}

////////////////////////////////////////////////////////////////////////////////

void Player::scores(CoinBank *bank) { 
	bank->deal1s(this, ownedRegions.size());
	std::cout << "You have scored " << ownedRegions.size() << " points from your regions this turn." << std::endl;

	int bonusCoins;

	if (this->inDecline == false) {
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
			std::cout << "You have scored " << bonusCoins << " extra coins from your " << getPowerBadge()->getPowerName() << " power!" << endl;
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
	}
	std::cout << "You have " << this->getVictoryCoin1s().size() << " total coins" << std::endl;
}


//utility functions ------------------------------------------------------------------------------------

void Player::placeAllTokensOnMap() {
	
	std::cout << "Place your remaining tokens in hand onto one of your territories" << std::endl;

	deployment(nbOfUseableTokens);

	setNbOfUsableTokens(0);
}

void Player::deployment(int nbOfTokens) {

	vector<stack<int>> answers;

	if (aiStrategy != NULL) {
		cout << endl;
		answers = aiStrategy->aiRedeploy(this, redeployableTokens, getOwnedRegions());
		cout << endl;
	}

	while (nbOfTokens > 0) {
		std::cout << "You have " << nbOfTokens << " tokens to deploy" << std::endl;
		std::cout << "Choose a region to add tokens to: " << std::endl;
		for (size_t i = 0; i < getOwnedRegions().size(); i++) {
			std::cout << getOwnedRegions()[i]->getIndexOfVertex() << std::endl;
		}

		bool breakFree = false;
		bool bogusInputs = true;
		bool stuffHappened = false;
		int responseRegion, responseAdd;

		while (breakFree == false) {

			if (aiStrategy == NULL) {
				std::cin >> responseRegion;
			}
			else {
				cout << aiStrategy->getName() << " about region to deploy" << endl;
				cout << "Region with vertex " << answers[0].top() << endl;
				responseRegion = answers[0].top();
				answers[0].pop();
			}

			for (size_t i = 0; i < getOwnedRegions().size(); i++) {
				if (responseRegion == getOwnedRegions()[i]->getIndexOfVertex()) {
					std::cout << "Enter the number of tokens that you want to add here: " << std::endl;

					if (aiStrategy == NULL) {
						std::cin >> responseAdd;
					}
					else {
						cout << aiStrategy->getName() << " about number of tokens to deploy" << endl;
						cout << "This amount of tokens: " << answers[1].top() << endl;
						responseAdd = answers[1].top();
						answers[1].pop();
					}

					while (bogusInputs) {
						if (responseAdd > nbOfTokens) {
							std::cout << "Please enter a number that isn't bigger than the amount of tokens you have to place!" << std::endl;
							std::cin >> responseAdd;
						}
						else if (responseAdd < 0) {
							std::cout << "Oh no!! What is you doing! Do not enter negative numbers!" << std::endl;
							std::cin >> responseAdd;
						}
						else
							bogusInputs = false;
					}
					getOwnedRegions()[i]->addRaceTokens(this->getRaceToken(), responseAdd);
					nbOfTokens -= responseAdd;
					breakFree = true;
					stuffHappened = true;
					break;
				}
			}
			if (stuffHappened == false)
				std::cout << "Please enter a correct region." << std::endl;
		}
	}
			
}

void Player::returnTokensToHand(int returnedTokens) {
	setNbOfUsableTokens(nbOfUseableTokens + returnedTokens);
}

int Player::calculateCurrentNbUsableTokens(int subtracted) {
	if(nbOfUseableTokens - subtracted >= 0)
		setNbOfUsableTokens(nbOfUseableTokens - subtracted);
	else
		setNbOfUsableTokens(0);
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
