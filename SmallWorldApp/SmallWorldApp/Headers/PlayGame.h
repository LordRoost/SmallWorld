#pragma once
#define BOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE //this is just to not have the boost outdated message everytime code is run

#include "Map.h"
#include "Players.h"
#include "Game.h"
#include "TurnMarker.h"
#include "Subject.h"
#include "GameStats.h"
#include "UserInputException.h"

//static const string mapFilesPath="/Users/ericpayettereformed/Documents/Smallworld/MapFiles/";
static const std::string mapFilesPath = "C:/Users/luoja/Documents/Github/SmallWorld/MapFiles/";

static int victoryPointBank=515;



class PlayGame : public Subject {
public:
	PlayGame();

    //Start game methods
	Map getMap();
    void startGame();
	void startGame(int nbPlayers);
    void setNumberOfPlayers();
	void setNumberOfPlayers(int nb);
    void addPiecesToWells();


	Player* getWinner();
	int getCurrentPlayerNb();
	std::string getCurrentPhase();
	int getCurrentTurn();
	int getTotalTurns();
	TurnMarker* getTurnMarker();

	void setWinner(Player* aPlayer);
	void setCurrentPlayerNb(int nb);
	void setCurrentPhase(std::string phase);
	void setCurrentTurn();
	void setTotalTurns(int nbPlayers);

    //First turn methods
    void firstTurn();
    void followingTurns();

	void decoratorPrompt(Player *player);
	void deleteAll();
	void findWinner();


	std::vector<Player*> players;

    
private:

	RacePicker *decks;
	CoinBank* coinBank;
	TurnMarker* turnMarker;
	TokenWell* tokenWell;
	Player* theWinner;
	int currentPlayerNb;
	std::string currentPhase;
	int currentTurn;
	int totalTurns;
};
