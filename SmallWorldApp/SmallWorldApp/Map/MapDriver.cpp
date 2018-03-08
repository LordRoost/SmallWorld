#include <stdio.h>
#include "../Headers/Map.h"
#include <boost/graph/graphviz.hpp>

using namespace std;


int mainwe() {

	Map m;

	m.loadMap("/Users/ericpayettereformed/Documents/Smallworld/Smallworld/MapFiles/map.txt");

	cout << "V___________________" << endl;

	m.graphIsConnected();



	return 0;
}
