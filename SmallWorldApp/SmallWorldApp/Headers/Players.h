#ifndef __PLAYERS_H__
#define __PLAYERS_H__
#pragma once

#include <iostream>
#include <list>
#include "Dice.h"
#include "Tokens.h"
#include "Game.h"
#include "Map.h"
#include "PlayGame.h"
#include "AI.h"

class Player {
public:	
	Player();
    Player(AI *aiStrategy);
	~Player() {}

	//getters
	DieRoller getDieRoller();
	PowerBadge* getPowerBadge();
	RaceToken getRaceToken();
	races getCurrentRace();
	races getDeclinedRace();
	races getPreviouslyDeclinedRace();
	std::list<VictoryCoin> getVictoryCoin1s(); 
	std::list<VictoryCoin> getOtherCoins();
	RaceBanner* getRacebanner();
	int getNbOfUsableTokens();
	std::vector<MapRegion*> getOwnedRegions();
	std::vector<MapRegion*> getAttackableRegions();
	int getRedeployableTokens();
	bool getIfClaimedWealthy();
	bool getInDecline();
    AI *getAIStrategy();

	//setters
	void setPowerBadge(PowerBadge *badge);
	void setDieRoller(DieRoller *dice);
	void setRaceToken(RaceToken tokens);
	void setCurrentRace(races race);
	void setDeclinedRace(races race);
	void setPreviouslyDeclinedRace(races race);
	void setRaceBanner(RaceBanner *banner);
	void setNbOfUsableTokens(int tokenAmount);
	void setRedeployableTokens(int amount);
	void setIfClaimedWealthy(bool claim);
    void setInDecline(bool InDecline);

	
	void addOwnedRegion(MapRegion *region);
	void addAttackableRegion(MapRegion *region);
	void addVictoryCoin(VictoryCoin coins);
	void addVictoryCoin1s(VictoryCoin ones);

	//3 main methods
	void picks_race(RacePicker *picker); //allows player to choose a racebanner and a powerbadge from the choice of 6
	void conquers(); //allows a player to conquer regions until they do not have any tokens in hand
	void scores(CoinBank *bank); //allows a player to get points for their turn

	void firstConquest();
	int attackTerritory(MapRegion *region);
	bool finalAttack(MapRegion *region);
	void redeploy();
	void readyTroops();
	int calculateAttackThreshold(MapRegion *region);
	void removeEnemyTokens(MapRegion *region);
	void removeOwnedRegion(MapRegion *region);
    void declineRace();

	//various utility methods
	void placeAllTokensOnMap();//Places all tokens that users have in hand in one of their owned territories.
	void deployment(int nbOfTokens);
	void returnTokensToHand(int returnedTokens); 
	int calculateCurrentNbUsableTokens(int subtracted);
	void calculateUsableTokens();
	void findAllAdjacentTerritories();
	//void calculateUsableTokens(PowerBadge power, RaceBanner banner);
	void printAmountTokens();
	void printCurrentMoney();
	void printCurrentBanner();
	void printCurrentPower();
	void sortMapregionVector(std::vector<MapRegion*>*); //sorts a vector of mapregions so that the display is in order

	MapRegion *choiceOfRegion;
	int occupiedRegionCounter;

private:
	std::vector<MapRegion*> ownedRegions;
	std::vector<MapRegion*> attackableRegions;
	DieRoller *dice;
	PowerBadge *currentBadge;
	RaceToken currentRaceToken, declinedRaceToken, previousDeclinedRaceToken;
	races currentRace, declinedRace, previousDeclinedRace;
	std::list<VictoryCoin> ownedOtherCoins;
	std::list<VictoryCoin> owned1s;
	RaceBanner *currentRaceBanner, *declinedRaceBanner;
	int nbOfUseableTokens; //number of tokens of a race that the user has in hand
	bool lastAttack;
    int redeployableTokens;
    bool wealthyClaimed;
    bool inDecline;
    AI *aiStrategy;
};

#endif //__PLAYERS_H__
