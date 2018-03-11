#pragma once

#include "Map.h"
#include "Players.h"
//#include "Tokens.h"
#include "Game.h"
#include "TurnMarker.h"

static const string mapFilesPath="/Users/ericpayettereformed/Documents/Smallworld/MapFiles/";
//static const string mapFilesPath = "C:/Users/luoja/Documents/Github/SmallWorld/MapFiles/";

static int victoryPointBank=515;


class PlayGame {
public:
    //Start game methods
    Map getMap();
    string getMapFilesPath();
    void startGame();
    void setNumberOfPlayers();
    void addPiecesToWells();
    
    //First turn methods
    void turn();
    
    
private:
    //Map map;
    vector<Player> players;
	RacePicker *decks;
    //RaceBannerDeck raceBannerDeck;
    //PowerBadgeDeck powerBadgeDeck;
	CoinBank coinBank;
	TurnMarker turnMarker;
    
    
};
