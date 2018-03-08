#include <iostream>
#include "../Headers/MapRegion.h"

using namespace std;

RegionInfo regionInfo[TOTAL_REGION_TYPE] = { {REGION_TYPE_FOREST, "Forest"}, {REGION_TYPE_FARMLAND, "Farmland"}, {REGION_TYPE_MOUNTAIN, "Mountain"}, 
{REGION_TYPE_HILL, "Hill"}, {REGION_TYPE_SWAMP, "Swamp"} };


MapRegion::MapRegion() {
	type = REGION_TYPE_FOREST;
}

MapRegion::MapRegion(string s) {

	int x = std::distance(EnumRegionTypes, std::find(EnumRegionTypes, EnumRegionTypes + 5, s));

	type = static_cast<regionTypes>(x);

}

MapRegion::MapRegion(regionTypes _type) {
	cout << "Object is being created, regionType = " << _type << endl;
	type = _type;
	typeName = regionInfo[type].regionName;
}


//const char * MapRegion::getTextForEnumRegionTypes(int enumVal)
//{
//	return EnumRegionTypes[enumVal];
//}

string MapRegion::getName() {
	return typeName;
}

regionTypes MapRegion::getType() {
	return type;
}

bool MapRegion::getOwnershipStatus() {
	return isOwned;
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

