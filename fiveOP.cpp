#include "fiveOP.h"

void fiveOP::initMis()
{
	numsVec.clear();
	xPlace.clear();
	initMis();
}

bool fiveOP::isCorrectNum(int x)
{
	vector<int> nums = numsVec;
	for (int p = 0; p < xPlace.size(); p++)
	{//put the number in x spot
		int j = *(xPlace.begin() + p);
		nums[j] = x;
	}
	return calculate(nums, op);
}
vector <int> fiveOP::PickNums()
{//making the exe - with numbers
	vector <int> nums;
	for (int j = 0; j < numbers.size(); j++)
	{
		if (strcmp(numbers[j], "X") == 0)
			nums.push_back(FreeSpace);
		else if (strcmp(numbers[j], "A") >= 0 && strcmp(numbers[j], "Z") <= 0)
			nums.push_back(rand() % 169 + 1);
		else
			nums.push_back(stoi(numbers[j]));

	}
	return nums;
}


bool fiveOP::isValid( vector <int>nums, vector <int> xPlace)
{//checking if there is a correct answer
	for (int i = 1; i < 170; i++)
	{
		for (int p = 0; p < xPlace.size(); p++)
		{//put the number in x spot
			int j = *(xPlace.begin() + p);
			nums[j] = i;
		}
		if (calculate(nums, op))
			return true;
	}
	return false;
}
void fiveOP::makeValidExe()
{//checking validation of the exe
	vector <int>nums;
	bool good = false;
	while (!good)
	{
		nums = PickNums();//get random numbers
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == FreeSpace)
				xPlace.push_back(i);
		}
		good = isValid(nums, xPlace);
	}
	numsVec = nums;//save the correct exe
	SetMission(numsVec);
}
bool fiveOP::calculate(vector<int >nums, vector <char> op)
{//calculate the exe - virtual by the numbers of op
	vector <char> op1;
	vector <int>nums1;
	op1.push_back(op[3]);
	op1.push_back(op[4]);
	nums1.push_back(nums[3]);
	nums1.push_back(nums[4]);
	nums1.push_back(nums[5]);
	if (op[2] == '&')
		return (calculate2(nums, op) && calculate2(nums1, op1));
	else
		return (calculate2(nums, op) || calculate2(nums1, op1));
}