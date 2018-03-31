#include "../Headers/PlayGame.h"
#include "../Headers/DominationView.h"
//Map gameMap;

int main(){

//int GameDriver(){
	int input;
	

    PlayGame game1;
        
    game1.startGame();

	for (std::vector<int>::size_type i = 0; i < game1.players.size(); i++) {
		Player *pointer = game1.players[i];
		DominationView *dView = new DominationView(pointer);

	}
    game1.firstTurn();
    game1.getTurnMarker()->nextTurn();
    game1.followingTurns();
    
    cout<<"game ended"<<endl;

    
	//cin >> input; 
    return 0;
}

