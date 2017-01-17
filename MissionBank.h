#ifndef _MISSIONBANK_H
#define _MISSIONBANK_H
#include "io_utils.h"
#include <vector>
#include "randNumbers.h"
class Menu;
enum {FreeSpace = -1};//free space is for the user selection(x places)
class MissionBank {
protected:
	char *mission; // string missions
	Menu *theMenu;
	vector <char*> numbers;
	vector <char*> operators;
	vector <char> op;
public:
	MissionBank(char * str, Menu *m, vector <char*> nums, vector <char*> ops) :theMenu(m), numbers(nums) ,operators(ops)
	{
		op = castingOP();//init the operators vector
		mission = new char[strlen(str)+10];
		strcpy(mission, str);
	}
	void initMis()
	{
		strcpy(mission, strtok(mission, ":"));
		strcat(mission, ": ");
	}
	~MissionBank() 
	{
		operators.clear();
		op.clear(); numbers.clear();
		//strcpy(mission,strtok(mission, ":"));
		//strcat(mission, ": ");
	}
	void SetMission(vector <int> numsVec);//AFTER GETTING THE NUMBERS setting the mission with current random numbers
	char* getMission(){	return mission;}
	virtual bool isCorrectNum(int x)=0;//this function get number and put it in x places and check if correct
	virtual vector <int> PickNums() = 0;//this function generate the numbers randomaly
	vector <char> castingOP();//casting the operators to char 
	virtual bool isValid(vector <int>nums, vector <int> xPlace) = 0;
	virtual void makeValidExe() = 0;//making the exe - with numbers
	virtual bool calculate(vector<int >nums, vector <char> op) = 0;//virtual function in each derived calculate appropriatly 
	bool calculate2(vector<int >nums, vector <char> op);//calculation of 2 operators - in here because common function to two derived classes

};
#endif