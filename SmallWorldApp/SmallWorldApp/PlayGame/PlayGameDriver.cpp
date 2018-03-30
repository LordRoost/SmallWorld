#include "../Headers/PlayGame.h"
//Map gameMap;

int main(){

//int GameDriver(){
	int input;
	

    PlayGame game1;
    
    
    
    game1.startGame();
    game1.firstTurn();
    game1.getTurnMarker().nextTurn();
    game1.followingTurns();
    
    cout<<"game ended"<<endl;

    
	//cin >> input; 
    return 0;
}

