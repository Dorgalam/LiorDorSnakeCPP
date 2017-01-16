#include "threeOP.h"

void threeOP::initMis()
{
	numsVec.clear();
	xPlace.clear();
	initMis();
}

bool threeOP::isCorrectNum(int x)
{
	//vector<char> op;
	vector<int> nums = numsVec;
	for (int p = 0; p < xPlace.size(); p++)
	{//put the number in x spot
		int j = *(xPlace.begin() + p);
		nums[j] = x;
	}
	return calculate(nums, op);
}
vector <int> threeOP::PickNums()
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

bool threeOP::isValid(vector <int>nums, vector <int> xPlace)
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
void threeOP::makeValidExe()
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
bool threeOP::calculate(vector<int >nums, vector <char> op)
{
	
	switch (op[0])
	{
	case '<'://op[1] must be && or ||
		switch (op[1])
		{
		case '&':
			switch (op[2])
			{
			case '<':
				return nums[0] < nums[1] && nums[2] < nums[3];
			case '>':
				return nums[0] < nums[1] && nums[2] > nums[3];
			}
		case '|':
			switch (op[2])
			{
			case '<':
				return nums[0] < nums[1] || nums[2] < nums[3];
			case '>':
				return nums[0] < nums[1] || nums[2] > nums[3];
			}
		}
	case '>'://op[1] must be && or ||
		switch (op[1])
		{
		case '&':
			switch (op[2])
			{
			case '<':
				return nums[0] > nums[1] && nums[2] < nums[3];
			case '>':
				return nums[0] > nums[1] && nums[2] > nums[3];
			}
		case '|':
			switch (op[2])
			{
			case '<':
				return nums[0] > nums[1] || nums[2] < nums[3];
			case '>':
				return nums[0] > nums[1] || nums[2] > nums[3];
			}
		}
	case '+'://the next must be = , so we skip to op 2
		switch (op[2])
		{
		case '+':
			return (nums[0] + nums[1] == nums[2] + nums[3]);
		case '-':
			return (nums[0] + nums[1] == nums[2] - nums[3]);
		case '*':
			return (nums[0] + nums[1] == nums[2] * nums[3]);
		case '/':
			return (nums[0] + nums[1] == nums[2] / nums[3]);
		case '^':
			return (nums[0] + nums[1] == pow(nums[2], nums[3]));
		case '%':
			return (nums[0] + nums[1] == nums[2] % nums[3]);
		}
	case '-':
		switch (op[2])
		{
		case '+':
			return (nums[0] - nums[1] == nums[2] + nums[3]);
		case '-':
			return (nums[0] - nums[1] == nums[2] - nums[3]);
		case '*':
			return (nums[0] * nums[1] == nums[2] * nums[3]);
		case '/':
			return (nums[0] / nums[1] == nums[2] / nums[3]);
		case '^':
			return (nums[0] ^ nums[1] == pow(nums[2], nums[3]));
		case '%':
			return (nums[0] % nums[1] == nums[2] % nums[3]);
		}
	case '*':
		switch (op[2])
		{
		case '+':
			return (nums[0] * nums[1] == nums[2] + nums[3]);
		case '-':
			return (nums[0] * nums[1] == nums[2] - nums[3]);
		case '*':
			return (nums[0] * nums[1] == nums[2] * nums[3]);
		case '/':
			return (nums[0] * nums[1] == nums[2] / nums[3]);
		case '^':
			return (nums[0] * nums[1] == pow(nums[2], nums[3]));
		case '%':
			return (nums[0] * nums[1] == nums[2] % nums[3]);
		}
	case '/':
		switch (op[2])
		{
		case '+':
			return (nums[0] * nums[1] == nums[2] + nums[3]);
		case '-':
			return (nums[0] * nums[1] == nums[2] - nums[3]);
		case '*':
			return (nums[0] * nums[1] == nums[2] * nums[3]);
		case '/':
			return (nums[0] * nums[1] == nums[2] / nums[3]);
		case '^':
			return (nums[0] * nums[1] == pow(nums[2], nums[3]));
		case '%':
			return (nums[0] * nums[1] == nums[2] % nums[3]);
		}
	case '^':
		switch (op[2])
		{
		case '+':
			return (nums[0] * nums[1] == nums[2] + nums[3]);
		case '-':
			return (nums[0] * nums[1] == nums[2] - nums[3]);
		case '*':
			return (nums[0] * nums[1] == nums[2] * nums[3]);
		case '/':
			return (nums[0] * nums[1] == nums[2] / nums[3]);
		case '^':
			return (nums[0] * nums[1] == pow(nums[2], nums[3]));
		case '%':
			return (nums[0] * nums[1] == nums[2] % nums[3]);
		}
	case '%':
		switch (op[2])
		{
		case '+':
			return (nums[0] % nums[1] == nums[2] + nums[3]);
		case '-':
			return (nums[0] % nums[1] == nums[2] - nums[3]);
		case '*':
			return (nums[0] % nums[1] == nums[2] * nums[3]);
		case '/':
			return (nums[0] % nums[1] == nums[2] / nums[3]);
		case '^':
			return (nums[0] % nums[1] == pow(nums[2], nums[3]));
		case '%':
			return (nums[0] % nums[1] == nums[2] % nums[3]);
		}
	case '=':
		switch (op[1])
		{
		case '+':
			switch (op[2])
			{
			case '+':
				return (nums[0] == nums[1] + nums[2] + nums[3]);
			case '-':
				return (nums[0] == nums[1] + nums[2] - nums[3]);
			case '*':
				return (nums[0] == nums[1] + nums[2] * nums[3]);
			case '/':
				return (nums[0] == nums[1] + nums[2] / nums[3]);
			case '^':
				return (nums[0] == nums[1] + pow(nums[2], nums[3]));
			case '%':
				return (nums[0] == nums[1] + nums[2] % nums[3]);
			}
		case '-':
			switch (op[2])
			{
			case '+':
				return (nums[0] == nums[1] - nums[2] + nums[3]);
			case '-':
				return (nums[0] == nums[1] - nums[2] - nums[3]);
			case '*':
				return (nums[0] == nums[1] - nums[2] * nums[3]);
			case '/':
				return (nums[0] == nums[1] - nums[2] / nums[3]);
			case '^':
				return (nums[0] == nums[1] - pow(nums[2], nums[3]));
			case '%':
				return (nums[0] == nums[1] - nums[2] % nums[3]);
			}
		case '*':
			switch (op[2])
			{
			case '+':
				return (nums[0] == nums[1] * nums[2] + nums[3]);
			case '-':
				return (nums[0] == nums[1] * nums[2] - nums[3]);
			case '*':
				return (nums[0] == nums[1] * nums[2] * nums[3]);
			case '/':
				return (nums[0] == nums[1] * nums[2] / nums[3]);
			case '^':
				return (nums[0] == nums[1] * pow(nums[2], nums[3]));
			case '%':
				return (nums[0] == nums[1] * nums[2] % nums[3]);
			}
		case '/':
			switch (op[2])
			{
			case '+':
				return (nums[0] == nums[1] / nums[2] + nums[3]);
			case '-':
				return (nums[0] == nums[1] / nums[2] - nums[3]);
			case '*':
				return (nums[0] == nums[1] / nums[2] * nums[3]);
			case '/':
				return (nums[0] == nums[1] / nums[2] / nums[3]);
			case '^':
				return (nums[0] == nums[1] / pow(nums[2], nums[3]));
			case '%':
				return (nums[0] == nums[1] / nums[2] % nums[3]);
			}
		case '^':
			switch (op[2])
			{
			case '+':
				return (nums[0] == pow(nums[1], nums[2]) + nums[3]);
			case '-':
				return (nums[0] == pow(nums[1], nums[2]) - nums[3]);
			case '*':
				return (nums[0] == pow(nums[1], nums[2]) * nums[3]);
			case '/':
				return (nums[0] == pow(nums[1], nums[2]) / nums[3]);
				//case '^':
				//	return (nums[0] == nums[1] ^ nums[2] ^ nums[3]);
				//case '%':
				//	return (nums[0] == pow(nums[1], nums[2] % nums[3]));
			}
		case '%':
			switch (op[2])
			{
			case '+':
				return (nums[0] == nums[1] % nums[2] + nums[3]);
			case '-':
				return (nums[0] == nums[1] % nums[2] - nums[3]);
			case '*':
				return (nums[0] == nums[1] % nums[2] * nums[3]);
			case '/':
				return (nums[0] == nums[1] % nums[2] / nums[3]);
				//case '^':
				//	return (nums[0] == (int)pow((nums[1] % nums[2]),nums[3]));
			case '%':
				return (nums[0] == nums[1] % nums[2] % nums[3]);
			}
		}
	case '!':
		switch (op[1])
		{
		case '+':
			switch (op[2])
			{
			case '+':
				return (nums[0] != nums[1] + nums[2] + nums[3]);
			case '-':
				return (nums[0] != nums[1] + nums[2] - nums[3]);
			case '*':
				return (nums[0] != nums[1] + nums[2] * nums[3]);
			case '/':
				return (nums[0] != nums[1] + nums[2] / nums[3]);
			case '^':
				return (nums[0] != nums[1] + pow(nums[2], nums[3]));
			case '%':
				return (nums[0] != nums[1] + nums[2] % nums[3]);
			}
		case '-':
			switch (op[2])
			{
			case '+':
				return (nums[0] != nums[1] - nums[2] + nums[3]);
			case '-':
				return (nums[0] != nums[1] - nums[2] - nums[3]);
			case '*':
				return (nums[0] != nums[1] - nums[2] * nums[3]);
			case '/':
				return (nums[0] != nums[1] - nums[2] / nums[3]);
			case '^':
				return (nums[0] != nums[1] - pow(nums[2], nums[3]));
			case '%':
				return (nums[0] != nums[1] - nums[2] % nums[3]);
			}
		case '*':
			switch (op[2])
			{
			case '+':
				return (nums[0] != nums[1] * nums[2] + nums[3]);
			case '-':
				return (nums[0] != nums[1] * nums[2] - nums[3]);
			case '*':
				return (nums[0] != nums[1] * nums[2] * nums[3]);
			case '/':
				return (nums[0] != nums[1] * nums[2] / nums[3]);
			case '^':
				return (nums[0] != nums[1] * pow(nums[1], nums[2]));
			case '%':
				return (nums[0] != nums[1] * nums[2] % nums[3]);
			}
		case '/':
			switch (op[2])
			{
			case '+':
				return (nums[0] != nums[1] / nums[2] + nums[3]);
			case '-':
				return (nums[0] != nums[1] / nums[2] - nums[3]);
			case '*':
				return (nums[0] != nums[1] / nums[2] * nums[3]);
			case '/':
				return (nums[0] != nums[1] / nums[2] / nums[3]);
			case '^':
				return (nums[0] != nums[1] / pow(nums[1], nums[2]));
			case '%':
				return (nums[0] != nums[1] / nums[2] % nums[3]);
			}
		case '^':
			switch (op[2])
			{
			case '+':
				return (nums[0] != pow(nums[1], nums[2]) + nums[3]);
			case '-':
				return (nums[0] != pow(nums[1], nums[2]) - nums[3]);
			case '*':
				return (nums[0] != pow(nums[1], nums[2]) * nums[3]);
			case '/':
				return (nums[0] != pow(nums[1], nums[2]) / nums[3]);
				//case '^':
				//	return (nums[0] != nums[1] ^ pow(nums[1], nums[2]));
				//case '%':
				//	return (nums[0] != (int)pow(nums[1], nums[2]) % nums[3]);
			}
		case '%':
			switch (op[2])
			{
			case '+':
				return (nums[0] != nums[1] % nums[2] + nums[3]);
			case '-':
				return (nums[0] != nums[1] % nums[2] - nums[3]);
			case '*':
				return (nums[0] != nums[1] % nums[2] * nums[3]);
			case '/':
				return (nums[0] != nums[1] % nums[2] / nums[3]);
				//case '^':
				//	return (nums[0] != nums[1] % nums[2] ^ nums[3]);
			case '%':
				return (nums[0] != nums[1] % nums[2] % nums[3]);
			}
		}
	default:return false; break;
	}
}