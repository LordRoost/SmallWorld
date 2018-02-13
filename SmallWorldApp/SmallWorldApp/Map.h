#pragma once
#include <iostream>

enum regionTypes {
	REGION_TYPE_FOREST, REGION_TYPE_FARMLAND, REGION_TYPE_MOUNTAIN, REGION_TYPE_HILL, REGION_TYPE_SWAMP, TOTAL_REGION_TYPE
};

enum regionBonus {
	REGION_BONUS_MINES, REGION_BONUS_MAGIC, REGION_BONUS_CAVERN, TOTAL_REGION_BONUS
};

class MapRegion {
public:
	MapRegion(regionTypes regionType);
	~MapRegion() {};
	bool isEmpty(); //if there are no "people" aka race tokens in the region it is empty.

private:
	//Token tokens[];
	regionTypes type;
	bool isBorder;
	//Player *ownedBy;

};
