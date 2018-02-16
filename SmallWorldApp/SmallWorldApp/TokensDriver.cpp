#include "Tokens.h"


int main(int argc, char*[]) {

	char answer;

	//this block initializes the coins
	VictoryCoin *coins[TOTAL_NUM_COINS];
	int upperLimit = NUM_OF_10S;

	for (int i = 0; i < upperLimit; i++) {
		coins[i] = new VictoryCoin(10);
		coins[i]->printValue();
	}

	upperLimit += NUM_OF_5S;

	for (int i = 30; i < upperLimit; i++) {
		coins[i] = new VictoryCoin(5);
		coins[i]->printValue();
	}

	upperLimit += NUM_OF_3S;

	for (int i = 54; i < upperLimit; i++) {
		coins[i] = new VictoryCoin(3);
		coins[i]->printValue();
	}

	upperLimit += NUM_OF_1S;

	for (int i = 74; i < upperLimit; i++) {
		coins[i] = new VictoryCoin(1);
		coins[i]->printValue();
	}

	/*
	for (int i = 0; i < TOTAL_RACES; i++) {
		RaceToken *raceTokens[i] = new RaceToken(r);
	}*/
	
	//LostTribeToken 

	//this block generates the race banners
	RaceBannerDeck *raceDeck = new RaceBannerDeck();
	raceDeck->printDeck();

	std::cout << "Please enter a command! S to shuffle, D to draw, B to build the deck, P to print and Q to quit" << std::endl;
	std::cin >> answer;
	while (true) {
		std::cin >> answer;
		if (answer == 'S') { //need to press S many times for it to actually shuffle, why?
			raceDeck->shuffle();
		}
		else if (answer == 'D') {
			raceDeck->draw();
		}
		else if (answer == 'B') {
			raceDeck->buildDeck();
		}
		else if (answer == 'P') {
			std::cout << "Here it is: " << std::endl;
			raceDeck->printDeck();
		}
		else if (answer == 'Q') {
			std::cout << "Bye!" << std::endl;
			break;
		}
		else {
			std::cout << "Please enter and appropriate command!" << std::endl;
		}
	}


}

