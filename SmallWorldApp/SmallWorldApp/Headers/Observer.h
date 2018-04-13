#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#pragma once

class Observer {
public:
	~Observer();
	virtual void Update() = 0;

protected:
	Observer();
};

#endif //__OBSERVER_H__