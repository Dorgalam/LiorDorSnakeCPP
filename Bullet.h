
#ifndef _BULLET_H_
#define _BULLET_H_
using namespace std;
#include <cstring>
#include "Point.h"
#include "Color.h"
#include <vector>
#include "randNumbers.h"

class TheSnakesGame;
class Snake;
class Bullet {
	enum { UP = 0, DOWN, LEFT, RIGHT };
	Point p;
	Snake *snakef;
	int direction;
	Color color;
	char symbol = '*';
	TheSnakesGame *G;
public:
	Bullet(TheSnakesGame* _theGame,Snake *father, Point start, int dir = 4, Color c = WHITE) : G (_theGame),p(start), direction(dir), color(c), snakef(father) {};
	void setBullet(Point start, int dir = 4, Color c = WHITE)
	{
		p = start;
		direction = dir;
		color = c;
	}
	void StartMove();//move the point to the next place and update on the board
	int getDir() { return direction; }
	Point getBullet() { return p; }
	Point GetNext() { return p.next(direction); }
	void clearBul();
	void moveB();//delete from board the last place and drawing the new place
	Snake *getfSnake() { return snakef; }
	void setG(TheSnakesGame* _theGame) {
		G = _theGame;
	}
};
#endif