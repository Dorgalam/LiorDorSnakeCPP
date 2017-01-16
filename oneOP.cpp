#include "oneOP.h"

void oneOP::initMis()
{
	numsVec.clear();
	xPlace.clear();
	initMis();
}

bool oneOP::isCorrectNum(int x)
{
	vector<int> nums = numsVec;
	for (int p = 0; p < xPlace.size(); p++)
	{//put the number in x spot
		int j = *(xPlace.begin() + p);
		nums[j] = x;
	}
	return calculate(nums, op);
}
vector <int> oneOP::PickNums()
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

bool oneOP::isValid(vector <int>nums, vector <int> xPlace)
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
void oneOP::makeValidExe()
{//checking validation of the exe
 //vector<int> xPlace;
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
		good = isValid (nums, xPlace);
	}
	numsVec = nums;//save the correct exe
	SetMission(numsVec);
}
bool oneOP::calculate(vector<int >nums, vector <char> op)
{
	switch (op[0])
	{
	case '<':
		return nums[0] < nums[1];
		break;
	case '>':
		return nums[0] > nums[1];
		break;
	case '=':
		return nums[0] == nums[1];
		break;
	case '!':
		return nums[0] != nums[1];
	default: return false;  break;

	}
}