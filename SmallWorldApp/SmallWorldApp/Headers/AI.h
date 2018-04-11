//#ifndef __AI_H__
//#define __AI_H__
#pragma once

#include <algorithm>
#include <iostream>
#include <list>
#include <stack>
#include "Dice.h"
#include "Tokens.h"
#include "Game.h"
#include "Map.h"
#include "PlayGame.h"
#include "Players.h"

extern Map gameMap;

class AI{
public:

    virtual int pickPowerRace(std::vector <RaceBanner*> races, std::vector <PowerBadge*> powers)=0;
    virtual int aiConquers(Player* aiPlayer, std::vector<MapRegion*> regions)=0;
    virtual std::vector<std::stack<int>> aiRedeploy(Player* aiPlayer,int redeployabeTokens, std::vector<MapRegion*> regions)=0;
    virtual std::string aiDecline(int turnNb)=0;
    virtual std::string getName(){return name;}

private:
	std::string name="AI";
};


//////////////////////////////////////////////////////////////////////////////////////////



class aggressiveAI:public AI{
public:
    
    //Picks power and race combo that is has the most aggressivepoints
    int pickPowerRace(std::vector <RaceBanner*> races, std::vector <PowerBadge*> powers)override{
        
        std::array<int,MAX_NUMBER_PICKABLE_RACES> aggressivePoints;
        
        for(int i=0;i<MAX_NUMBER_PICKABLE_RACES;i++){
            
            int test=races[i]->getAggressivePoint()+powers[i]->getAggressivePoint();
            aggressivePoints[i]=races[i]->getAggressivePoint()+powers[i]->getAggressivePoint();
			std::cout<<races[i]->getName()<<powers[i]->getPowerName()<<" :tot Aggressive Points: " <<test<< std::endl;
        }
        std::array<int,6> tempAggressivePoints=aggressivePoints;
        std::sort(tempAggressivePoints.begin(),tempAggressivePoints.end());
        
        for(int i=0;i<MAX_NUMBER_PICKABLE_RACES;i++){
            if(aggressivePoints[i]==tempAggressivePoints[5]){
                return i+1;
            }
        }
        return 1;
    }
    
    //Picks region to conquer that has the most enemytokens
    int aiConquers(Player* aiPlayer, std::vector<MapRegion*> regions)override{
        
		std::cout<<"aggressive ai picking vertex to attack"<< std::endl;
        std::vector<int> tempVector;
        for (size_t i = 0; i < regions.size(); i++) {
            
            if(aiPlayer!=regions[i]->getOwner()){
                tempVector.push_back(regions[i]->getNbTokens());
				std::cout<<"Index vertex "<<regions[i]->getIndexOfVertex()<< std::endl;
				std::cout<<"Nb enemy tokens"<<regions[i]->getNbTokens()<< std::endl;
            }
        }
        
        std::sort(tempVector.begin(),tempVector.end());
        
        int nbEnemyTokens=tempVector[tempVector.size()-1];
        
        for (size_t i = 0; i < regions.size(); i++) {
            
            if(aiPlayer!=regions[i]->getOwner()&&nbEnemyTokens==regions[i]->getNbTokens()){
				std::cout<<"Aggressive Ai chose"<<regions[i]->getIndexOfVertex()<< std::endl;
                return regions[i]->getIndexOfVertex();
            }
        }
        
        return 0;
    }
    
