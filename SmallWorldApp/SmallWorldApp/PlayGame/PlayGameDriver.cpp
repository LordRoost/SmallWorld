#include "../Headers/PlayGame.h"
//#include "../Headers/DominationView.h"
//#include "../Headers/StepView.h"
//#include "../Headers/DominationDecorator.h"
//#include "../Headers/VictoryCoinDecorator.h"
//#include "../Headers/GameStats.h"
//Map gameMap;

//DominationView;


int mainer(){	

    PlayGame game1;
	
	//GameStatsInterface *gs = new GameStats(&game1);

    game1.startGame();

	//StepView *sView = new StepView(&game1);
	//for (std::vector<int>::size_type i = 0; i < game1.players.size(); i++) {
	//	Player *pointer = game1.players[i];
	//	DominationView *dView = new DominationView(pointer, &game1);

	//}

	/*for (std::vector<int>::size_type i = 0; i < game1.players.size(); i++) {
		Player *pointer = game1.players[i];
		gs = new DominationDecorator(gs, &game1, pointer);
		gs = new VictoryCoinDecorator(gs, &game1, pointer);

	}*/


    game1.firstTurn();
    game1.followingTurns();
    
    std::cout<<"game ended"<<std::endl;

    
    return 0;
}

