#include "../Headers/PlayGame.h"
#include "../Headers/Players.h"

Map PlayGame::getMap(){
    return map;
}
string getMapFilesPath(){
    return mapFilesPath;
}

void PlayGame::startGame(){
    
    map.selectMap(mapFilesPath);
    setNumberOfPlayers();
    //make game pieces
    
    
}

void PlayGame::setNumberOfPlayers(){
    
    int nbOfPlayers;
    
    while(true)
    {
        cout<<"How many players will be playing? (2-5 players)"<<endl;
        cin>>nbOfPlayers;
        
        if(nbOfPlayers>1&&nbOfPlayers<6){
            break;
        }
        
        cout<<"Number of Players you entered is invalid, please try again"<<endl;
    }
    
    cout<< "Number of players you entered is " << nbOfPlayers<<endl;
    
    for(int i=0; i<nbOfPlayers;i++)
    {
        Player player=Player();
        players.push_back(player);
    }
    
}

