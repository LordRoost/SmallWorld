#include <iostream>
#include "../Headers/MapRegion.h"

using namespace std;
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
}


const char * MapRegion::getTextForEnumRegionTypes(int enumVal)
{
	return EnumRegionTypes[enumVal];
}

void MapRegion::setType(regionTypes regionType) {
	type = regionType;
}

