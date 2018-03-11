#ifndef MapRegion_H
#define MapRegion_H
#pragma once
#define BOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE //this is just to not have the boost outdated message everytime code is run

#include <stdio.h>
#include <iostream>
#include <list>
#include "Tokens.h"


class Player;

using namespace std;


enum regionTypes {
	REGION_TYPE_FOREST, REGION_TYPE_FARMLAND, REGION_TYPE_MOUNTAIN, REGION_TYPE_HILL, REGION_TYPE_SWAMP, TOTAL_REGION_TYPE
};

struct RegionInfo {
	regionTypes regionType;
	std::string regionName;
};

static const char * EnumRegionTypes[] = { "Forest", "Farmland", "Mountain","Hill","Swamp" };


enum regionBonus {
	REGION_BONUS_MINES, REGION_BONUS_MAGIC, REGION_BONUS_CAVERN, TOTAL_REGION_BONUS
};

class MapRegion {
public:
	MapRegion();
	MapRegion(string s,int indexOfVertex);
	MapRegion(regionTypes regionType);
	//static const char * getTextForEnumRegionTypes(int enumVal);
	void setOwner(Player *newOwner);
	void setType(regionTypes regionType);
	void setName(string newName);
	void setOwnershipStatus(bool status);
	void setNbTokens(int amount);
	void setLostTribeToken(LostTribeToken *tribe);
	void addRaceTokens(RaceToken race, int amount);
	//void addRaceToken(RaceToken *race);
	void adddefensiveStructure(GamePiece *piece);

	Player* getOwner();
	regionTypes getType();
	string getName();
	bool getOwnershipStatus();
	RaceToken getRaceToken();
	int getNbTokens();
	LostTribeToken* getLostTribeToken();
	vector<GamePiece> getDefensiveStructures();

	bool hasLostTribe();
    int getIndexOfVertex();

private:
	string typeName;
	regionTypes type;
	bool isOwned;
	Player *owner;
	//std::vector <Token> *tokens;
	RaceToken tokens;
	int nbOfTokens;
	LostTribeToken *lostTribes; 
	std::vector<GamePiece> *defensiveStructures; //holds game pieces that offer defensive abilities to regions (Mountain, Forteress, Troll Lair and Encampments)

    int indexOfVertex;
};

#endif
