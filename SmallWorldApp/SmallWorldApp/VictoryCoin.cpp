#include "Tokens.h"

VictoryCoin::VictoryCoin(int coinValue) {
	value = coinValue;
}

void VictoryCoin::setValue(int nb) {
	value = nb;
}

int VictoryCoin::getValue() {
	return value;
}

void VictoryCoin::printValue() {

	std::cout << value << std::endl;
}

