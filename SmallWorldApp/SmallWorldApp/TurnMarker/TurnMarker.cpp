#include "../Headers/TurnMarker.h"

TurnMarker::TurnMarker(){
    turnNumber=1;
}

int TurnMarker::getTurnNumber(){
    return turnNumber;
}

void TurnMarker::nextTurn(){
    ++turnNumber;
}