    //all in one place: where theres the most enemy tokens
	std::vector<std::stack<int>> aiRedeploy(Player* aiPlayer,int redeployableTokens, std::vector<MapRegion*> regions)override{
		std::stack<int> nbTokens;
		std::stack<int> theRegions;
        
		std::vector<int> enemyTokensOfAllRegions;
        
        int mostEnemyTokens=0;
        
        int answerRegionIndex;
        
        int nbRegions=regions.size();
        
        for(int i=0;i<nbRegions;i++){
            gameMap.getAdgacentTerritories(regions[i]);
            int totEnemyTokens=0;
            
            for(int j=0;j<gameMap.adgacentMapRegions.size();j++){
                if(aiPlayer!=gameMap.adgacentMapRegions[j]->getOwner()){
                    totEnemyTokens+=gameMap.adgacentMapRegions[j]->getNbTokens();
                }
            }
            
            std::cout<<"Index: "<<regions[i]->getIndexOfVertex()<<" has "<<totEnemyTokens<<" enemy tokens around it"<<std::endl;
            
            if(mostEnemyTokens<=totEnemyTokens){
                mostEnemyTokens=totEnemyTokens;
                answerRegionIndex=regions[i]->getIndexOfVertex();
            }
        }
        theRegions.push(answerRegionIndex);
        nbTokens.push(redeployableTokens);
        
		std::vector<std::stack<int>> answers;
        answers.push_back(theRegions);
        answers.push_back(nbTokens);
        
        return answers;
        
    }
    
	std::string aiDecline(int turnNb)override{
        
        if(turnNb%2==1){
            std::cout<<getName()<<" about declining"<<std::endl;
            std::cout<<"He wants to decline"<<std::endl;
            std::cout<<std::endl;
            return "y";
        }
        else{
            std::cout<<std::endl;
            std::cout<<getName()<<" about declining"<<std::endl;
            std::cout<<"He does not want to decline"<<std::endl;
            return "n";
        }
        
    }
    
	std::string getName()override{return name;}
private:
	std::string name="aggressive AI is thinking";
};



//////////////////////////////////////////////////////////////////////////////////////////



class defensiveAI:public AI{
public:
    //Picks power and race combo that is has the least aggressivepoints
    int pickPowerRace(std::vector <RaceBanner*> races, std::vector <PowerBadge*> powers)override{
        
        std::array<int,MAX_NUMBER_PICKABLE_RACES> aggressivePoints;
        
        for(int i=0;i<MAX_NUMBER_PICKABLE_RACES;i++){
            
            int test=races[i]->getAggressivePoint()+powers[i]->getAggressivePoint();
            aggressivePoints[i]=races[i]->getAggressivePoint()+powers[i]->getAggressivePoint();
            std::cout<<races[i]->getName()<<powers[i]->getPowerName()<<" :tot Aggressive Points: " <<test<<std::endl;
        }
        std::array<int,6> tempAggressivePoints=aggressivePoints;
        std::sort(tempAggressivePoints.begin(),tempAggressivePoints.end());
        
        for(int i=0;i<MAX_NUMBER_PICKABLE_RACES;i++){
            if(aggressivePoints[i]==tempAggressivePoints[0]){
                return i+1;
            }
        }
        return 1;
    }
    
    //Picks region to conquer that has the least enemytokens
    int aiConquers(Player* aiPlayer, std::vector<MapRegion*> regions)override{
        
        std::cout<<"defensive ai picking vertex to attack"<<std::endl;
        std::vector<int> tempVector;
        for (size_t i = 0; i < regions.size(); i++) {
            
            if(aiPlayer!=regions[i]->getOwner()){
                tempVector.push_back(regions[i]->getNbTokens());
                std::cout<<"Index vertex "<<regions[i]->getIndexOfVertex()<<std::endl;
                std::cout<<"Nb enemy tokens"<<regions[i]->getNbTokens()<<std::endl;
            }
        }
        
        std::sort(tempVector.begin(),tempVector.end());
        
        int nbEnemyTokens=tempVector[0];
        
        for (size_t i = 0; i < regions.size(); i++) {
            
            if(aiPlayer!=regions[i]->getOwner()&&nbEnemyTokens==regions[i]->getNbTokens()){
                std::cout<<"defensive Ai chose"<<regions[i]->getIndexOfVertex()<<std::endl;
                return regions[i]->getIndexOfVertex();
            }
        }
        
        return 0;
    }
    
