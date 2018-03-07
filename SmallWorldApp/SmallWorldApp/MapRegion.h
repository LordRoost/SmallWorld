#ifndef MapRegion_H
#define MapRegion_H

#include <stdio.h>
#include <iostream>

using namespace std;

enum regionTypes {
	REGION_TYPE_FOREST, REGION_TYPE_FARMLAND, REGION_TYPE_MOUNTAIN, REGION_TYPE_HILL, REGION_TYPE_SWAMP//, TOTAL_REGION_TYPE
};

static const char * EnumRegionTypes[] = { "Forest", "Farmland", "Mountain","Hill","Swamp" };



enum regionBonus {
	REGION_BONUS_MINES, REGION_BONUS_MAGIC, REGION_BONUS_CAVERN, TOTAL_REGION_BONUS
};

class MapRegion {
public:
	MapRegion();
	MapRegion(string s);
	MapRegion(regionTypes regionType);
	static const char * getTextForEnumRegionTypes(int enumVal);
	void setType(regionTypes regionType);
	string getType();

private:

	regionTypes type;


};

#endif
