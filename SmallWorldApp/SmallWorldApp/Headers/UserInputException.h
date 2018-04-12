#pragma once
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class UserInputException : public runtime_error {
public:
	UserInputException() : runtime_error("Error: User input error."){}
	char * exc_time;
	//const char *what() const;

};

