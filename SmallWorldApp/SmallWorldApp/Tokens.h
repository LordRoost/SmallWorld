#pragma once
#ifndef __TOKENS_H__
#define __TOKENS_H__

#include <queue>
#include <iostream>
#include <algorithm>
#define NUM_OF_10S 30
#define NUM_OF_5S 24
#define NUM_OF_3S 20
#define NUM_OF_1S 35
#define TOTAL_NUM_COINS 109
#define NUM_OF_RACE_BANNERS 14

enum races {
	RACE_AMAZONS, RACE_DWARVES, RACE_ELVES, RACE_GHOULS, RACE_GIANTS, RACE_HALFLINGS, RACE_HUMANS, 
	RACE_ORCS, RACE_RATMEN, RACE_SKELETONS, RACE_SORCERERS, RACE_TRITONS, RACE_TROLLS, RACE_WIZARDS, TOTAL_RACES //RACE_LOST_TRIBES
};

struct RaceInfo {
	races race;
	int amountTokensReceived;
	int totalAmount;
	//power still needed to be added
};

RaceInfo raceInfo[TOTAL_RACES] = {{ RACE_AMAZONS, 6, 15 },{ RACE_DWARVES, 3, 8 },{ RACE_ELVES, 6, 11 },{ RACE_GHOULS, 5, 10 },{ RACE_GIANTS, 6, 11 },{ RACE_HALFLINGS, 6, 11 },
{ RACE_HUMANS, 5, 10 },{ RACE_ORCS, 5, 10 },{ RACE_RATMEN, 8, 13 } ,{ RACE_SKELETONS, 6, 20 } ,{ RACE_SORCERERS, 5, 18 } ,{ RACE_TRITONS, 6, 11 } ,{ RACE_TROLLS, 5, 10 } ,{ RACE_WIZARDS, 5, 10 } };

class Token {
public:
	Token();
	~Token() {};

private:
	unsigned int maxAmount;
};

class RaceToken : public Token {
public:

private:
	races race;
};

class LostTribeToken : public Token {
public:

private:

};

class VictoryCoin {
public:
	VictoryCoin(int coinValue);
	~VictoryCoin() {};
	void printValue();
	int getValue();
	void setValue(int nb);

private:
	int value;
};


class RaceBanner {
public:
	RaceBanner();
	RaceBanner(races race);
	~RaceBanner() {};
	bool getStatus(); //active or not
	void setStatus(bool status);
	races getRace();
	void setRace(races race);
	void decline();

private:
	bool isActive;
	int amountOfTokensReceived;
	races race;
};

class RaceBannerDeck {
public:
	RaceBannerDeck();
	~RaceBannerDeck() {};
	void shuffle();
	void buildDeck();
	RaceBanner draw();
	void putBannerBack(RaceBanner banner);

private:
	RaceBanner *banners[NUM_OF_RACE_BANNERS]; //for initial array
	std::queue<RaceBanner> deck;

};

//class RacePower {
//public:
//	RacePower(races race);
//	~RacePower() {};
//};

class PowerBadge {

};

class GamePiece {

};

#endif //__TOKENS_H__