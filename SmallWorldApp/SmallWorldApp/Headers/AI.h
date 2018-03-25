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
    virtual void test(){};
    virtual int pickPowerRace(RaceBanner* races,PowerBadge* powers){return 1;};
private:
};

class aggressiveAI:public AI{
public:
    void test() override{
        cout<<"This is aggressive clase"<<endl;
    } ;
private:
};

class defensiveAI:public AI{
public:
    void test()override{
        cout<<"This is defensive clase"<<endl;
    } ;
private:
};

class moderateAI:public AI{
public:
    void test()override{
        cout<<"This is moderate clase"<<endl;
    };
    int pickPowerRace(RaceBanner* races,PowerBadge* powers)override{
        
        std::array<int,MAX_NUMBER_PICKABLE_RACES> aggressivePoints;
        
        for(int i=0;i<MAX_NUMBER_PICKABLE_RACES;i++){
            aggressivePoints[i]=races[i].getAggressivePoint()+powers[i].getAggressivePoint();
            cout<<"race and power"<<races[i].getName()<<":::::::" <<races[i].getAggressivePoint()+powers[i].getAggressivePoint()<<endl;
            
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
private:
};


#endif //__AI_H__
