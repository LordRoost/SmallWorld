#pragma once
#include <iostream>
#define MAX_AMOUNT_DICE 3

class Dice {

private:
	int dieSides = 6;
	int *dieFaces;

public:

	Dice() {};

	Dice(int nbOfFaces);

	int roll();
};
