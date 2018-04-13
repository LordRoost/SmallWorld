#ifndef __USERINPUTEXCEPTION_H__
#define __USERINPUTEXCEPTION_H__
#pragma once
#include <iostream>
#include <exception>
#include <stdexcept>

class UserInputException : public std::runtime_error {
public:
	UserInputException() : std::runtime_error("Error: User input error."){}

};

#endif //__USERINPUTEXCEPTION_H__