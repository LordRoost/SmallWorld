#pragma once

#include "Map.h"
#include "Players.h"

//static const string mapFilesPath="/Users/ericpayettereformed/Documents/Smallworld/MapFiles/";
static const string mapFilesPath = "C:/Users/luoja/Documents/Github/SmallWorld/MapFiles/";

class PlayGame {
public:
    Map getMap();
    string getMapFilesPath();
    void startGame();
    void setNumberOfPlayers();
    
private:
    Map map;
    vector<Player> players;
    
};
