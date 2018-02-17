#ifndef __TOKENS_H__
#define __TOKENS_H__
#pragma once

#include <queue>
#include <iostream>
#include <string>
#include <algorithm>
#define NUM_OF_10S 30
#define NUM_OF_5S 24
#define NUM_OF_3S 20
#define NUM_OF_1S 35
#define TOTAL_NUM_COINS 109
#define NUM_OF_RACE_BANNERS 14
#define NUM_OF_POWERS 20

enum races {
	RACE_AMAZONS, RACE_DWARVES, RACE_ELVES, RACE_GHOULS, RACE_GIANTS, RACE_HALFLINGS, RACE_HUMANS, 
	RACE_ORCS, RACE_RATMEN, RACE_SKELETONS, RACE_SORCERERS, RACE_TRITONS, RACE_TROLLS, RACE_WIZARDS, TOTAL_RACES //RACE_LOST_TRIBES
};

enum powers {
	POWER_ALCHEMIST, POWER_BERSERK, POWER_BIVOUACKING, POWER_COMMANDO, POWER_DIPLOMAT, POWER_DRAGON_MASTER, POWER_FLYING, POWER_FOREST, POWER_FORTIFIED, POWER_HEROIC, 
	POWER_HILL, POWER_MERCHANT, POWER_MOUNTED, POWER_PILLAGING, POWER_SEAFARING, POWER_SPIRIT, POWER_STOUT, POWER_SWAMP, POWER_UNDERWORLD, POWER_WEALTHY, TOTAL_POWERS
};

struct RaceInfo {
	races race;
	std::string raceName;
	int amountTokensReceived;
	int totalAmount;
	//power still needed to be added
};


struct PowerInfo {
	powers power;
	std::string powerName;
	int amountTokensReceived;
	//special ability still needed to be added
};

class Token {
public:
	Token();
	Token(int maxAmount);
	~Token() {}
	int getMaxAmount();
	void setMaxAmount(int amount);

private:
	int maxAmount;
};

class RaceToken : public Token {
public:
	RaceToken() {}
	RaceToken(races race);
	bool getStatus(); //active or not
	void setStatus(bool status);
	races getRace();
	void setRace(races race);
	void decline();

private:
	races race;
	//Player owner;
	bool isActive;

};

class LostTribeToken : public Token {
public:
	LostTribeToken();

private:
};

class VictoryCoin {
public:
	VictoryCoin() {}
	VictoryCoin(int coinValue);
	~VictoryCoin() {}
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
	std::string getName();
	void setName(std::string newName);
	int getAmountTokensReceived();
	void setAmountTokensReceived(int tokens);
	void decline();

private:
	bool isActive;
	std::string name;
	int amountOfTokensReceived;
	races race;
};

class RaceBannerDeck {
public:
	RaceBannerDeck();
	~RaceBannerDeck() {}
	void shuffle();
	void buildDeck();
	RaceBanner* draw();
	void putBannerBack(RaceBanner *banner);
	void printDeck();

private:
	RaceBanner *banners[NUM_OF_RACE_BANNERS]; //for initial array
	std::queue<RaceBanner*> deck;

};

class PowerBadge {
public:
	PowerBadge() {}
	PowerBadge(powers power);
	powers getPower(); 
	void setPower(powers newPower);
	std::string getPowerName();
	void setPowerName(std::string newName);
	int getAmountTokensReceived();
	void setAmountTokensReceived(int tokens);

private:
	powers power;
	int amountTokensReceived;
	std::string powerName;
};

class PowerBadgeDeck {
public:
	std::vector<PowerBadge> discardPile; //should later be made private
	PowerBadgeDeck();
	~PowerBadgeDeck() {}
	void shuffle();
	void buildDeck();
	PowerBadge* draw();
	void discardBadge(PowerBadge *powerBadge);
	void printDeck();

private:
	PowerBadge *badges[NUM_OF_POWERS]; //for initial array
	std::queue<PowerBadge*> deck;

};

class GamePiece {
public:
	GamePiece();
	~GamePiece() {}
	//mapRegion getLocation();
	//void setLocation(mapRegion location);

private:
	//mapRegion currentLocation;

};

class MoveablePiece: public GamePiece{ //encampment, hero, dragon
public:

private:

};



#endif //__TOKENS_H__