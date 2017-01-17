#ifndef _FIVEOP_H
#define _FIVEOP_H
#include "io_utils.h"
#include <vector>
#include <string>
#include "MissionBank.h"


class fiveOP : public MissionBank {
protected:
	vector <int> numsVec;//save the current numbers that picked randomaly
	vector <int> xPlace;//save the places that for the user to choose the answer
public:
	fiveOP(char *str, Menu *menu, vector <char*> nums, vector <char*> op) :MissionBank(str, menu, nums, op) {}
	~fiveOP() { numsVec.clear(); }
	virtual void initMis();//this function init empty mission
	virtual bool isCorrectNum(int x);//this function get number and put it in x places and check if correct 
	virtual vector <int> PickNums();//making the exe - with numbers
	
	virtual bool isValid(vector <int>nums, vector <int> xPlace);//checking if there is any correct answer from therange of numbers

	virtual void makeValidExe();//checking validation of the exe and build the string
						

	virtual bool calculate(vector<int >nums, vector <char> op);
};

#endif 

