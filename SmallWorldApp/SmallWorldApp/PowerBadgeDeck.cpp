#include "Tokens.h"

//Constructor, populating the initial array
PowerBadgeDeck::PowerBadgeDeck() {

	for (int i = 0; i < NUM_OF_POWERS; i++) {
		for (unsigned j = RACE_AMAZONS; j != TOTAL_RACES; j++)
		{
			badges[i] = new PowerBadge(static_cast<powers>(j));
		}
	}
}

void PowerBadgeDeck::shuffle() {
	std::random_shuffle(std::begin(badges), std::end(badges)); //last element may not be shuffled?
}

void PowerBadgeDeck::buildDeck() {
	shuffle();
	for (int i = 0; i < NUM_OF_POWERS; i++) {
		deck.push(badges[i]);
	}
}

PowerBadge PowerBadgeDeck::draw() {
	PowerBadge *drawnCard = deck.front();
	deck.pop();
	return *drawnCard;
}

void PowerBadgeDeck::putBadgeBack(PowerBadge *badge) {
	deck.push(badge);
}

void PowerBadgeDeck::printDeck() {
	std::cout << "Here is the deck of power badges" << std::endl;
	for (int i = 0; i < NUM_OF_POWERS; i++) {
		std::cout << badges[i]->getPower() << std::endl;
	}
}