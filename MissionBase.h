#ifndef _MISSIONBASE_H
#define _MISSIONBASE_H
#include "io_utils.h"
#include <vector>
#include <string>
#include "MissionBank.h"
//enum { FreeSpace = -1 };

class MissionBase : public MissionBank {
protected:
	//Menu *theMenu;
	vector <char*> numbers;
	vector <int> numsVec;
	vector <char*> operators;
	vector <int> xPlace;
	//char *menuStr;
public:
	MissionBase(char *str, Menu *menu) :MissionBank(str, menu)
	{
		char *line = new char[sizeof(char) * 80];
		operators.push_back("dummy");
		strcpy(line, str);
		strtok(line, ":");
		while (operators.back() != NULL)
		{
			numbers.push_back(strtok(NULL, " "));
			operators.push_back(strtok(NULL, " "));
		}
		operators.erase(operators.begin() + 0);
		operators.erase(operators.begin() + operators.size() - 1);
	}
	~MissionBase()
	{
		numsVec.clear();
	}
	void initMis();
	
	void setMission();//AFTER GETTING THE NUMBERS
	bool isCorrectNum(int x);
	vector <int> PickNums();//making the exe - with numbers
	vector <char> castingOP();
	bool helperMath(vector <char> op, vector <int>nums);
	bool isValid(vector<char> op, vector <int>nums, vector <int> xPlace);//checking if there is a correct answer

	void makeValidExe();//checking validation of the exe
		//vector<int> xPlace;
	
	bool calculate1op(vector<int >nums, vector <char> op);
	bool calculate2op(vector<int >nums, vector <char> op);//calculate the exe - virtual by the numbers of op
	
	bool calculate3op(vector<int >nums, vector <char> op);//calculate the exe - virtual by the numbers of op
};

#endif 
