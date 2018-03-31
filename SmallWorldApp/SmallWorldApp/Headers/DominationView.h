#pragma once
#include "Observer.h"
#include "PlayGame.h"
#include "Players.h"

/*Using the Observer design pattern, implement a view that displays some useful statistics about the game, 
the minimum being a “players SmallWorld domination view” that shows using some kind of bar graph depicting
what percentage of the world is currently being controlled by each player. This should dynamically be updated 
as the map state changes and be visible at all times during game play.*/

class DominationView : public Observer{
public:
	//DominationView();
	DominationView(PlayGame* game);
	DominationView(Player* player);
	~DominationView();
	void Update();
	void display();

private:
	PlayGame * _subjectGame;
	Player * _subjectPlayer;
};
