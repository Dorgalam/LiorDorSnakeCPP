#ifndef _MISSION_H
#define _MISSION_H
#include "io_utils.h"

enum {
	PRIME, DIV4, DIV7, IS_SQUARE, DIV7REM3, IS169,ISPALINDROM,UNKNOWN_QUE
};
enum { FreeSpace = -1 };//the free space for the number

//mission class, keeps track of and checks mission status

class Menu;

class Mission {
	int currMission;
	Menu *theMenu;
	char *mission7;
public:
	void startMission();
	int getMission() { return currMission; }
	//given the answer of one of the players, return true iff the number fits mission requirements
	bool isPrime(int n);//0
	bool div4(int n) { return n % 4 == 0; }//1
	bool div7(int n) { return n % 7 == 0; }//2
	bool isSquare(int n) { return (int)sqrt(n) == (sqrt(n)); }//3
	bool div7rem3(int n) { return n % 7 == 3; }//4
	bool is169(int n) { return n == 169; }//5
	bool isPalindrom(int n);//6 - palindrom number is 131 in example
	void getNums(char *str, int nums[]);//get the numbers from the string
	void getOP(char *str, char ops[]);//get the operators from the string
	bool mathExe(int n);//7
	bool helperMath(int nums[], char op1, char op2);//calculate the solution of the mission 
	void set7(char * str)
	{//set mission number 7 string 
		mission7 = new char[25];
		strcpy(mission7, str);
	}
	void free7()//free the string of the mission number 7 after finish the mission
	{
		free(mission7);
	}
};

#endif // !_MISSION_H
