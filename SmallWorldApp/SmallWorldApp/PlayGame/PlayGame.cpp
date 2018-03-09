#include "../Headers/PlayGame.h"

Map PlayGame::getMap(){
    return map;
}
string getMapFilesPath(){
    return mapFilesPath;
}

void PlayGame::startGame(){
    map.selectMap(mapFilesPath);
    
    
}

