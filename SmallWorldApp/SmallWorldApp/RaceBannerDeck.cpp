#include "Tokens.h"

//Constructor, populating the initial array with raceBanners
RaceBannerDeck::RaceBannerDeck() {
	
	for (int i = 0; i < NUM_OF_RACE_BANNERS; i++) {
		//loop to enumerate through races enum
		for (unsigned j = RACE_AMAZONS; j != TOTAL_RACES; j++)
		{
			banners[i] = new RaceBanner(static_cast<races>(j));
		}
	}
}

void RaceBannerDeck::shuffle() {
	std::random_shuffle(std::begin(banners), std::end(banners)); //last element may not be shuffled?
}

void RaceBannerDeck::buildDeck() {
	shuffle();
	for (int i = 0; i < NUM_OF_RACE_BANNERS; i++) {
		deck.push(banners[i]);
	}
}

RaceBanner RaceBannerDeck::draw() {
	RaceBanner *drawnCard = deck.front();
	deck.pop();
	return *drawnCard;
}

void RaceBannerDeck::putBannerBack(RaceBanner *banner) {
	deck.push(banner);
}

void RaceBannerDeck::printDeck() {
	std::cout << "Here is the deck of race banners" << std::endl;
	for (int i = 0; i < NUM_OF_RACE_BANNERS; i++) {
		std::cout << banners[i]->getRace() << std::endl;
	}
}