    //equal amount of tokens for every owned regions
	std::vector<std::stack<int>> aiRedeploy(Player* aiPlayer,int redeployableTokens, std::vector<MapRegion*> regions)override{
		std::stack<int> nbTokens;
		std::stack<int> theRegions;
        
        int nbRegions=regions.size();
        int equalTokens=redeployableTokens/nbRegions;
        int modulo=redeployableTokens%nbRegions;
        
        for(int i=0;i<nbRegions;i++){
            theRegions.push(regions[i]->getIndexOfVertex());
            
            if(modulo>0){
                nbTokens.push(equalTokens+1);
                --modulo;
            }
            else{
                nbTokens.push(equalTokens);
            }
        }
        
		std::vector<std::stack<int>> answers;
        answers.push_back(theRegions);
        answers.push_back(nbTokens);
        
        return answers;
        
    }
    
	std::string aiDecline(int turnNb)override{
        
        if(turnNb%2==1){
            std::cout<<getName()<<" about declining"<<std::endl;
            std::cout<<"He wants to decline"<<std::endl;
            std::cout<<std::endl;
            return "y";
        }
        else{
            std::cout<<std::endl;
            std::cout<<getName()<<" about declining"<<std::endl;
            std::cout<<"He does not want to decline"<<std::endl;
            return "n";
        }
        
    }
    
	std::string getName()override{return name;}
private:
	std::string name="defensive AI is thinking";
};


//////////////////////////////////////////////////////////////////////////////////////////


class moderateAI:public AI{
public:

    //Picks power and race combo that is has medium aggressivepoints
    int pickPowerRace(std::vector <RaceBanner*> races, std::vector <PowerBadge*> powers)override{
        
        std::array<int,MAX_NUMBER_PICKABLE_RACES> aggressivePoints;
        
        for(int i=0;i<MAX_NUMBER_PICKABLE_RACES;i++){
            
            int test=races[i]->getAggressivePoint()+powers[i]->getAggressivePoint();
            aggressivePoints[i]=races[i]->getAggressivePoint()+powers[i]->getAggressivePoint();
            std::cout<<races[i]->getName()<<powers[i]->getPowerName()<<" :tot Aggressive Points: " <<test<<std::endl;
        }
        std::array<int,6> tempAggressivePoints=aggressivePoints;
        std::sort(tempAggressivePoints.begin(),tempAggressivePoints.end());
        
        for(int i=0;i<MAX_NUMBER_PICKABLE_RACES;i++){
            if(aggressivePoints[i]==tempAggressivePoints[2]){
                return i+1;
            }
        }
        return 1;
    }
    //does the same as defensiveAi
    int aiConquers(Player* aiPlayer, std::vector<MapRegion*> regions)override{
        
        std::cout<<"defensive ai picking vertex to attack"<<std::endl;
        std::vector<int> tempVector;
        for (size_t i = 0; i < regions.size(); i++) {
            
            if(aiPlayer!=regions[i]->getOwner()){
                tempVector.push_back(regions[i]->getNbTokens());
                std::cout<<"Index vertex "<<regions[i]->getIndexOfVertex()<<std::endl;
                std::cout<<"Nb enemy tokens"<<regions[i]->getNbTokens()<<std::endl;
            }
        }
        
        std::sort(tempVector.begin(),tempVector.end());
        
        int nbEnemyTokens=tempVector[0];
        
        for (size_t i = 0; i < regions.size(); i++) {
            
            if(aiPlayer!=regions[i]->getOwner()&&nbEnemyTokens==regions[i]->getNbTokens()){
                std::cout<<"defensive Ai chose"<<regions[i]->getIndexOfVertex()<<std::endl;
                return regions[i]->getIndexOfVertex();
            }
        }
        
        return 0;
    }
    
