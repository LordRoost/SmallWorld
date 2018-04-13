#pragma once
#include "GameStatsInterface.h"
#include <iostream>

//basic decorator, used for decorating GameStats
class GameStatsDecorator : public GameStatsInterface {
public:

	GameStatsDecorator(GameStatsInterface *decoratedGameStats) {
		this->decoratedGameStats = decoratedGameStats;
	}

	~GameStatsDecorator() {
		if (decoratedGameStats != NULL) {
			delete(decoratedGameStats);
			decoratedGameStats = NULL;
		}
	}

	void Update() {
		return decoratedGameStats->Update();
	}

	void display() {
		return decoratedGameStats->display();
	}

protected:
	GameStatsInterface * decoratedGameStats;
};