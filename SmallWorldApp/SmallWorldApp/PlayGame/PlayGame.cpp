#include "../Headers/PlayGame.h"
//#include "../Headers/GameStats.h"
#include "../Headers/DominationDecorator.h"
#include "../Headers/VictoryCoinDecorator.h"

//class DominationDecorator;
//class VictoryCoindecorator;

Map gameMap;
GameStatsInterface *gs; 
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

	tokenWell = TokenWell();

	addPiecesToWells();

	gameMap.initialize(&tokenWell);

	setNumberOfPlayers();

	std::cout << std::endl;

	//Make victory coins in bank
	coinBank = CoinBank();
	
	//Give players 5 victory coins of value 1
	for (std::vector<int>::size_type i = 0; i < players.size(); i++) {
		Player *pointer = players[i];
		coinBank.startingDeal(pointer);
	
	}
	//Turn 1
	turnMarker = new TurnMarker();
}

void PlayGame::firstTurn(){
	//gs = new GameStats(this); //comment back for decorator demo
	setCurrentTurn();
    std::cout << "Turn " << currentTurn <<" is beginning" << std::endl;
    
    for (std::vector<int>::size_type i = 0; i < players.size(); i++) {

		Player *pointer = players[i];
		//decoratorPrompt(pointer); //comment back for decorator demo
	
		setCurrentPlayerNb(i+1);
		setCurrentPhase("Picking Race");
		Notify();
        pointer->picks_race(decks);
		setCurrentPhase("Conquering");
		Notify();
        pointer->conquers();
		setCurrentPhase("Redeploying");
		Notify();
		pointer->redeploy();
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
    
	while (currentTurn <= TOTAL_NUM_TURNS) {
		setCurrentTurn();
		std::cout << "Turn " << currentTurn <<" is beginning"<< std::endl;
        for (std::vector<int>::size_type i = 0; i < players.size(); i++) {
			Player *pointer = players[i];
			//decoratorPrompt(pointer); //comment out for observerdemo

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
						pointer->abandonRegion(); //comment out for AI demo
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
		else if (cin.fail()) {
			cin.clear();
			cin.ignore();
		}
        
        cout<<"Number of Players you entered is invalid, please try again"<<endl;
    }
    
    cout<< "Number of players you entered is " << nbOfPlayers<<endl;
    
    for(int i=0; i<nbOfPlayers;i++)
    {
        Player *player = new Player();
        if(i==0){
            //player = new Player(new moderateAI()); //uncomment for AI demo
            //player = new Player(new defensiveAI()); //uncomment for AI demo
        }
        else{
            //player = new Player(new randomAI()); //uncomment for AI demo
            //player = new Player(new aggressiveAI()); //uncomment for AI demo
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

	for (int i = 0; i < MAX_NUM_MOUNTAIN_TOKENS; i++) {
		MountainPiece *mountain = new MountainPiece;
		tokenWell.addMountainPieces(mountain);
	}

}

void PlayGame::decoratorPrompt(Player *player) {
	char decoAnswer = '0';
	char chosenDeco = '0';
	char chosenRemoveDeco = '0';
	int temp,tempRemove;
	if (player->statusDecorators == true) {
		while (decoAnswer != 'y' && decoAnswer != 'n' &&decoAnswer != 'q') {
			std::cout << "Do you want to add decorators to the Game Stats view? Enter q if you do not want to be prompted again in the future. Enter r if you want to remove decorators instead. (y/n/r/q)" << std::endl;
			std::cin >> decoAnswer;
			if (decoAnswer == 'y') {
				std::cout << "You can add: " << std::endl << "1. Domination Observer Decorator" << std::endl << "2. Victory Coins Observer Decorator" << std::endl;
				std:cout << "Enter n to stop adding." << std::endl;

				while (chosenDeco != '1' && chosenDeco != '2'&& chosenDeco != 'n') {
					std::cout << "Enter the number of the decorator that you want to add: " << std::endl;
					std::cin >> chosenDeco;
					temp = chosenDeco - '0';
					if (temp == 1 && player->decoDominationCheck == false) {

						gs = new DominationDecorator(gs, this, player);
						player->decoDominationCheck = true;
						std::cout << "You have added a Domination Observer Decorator." << std::endl;
						chosenDeco = '0';
					}
					else if (temp == 1 && player->decoDominationCheck == true) {
						std::cout << "You already have a Domination Observer Decorator!" << std::endl;
						chosenDeco = '0';
					}
					else if (temp == 2 && player->decoCoinsCheck == false) {
						gs = new VictoryCoinDecorator(gs, this, player);
						player->decoCoinsCheck = true;
						std::cout << "You have added a Victory Coin Observer Decorator." << std::endl;
						chosenDeco = '0';
					}
					else if (temp == 2 && player->decoCoinsCheck == true) {
						std::cout << "You already have a Victory Coin Observer Decorator!" << std::endl;
						chosenDeco = '0';
					}
					else if (chosenDeco == 'n') {
						chosenDeco = '0';
						break;
					}
					else {
						std::cout << "Please enter the correct number!" << std::endl;
					}
				}
				
			}
			else if (decoAnswer == 'n') {
				std::cout << "You have chosen not to add any decorators this turn." << std::endl;
				break;
			}
			else if (decoAnswer == 'r') {
				std::cout << "Which decorator do you wish to remove?" << std::endl << "1. Domination Observer Decorator" << std::endl << "2. Victory Coins Observer Decorator" << std::endl;
				std::cout << "Enter n to stop adding." << std::endl;

				while (chosenRemoveDeco != '1' && chosenRemoveDeco != '2'&& chosenRemoveDeco != 'n') {
					std::cout << "Enter the number of the decorator that you want to remove: " << std::endl;
					std::cin >> chosenRemoveDeco;
					tempRemove = chosenRemoveDeco - '0';
					if (tempRemove == 1 && player->decoDominationCheck == true) {
						if (player->decoCoinsCheck == true) {
							//GameStatsInterface *newGameStats = new VictoryCoinDecorator(new GameStats(this), this, player);
							delete(gs);
							gs = new VictoryCoinDecorator(new GameStats(this), this, player);
							player->decoDominationCheck = false;
							chosenRemoveDeco = '0';
						}
						else {
							//GameStatsInterface *newGameStats = new GameStats(this);
							delete(gs);
							gs = new GameStats(this);
							player->decoDominationCheck = false;
							chosenRemoveDeco = '0';
						}
					}
					else if (tempRemove == 1 && player->decoDominationCheck == false) {
						std::cout << "You don't have a Domination Observer Decorator!" << std::endl;
						chosenRemoveDeco = '0';
					}
					else if (tempRemove == 2 && player->decoCoinsCheck == true) {
						if (player->decoDominationCheck == true) {
							gs = new DominationDecorator(new GameStats(this), this, player);
							player->decoCoinsCheck = false;
							chosenRemoveDeco = '0';
						}
						else {
							gs = new GameStats(this);
							player->decoCoinsCheck = false;
							chosenRemoveDeco = '0';
						}
					}
					else if (tempRemove == 2 && player->decoCoinsCheck == false) {
						std::cout << "You don't have a Victory Coin Observer Decorator!" << std::endl;
						chosenRemoveDeco = '0';
					}
					else if (chosenRemoveDeco == 'n') {
						chosenRemoveDeco = '0';
						break;
					}
					else {
						std::cout << "Please enter the correct number!" << std::endl;
					}
				}
			}
			else if (decoAnswer == 'q') {
				player->statusDecorators = false;
				std::cout << "You have chosen not to add any decorators. You will no longer be messaged about decorators." << std::endl;
				break;
			}
			else {
				std::cout << "Please enter y/n or q!" << std::endl;
			}
		}
	}
}
