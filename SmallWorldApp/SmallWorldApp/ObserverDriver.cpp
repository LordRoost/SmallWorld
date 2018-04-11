#include "Headers/PlayGame.h"
#include "Headers/StepView.h"
#include "Headers/DominationView.h"


int mainer() {

	PlayGame game1;
	int word;

	game1.startGame();

	StepView *sView = new StepView(&game1);
	for (std::vector<int>::size_type i = 0; i < game1.players.size(); i++) {
		Player *pointer = game1.players[i];
		DominationView *dView = new DominationView(pointer, &game1);

	}


	game1.firstTurn();
	game1.followingTurns();

	std::cout << "game ended" << std::endl;

	std::cin >> word;
	return 0;
}

