#pragma once
#include "Observer.h"
#include "PlayGame.h"
#include "Players.h"


class DominationView : public Observer{
public:

	DominationView(Player* player, PlayGame *game);
	~DominationView();
	void Update();
	void barDisplay(int nb);
	void display();


private:
	Player * _subjectPlayer;

	PlayGame *theGame;
};
