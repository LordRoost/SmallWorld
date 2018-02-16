#include "Players.h"

Player::Player() {		

}

DieRoller Player::getDieRoller() {
	return dice;
}

PowerBadge Player::getBadge() {
	return currentBadge;
}

RaceToken Player::getToken() {
	return currentRace;
}

VictoryCoin Player::getVictoryCoin() {
	return ownedCoins;
}

RaceBanner Player::getRacebanner() {
	return currentBanner;
}

void Player::setBadge(PowerBadge badge) {
	currentBadge = badge;
}

void Player::setDieRoller(DieRoller die) {
	dice = die;
}

void Player::setRaceToken(RaceToken tokens) {
	currentRace = tokens;
}

void Player::setVictoryCoin(VictoryCoin coins) {
	ownedCoins = coins;
}

void Player::setRaceBanner(RaceBanner banner) {
	currentBanner = banner;
}

void Player::picks_race() {

}

void Player::conquers() {

}

void Player::scores() {

}

