#ifndef __AI_H__
#define __AI_H__
#pragma once

#include <algorithm>
#include <iostream>
#include <list>
#include "Dice.h"
#include "Tokens.h"
#include "Game.h"
#include "Map.h"
#include "PlayGame.h"



class AI{
public:

    virtual int pickPowerRace(vector <RaceBanner*> races,vector <PowerBadge*> powers)=0;
    virtual string getName(){return name;};

private:
    string name="AI";
};


//////////////////////////////////////////////////////////////////////////////////////////



class aggressiveAI:public AI{
public:
    int pickPowerRace(vector <RaceBanner*> races,vector <PowerBadge*> powers)override{
        
        std::array<int,MAX_NUMBER_PICKABLE_RACES> aggressivePoints;
        
        for(int i=0;i<MAX_NUMBER_PICKABLE_RACES;i++){
            
            int test=races[i]->getAggressivePoint()+powers[i]->getAggressivePoint();
            aggressivePoints[i]=races[i]->getAggressivePoint()+powers[i]->getAggressivePoint();
            cout<<races[i]->getName()<<powers[i]->getPowerName()<<":::::::" <<test<<endl;
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
    virtual string getName()override{return name;};
private:
    string name="aggressive AI is thinking";
};



//////////////////////////////////////////////////////////////////////////////////////////



class defensiveAI:public AI{
public:
    int pickPowerRace(vector <RaceBanner*> races,vector <PowerBadge*> powers)override{
        
        std::array<int,MAX_NUMBER_PICKABLE_RACES> aggressivePoints;
        
        for(int i=0;i<MAX_NUMBER_PICKABLE_RACES;i++){
            
            int test=races[i]->getAggressivePoint()+powers[i]->getAggressivePoint();
            aggressivePoints[i]=races[i]->getAggressivePoint()+powers[i]->getAggressivePoint();
            cout<<races[i]->getName()<<powers[i]->getPowerName()<<":::::::" <<test<<endl;
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
    virtual string getName()override{return name;};
private:
    string name="defensive AI is thinking";
};


//////////////////////////////////////////////////////////////////////////////////////////


class moderateAI:public AI{
public:

    int pickPowerRace(vector <RaceBanner*> races,vector <PowerBadge*> powers)override{
        
        std::array<int,MAX_NUMBER_PICKABLE_RACES> aggressivePoints;
        
        for(int i=0;i<MAX_NUMBER_PICKABLE_RACES;i++){
            
            int test=races[i]->getAggressivePoint()+powers[i]->getAggressivePoint();
            aggressivePoints[i]=races[i]->getAggressivePoint()+powers[i]->getAggressivePoint();
            cout<<races[i]->getName()<<powers[i]->getPowerName()<<":::::::" <<test<<endl;
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
    virtual string getName()override{return name;};
private:
    string name="moderate AI is thinking";
};

//////////////////////////////////////////////////////////////////////////////////////////


class randomAI:public AI{
public:
    
    int pickPowerRace(vector <RaceBanner*> races,vector <PowerBadge*> powers)override{
        return (rand() % 6)+1;
    }
    virtual string getName()override{return name;};
private:
    string name="random AI is thinking";
};

#endif __AI_H__
