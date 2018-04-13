#include "../Headers/Game.h"
#include "../Headers/Players.h"

CoinBank::CoinBank() {

	for (int i = 0; i < NUM_OF_10S; i++) {
		VictoryCoin *coin = new VictoryCoin(10);
		coinValue10.push_back(coin);
	}

	for (int i = 0; i < NUM_OF_5S; i++) {
		VictoryCoin *coin = new VictoryCoin(5);
		coinValue5.push_back(coin);
	}

	for (int i = 0; i < NUM_OF_3S; i++) {
		VictoryCoin *coin = new VictoryCoin(3);
		coinValue3.push_back(coin);
	}

	for (int i = 0; i < NUM_OF_1S; i++) {
		VictoryCoin *coin = new VictoryCoin(1);
		coinValue1.push_back(coin);
	}
}

CoinBank::~CoinBank() {

	for (std::vector< VictoryCoin* >::iterator it = coinValue10.begin(); it != coinValue10.end(); ++it) {
		delete(*it);
	}
	coinValue10.clear();

	for (std::vector< VictoryCoin* >::iterator it = coinValue5.begin(); it != coinValue5.end(); ++it) {
		delete(*it);
	}
	coinValue5.clear();

	for (std::vector< VictoryCoin* >::iterator it = coinValue3.begin(); it != coinValue3.end(); ++it) {
		delete(*it);
	}
	coinValue3.clear();

	for (std::vector< VictoryCoin* >::iterator it = coinValue1.begin(); it != coinValue1.end(); ++it) {
		delete(*it);
	}
	coinValue1.clear();
}

void CoinBank::deal1s(Player *aPlayer, int amount){
	for (int i = 0; i < amount; i++) {
		aPlayer->addVictoryCoin1s(*coinValue1.back());
		coinValue1.pop_back();
	}
}

void CoinBank::startingDeal(Player *aPlayer) {
	deal1s(aPlayer, 5);
}

int CoinBank::getAmount1s() {
	return coinValue1.size();
}

int CoinBank::getAmount3s() {
	return coinValue3.size();
}

int CoinBank::getAmount5s() {
	return coinValue5.size();
}

int CoinBank::getAmount10s() {
	return coinValue10.size();
}

void CoinBank::printContents() {
	std::cout << "1 coins: ";
	std::cout << getAmount1s() << std::endl;
	std::cout << "3 coins: ";
	std::cout << getAmount3s() << std::endl;
	std::cout << "5 coins: ";
	std::cout << getAmount5s() << std::endl;
	std::cout << "10 coins: ";
	std::cout << getAmount10s() << std::endl;
	
}

std::vector <VictoryCoin*> CoinBank::get1s(){
	return coinValue1;
}

std::vector <VictoryCoin*> CoinBank::get3s(){
	return coinValue3;
}

std::vector <VictoryCoin*> CoinBank::get5s(){
	return coinValue5;
}

std::vector <VictoryCoin*> CoinBank::get10s(){
	return coinValue10;
}