    //does the same as defensive ai because its the best strategy
	std::vector<std::stack<int>> aiRedeploy(Player* aiPlayer,int redeployableTokens, std::vector<MapRegion*> regions)override{
		std::stack<int> nbTokens;
		std::stack<int> theRegions;
        
        int nbRegions=regions.size();
        int equalTokens=redeployableTokens/nbRegions;
        int modulo=redeployableTokens%nbRegions;
        
        for(int i=0;i<nbRegions;i++){
            theRegions.push(regions[i]->getIndexOfVertex());
            
            if(modulo>0){
                nbTokens.push(equalTokens+1);
                --modulo;
            }
            else{
                nbTokens.push(equalTokens);
            }
        }
        
		std::vector<std::stack<int>> answers;
        answers.push_back(theRegions);
        answers.push_back(nbTokens);
        
        return answers;
        
    }
    
	std::string aiDecline(int turnNb)override{
        
        if(turnNb%2==1){
            std::cout<<getName()<<" about declining"<<std::endl;
            std::cout<<"He wants to decline"<<std::endl;
            std::cout<<std::endl;
            return "y";
        }
        else{
            std::cout<<std::endl;
            std::cout<<getName()<<" about declining"<<std::endl;
            std::cout<<"He does not want to decline"<<std::endl;
            return "n";
        }
        
    }
    
	std::string getName()override{return name;}
private:
	std::string name="moderate AI is thinking";
};

//////////////////////////////////////////////////////////////////////////////////////////


class randomAI:public AI{
public:
    
    //Picks randomly the power and race combo
    int pickPowerRace(std::vector <RaceBanner*> races, std::vector <PowerBadge*> powers)override{
        int randomPick=(rand() % 6)+1;
        return randomPick;
    }
    
    //Picks region to conquer randomly
    int aiConquers(Player* aiPlayer, std::vector<MapRegion*> regions)override{
        
        std::cout<<"random ai picking vertex to attack"<<std::endl;
        std::vector<int> tempVector;
        for (size_t i = 0; i < regions.size(); i++) {
            
            if(aiPlayer!=regions[i]->getOwner()){
                tempVector.push_back(regions[i]->getIndexOfVertex());
                std::cout<<"Index vertex "<<regions[i]->getIndexOfVertex()<<std::endl;
            }
        }
        
        std::sort(tempVector.begin(),tempVector.end());
        
        int nbChoices=tempVector.size();
       
        int randomChoice=(rand() % nbChoices);
        
        std::cout<<"random ai chose  "<<tempVector[randomChoice]<<std::endl;
        
        return tempVector[randomChoice];
       
    }
    
    //Randomly put random amount of tokens on owned regions
	std::vector<std::stack<int>> aiRedeploy(Player* aiPlayer,int redeployableTokens, std::vector<MapRegion*> regions)override{
		std::stack<int> nbTokens;
		std::stack<int> theRegions;
        
        int nbRegions=regions.size();
        int tokensLeft=redeployableTokens;
        
        int randomAmountOfTokens;
        int randomVertexOfRegion;
        
        while(tokensLeft>0){
            
            
            randomAmountOfTokens=(rand() % tokensLeft)+1;
            randomVertexOfRegion=regions[(rand() % nbRegions)]->getIndexOfVertex();
            
            nbTokens.push(randomAmountOfTokens);
            theRegions.push(randomVertexOfRegion);
            
            tokensLeft-=randomAmountOfTokens;
            
        }
   
		std::vector<std::stack<int>> answers;
        answers.push_back(theRegions);
        answers.push_back(nbTokens);
        
        return answers;
        
    }
    
	std::string aiDecline(int turnNb)override{
        
        if(turnNb%2==1){
            std::cout<<getName()<<" about declining"<<std::endl;
            std::cout<<"He wants to decline"<<std::endl;
            std::cout<<std::endl;
            return "y";
        }
        else{
            std::cout<<std::endl;
            std::cout<<getName()<<" about declining"<<std::endl;
            std::cout<<"He does not want to decline"<<std::endl;
            return "n";
        }
        
    }
    
	std::string getName()override{return name;}
private:
	std::string name="random AI is thinking";
};

//#endif __AI_H__
