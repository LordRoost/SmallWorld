#ifndef __NOUNITATTACKINGEXCEPTION_H__
#define __NOUNITATTACKINGEXCEPTION_H__
#pragma once
#include <iostream>
#include <exception>
#include <stdexcept>


class NoUnitAttackException : public std::runtime_error {
public:
	NoUnitAttackException() : std::runtime_error("Error: Attacking with no tokens.") {}


};

#endif //__NOUNITATTACKINGEXCEPTION_H__