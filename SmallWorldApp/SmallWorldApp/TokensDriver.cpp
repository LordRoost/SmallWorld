#include "Tokens.h"
#include "Game.h"


//int main(int argc, char*[]) {

int TokensDriver(){

	char answer;
	
	CoinBank *bank = new CoinBank();
	bank->printContents();

	/*
	for (int i = 0; i < TOTAL_RACES; i++) {
		RaceToken *raceTokens[i] = new RaceToken(r);
	}*/
	
	//LostTribeToken 

	//this block generates the race banners
	RaceBannerDeck *raceDeck = new RaceBannerDeck();
	raceDeck->printDeck();

	PowerBadgeDeck *powerDeck = new PowerBadgeDeck();
	powerDeck->printDeck();


	std::cin >> answer;
	//std::cout << "Please enter a command! S to shuffle, D to draw, B to build the deck, P to print and Q to quit" << std::endl;
	//std::cin >> answer;
	//while (true) {
	//	std::cin >> answer;
	//	if (answer == 'S') { //need to press S many times for it to actually shuffle, why?
	//		raceDeck->shuffle();
	//	}
	//	else if (answer == 'D') {
	//		raceDeck->draw();
	//	}
	//	else if (answer == 'B') {
	//		raceDeck->buildDeck();
	//	}
	//	else if (answer == 'P') {
	//		std::cout << "Here it is: " << std::endl;
	//		raceDeck->printDeck();
	//	}
	//	else if (answer == 'Q') {
	//		std::cout << "Bye!" << std::endl;
	//		break;
	//	}
	//	else {
	//		std::cout << "Please enter an appropriate command!" << std::endl;
	//	}
	//}

	return 0;

}

