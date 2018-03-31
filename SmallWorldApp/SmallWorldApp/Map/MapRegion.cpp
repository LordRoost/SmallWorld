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
    isBorder=false;
	mountainPiece = NULL;
	nbOfTokens = 0;
	raceOfOccupants = RACE_NONE;
}

MapRegion::MapRegion(string s, int _indexOfVertex) {

	int x = std::distance(EnumRegionTypes, std::find(EnumRegionTypes, EnumRegionTypes + 5, s));

	type = static_cast<regionTypes>(x);
	lostTribes = NULL;
	owner = NULL;
	isOwned = false;
    indexOfVertex=_indexOfVertex;
	nbOfTokens = 0;
	raceOfOccupants = RACE_NONE;

    if((rand() % 100) < 40){
        isBorder=true;
    }
    else{
        isBorder=false;
    }

	if (s == "Mountain") {
		MountainPiece m = MountainPiece();
		MountainPiece * pointer = &m;
		mountainPiece = pointer;
		
	}
	else {
		mountainPiece = NULL;
		
	}
	
}

MapRegion::MapRegion(regionTypes _type) {
	cout << "Object is being created, regionType = " << _type << endl;
	type = _type;
	typeName = regionInfo[type].regionName;
	lostTribes = NULL;
	owner = NULL;
	isOwned = false;
    isBorder=false;
	nbOfTokens = 0;
	raceOfOccupants = RACE_NONE;
}


//const char * MapRegion::getTextForEnumRegionTypes(int enumVal)
//{
//	return EnumRegionTypes[enumVal];
//}

Player* MapRegion::getOwner() {
	return owner;
}

bool MapRegion::getIsBorder(){
    return isBorder;
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

races MapRegion::getRaceOfOccupants() {
	return raceOfOccupants;
}

LostTribeToken* MapRegion::getLostTribeToken() {
	return lostTribes;
}

vector<GamePiece> MapRegion::getDefensiveStructures() {
	return defensiveStructures;
}
int MapRegion::getIndexOfVertex(){
    return indexOfVertex;
}

void MapRegion::setMountainPiece(MountainPiece *m) {
	mountainPiece = m;
	addDefensiveStructure(*m);
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

void MapRegion::setIsBorder(bool _isBorder){
    isBorder=_isBorder;
}

void MapRegion::setRaceOfOccupants(races occupantRace) {
	raceOfOccupants = occupantRace;
}

void MapRegion::addRaceTokens(RaceToken race, int amount) {
	tokens = race;
	nbOfTokens += amount;

}

void MapRegion::addDefensiveStructure(GamePiece piece) {
	defensiveStructures.push_back(piece);
}

bool MapRegion::hasLostTribe() {
	//if (lostTribes == NULL)
	if(hasTribe == false)
		return false;
	else
		return true;
}

void MapRegion::setTribe(bool tribe) {
	hasTribe = tribe;
}

bool MapRegion::getTribe() {
	return hasTribe;
}

void MapRegion::addLostTribeToken() {

}