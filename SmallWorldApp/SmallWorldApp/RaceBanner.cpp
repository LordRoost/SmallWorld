#include "Tokens.h"

RaceInfo raceInfo[TOTAL_RACES] = { { RACE_AMAZONS, "Amazons", 6, 15 },{ RACE_DWARVES, "Dwarves", 3, 8 },{ RACE_ELVES, "Elves", 6, 11 },{ RACE_GHOULS, "Ghouls", 5, 10 },{ RACE_GIANTS, "Giants", 6, 11 },
{ RACE_HALFLINGS, "Halflings", 6, 11 },{ RACE_HUMANS, "Humans", 5, 10 },{ RACE_ORCS, "Orcs", 5, 10 },{ RACE_RATMEN, "Ratmen", 8, 13 } ,{ RACE_SKELETONS, "Skeletons", 6, 20 } ,{ RACE_SORCERERS, "Sorcerers", 5, 18 } ,
{ RACE_TRITONS, "Tritons", 6, 11 } ,{ RACE_TROLLS, "Trolls", 5, 10 } ,{ RACE_WIZARDS, "Wizards", 5, 10 } };

RaceBanner::RaceBanner() {
	isActive = true;
}

RaceBanner::RaceBanner(races bannerRace) {
	isActive = true;
	race = bannerRace;
	name = raceInfo[race].raceName;
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

std::string RaceBanner::getName() {
	return name;
}

void RaceBanner::setName(std::string newName) {
	name = newName;
}

void RaceBanner::decline() {
	isActive = false;

}

