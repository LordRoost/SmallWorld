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
#define NUM_OF_1S 500 //temporary
#define TOTAL_NUM_COINS 109
#define NUM_OF_RACE_BANNERS 14
#define NUM_OF_POWERS 20
#define ALCHEMIST_NUM_COINS 2
#define WEALTHY_NUM_COINS 7 //number of coins given by wealthy special power
#define MAX_NUM_MOUNTAIN_TOKENS 10
#define MAX_NUM_FORTRESS_TOKENS 6
#define MAX_NUM_TROLL_LAIR_TOKENS 10
#define MAX_NUM_ENCAMPMENT_TOKENS 5
#define MAX_NUM_HOLES_IN_THE_GROUND_TOKENS 2
#define MAX_NUM_HEROES_TOKENS 2
#define MAX_NUM_DRAGON_TOKENS 1

enum races {
	RACE_AMAZONS, RACE_DWARVES, RACE_ELVES, RACE_GHOULS, RACE_GIANTS, RACE_HALFLINGS, RACE_HUMANS, 
	RACE_ORCS, RACE_RATMEN, RACE_SKELETONS, RACE_SORCERERS, RACE_TRITONS, RACE_TROLLS, RACE_WIZARDS, TOTAL_RACES, RACE_NONE 
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
    int aggressivePoint;
};


struct PowerInfo {
	powers power;
	std::string powerName;
	int amountTokensReceived;
    int aggressivePoint;
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

//coins with which to determind the winner of the game. Can also be spent during picking of races and powers
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

//the banner with the race that the user can choose
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
    int getAggressivePoint();

private:
	bool isActive;
	std::string name;
	int amountOfTokensReceived;
	races race;
    int aggressivePoint;
};

class RaceBannerDeck {
public:
	RaceBannerDeck();
	~RaceBannerDeck() {}
	void shuffle();
	void shuffleDiscard();
	void buildDeck();
	RaceBanner* draw();
	void discardBanner(RaceBanner *banner);
	void printDeck();
	void addBanner(RaceBanner *banner);

	std::deque<RaceBanner*> bannerDiscardPile;

private:
	RaceBanner *banners[NUM_OF_RACE_BANNERS]; //for initial array
	std::queue<RaceBanner*> deck;

};

//the badges with the powers that the player can choose
class PowerBadge {
public:
	PowerBadge() {}
	~PowerBadge() {}
	PowerBadge(powers power);
	powers getPower(); 
	void setPower(powers newPower);
	std::string getPowerName();
	void setPowerName(std::string newName);
	int getAmountTokensReceived();
	void setAmountTokensReceived(int tokens);
    int getAggressivePoint();

private:
	powers power;
	int amountTokensReceived;
	std::string powerName;
    int aggressivePoint;
};

class PowerBadgeDeck {
public:
	std::deque<PowerBadge*> badgeDiscardPile; //should later be made private
	PowerBadgeDeck();
	~PowerBadgeDeck() {}
	void shuffle();
	void shuffleDiscard();
	void buildDeck();
	PowerBadge* draw();
	void discardBadge(PowerBadge *powerBadge);
	void printDeck(); //prints the contents of the deck
	void addBadge(PowerBadge *badge);

private:
	PowerBadge *badges[NUM_OF_POWERS]; //for initial array
	std::queue<PowerBadge*> deck; //actual deck which the players draw from

};

//The pieces that go on teh map, such as mountains, dragons, structures, etc
class GamePiece {
public:
	GamePiece();
	~GamePiece() {}
	//mapRegion getLocation();
	//void setLocation(mapRegion location);

private:
	//mapRegion currentLocation;

};

class MountainPiece :public GamePiece {
public:
	MountainPiece();
				
};


class MoveablePiece: public GamePiece{ //encampment, hero, dragon
public:

private:

};



#endif //__TOKENS_H__
