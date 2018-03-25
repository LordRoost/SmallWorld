#include "../Headers/PlayGame.h"

extern Map gameMap;

Map PlayGame::getMap(){
    return gameMap;
}

TurnMarker PlayGame::getTurnMarker(){
    return turnMarker;
}

void PlayGame::startGame(){
    
    gameMap.selectMap(mapFilesPath);
    gameMap.getAllBorders();
    setNumberOfPlayers();
    addPiecesToWells();

	
	std::cout << std::endl;

	Graph tempGraph = *gameMap.getGraph();
	MapRegion *m = tempGraph[1];
	gameMap.getAdgacentTerritories(m);

	//Make victory coins in bank
	coinBank = CoinBank();
	
	//Give players 5 victory coins of value 1
	for (std::vector<int>::size_type i = 0; i < players.size(); i++) {
	Player *pointer = &players[i];
	coinBank.startingDeal(pointer);
	
	}
	//Turn 1
	turnMarker = TurnMarker();
}

void PlayGame::firstTurn(){
    
    for (std::vector<int>::size_type i = 0; i < players.size(); i++) {
        Player *pointer = &players[i];
        pointer->picks_race(decks);
        pointer->conquers();
        pointer->scores(&coinBank);
        
    }
    
    
}

void PlayGame::followingTurns(){
    
    while(turnMarker.getTurnNumber()<=TOTAL_NUM_TURNS){
		std::cout << "Turn " << turnMarker.getTurnNumber()+1 << std::endl;
        for (std::vector<int>::size_type i = 0; i < players.size(); i++) {
            Player *pointer = &players[i];
            
			//cout << "Nb of Regions " << pointer->getOwnedRegions().size() << endl;
			//cout << "Race Banner of player " << pointer->getRacebanner()->getName() << endl;
            cout<<"Do you want to decline your race?(y or n)"<<endl;
            string yorn;
            cin>>yorn;
            if(yorn=="y"){
                pointer->declineRace();
            }
            else{
				pointer->readyTroops();
                pointer->conquers();
            }

            pointer->scores(&coinBank);

        }
        
        turnMarker.nextTurn();
    }
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
    moderateAI moderateai;
    for(int i=0; i<nbOfPlayers;i++)
    {
        Player player=Player(&moderateai);
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

