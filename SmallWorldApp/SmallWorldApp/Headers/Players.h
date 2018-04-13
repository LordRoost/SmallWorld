#ifndef __PLAYERS_H__
#define __PLAYERS_H__
#pragma once

#include <iostream>
#include <list>
#include "Dice.h"
#include "Subject.h"
#include "Tokens.h"
#include "Game.h"
#include "Map.h"
#include "PlayGame.h"
#include "AI.h"
#include "NoUnitAttackingException.h"

class Player : public Subject{
public:	
	Player();
    Player(AI *aiStrategy);
	~Player();

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

	void firstConquest(); //The first attack, where the player must attack a border region
	int attackTerritory(MapRegion *region); //the method that actually attacks a region
	bool finalAttack(MapRegion *region); //the last attack of a turn, it involves the dice. Gets called if the number of tokens a user has in hand is less than the number of tokens in the region they are attacking
	void redeploy(); //calls the deployment function
	void readyTroops(); //also calls the deployment function. Allows a user to leave 1 token in all of their regions and take the rest in hand.
	void abandonRegion(); //allows a user to remove all their tokens from a region and relinquish ownership of it
	int calculateAttackThreshold(MapRegion *region);
	void removeEnemyTokens(MapRegion *region);
	void removeOwnedRegion(MapRegion *region);
    void declineRace(RacePicker *picker);

	//various utility methods
	void placeAllTokensOnMap();//Places all tokens that users have in hand in one of their owned territories.
	void deployment(int nbOfTokens);
	void returnTokensToHand(int returnedTokens); 
	int calculateCurrentNbUsableTokens(int subtracted);
	void calculateUsableTokens();
	void findAllAdjacentTerritories();
	void printAmountTokens();
	void printCurrentMoney();
	void printCurrentBanner();
	void printCurrentPower();
	void sortMapregionVector(std::vector<MapRegion*>*); //sorts a vector of mapregions so that the display is in order
	double calculateOwnedPercentage(int nbPlayers); //gives the % of territory that the player owns

	MapRegion *choiceOfRegion;
	int occupiedRegionCounter;
	int nbScoredCoinsPower;
	bool statusDecorators;
	bool decoDominationCheck;
	bool decoCoinsCheck;

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
