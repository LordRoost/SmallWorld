#pragma once
#include <iostream>
#include <stdio.h>

#define TOTAL_NUM_TURNS_2_PLAYERS 10 
#define TOTAL_NUM_TURNS_4_PLAYERS 9
#define TOTAL_NUM_TURNS_5_PLAYERS 8

class TurnMarker {
public:
	TurnMarker() : turnNumber(1) {}
    void nextTurn();
    int getTurnNumber();
	void operator++() { ++turnNumber; }
    
private:
    int turnNumber;
   
};

