#ifndef _CREATURE_H
#define _CREATURE_H
#include "Point.h"
#include "Color.h"

class TheSnakesGame;
class Creature
{
public:
	Point p;
	char symbol;
	int dir;
	TheSnakesGame * game;
public:
	Creature(const Point _p, const char sym, const int _dir, TheSnakesGame* _theGame) :p(_p), symbol(sym), dir(_dir),game(_theGame) {}
	void setDir(int direction) { dir = direction; }
	virtual void move();
	virtual void setSuspend(bool newState)=0;
	void setG(TheSnakesGame* _theGame) {
		game = _theGame;
	}
	

};
#endif