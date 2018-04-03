#pragma once
#include "GameStatsInterface.h"

class GameStatsDecorator : public GameStatsInterface {
public:

	//GameStatsDecorator();
	GameStatsDecorator(GameStatsInterface *decoratedGameStats) {
		this->decoratedGameStats = decoratedGameStats;
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