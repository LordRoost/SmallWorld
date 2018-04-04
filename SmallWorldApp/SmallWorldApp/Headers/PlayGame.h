#pragma once
#define BOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE //this is just to not have the boost outdated message everytime code is run

#include "Map.h"
#include "Players.h"
//#include "Tokens.h"
#include "Game.h"
#include "TurnMarker.h"
#include "Subject.h"
#include "GameStats.h"
//#include "GameStatsInterface.h"
//#include "DominationView.h"
//#include "DominationDecorator.h"
//#include "VictoryCoinDecorator.h"

//static const string mapFilesPath="/Users/ericpayettereformed/Documents/Smallworld/MapFiles/";
static const std::string mapFilesPath = "C:/Users/luoja/Documents/Github/SmallWorld/MapFiles/";

static int victoryPointBank=515;



class PlayGame : public Subject {
public:
    TurnMarker* getTurnMarker();
    
    //Start game methods
    Map getMap();
    std::string getMapFilesPath();
    void startGame();
    void setNumberOfPlayers();
    void addPiecesToWells();


	//Player* getCurrentPlayer();
	int getCurrentPlayerNb();
	std::string getCurrentPhase();
	int getCurrentTurn();

	//void setCurrentPlayer(Player* person);
	void setCurrentPlayerNb(int nb);
	void setCurrentPhase(std::string phase);
	void setCurrentTurn();

    //First turn methods
    void firstTurn();
    void followingTurns();

	void decoratorPrompt(Player *player);

	std::vector<Player*> players;
	//GameStatsInterface *gs;

    
private:

    //Map map;
    //vector<Player> players;
	RacePicker *decks;
	CoinBank coinBank;
	TurnMarker* turnMarker;
	TokenWell tokenWell;

	//Player *currentPlayer;
	int currentPlayerNb;
	std::string currentPhase;
	int currentTurn;
	//bool statusDecorators = true;
    
    
};
