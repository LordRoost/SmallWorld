//#include "../Headers/PlayGame.h"
#include "../Headers/DominationView.h"
#include "../Headers/StepView.h"
//Map gameMap;

DominationView;

int main(){

//int GameDriver(){
	

    PlayGame game1;
	
	StepView *sView = new StepView(&game1);

    game1.startGame();

	for (std::vector<int>::size_type i = 0; i < game1.players.size(); i++) {
		Player *pointer = game1.players[i];
		DominationView *dView = new DominationView(pointer, &game1);

	}

    game1.firstTurn();
    game1.followingTurns();
    
    cout<<"game ended"<<endl;

    
    return 0;
}

