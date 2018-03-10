#pragma once

#include "Map.h"
#include "Players.h"
#include "Tokens.h"

static const string mapFilesPath="/Users/ericpayettereformed/Documents/Smallworld/MapFiles/";
static int victoryPointBank=515;


class PlayGame {
public:
    Map getMap();
    string getMapFilesPath();
    void startGame();
    void setNumberOfPlayers();
    void addPiecesToWells();
    
private:
    Map map;
    vector<Player> players;
    RaceBannerDeck raceBannerDeck;
    PowerBadgeDeck powerBadgeDeck;
    
    
};
