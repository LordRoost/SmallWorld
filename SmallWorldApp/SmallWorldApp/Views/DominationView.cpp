#include "../Headers/DominationView.h"

DominationView::DominationView(Player* player, PlayGame *game) {
	_subjectPlayer = player;
	_subjectPlayer->Attach(this);
	theGame = game;
}


DominationView::~DominationView() {
	_subjectPlayer->Detach(this);
}

void DominationView::Update() {
	display();
}

void DominationView::barDisplay(int nb) {

	for(int i = 0; i < nb; i++)
		std::cout << "|";
	std::cout << std::endl;
}

void DominationView::display() {

	std::cout << "--------------------------------------------------------------------------------------------------------------------" << std::endl;
	barDisplay(100);
	std::cout << "--------------------------------------------------------------------------------------------------------------------" << std::endl;
	for (size_t i = 0; i < theGame->players.size(); i++) {
		double percentageOfMap = theGame->players[i]->calculateOwnedPercentage(theGame->players.size());
		std::cout << "         Player " << (i + 1) << " owns " << setprecision(3) << percentageOfMap << " % of the map" << std::endl;
		barDisplay(percentageOfMap);
	}

	std::cout << "--------------------------------------------------------------------------------------------------------------------" << std::endl;
}