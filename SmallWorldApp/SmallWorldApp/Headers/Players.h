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

class Player {
public:	
	Player();
	~Player() {}

	//getters
	DieRoller getDieRoller();
	PowerBadge* getPowerBadge();
	RaceToken getToken();
	std::list<VictoryCoin> getVictoryCoin1s(); 
	std::list<VictoryCoin> getOtherCoins();
	RaceBanner* getRacebanner();
	int getNbOfUsableTokens();
	std::vector<MapRegion*> getOwnedRegions();
	int getRedeployableTokens();
	bool getIfClaimedWealthy();

	//setters
	void setPowerBadge(PowerBadge *badge);
	void setDieRoller(DieRoller *dice);
	void setRaceToken(RaceToken tokens);
	void setRaceBanner(RaceBanner *banner);
	void setNbOfUsableTokens(int tokenAmount);
	void setRedeployableTokens(int amount);
	void setIfClaimedWealthy(bool claim);
	
	void addOwnedRegion(MapRegion *region);
	void addVictoryCoin(VictoryCoin coins);
	void addVictoryCoin1s(VictoryCoin ones);

	//3 main methods
	void picks_race(RacePicker *picker); //allows player to choose a racebanner and a powerbadge from the choice of 6
	void conquers(); //allows a player to conquer regions until they do not have any tokens in hand
	void scores(CoinBank *bank); //allows a player to get points for their turn

	//helper methods for conquers
	void firstConquest(); //the first conquest, when one must attack a border region
	void attackTerritory(MapRegion *region); //actually capturing a region
	bool finalAttack(MapRegion *region); //the attack in which a player must roll a dice because they do not have enough tokens in hand for a normal attack
	void redeploy(); //redeploy phase, after conquest, when the player moves their tokens around their owned regions
	int calculateAttackThreshold(MapRegion *region); //method to determine how many tokens a player needs to conquer a region
	void removeEnemyTokens(MapRegion *region); //method that cleans up the area, removing the former owner and their pieces

	//various utility methods
	void returnTokensToHand(int returnedTokens); //
	int calculateCurrentNbUsableTokens(int subtracted);
	void calculateUsableTokens();
	//void calculateUsableTokens(PowerBadge power, RaceBanner banner);
	void printAmountTokens();
	void printCurrentMoney();
	void printCurrentBanner();
	void printCurrentPower();

	MapRegion *choiceOfRegion;
	int occupiedRegionCounter;

private:
	std::vector<MapRegion*> ownedRegions;
	DieRoller *dice;
	PowerBadge *currentBadge;
	RaceToken currentRace, declinedRace;
	std::list<VictoryCoin> ownedOtherCoins;
	std::list<VictoryCoin> owned1s;
	RaceBanner *currentRaceBanner, *declinedRaceBanner;
	int nbOfUseableTokens; //number of tokens of a race that the user has in hand
	bool lastAttack;
	int redeployableTokens;
	bool wealthyClaimed;
};


#endif //__PLAYERS_H__