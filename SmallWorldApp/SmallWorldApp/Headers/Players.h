#ifndef __PLAYERS_H__
#define __PLAYERS_H__
#pragma once

#include <iostream>
#include <list>
#include "Dice.h"
#include "Tokens.h"
#include "Game.h"
#include "MapRegion.h"

class Player {
public:	
	Player();
	~Player() {}

	DieRoller getDieRoller();
	PowerBadge* getPowerBadge();
	RaceToken* getToken();
	std::list<VictoryCoin> getVictoryCoin1s(); //change to vectors, they are better
	std::list<VictoryCoin> getOtherCoins();
	RaceBanner* getRacebanner();
	int getNbOfUsableTokens();
	std::vector<MapRegion> getOwnedRegions();

	void setPowerBadge(PowerBadge *badge);
	void setDieRoller(DieRoller *dice);
	void setRaceToken(RaceToken *tokens);
	void setRaceBanner(RaceBanner *banner);
	void setNbOfUsableTokens(int tokenAmount);
	
	void addOwnedRegion(MapRegion *region);
	void addVictoryCoin(VictoryCoin coins);
	void addVictoryCoin1s(VictoryCoin ones);

	void picks_race(RacePicker *picker);
	void conquers();
	//void scores(CoinBank *bank);

	//void isRegionOwned();
	void firstConquest();
	void attackTerritory(MapRegion *region);
	bool finalAttack(MapRegion *region);
	void redeploy();
	int calculateAttackThreshold(MapRegion *region);

	void calculateUsableTokens();
	void printAmountTokens();
	void printCurrentMoney();
	void printCurrentBanner();
	void printCurrentPower();

private:
	std::vector<MapRegion> *ownedRegions; 
	DieRoller *dice;
	PowerBadge *currentBadge;
	RaceToken *currentRace, declinedRace;
	std::list<VictoryCoin> ownedOtherCoins;
	std::list<VictoryCoin>  owned1s;
	RaceBanner *currentRaceBanner, declinedRaceBanner;
	int nbOfUseableTokens; //number of tokens of a race that the user has in hand
	//SummarySheet ownedSummarySheet;
};


#endif //__PLAYERS_H__