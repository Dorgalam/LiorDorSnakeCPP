#ifndef _RANDNUMBERS_H
#define _RANDNUMBERS_H

#include "Point.h"
#include <vector>


struct numCoord {
	int num;
	int len;
	Point p;
};
class TheSnakesGame;
class randNumbers {
	vector<numCoord> numVec;
	TheSnakesGame *game;
public:
	randNumbers(TheSnakesGame *_game): game(_game) {}
	
	int generateNumber();
	numCoord randNumbers::findSpot();
	bool checkSpot(const int& x, const int& y, const int& len);
	void addNumber();
	int whatNum(const Point &p);
};



#endif // !_RANDNUMBERS_H
