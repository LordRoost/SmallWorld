#pragma once
#include <iostream>

#include "Observer.h"
//#include "PlayGame.h"


class GameStatsInterface : public Observer {
public:
	//GameStatsInterface();
	//GameStatsInterface(PlayGame* game);
	~GameStatsInterface() {
		//std::cout << "hiInter" << std::endl;
	}

	virtual void Update() = 0;
	virtual void display() = 0;

};
