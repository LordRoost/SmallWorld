#pragma once
#include <iostream>
#define NUM_OF_10S 30
#define NUM_OF_5S 24
#define NUM_OF_3S 20
#define NUM_OF_1S 35
#define TOTAL_NUM_COINS 109
#define NUM_OF_RACE_BANNERS 14

enum races {
	RACE_AMAZONS, RACE_DWARVES, RACE_ELVES, RACE_GHOULS, RACE_RATMEN, RACE_SKELETONS, RACE_SORCERERS, RACE_TRITONS,
	RACE_GIANTS, RACE_HALFLINGS, RACE_HUMANS, RACE_ORCS, RACE_TROLLS, RACE_WIZARDS, TOTAL_RACES //RACE_LOST_TRIBES
};

class Token {
public:
	Token(races race);
	~Token() {};

private:
	races race;
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
	bool getStatus();
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

private:
	RaceBanner deckOfBanners[NUM_OF_RACE_BANNERS];
	std::

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

