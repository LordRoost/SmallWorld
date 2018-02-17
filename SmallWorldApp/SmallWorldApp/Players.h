#ifndef __PLAYERS_H__
#define __PLAYERS_H__
#pragma once

#include <iostream>
#include "Dice.h"
#include "Tokens.h"
#include "Game.h"

class Player {
public:	
	Player();
	~Player() {}

	DieRoller getDieRoller();
	PowerBadge* getPowerBadge();
	RaceToken* getToken();
	//VictoryCoin getVictoryCoin();
	RaceBanner* getRacebanner();
	int getNbOfUsableTokens();

	void setPowerBadge(PowerBadge *badge);
	void setDieRoller(DieRoller *dice);
	void setRaceToken(RaceToken *tokens);
	void setVictoryCoin(VictoryCoin coins);
	void setRaceBanner(RaceBanner *banner);
	void setNbOfUsableTokens(int tokenAmount);

	void picks_race(RacePicker *picker);
	void conquers();
	void scores();

	void calculateUsableTokens();
	void printAmountTokens();
	void printCurrentMoney();
	void printCurrentBanner();
	void printCurrentPower();

private:
	//MapRegion *ownedRegions[];
	DieRoller *dice;
	PowerBadge *currentBadge;
	RaceToken *currentRace, declinedRace;
	VictoryCoin *ownedCoins[3];
	RaceBanner *currentRaceBanner, declinedRaceBanner;
	int nbOfUseableTokens;
	//SummarySheet ownedSummarySheet;
};


#endif //__PLAYERS_H__