#ifndef _MISSIONBANK_H
#define _MISSIONBANK_H
#include "io_utils.h"
#include <vector>
#include "randNumbers.h"
class Menu;

class MissionBank {
protected:
	char *mission; // string missions
	Menu *theMenu;
public:
	MissionBank(char * str, Menu *m) :theMenu(m)
	{
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
	virtual void SetMission(char * str) {
		strcpy(mission, str);
	}
	char* getMission()
	{
		return mission;
	}
	virtual bool isCorrectNum(int x)=0;
	virtual vector <int> PickNums() = 0;
	virtual vector <char> castingOP() = 0;
	virtual bool helperMath(vector <char> op, vector <int>nums) = 0;
	virtual bool isValid(vector<char> op, vector <int>nums, vector <int> xPlace) = 0;
	virtual void makeValidExe() = 0;
	//virtual bool calculate1op(vector<int >nums, vector <char> op) = 0;
	//virtual bool calculate2op(vector<int >nums, vector <char> op) = 0;

};
#endif