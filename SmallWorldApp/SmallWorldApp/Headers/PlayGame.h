#pragma once

#include "Map.h"

static const string mapFilesPath="/Users/ericpayettereformed/Documents/Smallworld/MapFiles/";

class PlayGame {
public:
    Map getMap();
    string getMapFilesPath();
    void startGame();
    
private:
    Map map;
    
};
