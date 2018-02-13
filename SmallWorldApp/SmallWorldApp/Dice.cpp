#include "Dice.h"

//Initialize the die with the values on each face
Dice::Dice() {

	dieFaceValues[0] = 0;
	dieFaceValues[1] = 0;
	dieFaceValues[2] = 0;
	dieFaceValues[3] = 1;
	dieFaceValues[4] = 2;
	dieFaceValues[5] = 3;

}


int Dice::roll() {

	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(0, 5);
	return dieFaceValues[dis(gen)]; //Use dis to transform the random unsigned int generated by gen into an int in [0, 5]

}

