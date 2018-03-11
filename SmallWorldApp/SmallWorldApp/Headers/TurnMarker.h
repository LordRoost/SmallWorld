#pragma once

#define TOTAL_NUM_TURNS 8

class TurnMarker {
public:
    TurnMarker();
    void nextTurn();
    int getTurnNumber();
    
private:
    int turnNumber;
   
};

