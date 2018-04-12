#include "../Headers/PlayGame.h"

int main(){	

    PlayGame tournament2Players, tournament3Players, tournament4Players, tournament5Players;
	int stall;

	tournament2Players.startGame(2);
	tournament2Players.firstTurn();
	tournament2Players.followingTurns();
	tournament2Players.findWinner();

	tournament2Players.deleteAll();
	std::cout << "\n---------------------------- 2 player tournament ended ----------------------------\n" << std::endl;

	tournament3Players.startGame(3);
	tournament3Players.firstTurn();
	tournament3Players.followingTurns();
	tournament3Players.findWinner();

	tournament3Players.deleteAll();
	std::cout << "\n---------------------------- 3 player tournament ended ----------------------------\n" << std::endl;

	tournament4Players.startGame(4);
	tournament4Players.firstTurn();
	tournament4Players.followingTurns();
	tournament4Players.findWinner();

	tournament4Players.deleteAll();
	std::cout << "\n---------------------------- 4 player tournament ended ----------------------------\n" << std::endl;

	tournament5Players.startGame(5);
	tournament5Players.firstTurn();
	tournament5Players.followingTurns();
	tournament5Players.findWinner();

	tournament5Players.deleteAll();
	std::cout << "\n---------------------------- 5 player tournament ended ----------------------------\n" << std::endl;

	std::cin >> stall;
    return 0;
}

