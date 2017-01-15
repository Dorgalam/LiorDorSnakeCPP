#include "MissionBase.h"

void MissionBase::initMis()
{
	numsVec.clear();
	xPlace.clear();
	initMis();
}

void MissionBase::setMission()
{//AFTER GETTING THE NUMBERS
	char *mstr = new char[sizeof(char) * 50], *newstr = new char[sizeof(char) * 50];
	strcpy(mstr, mission);
	strcpy(newstr, strtok(mstr, ":"));
	strcat(newstr, ": ");
	for (int i = 0; i < operators.size(); i++)
	{
		if (numsVec[i] == FreeSpace)
			strcat(newstr, "X");
		else
		{
			char str[4];
			strcat(newstr, itoa(numsVec[i], str, 10));
		}
		strcat(newstr, " ");
		strcat(newstr, operators[i]);
		strcat(newstr, " ");
	}
	if (numsVec[numsVec.size() - 1] == FreeSpace)
		strcat(newstr, "X");
	else
	{
		char str[4];
		strcat(newstr, itoa(numsVec[numsVec.size() - 1], str, 10));
	}
	SetMission(newstr);
}
bool MissionBase::isCorrectNum(int x)
{
	vector<char> op;
	vector<int> nums = numsVec;
	op = castingOP();
	for (int p = 0; p < xPlace.size(); p++)
	{//put the number in x spot
		int j = *(xPlace.begin() + p);
		nums[j] = x;
	}
	return helperMath(op, nums);
}
vector <int> MissionBase::PickNums()
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
vector <char> MissionBase::castingOP()
{
	vector <char> op;
	for (int i = 0; i < operators.size(); i++)
	{
		op.push_back(operators[i][0]);
	}
	return op;
}
bool MissionBase::helperMath(vector <char> op, vector <int>nums)
{
	vector <char> op1;
	vector <int>nums1;
	switch (op.size())
	{
	case 1:
		return calculate1op(nums, op);
		break;
	case 2:
		return calculate2op(nums, op);
		break;
	case 3:
		return (calculate3op(nums, op));
		break;
	case 5:
		op1.push_back(op[3]);
		op1.push_back(op[4]);
		nums1.push_back(nums[3]);
		nums1.push_back(nums[4]);
		nums1.push_back(nums[5]);
		if (op[2] == '&')
			return (calculate2op(nums, op) && calculate2op(nums1, op1));
		else
			return (calculate2op(nums, op) || calculate2op(nums1, op1));
		break;
	default:
		return false; break;
	}
	return false;
}
bool MissionBase::isValid(vector<char> op, vector <int>nums, vector <int> xPlace)
{//checking if there is a correct answer
	for (int i = 1; i < 170; i++)
	{
		for (int p = 0; p < xPlace.size(); p++)
		{//put the number in x spot
			int j = *(xPlace.begin() + p);
			nums[j] = i;
		}
		if (helperMath(op, nums))
			return true;
	}
	return false;
}
void MissionBase::makeValidExe()
{//checking validation of the exe
 //vector<int> xPlace;
	vector<char> op;
	vector <int>nums;
	op = castingOP();
	bool good = false;
	while (!good)
	{
		nums = PickNums();//get random numbers
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == FreeSpace)
				xPlace.push_back(i);
		}
		good = isValid(op, nums, xPlace);
	}
	numsVec = nums;//save the correct exe
	setMission();
}
bool MissionBase::calculate1op(vector<int >nums, vector <char> op)
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
bool MissionBase::calculate2op(vector<int >nums, vector <char> op)
{//calculate the exe - virtual by the numbers of op
	switch (op[0])
	{
	case '+':
		switch (op[1])
		{
		case '=':
			return (nums[0] + nums[1] == nums[2]);
		case '!':
			return (nums[0] + nums[1] != nums[2]);
		}
	case '-':
		switch (op[1])
		{
		case '=':
			return (nums[0] - nums[1] == nums[2]);
		case '!':
			return (nums[0] - nums[1] != nums[2]);
		}
	case '*':
		switch (op[1])
		{
		case '=':
			return (nums[0] * nums[1] == nums[2]);
		case '!':
			return (nums[0] * nums[1] != nums[2]);
		}
	case '/':
		switch (op[1])
		{
		case '=':
			return (nums[0] / nums[1] == nums[2]);
		case '!':
			return (nums[0] / nums[1] != nums[2]);
		}
	case '^':
		switch (op[1])
		{
		case '=':
			return (pow(nums[0], nums[1]) == nums[2]);
		case '!':
			return (pow(nums[0], nums[1]) != nums[2]);
		}
	case '%':
		switch (op[1])
		{
		case '=':
			return (nums[0] % nums[1] == nums[2]);
		case '!':
			return (nums[0] % nums[1] != nums[2]);
		}
	case '=':
		switch (op[1])
		{
		case '+':
			return (nums[0] == nums[1] + nums[2]);
		case '-':
			return (nums[0] == nums[1] - nums[2]);
		case '*':
			return (nums[0] == nums[1] * nums[2]);
		case '/':
			return (nums[0] == nums[1] / nums[2]);
		case '^':
			return (nums[0] == pow(nums[1], nums[2]));
		case '%':
			return (nums[0] == nums[1] % nums[2]);
		}
	case '!':
		switch (op[1])
		{
		case '+':
			return (nums[0] != nums[1] + nums[2]);
		case '-':
			return (nums[0] != nums[1] - nums[2]);
		case '*':
			return (nums[0] != nums[1] * nums[2]);
		case '/':
			return (nums[0] != nums[1] / nums[2]);
		case '^':
			return (nums[0] != pow(nums[1], nums[2]));
		case '%':
			return (nums[0] != nums[1] % nums[2]);
		}
	default:return false; break;
	}
}
bool MissionBase::calculate3op(vector<int >nums, vector <char> op)
{//calculate the exe - virtual by the numbers of op
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