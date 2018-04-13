#include "../Headers/DominationDecorator.h"

DominationDecorator::~DominationDecorator() {
	_subject->Detach(this);
	
}

void DominationDecorator::Update() {

	if (theGame->getCurrentPhase() == "Conquering")
		display();
}

void DominationDecorator::barDisplay(int nb) {

	for (int i = 0; i < nb; i++)
		std::cout << "|";
	std::cout << std::endl;
}

void DominationDecorator::display() {

	std::cout << "-------------------------------------DOMINATION-DECORATOR-----------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------------" << std::endl;
	barDisplay(100);
	std::cout << "--------------------------------------------------------------------------------------------------------------------" << std::endl;
	for (size_t i = 0; i < theGame->players.size(); i++) {
		double percentageOfMap = theGame->players[i]->calculateOwnedPercentage(theGame->players.size());
		std::cout << "         Player " << (i + 1) << " owns " << std::setprecision(3) << percentageOfMap << " % of the map" << std::endl;
		barDisplay(percentageOfMap);
	}

	std::cout << "--------------------------------------------------------------------------------------------------------------------" << std::endl;
}