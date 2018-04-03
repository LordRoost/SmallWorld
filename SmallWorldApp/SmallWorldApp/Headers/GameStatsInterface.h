#pragma once

#include "Observer.h"
#include "PlayGame.h"


class GameStatsInterface : public Observer {
public:
	//GameStatsInterface();
	//GameStatsInterface(PlayGame* game);
	//~GameStatsInterface();
	virtual void Update() = 0;
	virtual void display() = 0;

};
