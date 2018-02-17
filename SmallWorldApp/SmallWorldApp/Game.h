#pragma once

#include "Tokens.h"
#define MAX_NUMBER_PICKABLE_RACES 6
#define MAX_NUMBER_PICKABLE_POWERS 6

class RacePicker {
public:
	RacePicker();
	void setup();
	RaceBanner* getPickableRaces();
	PowerBadge* getPickablePowers();
	RaceBanner* getPickableRaces(int index);
	PowerBadge* getPickablePowers(int index);
	void printOptions();

private:
	RaceBannerDeck *bannerDeck;
	PowerBadgeDeck *powerDeck;
	RaceBanner *pickableRaces[MAX_NUMBER_PICKABLE_RACES];
	PowerBadge *pickablePowers[MAX_NUMBER_PICKABLE_POWERS];
};