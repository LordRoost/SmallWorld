#pragma once
#include "GameStatsInterface.h"
#include <iostream>
#define NULL 0

using namespace std;

class GameStatsDecorator : public GameStatsInterface {
public:

	//GameStatsDecorator();
	GameStatsDecorator(GameStatsInterface *decoratedGameStats) {
		this->decoratedGameStats = decoratedGameStats;
	}

	~GameStatsDecorator() {
		//std::cout << "hiDeco" << std::endl;
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