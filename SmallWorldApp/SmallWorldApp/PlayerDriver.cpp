#include "Players.h"


int main(int argc, char*[]) {

	char answer;

	RacePicker *picker = new RacePicker();
	picker->setup();

	Player *player1 = new Player();

	player1->picks_race(picker);
	player1->printAmountTokens();
	player1->printCurrentBanner();
	player1->printCurrentPower();
	player1->printCurrentMoney();

	std::cin >> answer;

	return 0;

}

