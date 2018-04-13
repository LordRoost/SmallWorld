#ifndef __MAPREGION_H__
#define __MAPREGION_H__
#pragma once
#define BOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE //this is just to not have the boost outdated message everytime code is run

#include <stdio.h>
#include <iostream>
#include <list>
#include "Tokens.h"


class Player;

enum regionTypes {
	REGION_TYPE_FOREST, REGION_TYPE_FARMLAND, REGION_TYPE_MOUNTAIN, REGION_TYPE_HILL, REGION_TYPE_SWAMP, TOTAL_REGION_TYPE
};

struct RegionInfo {
	regionTypes regionType;
	std::string regionName;
};

static const char * EnumRegionTypes[] = { "Forest", "Farmland", "Mountain", "Hill", "Swamp" };


enum regionBonus {
	REGION_BONUS_MINES, REGION_BONUS_MAGIC, REGION_BONUS_CAVERN, TOTAL_REGION_BONUS
};

class MapRegion {
public:
	MapRegion();
	MapRegion(std::string s,int indexOfVertex);
	MapRegion(regionTypes regionType);
	~MapRegion();
	void setOwner(Player *newOwner);
	void setType(regionTypes regionType);
	void setName(std::string newName);
	void setOwnershipStatus(bool status);
	void setNbTokens(int amount);
	void setLostTribeToken(LostTribeToken *tribe);
    void setIsBorder(bool _isBorder);
	void addRaceTokens(RaceToken race, int amount);
	void addDefensiveStructure(GamePiece piece);
	void addLostTribeToken();
	void setMountainPiece(MountainPiece *m);
	void setRaceOfOccupants(races occupantRace);

	Player* getOwner();
	regionTypes getType();
	std::string getName();
	bool getOwnershipStatus();
	RaceToken getRaceToken();
	int getNbTokens();
	LostTribeToken* getLostTribeToken();
	std::vector<GamePiece> getDefensiveStructures();
    bool getIsBorder();
	races getRaceOfOccupants();

	bool hasLostTribe();
    int getIndexOfVertex();
	void setTribe(bool tribe);
	bool getTribe();

	void vacate(); //empties the region and resets it to a clean slate

private:
	std::string typeName;
	regionTypes type;
	bool isOwned;
	Player *owner;
	RaceToken tokens;
	races raceOfOccupants;
	int nbOfTokens;
	LostTribeToken *lostTribes; 
	std::vector<GamePiece> defensiveStructures; //holds game pieces that offer defensive abilities to regions (Mountain, Forteress, Troll Lair and Encampments)

    int indexOfVertex;
    bool isBorder;
	bool hasTribe;
	MountainPiece *mountainPiece;
};

#endif //__MAPREGION_H__
