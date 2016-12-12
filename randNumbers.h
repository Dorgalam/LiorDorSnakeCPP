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
class Mission;
class randNumbers {
	vector<numCoord> numVec;
	Mission *m;
	TheSnakesGame *game;
public:
	randNumbers(TheSnakesGame *_game): game(_game) {}
	
	int generateNumber();
	numCoord randNumbers::findSpot();
	int getSize() { return numVec.size(); }
	bool checkSpot(const int& x, const int& y, const int& len);
	void addNumber();
	int whatNum(const Point &p);
	void removeHalf() ;
	bool goodNum(int numMission, int num);
	bool showNumbers(int num);
	void removeAll();
};



#endif // !_RANDNUMBERS_H
