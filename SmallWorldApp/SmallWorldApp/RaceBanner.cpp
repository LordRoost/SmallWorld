#include "Tokens.h"

RaceBanner::RaceBanner() {
	isActive = true;
}

RaceBanner::RaceBanner(races bannerRace) {
	isActive = true;
	race = bannerRace;
	amountOfTokensReceived = raceInfo[race].amountTokensReceived; 
}

bool RaceBanner::getStatus() {
	return isActive;
}

void RaceBanner::setStatus(bool status) {
	isActive = status;
}

races RaceBanner::getRace() {
	return race;
}

void RaceBanner::setRace(races bannerRace) {
	race = bannerRace;
}

void RaceBanner::decline() {
	isActive = false;

}

