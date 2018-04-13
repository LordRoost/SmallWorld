#include "../Headers/MapRegion.h"
#include "../Headers/Map.h"

using namespace boost;

typedef graph_traits<Graph>::vertex_descriptor vertex_t;

Map::Map() {
	well = NULL;
}

Map::~Map() {
	delete(well);
	well = NULL;
}

Map::Map(TokenWell *aWell) {
	well = aWell;
}

Graph* Map::getGraph(){
    return &g;
}

//load map
//first line is creating tiles(vertices)
//second line is creating edges that connect vertices
//line 3 is border or not
//line 4 is lost tribe or not
void Map::loadMap(std::string filename) {
	std::string line;
	std::ifstream file(filename.c_str());

	if (!file) {
		std::cout << "file not read" << std::endl;
	}

	//0 is first line
	//1 is second line
	int lineNb = 0;

	for (line; getline(file, line);)
	{
		std::string s = line;
		std::string delimiter = " ";

		size_t pos = 0;
		std::string token;
		while ((pos = s.find(delimiter)) != std::string::npos) {
			token = s.substr(0, pos);

			if (lineNb == 0) {
				vertex_t tile = add_vertex(g);
				int index = tile & INT_MAX;
				g[tile] = new MapRegion(token, index);
                
				if (g[tile]->getType()==REGION_TYPE_MOUNTAIN) {
					g[tile]->setMountainPiece(well->dealMountain());
				}

			}
			else if(lineNb == 1) {

				//vector to store both sides of "-"
				std::vector<int> edge;

				std::string delimiter2 = "-";
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
			else if (lineNb == 2) {
				bordersInputs.push_back(token); 
			}
			else if (lineNb == 3) {
				lostTribesInputs.push_back(token); 
			}

			s.erase(0, pos + delimiter.length());
		}

		if (lineNb == 0) {
			vertex_t tile = add_vertex(g);
			int index = tile & INT_MAX;
			g[tile] = new MapRegion(token, index);
			if (g[tile]->getType() == REGION_TYPE_MOUNTAIN) {
				g[tile]->setMountainPiece(well->dealMountain());
			}
		}
		else if (lineNb == 1){

			std::vector<int> edge2;

			std::string delimiter2 = "-";
			size_t pos2 = 0;
			std::string token2;
			while ((pos2 = s.find(delimiter2)) != std::string::npos) {
				token2 = s.substr(0, pos2);

				int x = atoi(token2.c_str());
				edge2.push_back(x);

				s.erase(0, pos2 + delimiter2.length());
			}
			int y = atoi(s.c_str());
			edge2.push_back(y);

			add_edge(edge2[0], edge2[1], g);
		}
		else if (lineNb == 2) {
			bordersInputs.push_back(token);
		}
		else if (lineNb == 3) {
			lostTribesInputs.push_back(token); 
		}
		lineNb++;
	}
	write_graphviz(std::cout, g);
	setLostTribe();
	setBorders();
}



bool Map::graphIsConnected() {
	std::vector<int> component(num_vertices(g));
	size_t num_components = connected_components(g, &component[0]);

	int number_of_connected_vertices = 0;

	std::cout << "Vertices in the first component:" << std::endl;
	for (size_t i = 0; i < num_vertices(g); ++i) {
		if (component[i] == 0) {
			std::cout << i << std::endl;
			number_of_connected_vertices++;
		}
	}

	std::cout << "Number of vertices " + lexical_cast<std::string>(num_vertices(g)) + "\nNumber of connected vertices: " + lexical_cast<std::string>(number_of_connected_vertices) << std::endl;

	if (num_vertices(g) == number_of_connected_vertices) {
		std::cout << "We got ourselves a connected graph" << std::endl;
		return true;
	}
	else {
		std::cout << "Not a connected graph" << std::endl;
		return false;
	}

}

void Map::getListOfMaps(const std::string& path)
{

     if (!path.empty())
     {
     
		 std::cout<< "\n--------------------------"<< std::endl;
         
         namespace fs = boost::filesystem;
         
         fs::path apk_path(path);
         fs::recursive_directory_iterator end;
         
         for (fs::recursive_directory_iterator i(apk_path); i != end; ++i)
         {
             fs::path cp = (*i);
			 std::cout<<cp.string()<< std::endl;
         
         }
		 std::cout<< "--------------------------\n"<< std::endl;
     }
     
     else{
		 std::cout<< "Path not found"<< std::endl;
     }
   
}


void Map::selectMap(int nbOfPlayers) {

	//Display Map files in directory
	std::cout << "Let's start a Smallworld game" << std::endl;

	std::string fullPath = "C:/Users/luoja/Documents/Github/SmallWorld/MapFiles/map";
	//string fullPath="/Users/ericpayettereformed/Documents/Smallworld/MapFiles/map";

	fullPath.append(std::to_string(nbOfPlayers));
	fullPath.append(".txt");

	loadMap(fullPath);
}


void Map::getAdgacentTerritories(MapRegion *region){
    
	adgacentMapRegions.clear();
    AdjacencyIterator ai, a_end;

    MapRegion *pointer;
    
    int index=region->getIndexOfVertex();

    boost::tie(ai, a_end) = boost::adjacent_vertices(index, g);
    for (; ai != a_end; ai++) {
        pointer=g[*ai];
        adgacentMapRegions.push_back(pointer);
    }

    
}


void Map::getAllBorders() {

	MapRegion *pointer;
	for (int i = 0; i<num_vertices(g); i++) {
		if (g[i]->getIsBorder()) {
			pointer = g[i];
			borderRegions.push_back(pointer);
		}
	}
}

void Map::setBorders() {

	std::string inputted;
	for (int i = 0; i < num_vertices(g); i++) {
		inputted = bordersInputs.front();
		if (inputted == "0") {
			g[i]->setIsBorder(false);
		}
		else if(inputted == "1") {
			g[i]->setIsBorder(true);
		}
		else{
			std::cout << "Something is odd..." << std::endl;
		}
		bordersInputs.pop_front();
	}
}

void Map::setLostTribe() {

	std::string inputted;
	for (int i = 0; i < num_vertices(g); i++) {
		inputted = lostTribesInputs.front();
		if (inputted == "0") {
			g[i]->setLostTribeToken(NULL);
			g[i]->setTribe(false);
		}
		else if (inputted == "1") {
			LostTribeToken LostTribe = LostTribeToken();
			LostTribeToken* pointer = &LostTribe;
			g[i]->setLostTribeToken(pointer);
			g[i]->setTribe(true);
		}
		else {
			std::cout << "Something is odd..." << std::endl;
		}
		lostTribesInputs.pop_front();
	}

}

void Map::initialize(TokenWell *aWell) {
	well = aWell;
}

void Map::deleteMap() {

	for (size_t i = 0; i < borderRegions.size(); i++) {
		borderRegions[i] = NULL;
	}

	for (size_t i = 0; i < adgacentMapRegions.size(); i++) {
		adgacentMapRegions[i] = NULL;
	}

	adgacentMapRegions.resize(0);
	borderRegions.resize(0);

	g.clear();
	
}