#include "../Headers/Tokens.h"
#include <iterator>
#include <random>
#include <chrono>

//Constructor, populating the initial array with raceBanners
RaceBannerDeck::RaceBannerDeck() {
	
	for (unsigned i = RACE_AMAZONS; i != TOTAL_RACES; i++) {
		banners[i] = new RaceBanner(static_cast<races>(i));
	}
}

RaceBannerDeck::~RaceBannerDeck() {
	for (unsigned i = RACE_AMAZONS; i != TOTAL_RACES; i++) {
		delete(banners[i]);
		banners[i] = NULL;
	}
}

void RaceBannerDeck::shuffle() {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(std::begin(banners), std::end(banners), std::default_random_engine(seed));
}

void RaceBannerDeck::shuffleDiscard() {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(std::begin(bannerDiscardPile), std::end(bannerDiscardPile), std::default_random_engine(seed));
}

void RaceBannerDeck::buildDeck() {
	shuffle();
	for (int i = 0; i < NUM_OF_RACE_BANNERS; i++) {
		deck.push(banners[i]);
	}
}

RaceBanner* RaceBannerDeck::draw() {
	RaceBanner *drawnCard = deck.front(); 
	deck.pop();
	return drawnCard;
}

void RaceBannerDeck::discardBanner(RaceBanner *banner) {
	bannerDiscardPile.push_back(banner);
}

void RaceBannerDeck::printDeck() {
	std::cout << "Here is the deck of race banners" << std::endl;
	for (int i = 0; i < NUM_OF_RACE_BANNERS; i++) {
		std::cout << banners[i]->getName() << std::endl;
	}
}

void RaceBannerDeck::addBanner(RaceBanner *banner) {
	deck.push(banner);
}