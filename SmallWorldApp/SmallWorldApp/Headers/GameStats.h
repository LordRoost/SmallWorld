#pragma once
#include "GameStatsInterface.h"
//#include "PlayGame.h"

class GameStats : public GameStatsInterface {
public:

	GameStats(PlayGame *game);

	~GameStats();

	void Update();

	void display();

protected:
	PlayGame * _subject;
};