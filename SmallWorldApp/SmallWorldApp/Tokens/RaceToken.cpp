#include "../Headers/Tokens.h"


RaceToken::RaceToken(races newRace) {
	race = newRace;
	isActive = false;
}

bool RaceToken::getStatus() {
	return isActive;
}

void RaceToken::setStatus(bool status) {
	isActive = status;
}

races RaceToken::getRace() {
	return race;
}

void RaceToken::setRace(races bannerRace) {
	race = bannerRace;
}

void RaceToken::decline() {
	isActive = false;

}