#ifndef __GAME_H__
#define __GAME_H__
#pragma once

#include "Tokens.h"
#define MAX_NUMBER_PICKABLE_RACES 6
#define MAX_NUMBER_PICKABLE_POWERS 6
#define BOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE //this is just to not have the boost outdated message everytime code is run

class Player;

class RacePicker {
public:
	RacePicker();
	void setup();
	RaceBanner* getPickableRaces();
	PowerBadge* getPickablePowers();
    std::vector<RaceBanner*>getAllPickableRaces();
    std::vector<PowerBadge*> getAllPickablePowers();
	RaceBanner* getPickableRaces(int index);
	PowerBadge* getPickablePowers(int index);
	void printOptions();
	void replaceChoices(int index);
	int calculateTotalTokens(int index);
	void discardDeclined(RaceBanner *discardedBanner, PowerBadge *discardedBadge);

private:
	RaceBannerDeck *bannerDeck;
	PowerBadgeDeck *powerDeck;
	RaceBanner *pickableRaces[MAX_NUMBER_PICKABLE_RACES];
	PowerBadge *pickablePowers[MAX_NUMBER_PICKABLE_POWERS];
};

class CoinBank {
public:
	CoinBank();
	void deal1s(Player *aPlayer, int amount);
	int getAmount1s();
	int getAmount3s();
	int getAmount5s();
	int getAmount10s();
	void startingDeal(Player *aPlayer);

	void printContents();

	std::vector <VictoryCoin> get1s();
	std::vector <VictoryCoin> get3s();
	std::vector <VictoryCoin> get5s();
	std::vector <VictoryCoin> get10s();

private:
	std::vector <VictoryCoin> coinValue1;
	std::vector <VictoryCoin> coinValue3;
	std::vector <VictoryCoin> coinValue5;
	std::vector <VictoryCoin> coinValue10;
};

class TokenWell {
public:
	TokenWell();
	std::vector<MountainPiece*> getMountainPieces();
	void addMountainPieces(MountainPiece *piece);
	MountainPiece* dealMountain();

private:
	std::vector<MountainPiece*> mountainPieces;
};

#endif //__GAME_H__