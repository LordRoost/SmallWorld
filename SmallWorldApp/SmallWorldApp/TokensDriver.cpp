#include "Tokens.h"


int main(int argc, char*[]) {

	//this block initializes the coins
	VictoryCoin *coins[TOTAL_NUM_COINS];
	int upperLimit = NUM_OF_10S;

	for (int i = 0; i < upperLimit; i++) {
		coins[i] = new VictoryCoin(10);
	}

	upperLimit += NUM_OF_5S;

	for (int i = 30; i < upperLimit; i++) {
		coins[i] = new VictoryCoin(5);
	}

	upperLimit += NUM_OF_3S;

	for (int i = 54; i < upperLimit; i++) {
		coins[i] = new VictoryCoin(3);
	}

	upperLimit += NUM_OF_1S;

	for (int i = 74; i < upperLimit; i++) {
		coins[i] = new VictoryCoin(1);
	}
}

