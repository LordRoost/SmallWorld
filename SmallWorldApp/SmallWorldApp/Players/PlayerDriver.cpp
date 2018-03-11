#include "../Headers/Players.h"
#include "../Headers/Game.h"


int main(int argc, char*[]) {

//int PlayerDriver() {

	char answer;
	CoinBank *bank = new CoinBank();

	RaceToken *enemy = new RaceToken(RACE_AMAZONS);

	RacePicker *picker = new RacePicker();
	picker->setup();

	Player *player1 = new Player();
	Player *player2 = new Player();

	bank->startingDeal(player1);

	player1->picks_race(picker);
	player1->printCurrentBanner();
	player1->printCurrentPower();
	//player2->picks_race(picker);


	MapRegion *region = new MapRegion();
	region->addRaceTokens(*enemy, 9);
	//player1->addOwnedRegion(region);

	player1->attackTerritory(region);
	//player1->scores(bank);

	std::cin >> answer;

	return 0;

}

