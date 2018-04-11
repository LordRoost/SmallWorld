#pragma once
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class UserInputException : public runtime_error {
public:
	UserInputException();
	char * exc_time;
	const char *what() const;

};

class LetterInput : public UserInputException {

};