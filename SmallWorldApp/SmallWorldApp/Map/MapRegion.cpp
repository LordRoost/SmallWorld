#include <iostream>
#include "../Headers/MapRegion.h"

using namespace std;

RegionInfo regionInfo[TOTAL_REGION_TYPE] = { {REGION_TYPE_FOREST, "Forest"}, {REGION_TYPE_FARMLAND, "Farmland"}, {REGION_TYPE_MOUNTAIN, "Mountain"}, 
{REGION_TYPE_HILL, "Hill"}, {REGION_TYPE_SWAMP, "Swamp"} };


MapRegion::MapRegion() {
	type = REGION_TYPE_FOREST;
	lostTribes = NULL;
	owner = NULL;
	isOwned = false;
	//defensiveStructures 
}

MapRegion::MapRegion(string s) {

	int x = std::distance(EnumRegionTypes, std::find(EnumRegionTypes, EnumRegionTypes + 5, s));

	type = static_cast<regionTypes>(x);
	lostTribes = NULL;
	owner = NULL;
	isOwned = false;
}

MapRegion::MapRegion(regionTypes _type) {
	cout << "Object is being created, regionType = " << _type << endl;
	type = _type;
	typeName = regionInfo[type].regionName;
	lostTribes = NULL;
	owner = NULL;
	isOwned = false;
}


//const char * MapRegion::getTextForEnumRegionTypes(int enumVal)
//{
//	return EnumRegionTypes[enumVal];
//}

Player* MapRegion::getOwner() {
	return owner;
}

string MapRegion::getName() {
	return typeName;
}

regionTypes MapRegion::getType() {
	return type;
}

bool MapRegion::getOwnershipStatus() {
	return isOwned;
}

//RaceToken MapRegion::getRaceToken() {
//	return tokens.front();
//}
//
//int MapRegion::getNbTokens() {
//	return tokens.size();
//}

RaceToken MapRegion::getRaceToken() {
	return tokens;
}

int MapRegion::getNbTokens() {
	return nbOfTokens;
}

LostTribeToken* MapRegion::getLostTribeToken() {
	return lostTribes;
}

vector<GamePiece> MapRegion::getDefensiveStructures() {
	return defensiveStructures;
}


void MapRegion::setOwner(Player *newOwner) {
	owner = newOwner;
	setOwnershipStatus(true);
}

void MapRegion::setName(string newName) {
	typeName = newName;
}

void MapRegion::setType(regionTypes regionType) {
	type = regionType;
}

void MapRegion::setOwnershipStatus(bool status) {
	isOwned = status;
}

void MapRegion::setNbTokens(int amount) {
	nbOfTokens = amount;
}

void MapRegion::setLostTribeToken(LostTribeToken *tribe) {
	lostTribes = tribe;
}

void MapRegion::addRaceTokens(RaceToken race, int amount) {
	tokens = race;
	nbOfTokens = amount;

}

void MapRegion::addDefensiveStructure(GamePiece piece) {
	defensiveStructures.push_back(piece);
}

bool MapRegion::hasLostTribe() {
	if (lostTribes == NULL)
		return false;
	else
		return true;
}