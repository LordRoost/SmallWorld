#ifndef __PLAYERS_H__
#define __PLAYERS_H__
#pragma once

#include <iostream>
#include "Dice.h"
#include "Tokens.h"

class Player {
public:	
	Player();
	~Player() {}

	DieRoller getDieRoller();
	PowerBadge getBadge();
	RaceToken getToken();
	VictoryCoin getVictoryCoin();
	RaceBanner getRacebanner();

	void setBadge(PowerBadge badge);
	void setDieRoller(DieRoller dice);
	void setRaceToken(RaceToken tokens);
	void setVictoryCoin(VictoryCoin coins);
	void setRaceBanner(RaceBanner banner);

	void picks_race();
	void conquers();
	void scores();

private:
	//MapRegion ownedRegions;
	DieRoller dice;
	PowerBadge currentBadge;
	RaceToken currentRace;
	VictoryCoin ownedCoins;
	RaceBanner currentBanner;
	//SummarySheet ownedSummarySheet;
};


#endif //__PLAYERS_H__