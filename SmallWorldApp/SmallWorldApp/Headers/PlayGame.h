#ifndef __PLAYGAME_H__
#define __PLAYGAME_H__
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

class PlayGame : public Subject {
public:
	PlayGame();

    //Start game methods
	Map getMap();
    void startGame();
	void startGame(int nbPlayers); //same as startGame, but to be used if we dont want to take in user input and instead just start the game with nbPlayers of players.
    void setNumberOfPlayers();
	void setNumberOfPlayers(int nb); //see comment for void startGame(int nbPlayers); It is the same but instead for setNumberOfPlayers
    void addPiecesToWells(); //Create the various pieces into the well of tokens

	Player* getWinner(); 
	int getCurrentPlayerNb();
	std::string getCurrentPhase(); //returns the name of which step in the turn it current is (conquering, scoring, etc)
	int getCurrentTurn(); //returns the current turn number
	int getTotalTurns(); //returns the total number of turns
	TurnMarker* getTurnMarker();

	void setWinner(Player* aPlayer);
	void setCurrentPlayerNb(int nb);
	void setCurrentPhase(std::string phase);
	void setCurrentTurn();
	void setTotalTurns(int nbPlayers);

    //First turn methods
    void firstTurn(); //first turn for each player
    void followingTurns(); //every subsequent turn

	void decoratorPrompt(Player *player); //asks each user if they want to add decorators to the game.
	void deleteAll(); //deletes most elements of the game, freeing memory for the next game.
	void findWinner(); //returns the player with the most victory points

	std::vector<Player*> players; //vector of players. the size of the vector is the number of players there are.
    
private:

	RacePicker *decks; //The racebanner and powerbadge decks
	CoinBank* coinBank; //bank of coins
	TurnMarker* turnMarker; //marks which turn it is
	TokenWell* tokenWell; //where the tokens are initially placed
	Player* theWinner; //found at the end, the player with the most victory coins
	int currentPlayerNb;
	std::string currentPhase;
	int currentTurn;
	int totalTurns;
};

#endif // __PLAYGAME_H__