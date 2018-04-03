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
std::vector<RaceBanner*> RacePicker::getAllPickableRaces(){
    std::vector<RaceBanner*> vector(MAX_NUMBER_PICKABLE_RACES);
    
    for(int i=0;i<MAX_NUMBER_PICKABLE_RACES;i++){
        vector[i]=pickableRaces[i];
    }
    return vector;
}

std::vector<PowerBadge*> RacePicker::getAllPickablePowers(){
    std::vector<PowerBadge*> vector(MAX_NUMBER_PICKABLE_POWERS);
    
    for(int i=0;i<MAX_NUMBER_PICKABLE_POWERS;i++){
        vector[i]=pickablePowers[i];
    }
    return vector;
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
		if (pickableRaces[i] == NULL || pickablePowers[i] == NULL) {
			if (pickableRaces[i] == NULL) {
				bannerDeck->shuffleDiscard();
				bannerDeck->shuffleDiscard();
				bannerDeck->shuffleDiscard();

				for (size_t j = 0; j < bannerDeck->bannerDiscardPile.size(); j++) {
					RaceBanner *temp = bannerDeck->bannerDiscardPile[j];
					temp = bannerDeck->bannerDiscardPile.front();
					bannerDeck->bannerDiscardPile.pop_front();
					bannerDeck->addBanner(temp);
				}
			}
			else if (pickablePowers[i] == NULL) {
				powerDeck->shuffleDiscard();
				powerDeck->shuffleDiscard();
				powerDeck->shuffleDiscard();

				for (size_t j = 0; j < powerDeck->badgeDiscardPile.size(); j++) {
					PowerBadge *temp = powerDeck->badgeDiscardPile[j];
					temp = powerDeck->badgeDiscardPile.front();
					powerDeck->badgeDiscardPile.pop_front();
					powerDeck->addBadge(temp);
				}
			}
		}
		pickableRaces[i] = pickableRaces[i + 1];
		pickablePowers[i] = pickablePowers[i + 1];
	}
	pickableRaces[maxIndex] = bannerDeck->draw();
	pickablePowers[maxIndex] = powerDeck->draw();

}

void RacePicker::printOptions() {
	std::cout << "These are the available races: " << std::endl;

	for (int i = 0; i < MAX_NUMBER_PICKABLE_POWERS; i++) {
		std::cout << (i+1) << ". " << pickablePowers[i]->getPowerName() << " : " << pickableRaces[i]->getName() << " (" << calculateTotalTokens(i) << ") Tokens" << std::endl;
	}
}

int RacePicker::calculateTotalTokens(int index) {
	return (pickablePowers[index]->getAmountTokensReceived() + pickableRaces[index]->getAmountTokensReceived());
}

void RacePicker::discardDeclined(RaceBanner *discardedBanner, PowerBadge *discardedBadge) {
	bannerDeck->discardBanner(discardedBanner);
	powerDeck->discardBadge(discardedBadge);
}