#pragma once

#include "Map.h"
#include "Players.h"

static const string mapFilesPath="/Users/ericpayettereformed/Documents/Smallworld/MapFiles/";

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
