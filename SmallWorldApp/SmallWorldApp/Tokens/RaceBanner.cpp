#include "../Headers/Tokens.h"

RaceInfo raceInfo[TOTAL_RACES] = { { RACE_AMAZONS, "Amazons", 6, 15,13 },{ RACE_DWARVES, "Dwarves", 3, 8,1 },{ RACE_ELVES, "Elves", 6, 11,9 },{ RACE_GHOULS, "Ghouls", 5, 10,7 },{ RACE_GIANTS, "Giants", 6, 11,12 },
{ RACE_HALFLINGS, "Halflings", 6, 11,6 },{ RACE_HUMANS, "Humans", 5, 10,2 },{ RACE_ORCS, "Orcs", 5, 10,5 },{ RACE_RATMEN, "Ratmen", 8, 13,14 } ,{ RACE_SKELETONS, "Skeletons", 6, 20,10 } ,{ RACE_SORCERERS, "Sorcerers", 5, 18,8 } ,
{ RACE_TRITONS, "Tritons", 6, 11,11 } ,{ RACE_TROLLS, "Trolls", 5, 10,4 } ,{ RACE_WIZARDS, "Wizards", 5, 10,3 } };

RaceBanner::RaceBanner() {
	isActive = true;
}

RaceBanner::RaceBanner(races bannerRace) {
	isActive = true;
	race = bannerRace;
	name = raceInfo[race].raceName;
	amountOfTokensReceived = raceInfo[race].amountTokensReceived;
    aggressivePoint=raceInfo[race].aggressivePoint;
}

int RaceBanner::getAggressivePoint(){
    return aggressivePoint;
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

int RaceBanner::getAmountTokensReceived() {
	return amountOfTokensReceived;
}

void RaceBanner::setAmountTokensReceived(int nb) {
	amountOfTokensReceived = nb;
}

void RaceBanner::decline() {
	isActive = false;

}

