#include "../Headers/Game.h"
//#include "Players.h"

RacePicker::RacePicker() {
	bannerDeck = new RaceBannerDeck();
	powerDeck = new PowerBadgeDeck();
}

void RacePicker::setup() {
	bannerDeck->shuffle();//need to shuffle multiple times for it to actually work. Need to find out why
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

void RacePicker::replaceChoices(int index) {
	int maxIndex = MAX_NUMBER_PICKABLE_POWERS - 1;
	for (int i = index; i < maxIndex; i++) {
		pickableRaces[i] = pickableRaces[i + 1];
		pickablePowers[i] = pickablePowers[i + 1];
	}
	pickableRaces[maxIndex] = bannerDeck->draw();
	pickablePowers[maxIndex] = powerDeck->draw();
}

void RacePicker::printOptions() {
	std::cout << "These are the available races: " << std::endl;

	for (int i = 0; i < MAX_NUMBER_PICKABLE_POWERS; i++) {
		std::cout << (i+1) << ". " << pickablePowers[i]->getPowerName() << " : " << pickableRaces[i]->getName() << std::endl;
	}
}