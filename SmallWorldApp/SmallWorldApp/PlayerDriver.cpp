#include "Players.h"
#include "Game.h"


int main(int argc, char*[]) {

//int PlayerDriver() {

	char answer;
	CoinBank *bank = new CoinBank();

	RacePicker *picker = new RacePicker();
	picker->setup();

	Player *player1 = new Player();

	bank->startingDeal(player1);

	player1->picks_race(picker);
	//player1->printAmountTokens();
	player1->printCurrentBanner();
	player1->printCurrentPower();
	//player1->printCurrentMoney();
	picker->printOptions();

	//std::cout << "You roll your dice, the result is: ";
	//player1->getDieRoller().rollDice();

	//MapRegion *region = new MapRegion();
	//player1->addOwnedRegion(region);

	//player1->scores(bank);

	std::cin >> answer;

	return 0;

}

