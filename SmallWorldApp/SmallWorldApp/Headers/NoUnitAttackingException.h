#pragma once
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class NoUnitAttackException : public runtime_error {
public:
	NoUnitAttackException() : runtime_error("Error: Attacking with no tokens.") {}
	char * exc_time;

};
