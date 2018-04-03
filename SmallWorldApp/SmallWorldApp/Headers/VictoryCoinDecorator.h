#pragma once
#include "GameStatsDecorator.h"
#include "PlayGame.h"

class VictoryCoinDecorator : public GameStatsDecorator {
public:
	//VictoryCoinDecorator(GameStatsInterface *decoratedGameStats) : GameStatsDecorator(decoratedGameStats) {}
	VictoryCoinDecorator(GameStatsInterface *decoratedGameStats, PlayGame* game, Player* aPlayer) : GameStatsDecorator(decoratedGameStats) {
		_subject = aPlayer;
		_subject->Attach(this);
		theGame = game;
	}
	~VictoryCoinDecorator();
	void display();
	void Update();

private:
	Player * _subject;
	PlayGame *theGame;

};
