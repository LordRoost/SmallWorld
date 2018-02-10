#include <random>
#include "Dice.h"

//using namespace std;

int main(int argc, char*[]) {

	//Dice *pDice[MAX_AMOUNT_DICE];
	Dice *pDice;
	int input;
	int i = 0;

	pDice = new Dice();

	for (i; i < 100; i++)
	{
		std::cout << pDice->roll() << std::endl;
	}

	std::cin >> input;
	return 0;
};