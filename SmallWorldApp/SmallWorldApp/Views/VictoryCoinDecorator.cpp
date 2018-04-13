#include "../Headers/VictoryCoinDecorator.h"

VictoryCoinDecorator::~VictoryCoinDecorator() {
	_subject->Detach(this);
}

void VictoryCoinDecorator::Update() {

	if(theGame->getCurrentPhase() == "Scoring")
		display();
}

void VictoryCoinDecorator::display() {

	std::cout << "---------------------------------------VICTORY-COiN-DECORATOR-------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "           Player " << theGame->getCurrentPlayerNb() << " scores " << _subject->getOwnedRegions().size() << " victory coins for their regions." << std::endl;
	std::cout << "           Player " << theGame->getCurrentPlayerNb() << " scores " << _subject->nbScoredCoinsPower << " victory coins because of their power." << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------------" << std::endl;
}