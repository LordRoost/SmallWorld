#include "../Headers/PlayGame.h"

int main(){	

    PlayGame game1;
	int stall;
	

    game1.startGame();


    game1.firstTurn();
    game1.followingTurns();
	game1.findWinner();

	game1.deleteAll();
    std::cout<<"game ended"<<std::endl;

	std::cin >> stall;
    return 0;
}

