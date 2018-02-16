#include "Players.h"

Player::Player() {

}

DieRoller Player::getDieRoller() {
	return dice;
}

PowerBadge Player::getBadge() {
	return currentBadge;
}

RaceToken Player::getToken();
VictoryCoin Player::getVictoryCoin();
RaceBanner Player::getRacebanner();

void Player::setBadge(PowerBadge badge);
void Player::setDieRoller(DieRoller dice);
void Player::setRaceToken(RaceToken tokens);
void Player::setVictoryCoin(VictoryCoin coins);
void Player::setRaceBanner(Racebanner banner);

Player::picks_race();
Player::conquers();
Player::scores();