#include "../Headers/Tokens.h"
#include <iterator>
#include <random>
#include <chrono>

//Constructor, populating the initial array
PowerBadgeDeck::PowerBadgeDeck() {

	for (unsigned i = POWER_ALCHEMIST; i != TOTAL_POWERS; i++) {
		badges[i] = new PowerBadge(static_cast<powers>(i));
	}
}

void PowerBadgeDeck::shuffle() {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(std::begin(badges), std::end(badges), std::default_random_engine(seed));
}

void PowerBadgeDeck::buildDeck() {
	shuffle();
	for (int i = 0; i < NUM_OF_POWERS; i++) {
		deck.push(badges[i]);
	}
}

PowerBadge* PowerBadgeDeck::draw() {
	PowerBadge *drawnCard = deck.front();
	deck.pop();
	return drawnCard;
}

//when a player makes a race go into decline, the power gets discarded using this method
void PowerBadgeDeck::discardBadge(PowerBadge *badge) {
	discardPile.push_back(*badge);
	//deck.push(badge);
}

//prints the contents of the powers deck
void PowerBadgeDeck::printDeck() {
	std::cout << "Here is the deck of power badges" << std::endl;
	for (int i = 0; i < NUM_OF_POWERS; i++) {
		std::cout << badges[i]->getPowerName() << std::endl;
	}
}