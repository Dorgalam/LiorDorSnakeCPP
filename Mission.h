#ifndef _MISSION_H
#define _MISSION_H
#include "io_utils.h"

enum {
	PRIME, DIV4, DIV7, IS_SQUARE, DIV7REM3, IS169,ISPALINDROM
};

//mission class, keeps track of and checks mission status

class Menu;

class Mission {
	int currMission;
	Menu *theMenu;
public:
	void startMission();

	//given the answer of one of the players, return true iff the number fits mission requirements
	bool isPrime(int n);//0
	bool div4(int n) { return n % 4 == 0; }//1
	bool div7(int n) { return n % 7 == 0; }//2
	bool isSquare(int n) { return (int)sqrt(n) == (sqrt(n)); }//3
	bool div7rem3(int n) { return n % 7 == 3; }//4
	bool is169(int n) { return n == 169; }//5
	bool isPalindrom(int n)//6 - put explanation about this task:polyndrom number is 131 in example
	{
		if (n < 10)
			return true;
		else if (n<100)
			return n % 10 == n / 10 ? true : false;
		else
			return n / 100 == n % 10 ? true : false;
	}
};

#endif // !_MISSION_H
