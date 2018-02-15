#include "Tokens.h"

RaceInfo raceInfo[TOTAL_RACES] = { { RACE_AMAZONS, 6, 15 },{ RACE_DWARVES, 3, 8 },{ RACE_ELVES, 6, 11 },{ RACE_GHOULS, 5, 10 },{ RACE_GIANTS, 6, 11 },{ RACE_HALFLINGS, 6, 11 },
{ RACE_HUMANS, 5, 10 },{ RACE_ORCS, 5, 10 },{ RACE_RATMEN, 8, 13 } ,{ RACE_SKELETONS, 6, 20 } ,{ RACE_SORCERERS, 5, 18 } ,{ RACE_TRITONS, 6, 11 } ,{ RACE_TROLLS, 5, 10 } ,{ RACE_WIZARDS, 5, 10 } };

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

