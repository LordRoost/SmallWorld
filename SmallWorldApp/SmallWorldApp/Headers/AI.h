#ifndef __AI_H__
#define __AI_H__
#pragma once

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
private:
};


#endif //__AI_H__
