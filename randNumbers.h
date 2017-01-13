#ifndef _RANDNUMBERS_H
#define _RANDNUMBERS_H

#include "Point.h"
#include <vector>
#include "Mission.h"

struct numCoord {
	int num;
	int len;
	Point p;
};
class TheSnakesGame;
class Mission;
class randNumbers {
	vector<numCoord> numVec; //saves all on board random values
	Mission m;  
	TheSnakesGame *game;
public:
	randNumbers(TheSnakesGame *_game): game(_game) {} //constructor, just put game's value inside
	
	int generateNumber(); //creates a random as required
	numCoord randNumbers::findSpot(); //find a suitable spot in the board
	int getSize() { if (numVec.empty())return 0; return numVec.size(); } //just to pipe value forward
	bool checkSpot(const int& x, const int& y, const int& len); //checks if a specific spot on the board is suitable
	void addNumber();//add the generated number to the vector
	int whatNum(const Point &p); //given a point, returns the number that sits inside
	void removeHalf(); //removes half of the nubmers from the board, the vector and the actual screen
	bool goodNum(int numMission, int num);//checks if the number fits the mission requirements
	bool showNumbers(int num);//shows the numbers that fit the mission
	void removeAll(); //removes all numbers from vec/board etc
	void DeleteNum(const Point& p);
	int countSteps(const Point& p1, const Point& p2);
	int findCloseNum(const Point& p);
};



#endif // !_RANDNUMBERS_H
