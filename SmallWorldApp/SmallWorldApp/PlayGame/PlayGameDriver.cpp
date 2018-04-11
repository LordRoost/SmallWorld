#include "../Headers/PlayGame.h"

int main(){	

    PlayGame game1;
	int word;
	

    game1.startGame();


    game1.firstTurn();
    game1.followingTurns();
    
    std::cout<<"game ended"<<std::endl;

	std::cin >> word;
    return 0;
}

