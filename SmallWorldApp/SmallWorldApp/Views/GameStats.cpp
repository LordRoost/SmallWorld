#include "../Headers/GameStats.h"
#include "../Headers/PlayGame.h"


GameStats::GameStats(PlayGame* game) {
	_subject = game;
	_subject->Attach(this);
}


GameStats::~GameStats() {
	_subject->Detach(this);
}

void GameStats::Update() {
	display();
}

void GameStats::display() {

	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "                     Turn " << _subject->getCurrentTurn() << std::endl;
	std::cout << "           Player " << _subject->getCurrentPlayerNb() << ": " << _subject->getCurrentPhase() << " phase" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
}