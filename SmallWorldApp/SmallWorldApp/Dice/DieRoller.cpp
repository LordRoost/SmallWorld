#include "../Headers/Dice.h"


DieRoller::DieRoller() {
	rollCount = 0;
	
	for (int i = 0; i < MAX_DIFF_VALUE; i++) {
		valueCount[i] = 0;
	}

}

void DieRoller::rollDice() {

	int result = dice.roll();
	rollCount++;
	valueCount[result]++;

	std::cout << result << std::endl;
}

bool DieRoller::determineResult() {
	return false;
}

void DieRoller::printDistribution() {
	
	int distribution[MAX_DIFF_VALUE];

	if (rollCount == 0) {
		std::cout << "You haven't rolled the dice yet!" << std::endl;
		return;
	}

	for (int i = 0; i < MAX_DIFF_VALUE; i++) {
		distribution[i] = valueCount[i] * 100 / rollCount;
		std::cout << distribution[i] << std::endl;
	}

}