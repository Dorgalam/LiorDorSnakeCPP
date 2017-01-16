#ifndef _TWOOP_H
#define _TWOOP_H
#include "io_utils.h"
#include <vector>
#include <string>
#include "MissionBank.h"


class twoOP : public MissionBank {
protected:
	vector <int> numsVec;
	vector <int> xPlace;
public:
	twoOP(char *str, Menu *menu, vector <char*> nums, vector <char*> op) :MissionBank(str, menu, nums, op) {}
	~twoOP() { numsVec.clear(); }
	virtual void initMis();
	virtual bool isCorrectNum(int x);
	virtual vector <int> PickNums();//making the exe - with numbers
	//bool helperMath(vector <char> op, vector <int>nums) = 0;
	virtual bool isValid(vector <int>nums, vector <int> xPlace);//checking if there is a correct answer

	virtual void makeValidExe();//checking validation of the exe
						//vector<int> xPlace;

	virtual bool calculate(vector<int >nums, vector <char> op);
};

#endif 
