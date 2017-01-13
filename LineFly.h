
#ifndef _LINEFLY_H_
#define _LINEFLY_H_
#include "Creature.h"//parent
//#include "TheSnakesGame.h"//uses game objects and functions
//class Creature;
class TheSnakesGame;
class LineFly :public Creature
{
	bool ChangingSides;

public:
	LineFly():ChangingSides(false), Creature(Point(), '!', 4, nullptr) {}
	LineFly(TheSnakesGame *g,Point p,bool sidetoside,int d) : ChangingSides(sidetoside),Creature(p, '!', d, g) {}
	~LineFly() {}
	virtual void move();
	virtual void setSuspend(bool newState) { return; }

};
#endif