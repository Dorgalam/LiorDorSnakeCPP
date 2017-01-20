#ifndef _CREATURE_H
#define _CREATURE_H
#include "Point.h"
#include "Color.h"

class TheSnakesGame;
class Creature
{
<<<<<<< HEAD
protected:
=======
public:
>>>>>>> master
	Point p;
	char symbol;
	int dir;
	TheSnakesGame * game;
public:
	Creature(const Point _p, const char sym, const int _dir, TheSnakesGame* _theGame) :p(_p), symbol(sym), dir(_dir),game(_theGame) {}
<<<<<<< HEAD
	void setPoint(Point _p) { p = _p; }
	Point getPoint() { return p; }
	void setDir(int direction) { dir = direction; }
	virtual void move();
	void clearCr();
	virtual void setSuspend(bool newState)=0;
	virtual bool isSuspend() = 0;
=======
	void setDir(int direction) { dir = direction; }
	virtual void move();
	virtual void setSuspend(bool newState)=0;
>>>>>>> master
	void setG(TheSnakesGame* _theGame) {
		game = _theGame;
	}
	

};
#endif