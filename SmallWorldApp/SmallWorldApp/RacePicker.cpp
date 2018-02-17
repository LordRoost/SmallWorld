#include "Game.h"

RacePicker::RacePicker() {
	bannerDeck = new RaceBannerDeck();
	powerDeck = new PowerBadgeDeck();
}

void RacePicker::setup() {
	bannerDeck->shuffle();
	bannerDeck->shuffle();
	bannerDeck->shuffle();
	bannerDeck->buildDeck();
	powerDeck->shuffle();
	powerDeck->shuffle();
	powerDeck->shuffle();
	powerDeck->buildDeck();

	for (int i = 0; i < MAX_NUMBER_PICKABLE_RACES; i++) {
		pickableRaces[i] = bannerDeck->draw();
		//std::cout << pickableRaces[i]->getName() << std::endl;
		pickablePowers[i] = powerDeck->draw();
		//std::cout << pickablePowers[i]->getPowerName() << std::endl;
	}

}

RaceBanner* RacePicker::getPickableRaces() {
	return pickableRaces[0];
}

RaceBanner* RacePicker::getPickableRaces(int index) {
	return pickableRaces[index];
}

PowerBadge* RacePicker::getPickablePowers() {
	return pickablePowers[0];
}

PowerBadge* RacePicker::getPickablePowers(int index) {
	return pickablePowers[index];
}


void RacePicker::printOptions() {
	std::cout << "Which race would you like to choose?" << std::endl;

	for (int i = 0; i < MAX_NUMBER_PICKABLE_POWERS; i++) {
		std::cout << pickablePowers[i]->getPowerName();
		std::cout << " : ";
		std::cout << pickableRaces[i]->getName() << std::endl;
	}
}