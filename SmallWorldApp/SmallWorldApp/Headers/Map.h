#ifndef Map_H
#define Map_H

#include <stdio.h>
#include "Game.h"
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

#define NUM_REGIONS_2_PLAYER_MAP 20  
#define NUM_REGIONS_3_PLAYER_MAP 27
#define NUM_REGIONS_4_PLAYER_MAP 36
#define NUM_REGIONS_5_PLAYER_MAP 45

using namespace boost;
using namespace std;

typedef adjacency_list<listS, vecS, undirectedS, MapRegion*> Graph;
typedef boost::graph_traits<Graph>::adjacency_iterator AdjacencyIterator;
typedef boost::graph_traits<Graph>::vertex_iterator VertexIterator;

class Map {
public:
	Map();
	Map(TokenWell *aWell);
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
	void initialize(TokenWell *aWell);

	vector<MapRegion*> borderRegions;
	vector<MapRegion*> adgacentMapRegions;
	std::deque<std::string> bordersInputs;
	std::deque<std::string> lostTribesInputs;

private:
	Graph g;
	TokenWell *well;

};

#endif

