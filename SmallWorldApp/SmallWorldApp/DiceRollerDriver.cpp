#include "Dice.h"


//int main(int argc, char*[]) {

int DiceRollerDriver() {

	DieRoller *roller;

	char answer;


	std::cout << "Hello welcome to the dice driver!" << std::endl;

	roller = new DieRoller();

	while (true) {

		std::cout << "Do you want to roll a die? (Y/N) or quit (Q) (press R to roll 100 times and press P to print the distribution)" << std::endl;
		std::cin >> answer;
		if (answer == 'Y') {
			roller->rollDice();
		}
		else if (answer == 'N') {
			std::cout << "You don't want to? Bye!" << std::endl;
		}
		else if (answer == 'P') {
			std::cout << "Here it is: " << std::endl;
			roller->printDistribution();
		}
		else if (answer == 'R') {
			std::cout << "Rolling 100 " << std::endl;
			for (int i = 0; i < 100; i++)
			{
				roller->rollDice();
			}
		}
		else if (answer == 'Q') {
			std::cout << "Bye!" << std::endl;
			break;
		}
		else {
			std::cout << "Please enter an appropriate command!" << std::endl;
		}
	}

	delete roller;

	return 0;
};