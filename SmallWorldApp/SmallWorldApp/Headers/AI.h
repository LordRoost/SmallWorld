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

    virtual int pickPowerRace(vector <RaceBanner*> races,vector <PowerBadge*> powers)=0;
    virtual int aiConquers(Player* aiPlayer,vector<MapRegion*> regions)=0;
    virtual vector<stack<int>> aiRedeploy(Player* aiPlayer,int redeployabeTokens, vector<MapRegion*> regions)=0;
    virtual string getName(){return name;}

private:
    string name="AI";
};


//////////////////////////////////////////////////////////////////////////////////////////



class aggressiveAI:public AI{
public:
    
    //Picks power and race combo that is has the most aggressivepoints
    int pickPowerRace(vector <RaceBanner*> races,vector <PowerBadge*> powers)override{
        
        std::array<int,MAX_NUMBER_PICKABLE_RACES> aggressivePoints;
        
        for(int i=0;i<MAX_NUMBER_PICKABLE_RACES;i++){
            
            int test=races[i]->getAggressivePoint()+powers[i]->getAggressivePoint();
            aggressivePoints[i]=races[i]->getAggressivePoint()+powers[i]->getAggressivePoint();
            cout<<races[i]->getName()<<powers[i]->getPowerName()<<" :tot Aggressive Points: " <<test<<endl;
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
    int aiConquers(Player* aiPlayer, vector<MapRegion*> regions)override{
        
        cout<<"aggressive ai picking vertex to attack"<<endl;
        std::vector<int> tempVector;
        for (size_t i = 0; i < regions.size(); i++) {
            
            if(aiPlayer!=regions[i]->getOwner()){
                tempVector.push_back(regions[i]->getNbTokens());
                cout<<"Index vertex "<<regions[i]->getIndexOfVertex()<<endl;
                cout<<"Nb enemy tokens"<<regions[i]->getNbTokens()<<endl;
            }
        }
        
        std::sort(tempVector.begin(),tempVector.end());
        
        int nbEnemyTokens=tempVector[tempVector.size()-1];
        
        for (size_t i = 0; i < regions.size(); i++) {
            
            if(aiPlayer!=regions[i]->getOwner()&&nbEnemyTokens==regions[i]->getNbTokens()){
                cout<<"Aggressive Ai chose"<<regions[i]->getIndexOfVertex()<<endl;
                return regions[i]->getIndexOfVertex();
            }
        }
        
        return 0;
    }
    
    //all in one place: where theres the most enemy tokens
    vector<stack<int>> aiRedeploy(Player* aiPlayer,int redeployableTokens, vector<MapRegion*> regions)override{
        stack<int> nbTokens;
        stack<int> theRegions;
        
        vector<int> enemyTokensOfAllRegions;
        
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
            
            cout<<"Index: "<<regions[i]->getIndexOfVertex()<<" has "<<totEnemyTokens<<" enemy tokens around it"<<endl;
            
            if(mostEnemyTokens<=totEnemyTokens){
                mostEnemyTokens=totEnemyTokens;
                answerRegionIndex=regions[i]->getIndexOfVertex();
            }
        }
        theRegions.push(answerRegionIndex);
        nbTokens.push(redeployableTokens);
        
        vector<stack<int>> answers;
        answers.push_back(theRegions);
        answers.push_back(nbTokens);
        
        return answers;
        
    }
    
    string getName()override{return name;}
private:
    string name="aggressive AI is thinking";
};



//////////////////////////////////////////////////////////////////////////////////////////



class defensiveAI:public AI{
public:
    //Picks power and race combo that is has the least aggressivepoints
    int pickPowerRace(vector <RaceBanner*> races,vector <PowerBadge*> powers)override{
        
        std::array<int,MAX_NUMBER_PICKABLE_RACES> aggressivePoints;
        
        for(int i=0;i<MAX_NUMBER_PICKABLE_RACES;i++){
            
            int test=races[i]->getAggressivePoint()+powers[i]->getAggressivePoint();
            aggressivePoints[i]=races[i]->getAggressivePoint()+powers[i]->getAggressivePoint();
            cout<<races[i]->getName()<<powers[i]->getPowerName()<<" :tot Aggressive Points: " <<test<<endl;
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
    int aiConquers(Player* aiPlayer, vector<MapRegion*> regions)override{
        
        cout<<"defensive ai picking vertex to attack"<<endl;
        std::vector<int> tempVector;
        for (size_t i = 0; i < regions.size(); i++) {
            
            if(aiPlayer!=regions[i]->getOwner()){
                tempVector.push_back(regions[i]->getNbTokens());
                cout<<"Index vertex "<<regions[i]->getIndexOfVertex()<<endl;
                cout<<"Nb enemy tokens"<<regions[i]->getNbTokens()<<endl;
            }
        }
        
        std::sort(tempVector.begin(),tempVector.end());
        
        int nbEnemyTokens=tempVector[0];
        
        for (size_t i = 0; i < regions.size(); i++) {
            
            if(aiPlayer!=regions[i]->getOwner()&&nbEnemyTokens==regions[i]->getNbTokens()){
                cout<<"defensive Ai chose"<<regions[i]->getIndexOfVertex()<<endl;
                return regions[i]->getIndexOfVertex();
            }
        }
        
        return 0;
    }
    
    //equal amount of tokens for every owned regions
    vector<stack<int>> aiRedeploy(Player* aiPlayer,int redeployableTokens, vector<MapRegion*> regions)override{
        stack<int> nbTokens;
        stack<int> theRegions;
        
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
        
        vector<stack<int>> answers;
        answers.push_back(theRegions);
        answers.push_back(nbTokens);
        
        return answers;
        
    }
    
    string getName()override{return name;}
private:
    string name="defensive AI is thinking";
};


//////////////////////////////////////////////////////////////////////////////////////////


class moderateAI:public AI{
public:

    //Picks power and race combo that is has medium aggressivepoints
    int pickPowerRace(vector <RaceBanner*> races,vector <PowerBadge*> powers)override{
        
        std::array<int,MAX_NUMBER_PICKABLE_RACES> aggressivePoints;
        
        for(int i=0;i<MAX_NUMBER_PICKABLE_RACES;i++){
            
            int test=races[i]->getAggressivePoint()+powers[i]->getAggressivePoint();
            aggressivePoints[i]=races[i]->getAggressivePoint()+powers[i]->getAggressivePoint();
            cout<<races[i]->getName()<<powers[i]->getPowerName()<<" :tot Aggressive Points: " <<test<<endl;
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
    int aiConquers(Player* aiPlayer, vector<MapRegion*> regions)override{
        
        cout<<"defensive ai picking vertex to attack"<<endl;
        std::vector<int> tempVector;
        for (size_t i = 0; i < regions.size(); i++) {
            
            if(aiPlayer!=regions[i]->getOwner()){
                tempVector.push_back(regions[i]->getNbTokens());
                cout<<"Index vertex "<<regions[i]->getIndexOfVertex()<<endl;
                cout<<"Nb enemy tokens"<<regions[i]->getNbTokens()<<endl;
            }
        }
        
        std::sort(tempVector.begin(),tempVector.end());
        
        int nbEnemyTokens=tempVector[0];
        
        for (size_t i = 0; i < regions.size(); i++) {
            
            if(aiPlayer!=regions[i]->getOwner()&&nbEnemyTokens==regions[i]->getNbTokens()){
                cout<<"defensive Ai chose"<<regions[i]->getIndexOfVertex()<<endl;
                return regions[i]->getIndexOfVertex();
            }
        }
        
        return 0;
    }
    
    string getName()override{return name;}
private:
    string name="moderate AI is thinking";
};

//////////////////////////////////////////////////////////////////////////////////////////


class randomAI:public AI{
public:
    
    //Picks randomly the power and race combo
    int pickPowerRace(vector <RaceBanner*> races,vector <PowerBadge*> powers)override{
        int randomPick=(rand() % 6)+1;
        return randomPick;
    }
    
    //Picks region to conquer randomly
    int aiConquers(Player* aiPlayer, vector<MapRegion*> regions)override{
        
        cout<<"random ai picking vertex to attack"<<endl;
        std::vector<int> tempVector;
        for (size_t i = 0; i < regions.size(); i++) {
            
            if(aiPlayer!=regions[i]->getOwner()){
                tempVector.push_back(regions[i]->getIndexOfVertex());
                cout<<"Index vertex "<<regions[i]->getIndexOfVertex()<<endl;
            }
        }
        
        std::sort(tempVector.begin(),tempVector.end());
        
        int nbChoices=tempVector.size();
       
        int randomChoice=(rand() % nbChoices);
        
        cout<<"random ai chose  "<<tempVector[randomChoice]<<endl;
        
        return tempVector[randomChoice];
       
    }
    
    string getName()override{return name;}
private:
    string name="random AI is thinking";
};

//#endif __AI_H__
