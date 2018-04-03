#include "../Headers/PlayGame.h"

Map gameMap;
//extern Map gameMap;

Map PlayGame::getMap(){
    return gameMap;
}

TurnMarker* PlayGame::getTurnMarker(){
    return turnMarker;
}

//Player* PlayGame::getCurrentPlayer() {
//	return currentPlayer;
//}

int PlayGame::getCurrentPlayerNb() {
	return currentPlayerNb;
}

std::string PlayGame::getCurrentPhase() {
	return currentPhase;
}

int PlayGame::getCurrentTurn() {
	return currentTurn;
}

//void PlayGame::setCurrentPlayer(Player* person) {
//	currentPlayer = person;
//}

void PlayGame::setCurrentPlayerNb(int nb) {
	currentPlayerNb = nb;
}

void PlayGame::setCurrentPhase(std::string phase) {
	currentPhase = phase;
}

void PlayGame::setCurrentTurn() {
	currentTurn = turnMarker->getTurnNumber();
}

void PlayGame::startGame(){

  //gameMap.selectMap(mapFilesPath);
  //gameMap.getAllBorders();

	tokenWell = TokenWell();

	addPiecesToWells();

	gameMap.initialize(&tokenWell);

	setNumberOfPlayers();

	std::cout << std::endl;


	//Graph tempGraph = *gameMap.getGraph();
	//MapRegion *m = tempGraph[1];
	//gameMap.getAdgacentTerritories(m);


	//Make victory coins in bank
	coinBank = CoinBank();
	
	//Give players 5 victory coins of value 1
	for (std::vector<int>::size_type i = 0; i < players.size(); i++) {
	//Player *pointer = &players[i];
		Player *pointer = players[i];
		coinBank.startingDeal(pointer);
	
	}
	//Turn 1
	turnMarker = new TurnMarker();
}

void PlayGame::firstTurn(){
	setCurrentTurn();
    std::cout << "Turn " << currentTurn <<" is beginning" << std::endl;
    
    for (std::vector<int>::size_type i = 0; i < players.size(); i++) {
        //Player *pointer = &players[i];
		Player *pointer = players[i];
		setCurrentPlayerNb(i+1);
		setCurrentPhase("Picking Race");
		Notify();
        pointer->picks_race(decks);
		setCurrentPhase("Conquering");
		Notify();
        pointer->conquers();
		setCurrentPhase("Scoring");
		Notify();
        pointer->scores(&coinBank);
		setCurrentPhase("End");
		Notify();
        
    }
    
    std::cout << "Turn " << currentTurn <<" is ending" << std::endl;
	turnMarker->nextTurn();
}

void PlayGame::followingTurns(){
    
    //while(turnMarker->getTurnNumber()<=TOTAL_NUM_TURNS){
	while (currentTurn <= TOTAL_NUM_TURNS) {
		setCurrentTurn();
		std::cout << "Turn " << currentTurn <<" is beginning"<< std::endl;
        for (std::vector<int>::size_type i = 0; i < players.size(); i++) {
            //Player *pointer = &players[i];
			Player *pointer = players[i];
			setCurrentPlayerNb(i + 1);
			setCurrentPhase("Decline");
			Notify();
            
            string yorn;
            
            if(!pointer->getInDecline()){
                
            
                cout<<"Do you want to decline your race?(y or n)"<<endl;
                
                
                if(pointer->getAIStrategy()==NULL){
                    cin>>yorn;
                }
                else{
                    yorn=pointer->getAIStrategy()->aiDecline(currentTurn);
                }
            
                if(yorn=="y"){
                    pointer->declineRace(decks);
                }
                else{

					char abandonAnswer = '0';

					std::cout << "Do you wish to abandon some regions? (y/n)" << std::endl;
					std::cin >> abandonAnswer;
					if (abandonAnswer == 'y') {
						setCurrentPhase("Abandoning Regions");
						Notify();
						pointer->abandonRegion();
					}
					setCurrentPhase("Readying Troops");
					Notify();
                    pointer->readyTroops();
					setCurrentPhase("Conquering");
					Notify();
                    pointer->conquers();
                }
            }
            
            else{
                pointer->setInDecline(false);
				setCurrentPhase("Picking Race");
				Notify();
                pointer->picks_race(decks);
				setCurrentPhase("Conquering");
				Notify();
                pointer->conquers();
                
            }			
			setCurrentPhase("Scoring");
			Notify();
            pointer->scores(&coinBank);

        }
        
		setCurrentPhase("End");
		Notify();
        cout<<"Turn "<< currentTurn <<" has ended"<<endl;
        cout<<endl;
        
        turnMarker->nextTurn();

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
    
    for(int i=0; i<nbOfPlayers;i++)
    {
        Player *player = new Player();
        if(i==0){
            //player=Player(new moderateAI());
            //player=Player(new defensiveAI());
        }
        else{
            //player=Player(new randomAI());
            //player=Player(new aggressiveAI());
        }
        
        
        players.push_back(player);
		//delete(player);
    }

	gameMap.selectMap(nbOfPlayers);
	gameMap.getAllBorders();
}

void PlayGame::addPiecesToWells(){

	decks = new RacePicker();
	decks->setup();
	//decks->printOptions();

	for (int i = 0; i < MAX_NUM_MOUNTAIN_TOKENS; i++) {
		MountainPiece *mountain = new MountainPiece;
		tokenWell.addMountainPieces(mountain);
	}

}


