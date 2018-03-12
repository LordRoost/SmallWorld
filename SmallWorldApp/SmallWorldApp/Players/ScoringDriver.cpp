#include "../Headers/Players.h"
#include "../Headers/Game.h"


int main(int argc, char*[]) {

	//int ScoringDriver() {

	char answer;
	PlayGame game1;

	game1.startGame();

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


	//MapRegion *region = new MapRegion();
	//region->addRaceTokens(*enemy, 9);
	//player1->addOwnedRegion(region);
	player1->conquers();
	//player1->firstConquest();
	for (int i = 0; i < player1->getOwnedRegions().size(); i++) {
		cout << player1->getOwnedRegions()[i]->getNbTokens() << endl;
		cout << player1->getOwnedRegions()[i]->getOwnershipStatus() << endl;
		cout << player1->getOwnedRegions()[i]->getOwner() << endl;
	}

	//player1->attackTerritory(region);
	player1->scores(bank);

	std::cin >> answer;

	return 0;

}

