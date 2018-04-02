#pragma once
#include "Observer.h"
#include "PlayGame.h"
#include "GamesStatisticsDecorator.h"


class StepView : public GameStatistics, public Observer {
public:

	StepView(PlayGame* game);
	~StepView();
	void Update();
	void display();

private:
	PlayGame * _subject;
    GameStatistics* g;
};
