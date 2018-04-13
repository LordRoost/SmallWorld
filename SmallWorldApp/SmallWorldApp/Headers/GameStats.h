#ifndef __GAMESTATS_H__
#define __GAMESTATS_H__
#pragma once
#include "GameStatsInterface.h"

class PlayGame;

//Concrete simple implementation of GameStatsInterface, it is the base which will get decorated.
class GameStats : public GameStatsInterface {
public:

	GameStats(PlayGame *game);

	~GameStats();

	void Update();

	void display();

protected:
	PlayGame * _subject;
};

#endif //__GAMESTATS_H__