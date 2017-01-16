#include "MissionBank.h"

void MissionBank::SetMission(vector <int> numsVec) {
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
	strcpy(mission, newstr);
}

vector <char> MissionBank::castingOP()
{
	vector <char> op;
	for (int i = 0; i < operators.size(); i++)
	{
		op.push_back(operators[i][0]);
	}
	return op;
}
bool MissionBank::calculate2(vector<int >nums, vector <char> op)
{
	switch (op[0])
	{
	case '+':
		switch (op[1])
		{
		case '=':
			return (nums[0] + nums[1] == nums[2]);
		case '!':
			return (nums[0] + nums[1] != nums[2]);
		case '>':
			return (nums[0] + nums[1] > nums[2]);
		case '<':
			return (nums[0] + nums[1] < nums[2]);
		}
	case '-':
		switch (op[1])
		{
		case '=':
			return (nums[0] - nums[1] == nums[2]);
		case '!':
			return (nums[0] - nums[1] != nums[2]);
		case '>':
			return (nums[0] - nums[1] > nums[2]);
		case '<':
			return (nums[0] - nums[1] < nums[2]);
		}
	case '*':
		switch (op[1])
		{
		case '=':
			return (nums[0] * nums[1] == nums[2]);
		case '!':
			return (nums[0] * nums[1] != nums[2]);
		case '>':
			return (nums[0] * nums[1] > nums[2]);
		case '<':
			return (nums[0] * nums[1] < nums[2]);
		}
	case '/':
		switch (op[1])
		{
		case '=':
			return (nums[0] / nums[1] == nums[2]);
		case '!':
			return (nums[0] / nums[1] != nums[2]);
		case '>':
			return (nums[0] / nums[1] > nums[2]);
		case '<':
			return (nums[0] / nums[1] < nums[2]);
		}
	case '^':
		switch (op[1])
		{
		case '=':
			return (pow(nums[0], nums[1]) == nums[2]);
		case '!':
			return (pow(nums[0], nums[1]) != nums[2]);
		case '>':
			return (pow(nums[0], nums[1]) > nums[2]);
		case '<':
			return (pow(nums[0], nums[1]) < nums[2]);
		}
	case '%':
		switch (op[1])
		{
		case '=':
			return (nums[0] % nums[1] == nums[2]);
		case '!':
			return (nums[0] % nums[1] != nums[2]);
		case '>':
			return (nums[0] % nums[1] > nums[2]);
		case '<':
			return (nums[0] % nums[1] < nums[2]);
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