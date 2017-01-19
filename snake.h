
#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <cstring>
#include "Point.h"
#include <fstream>
#include <vector>
//#include "Mission.h"
#include "Bullet.h"
class TheSnakesGame;
class MissionBank;
class Snake {
	enum { SIZE = 5 };

	//int size;
	vector<Point> body;
	int direction; // TODO: use enum!
	char arrowKeys[4];
	Color color;
	MissionBank **m;
	TheSnakesGame* theGame = nullptr;
	char symbol;
	char ShootKey;
	bool stuck;
	bool suspended = false;
	int numBul = 5;
public:
	Snake(int dir, unsigned int size, char _symbol, Point start, Color c, char Skey,MissionBank **_m)
		: symbol(_symbol),m(_m)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			body.push_back(start);
		}
		setColor(c);
		direction = dir;
		ShootKey = Skey;
	
	}
	void setM(MissionBank **_m)
	{
		m = _m;
	}
	void setBank(MissionBank ** _m)
	{
		m = _m;
	}
	~Snake()
	{
		body.clear();
	}
	
	void newSnake(int x, int y, int dir);
	char getSymbol() {
		return this->symbol;
	}

	void setGame(TheSnakesGame* _theGame) {
		theGame = _theGame;
	}
	//void setPosition(int y, int x);
	void setArrowKeys(const char* keys);
	void setColor(Color c) {
		color = c;
	}

	Color getColor() {return color;}
	int move(char opSymbol, int numOfMission);//handle the movement of the snake and checking that he's move to a free and legit place 
	int getDirection(char key);//handle and adjust char direction input to int direction 
	int getDirection() {return direction;}//get the current direction of the snake
	void setDirection(int dir) {direction = dir; }
	int getSize() { return body.size(); }
	bool goodNum(int numMission, int num);//checking if the number meets the mission requirements
	void snakeGrow(){body.push_back(body[body.size() - 1]);}
	void backToStart(int x, int y, int dir = 4);
	void clearSnake();//clear the snake from the board
	bool checkNotSnake(Snake *s, Point p);//check that the snake's body is not in this point
	void findFreeSpot(Snake *s);//this function find a free spot for the snake on the board
	void clearBody() {//delete the body of the snake
		for (unsigned int i = 0; i < body.size(); i++)
			body.pop_back();
	}
	void setMission(MissionBank** gameM) { m = gameM; }
	char getShoot() { return ShootKey; }

	void Setsuspend(bool s) {
		suspended = s;
	}
	void setBul(int n) { numBul = n; updateBullets(); }
	bool isSuspend() { return suspended; }
	Point getbodyPlace() { return Point(body[0].getX(), body[0].getY()); }
	void addBullet() { numBul++; updateBullets(); }
	bool deleteBullet();
	void updateBullets();
};

#endif
