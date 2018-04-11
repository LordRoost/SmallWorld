#include "../Headers/TurnMarker.h"

int TurnMarker::getTurnNumber(){
    return turnNumber;
}

void TurnMarker::nextTurn(){
    ++turnNumber;
}



