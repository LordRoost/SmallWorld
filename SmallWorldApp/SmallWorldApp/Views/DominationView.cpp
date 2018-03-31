#include "../Headers/DominationView.h"
#include "../Headers/PlayGame.h"
#include "../Headers/Players.h"

DominationView::DominationView(PlayGame* game) {
	_subjectGame = game; 
	_subjectGame->Attach(this);
}

DominationView::DominationView(Player* player) {
	_subjectPlayer = player;
	_subjectPlayer->Attach(this);
}

DominationView::~DominationView() {
	_subjectGame->Detach(this);
	_subjectPlayer->Detach(this);
}

void DominationView::Update() {
	display();
}

void DominationView::display() {

	//for (size_t i = 0; i < players.size(); i++) {

	//}

	double percentageOfMap = _subjectPlayer->calculateOwnedPercentage();
	std::cout << "--------------Player " <<"1" << " owns " <<  percentageOfMap << " % of the map-------------------------" << std::endl;
}