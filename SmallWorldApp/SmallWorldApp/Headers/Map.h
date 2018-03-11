#ifndef Map_H
#define Map_H

#include <stdio.h>
#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include "MapRegion.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/connected_components.hpp>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

using namespace boost;
using namespace std;

typedef adjacency_list<listS, vecS, undirectedS, MapRegion> Graph;
typedef boost::graph_traits<Graph>::adjacency_iterator AdjacencyIterator;

class Map {
public:
	void createMap();
	void loadMap(string file);
	bool graphIsConnected();
	Graph getMap();
    static void getListOfMaps(const string& path);
    void selectMap(string path);
    bool addMountainorLostTribe(string regionType);
    vector<MapRegion> getAdgacentTerritories(MapRegion *region);

private:
	Graph g;
};

#endif

