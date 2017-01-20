
#ifndef _LINEFLY_H_
#define _LINEFLY_H_
#include "Creature.h"//parent

class TheSnakesGame;
class LineFly :public Creature
{
	bool ChangingSides;

public:
	//LineFly():Creature(Point(), '!', 4, nullptr) {}
	LineFly(TheSnakesGame *g,Point p,bool sidetoside,int d) : ChangingSides(sidetoside),Creature(p, '!', d, g) {}
	~LineFly() {}
	virtual void move();
	virtual bool isSuspend() { return false; }
	virtual void setSuspend(bool newState) { return; }

};
#endif