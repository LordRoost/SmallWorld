#pragma once
#include "GameStatsDecorator.h"
#include "PlayGame.h"

class DominationDecorator : public GameStatsDecorator {
public:
	DominationDecorator(GameStatsInterface *decoratedGameStats, PlayGame* game, Player *aPlayer) : GameStatsDecorator(decoratedGameStats) {
		_subject = aPlayer;
		_subject->Attach(this);
		theGame = game;
	}
	~DominationDecorator();
	void display();
	void Update();

	void barDisplay(int nb); 

private:
	Player * _subject; //the observable
	PlayGame * theGame;
};
