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

typedef adjacency_list<listS, vecS, undirectedS, MapRegion*> Graph;
typedef boost::graph_traits<Graph>::adjacency_iterator AdjacencyIterator;
typedef boost::graph_traits<Graph>::vertex_iterator VertexIterator;

class Map {
public:
	void createMap();
	void loadMap(string file);
	bool graphIsConnected();
	Graph* getGraph();
    static void getListOfMaps(const string& path);
    void selectMap(string path);
	void selectMap(int nbOfPlayers);
    bool addMountainorLostTribe(string regionType);
	void getAdgacentTerritories(MapRegion *region);
    //vector<MapRegion*> getAllBorders();
	void getAllBorders();
	void setBorders();
	void setLostTribe();

	vector<MapRegion*> borderRegions;
	vector<MapRegion*> adgacentMapRegions;
	std::deque<std::string> bordersInputs;
	std::deque<std::string> lostTribesInputs;

private:
	Graph g;

};

#endif

