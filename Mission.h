#ifndef _MISSION_H
#define _MISSION_H
#include "io_utils.h"

enum {
	PRIME, DIV4, DIV7, IS_SQUARE, DIV7REM3, IS169
};

class Menu;

class Mission {
	int currMission;
	Menu *theMenu;
public:
	void startMission();


	bool isPrime(int n);
	bool div4(int n) { return n % 4 == 0; }
	bool div7(int n) { return n % 7 == 0; }
	bool isSquare(int n) { return (int)sqrt(n) == (sqrt(n)); }
	bool div7rem3(int n) { return n % 7 == 3; }
	bool is169(int n) { return n == 169; }



	bool isPalindrom(int n)//put explanation about this task:polyndrom number is 131 in example
	{
		if (n < 10)
			return true;
		else if (n<100)
			return n % 10 == n / 10 ? true : false;
		else
			return n / 100 == n % 10 ? true : false;
	}
	bool is5plusSqrt121(int n)
	{
		return n == 16 ? true : false;
	}
};

#endif // !_MISSION_H
