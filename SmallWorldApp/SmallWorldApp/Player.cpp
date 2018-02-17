#include "Players.h"
//#include "PowerBadge.cpp"
//#include "Racebanner.cpp"

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

//VictoryCoin Player::getVictoryCoin() {
//	//return ownedCoins;
//}

RaceBanner* Player::getRacebanner() {
	return currentRaceBanner;
}

int Player::getNbOfUsableTokens() {
	return nbOfUseableTokens;
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

void Player::setVictoryCoin(VictoryCoin coins) {
	//ownedCoins = coins;
}

void Player::setRaceBanner(RaceBanner *banner) {
	currentRaceBanner = banner;
}

void Player::setNbOfUsableTokens(int tokenAmount) {
	nbOfUseableTokens = tokenAmount;
}

void Player::picks_race(RacePicker *picker) { //doesnt work when its not 1 entered
	
	picker->printOptions();
	int answer;
	std::cin >> answer;

	if ((answer != 1) && (answer != 2) && (answer != 3) && (answer != 4) && (answer != 5) && (answer != 6)) {
		std::cout << "Please enter a number from 1 to 6" <<std::endl;
		std::cin >> answer;
	}

	PowerBadge *temp = picker->getPickablePowers(answer - 1);
	RaceBanner *temp2 = picker->getPickableRaces(answer - 1);

	setPowerBadge(temp);
	setRaceBanner(temp2);
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

void Player::conquers() {

}

void Player::scores() {

}

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
	std::cout << "Money in hand: ";
}

void Player::printCurrentBanner() {
	std::cout << "Current Race: ";
	std::cout << getRacebanner()->getName() << std::endl;
}

void Player::printCurrentPower() {
	std::cout << "Current Power: ";
	std::cout << getPowerBadge()->getPowerName() << std::endl;
}