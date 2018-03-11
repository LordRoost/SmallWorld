#include "../Headers/PlayGame.h"

Map gameMap;


Map PlayGame::getMap(){
    return gameMap;
}

string getMapFilesPath(){
    return mapFilesPath;
}

void PlayGame::startGame(){
    
    gameMap.selectMap(mapFilesPath);
    setNumberOfPlayers();
    addPiecesToWells();
    
    //MapRegion *m=&gameMap.getMap()[0];
    //gameMap.getAdgacentTerritories(m);
    
    
   // vector<MapRegion*>asd=gameMap.getAllBorders();
    
    
    
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

void PlayGame::addPiecesToWells(){
    
    //raceBannerDeck=RaceBannerDeck();
    //raceBannerDeck.buildDeck();
    //raceBannerDeck.shuffle();
    //raceBannerDeck.printDeck();
    //
    //powerBadgeDeck=PowerBadgeDeck();
    //powerBadgeDeck.buildDeck();
    //powerBadgeDeck.shuffle();
    //powerBadgeDeck.printDeck();

	decks = new RacePicker();
	decks->setup();
	decks->printOptions();
    
    
    //Mountains and fortresses dragon etc
    //lost tribes
    //to be made as child classes of gamepiece
}

