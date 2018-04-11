#pragma once
#include <iostream>
#include <stdio.h>

#define TOTAL_NUM_TURNS 8

class TurnMarker {
public:
	TurnMarker() : turnNumber(1) {}
    void nextTurn();
    int getTurnNumber();
	void operator++() { ++turnNumber; }
    
private:
    int turnNumber;
   
};

