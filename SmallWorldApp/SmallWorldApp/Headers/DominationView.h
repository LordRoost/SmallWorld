#pragma once
#include "Observer.h"
#include "PlayGame.h"
#include "Players.h"
#include "GamesStatisticsDecorator.h"

class DominationView : public GameStatistics,public Observer{
public:

	//DominationView();
    DominationView(Player* player, PlayGame *game, GameStatistics* g);
	~DominationView();
	void Update();
	void display();


private:
	Player * _subjectPlayer;
    GameStatistics* g;
	PlayGame *theGame;
};
