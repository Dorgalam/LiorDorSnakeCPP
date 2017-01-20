#ifndef _NUMBEREATER_H
#define _NUMBEREATER_H
#include "Creature.h"
class TheSnakesGame;
class numberEater :public Creature
{
	bool suspend;

public:
	numberEater(TheSnakesGame *g, Point p) :suspend(false), Creature(p, '%', 4, g) {}
	~numberEater() {}
	virtual void move();
	virtual void setSuspend(bool newState) { suspend=newState; }
	virtual bool isSuspend() { return suspend; }
	void setDraw();

};

#endif