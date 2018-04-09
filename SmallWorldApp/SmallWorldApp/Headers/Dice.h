#ifndef __DICE_H__
#define __DICE_H__
#pragma once
#include <iostream>
#include <random>
#define DIE_FACES 6 //number of sides for the die
#define MAX_DIFF_VALUE 4 //the number of different values that are on the die (0-1-2-3)

class Dice {
public:
	Dice(); 
	~Dice() {} 
	int roll();

private:
	int dieFaceValues[DIE_FACES];
};

class DieRoller {

public:
	DieRoller();
	int rollDice();
	//void rollDice();
	//bool determineResult();
	void printDistribution();

private: 
	Dice dice;
	unsigned int rollCount;
	unsigned int valueCount[MAX_DIFF_VALUE];

};

#endif //__DICE_H__