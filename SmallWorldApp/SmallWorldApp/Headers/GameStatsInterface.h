#pragma once
#include <iostream>

#include "Observer.h"

//Interface for decorators
class GameStatsInterface : public Observer {
public:
	~GameStatsInterface() {}

	virtual void Update() = 0;
	virtual void display() = 0;

};
