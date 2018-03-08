#include "../Headers/Tokens.h"

Token::Token() {

}

Token::Token(int max) {
	maxAmount = max;
}

int Token::getMaxAmount() {
	return maxAmount;
}

void Token::setMaxAmount(int amount) {
	maxAmount = amount;
}
