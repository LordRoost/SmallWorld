#pragma once
#define BOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE //this is just to not have the boost outdated message everytime code is run

#include "Map.h"
#include "Players.h"
//#include "Tokens.h"
#include "Game.h"
#include "TurnMarker.h"
#include "Subject.h"
//#include "Observer.h"
//#include "DominationView.h"

//static const string mapFilesPath="/Users/ericpayettereformed/Documents/Smallworld/MapFiles/";
static const string mapFilesPath = "C:/Users/luoja/Documents/Github/SmallWorld/MapFiles/";

static int victoryPointBank=515;



class PlayGame : public Subject{// : public Observer{
public:
    TurnMarker* getTurnMarker();
    
    //Start game methods
    Map getMap();
    string getMapFilesPath();
    void startGame();
    void setNumberOfPlayers();
    void addPiecesToWells();
	//void addMountainPieces(MountainPiece piece);
	//MountainPiece dealMountain();
    
    //First turn methods
    void firstTurn();
    void followingTurns();
    
	vector<Player*> players;
	//vector<DominationView*> views;
    
private:
    //Map map;
    //vector<Player> players;
	RacePicker *decks;
    //RaceBannerDeck raceBannerDeck;
    //PowerBadgeDeck powerBadgeDeck;
	CoinBank coinBank;
	TurnMarker* turnMarker;
	TokenWell tokenWell;
	//vector<MountainPiece> mountainPieces;
    
    
};
