#ifndef __TURNMARKER_H__
#define __TURNMARKER_H__

#pragma once
#include <iostream>
#include <stdio.h>

#define TOTAL_NUM_TURNS_2_PLAYERS 10 
#define TOTAL_NUM_TURNS_4_PLAYERS 9
#define TOTAL_NUM_TURNS_5_PLAYERS 8

class TurnMarker {
public:
	TurnMarker() : turnNumber(1) {}
    int getTurnNumber();
	void operator++() { ++turnNumber; } //overloaded prefix increment operator. Essentially moves the turn forward by 1.
    
private:
    int turnNumber;
   
};

#endif //__TURNMARKER_H__