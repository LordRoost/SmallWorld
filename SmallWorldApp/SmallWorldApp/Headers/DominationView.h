#pragma once
#include "Observer.h"
#include "PlayGame.h"
#include "Players.h"


class DominationView : public Observer{
public:

	//DominationView();
	DominationView(Player* player, PlayGame *game);
	~DominationView();
	void Update();
	void display();


private:
	Player * _subjectPlayer;

	PlayGame *theGame;
};
