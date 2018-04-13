#include "../Headers/StepView.h"
#include "../Headers/PlayGame.h"


StepView::StepView(PlayGame* game) {
	_subject = game;
	_subject->Attach(this);
}


StepView::~StepView() {
	_subject->Detach(this);
}

void StepView::Update() {
	display();
}

void StepView::display() {

	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "                     Turn " << _subject->getCurrentTurn() << std::endl;
	std::cout << "           Player " << _subject->getCurrentPlayerNb() << ": " << _subject->getCurrentPhase() << " phase" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
}