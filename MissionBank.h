#ifndef _MISSIONBANK_H
#define _MISSIONBANK_H
#include "io_utils.h"
#include <vector>
#include "randNumbers.h"
class Menu;
enum {FreeSpace = -1};
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
		strcpy(mission,strtok(mission, ":"));
		strcat(mission, ": ");
	}
	void SetMission(vector <int> numsVec);//AFTER GETTING THE NUMBERS setting the mission with current random numbers
	char* getMission(){	return mission;}
	virtual bool isCorrectNum(int x)=0;
	virtual vector <int> PickNums() = 0;
	vector <char> castingOP();
	//virtual bool helperMath(vector <char> op, vector <int>nums) = 0;
	virtual bool isValid(vector <int>nums, vector <int> xPlace) = 0;
	virtual void makeValidExe() = 0;
	virtual bool calculate(vector<int >nums, vector <char> op) = 0;
	bool calculate2(vector<int >nums, vector <char> op);

	//virtual bool calculate1op(vector<int >nums, vector <char> op) = 0;
	//virtual bool calculate2op(vector<int >nums, vector <char> op) = 0;

};
#endif