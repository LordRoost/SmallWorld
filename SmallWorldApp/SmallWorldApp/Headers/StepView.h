#pragma once
#include "Observer.h"
#include "PlayGame.h"


class StepView : public Observer {
public:

	StepView(PlayGame* game);
	~StepView();
	void Update();
	void display();

private:
	PlayGame * _subject;
};
