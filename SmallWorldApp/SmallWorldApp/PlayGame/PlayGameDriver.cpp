//#include "../Headers/PlayGame.h"
#include "../Headers/DominationView.h"
#include "../Headers/GamesStatisticsDecorator.h"
#include "../Headers/StepView.h"
//Map gameMap;

int main(){

//int GameDriver(){
	

    PlayGame game1;
	
	//StepView *sView = new StepView(&game1);

    game1.startGame();
    
    GameStatistics* sView= new StepView(&game1);
    
    //GameStatistics *sView = new StepView(&game1);
    vector<GameStatistics*> views;
    
	for (std::vector<int>::size_type i = 0; i < game1.players.size(); i++) {
        Player *pointer = game1.players[i];
        GameStatistics tempView=sView;
        GameStatistics* asd= new DominationView(pointer, &game1, sView);
        
        views.push_back(asd);
        
		
        
		//DominationView *dView = new DominationView(pointer, &game1);

        if(i==1){
            views.erase(views.begin() + i);
            
            auto_ptr<GameStatistics> adc (new StepView(&game1));
            views.push_back(adc.get());
        }
        
	}

    game1.firstTurn();
    game1.getTurnMarker()->nextTurn();
    game1.followingTurns();
    
    cout<<"game ended"<<endl;

    
    return 0;
}

