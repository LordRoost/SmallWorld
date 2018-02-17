//#include <boost/graph/graphviz.hpp>
//#include <boost/graph/graph_traits.hpp>
//#include <boost/graph/connected_components.hpp>
//#include <boost/lexical_cast.hpp>
//#include "MapRegion.h"
//#include "Map.h"
//#include <fstream>
//#include <string>
//#include <sstream>
//#include <iostream>
//
//using namespace std;
//using namespace boost;
//typedef graph_traits<Graph>::vertex_descriptor vertex_t;
//
//void Map::createMap() {
//	//Some typedefs for simplicity
//
//
//	// Create vertices in that graph
//	vertex_t tile1 = add_vertex(g);
//	vertex_t tile2 = add_vertex(g);
//	vertex_t tile3 = add_vertex(g);
//	vertex_t tile4 = add_vertex(g);
//	vertex_t tile5 = add_vertex(g);
//	vertex_t tile6 = add_vertex(g);
//	vertex_t tile7 = add_vertex(g);
//	vertex_t tile8 = add_vertex(g);
//	vertex_t tile9 = add_vertex(g);
//	vertex_t tile10 = add_vertex(g);
//	vertex_t tile11 = add_vertex(g);
//	vertex_t tile12 = add_vertex(g);
//	vertex_t tile13 = add_vertex(g);
//	vertex_t tile14 = add_vertex(g);
//	vertex_t tile15 = add_vertex(g);
//
//	// Set regiontype
//	g[tile1].setType(REGION_TYPE_FARMLAND);
//	g[tile2].setType(REGION_TYPE_FARMLAND);
//	g[tile3].setType(REGION_TYPE_FARMLAND);
//	g[tile4].setType(REGION_TYPE_HILL);
//	g[tile5].setType(REGION_TYPE_HILL);
//	g[tile6].setType(REGION_TYPE_HILL);
//	g[tile7].setType(REGION_TYPE_MOUNTAIN);
//	g[tile8].setType(REGION_TYPE_MOUNTAIN);
//	g[tile9].setType(REGION_TYPE_MOUNTAIN);
//	g[tile10].setType(REGION_TYPE_FOREST);
//	g[tile11].setType(REGION_TYPE_FOREST);
//	g[tile12].setType(REGION_TYPE_FOREST);
//	g[tile13].setType(REGION_TYPE_SWAMP);
//	g[tile14].setType(REGION_TYPE_SWAMP);
//	g[tile15].setType(REGION_TYPE_SWAMP);
//
//	// Create an edge conecting those two vertices
//	add_edge(tile1, tile2, g);
//	add_edge(tile1, tile3, g);
//	add_edge(tile2, tile3, g);
//	add_edge(tile3, tile4, g);
//	add_edge(tile3, tile5, g);
//	add_edge(tile4, tile6, g);
//	add_edge(tile4, tile7, g);
//	add_edge(tile3, tile6, g);
//	add_edge(tile7, tile8, g);
//	add_edge(tile7, tile9, g);
//	add_edge(tile9, tile10, g);
//	add_edge(tile10, tile11, g);
//	add_edge(tile11, tile12, g);
//	add_edge(tile11, tile13, g);
//	add_edge(tile12, tile14, g);
//	add_edge(tile14, tile15, g);
//
//	//write_graphviz(cout, g);
//}
//
//void Map::loadMap(string filename) {
//	string line;
//	ifstream file(filename.c_str());
//
//	if (!file) {
//		cout << "file not read" << endl;
//	}
//
//	int lineNb = 0;
//
//	vector<vertex_t> tiles;
//	vector<string> edges;
//
//	for (line; getline(file, line); lineNb++)
//	{
//		string s = line;
//		string delimiter = " ";
//
//		size_t pos = 0;
//		string token;
//		while ((pos = s.find(delimiter)) != string::npos) {
//			token = s.substr(0, pos);
//			//cout << token << endl;
//
//
//
//			vertex_t tile = add_vertex(g);
//
//			g[tile] = MapRegion(token);
//
//			//tiles.push_back(token);
//			s.erase(0, pos + delimiter.length());
//		}
//		//cout << s << endl;
//		//tiles.push_back(s);
//	}
//
//	//std::copy(tiles.begin(), tiles.end(), std::ostream_iterator<string>(std::cout, " "));
//}
//
//
//
//bool Map::graphIsConnected() {
//	vector<int> component(num_vertices(g));
//	size_t num_components = connected_components(g, &component[0]);
//
//	int number_of_connected_vertices = 0;
//
//	cout << "Vertices in the first component:" << endl;
//	for (size_t i = 0; i < num_vertices(g); ++i) {
//		if (component[i] == 0) {
//			cout << i << endl;
//			number_of_connected_vertices++;
//		}
//	}
//
//	cout << "Number of vertices " + lexical_cast<string>(num_vertices(g)) + "\nNumber of connected vertices: " + lexical_cast<string>(number_of_connected_vertices) << endl;
//
//	if (num_vertices(g) == number_of_connected_vertices) {
//		cout << "We got ourselves a connected graph" << endl;
//		return true;
//	}
//	else {
//		cout << "Not a connected graph" << endl;
//		return false;
//	}
//
//}
