#ifndef Map_H
#define Map_H

#include <stdio.h>
#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include "MapRegion.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace boost;
using namespace std;

typedef adjacency_list<listS, vecS, undirectedS, MapRegion> Graph;

class Map {
public:
	void createMap();
	void loadMap(string file);
	bool graphIsConnected();
	Graph getMap();

private:
	Graph g;
};

#endif

