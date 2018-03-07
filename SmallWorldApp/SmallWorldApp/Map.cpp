#include <boost/graph/graphviz.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/connected_components.hpp>
//#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>
#include "MapRegion.h"
#include "Map.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using namespace boost;

typedef graph_traits<Graph>::vertex_descriptor vertex_t;

void Map::createMap() {

	// Create vertices in that graph
	vertex_t tile1 = add_vertex(g);
	vertex_t tile2 = add_vertex(g);
	vertex_t tile3 = add_vertex(g);
	vertex_t tile4 = add_vertex(g);
	vertex_t tile5 = add_vertex(g);
	vertex_t tile6 = add_vertex(g);
	vertex_t tile7 = add_vertex(g);
	vertex_t tile8 = add_vertex(g);
	vertex_t tile9 = add_vertex(g);
	vertex_t tile10 = add_vertex(g);
	vertex_t tile11 = add_vertex(g);
	vertex_t tile12 = add_vertex(g);
	vertex_t tile13 = add_vertex(g);
	vertex_t tile14 = add_vertex(g);
	vertex_t tile15 = add_vertex(g);

	// Set regiontype
	g[tile1].setType(REGION_TYPE_FARMLAND);
	g[tile2].setType(REGION_TYPE_FARMLAND);
	g[tile3].setType(REGION_TYPE_FARMLAND);
	g[tile4].setType(REGION_TYPE_HILL);
	g[tile5].setType(REGION_TYPE_HILL);
	g[tile6].setType(REGION_TYPE_HILL);
	g[tile7].setType(REGION_TYPE_MOUNTAIN);
	g[tile8].setType(REGION_TYPE_MOUNTAIN);
	g[tile9].setType(REGION_TYPE_MOUNTAIN);
	g[tile10].setType(REGION_TYPE_FOREST);
	g[tile11].setType(REGION_TYPE_FOREST);
	g[tile12].setType(REGION_TYPE_FOREST);
	g[tile13].setType(REGION_TYPE_SWAMP);
	g[tile14].setType(REGION_TYPE_SWAMP);
	g[tile15].setType(REGION_TYPE_SWAMP);

	// Create edges to vertices
	add_edge(tile1, tile2, g);
	add_edge(tile1, tile3, g);
	add_edge(tile2, tile3, g);
	add_edge(tile3, tile4, g);
	add_edge(tile3, tile5, g);
	add_edge(tile4, tile6, g);
	add_edge(tile4, tile7, g);
	add_edge(tile3, tile6, g);
	add_edge(tile7, tile8, g);
	add_edge(tile7, tile9, g);
	add_edge(tile9, tile10, g);
	add_edge(tile10, tile11, g);
	add_edge(tile11, tile12, g);
	add_edge(tile11, tile13, g);
	add_edge(tile12, tile14, g);
	add_edge(tile14, tile15, g);

	//write_graphviz(cout, g);
}

//load map
//first line is creating tiles(vertices)
//second line is creating edges that connect vertices
void Map::loadMap(string filename) {
	string line;
	ifstream file(filename.c_str());

	if (!file) {
		cout << "file not read" << endl;
	}

	//0 is first line
	//1 is second line
	int lineNb = 0;

	for (line; getline(file, line);)
	{
		string s = line;
		string delimiter = " ";

		size_t pos = 0;
		string token;
		while ((pos = s.find(delimiter)) != string::npos) {
			token = s.substr(0, pos);

			if (lineNb == 0) {
				vertex_t tile = add_vertex(g);
				g[tile] = MapRegion(token);
			}
			else {

				//vector to store both sides of "-"
				vector<int> edge;

				string delimiter2 = "-";
				size_t pos2 = 0;
				std::string token2;
				while ((pos2 = token.find(delimiter2)) != std::string::npos) {
					token2 = token.substr(0, pos2);

					int x = atoi(token2.c_str());
					edge.push_back(x);

					token.erase(0, pos2 + delimiter2.length());
				}
				int y = atoi(token.c_str());
				edge.push_back(y);

				add_edge(edge[0], edge[1], g);
			}

			s.erase(0, pos + delimiter.length());
		}

		if (lineNb == 0) {
			vertex_t tile = add_vertex(g);
			g[tile] = MapRegion(token);
		}
		else {

			vector<int> edge2;

			string delimiter2 = "-";
			size_t pos2 = 0;
			std::string token2;
			while ((pos2 = s.find(delimiter2)) != std::string::npos) {
				token2 = s.substr(0, pos2);

				//std::cout << token2 << std::endl;

				int x = atoi(token2.c_str());
				edge2.push_back(x);

				s.erase(0, pos2 + delimiter2.length());
			}
			int y = atoi(s.c_str());
			edge2.push_back(y);

			add_edge(edge2[0], edge2[1], g);
		}
		lineNb++;
	}
	write_graphviz(cout, g);
}



bool Map::graphIsConnected() {
	vector<int> component(num_vertices(g));
	size_t num_components = connected_components(g, &component[0]);

	int number_of_connected_vertices = 0;

	cout << "Vertices in the first component:" << endl;
	for (size_t i = 0; i < num_vertices(g); ++i) {
		if (component[i] == 0) {
			cout << i << endl;
			number_of_connected_vertices++;
		}
	}

	cout << "Number of vertices " + lexical_cast<string>(num_vertices(g)) + "\nNumber of connected vertices: " + lexical_cast<string>(number_of_connected_vertices) << endl;

	if (num_vertices(g) == number_of_connected_vertices) {
		cout << "We got ourselves a connected graph" << endl;
		return true;
	}
	else {
		cout << "Not a connected graph" << endl;
		return false;
	}

}
