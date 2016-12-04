
#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <cstring>
#include "Point.h"
#include <vector>

class TheSnakesGame;

class Snake {
	enum { SIZE = 5 };
	int size;
	vector<Point> body;
	int direction = 3; // TODO: use enum!
	char arrowKeys[4];
	Color color;
	TheSnakesGame* theGame;
	char symbol;
public:
	Snake(unsigned int size, char _symbol, Point start, Color c)
		: symbol(_symbol)
	{
		this->size = size;
		for (int i = 0; i < size; i++)
		{
			body.insert(body.end(), start);
			//body.push_back(start);
		}
		setColor(c);
	}
	~Snake()
	{
		body.clear();
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
	void move();
	int getDirection(char key);
	void setDirection(int dir) {
		direction = dir;
	}

};

#endif