
#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <cstring>
#include "Point.h"
#include <vector>
#include "Mission.h"

class TheSnakesGame;

class Snake {
	enum { SIZE = 5 };
	enum { UP = 0, DOWN, LEFT, RIGHT };

	int size;
	vector<Point> body;
	int direction; // TODO: use enum!
	char arrowKeys[4];
	Color color;
	Mission m;
	TheSnakesGame* theGame;
	char symbol;
	bool stuck;
public:
	Snake(int dir,unsigned int size, char _symbol, Point start, Color c)
		: symbol(_symbol)
	{
		this->size = size;
		for (unsigned int i = 0; i < size; i++)
		{
			body.push_back(start);
		}
		setColor(c);
		direction = dir;
	}
	~Snake()
	{
		body.clear();
	}
	void newSnake(int x,int y,int dir)
	{
		Point p;
		p.set(x, y);
		for (int i = 0; i < 3; i++)
		{
			body.push_back(p);
		}
		direction = dir;
		size = 3;
	}
	char getSymbol() {
		return this->symbol;
	}

	void setGame(TheSnakesGame* _theGame) {
		theGame = _theGame;
	}
	//void setPosition(int y, int x);
	void setArrowKeys(const char* keys) {
		arrowKeys[0] = keys[0];
		arrowKeys[1] = keys[1];
		arrowKeys[2] = keys[2];
		arrowKeys[3] = keys[3];
	}
	void setColor(Color c) {
		color = c;
	}
	int move(char opSymbol, int numOfMission);
	int getDirection(char key);
	void setDirection(int dir) {
		direction = dir;
	}
	int getSize() { return size; }
	bool goodNum(int numMission,int num);
	void snakeGrow()
	{
		body.push_back(body[size-1]);
		size++;
	}
	void backToStart(int x,int y,int dir)
	{
		for (int i = 0; i < size; i++)
			body[i].set(x,y);
		direction = dir;
	}
	void clearSnake();
	void clearBody() {
		for (int i = 0; i < size; i++)
			body.pop_back();
		size = 0;
	}
	void getGameM(Mission gameM)
	{
		m = gameM;
	}
};

#endif
