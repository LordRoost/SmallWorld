#include "Tokens.h"
//#include <array> should use arrays like this?
#include <iterator>
#include <random>
#include <chrono>

//Constructor, populating the initial array with raceBanners
RaceBannerDeck::RaceBannerDeck() {
	
	for (unsigned i = RACE_AMAZONS; i != TOTAL_RACES; i++) {
		banners[i] = new RaceBanner(static_cast<races>(i));
	}
}

void RaceBannerDeck::shuffle() {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(std::begin(banners), std::end(banners), std::default_random_engine(seed));
}

void RaceBannerDeck::buildDeck() {
	shuffle();
	for (int i = 0; i < NUM_OF_RACE_BANNERS; i++) {
		deck.push(banners[i]);
	}
}

RaceBanner* RaceBannerDeck::draw() {
	RaceBanner *drawnCard = deck.front(); //If see this error 'Expression: deque iterator not dereferencable' possible that queue is empty
	deck.pop();
	return drawnCard;
}

void RaceBannerDeck::putBannerBack(RaceBanner *banner) {
	deck.push(banner);
}

void RaceBannerDeck::printDeck() {
	std::cout << "Here is the deck of race banners" << std::endl;
	for (int i = 0; i < NUM_OF_RACE_BANNERS; i++) {
		std::cout << banners[i]->getName() << std::endl;
	}
}