#ifndef _COLFLY_H_
#define _COLFLY_H_
#include "creature.h"

class TheSnakesGame;
class ColFly :public Creature
{
	bool ChangingSides;
	bool suspend;

public:
	ColFly(TheSnakesGame *g, Point p, bool sidetoside, int d) : suspend(false),ChangingSides(sidetoside), Creature(p, '$', d, g) {}
	~ColFly() {}
	virtual void move();
<<<<<<< HEAD
	virtual bool isSuspend() { return suspend; }
=======
>>>>>>> master
	virtual void setSuspend(bool newState) { suspend = newState; }

};
#endif