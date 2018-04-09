#ifndef __GAMESTATS_H__
#define __GAMESTATS_H__
#pragma once
#include "GameStatsInterface.h"
//#include "PlayGame.h"

class PlayGame;

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