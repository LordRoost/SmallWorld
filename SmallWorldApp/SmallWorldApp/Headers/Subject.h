#ifndef __SUBJECT_H__
#define __SUBJECT_H__
#pragma once
#include "Observer.h"
#include <list>

class Subject {
public:
	virtual void Attach(Observer* o);
	virtual void Detach(Observer* o);
	virtual void Notify(); //Calls all attached observer's update function
	Subject();
	~Subject();

private:
	std::list<Observer*> *_observers; //list of attached observers

};

#endif //__SUBJECT_H__