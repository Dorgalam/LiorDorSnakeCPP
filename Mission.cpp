#include "Mission.h"
#include "Menu.h"

bool Mission::isPrime(int n) {
	for (int i = 2; i <= n / 2; ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
void Mission::startMission() {
	bool correct = false;
	currMission = (rand() % 8);
	theMenu->newMission(currMission);
}
bool Mission::isPalindrom(int n)//6 - palindrom number is 131 in example
{
	if (n < 10)
		return true;
	else if (n<100)
		return n % 10 == n / 10 ? true : false;
	else
		return n / 100 == n % 10 ? true : false;
}
void Mission::getNums(char *str, int nums[])
{
	int i = 0;
	while (*str != '\0')
	{
		if (*str == '_')
		{
			str = str + 3;
			nums[i++] = FreeSpace;
		}
		if (*str <= '9'&&*str >= '0')
		{
			while (*str <= '9'&&*str >= '0')
			{
				nums[i] = nums[i] * 10 + (int)(*str - '0');
				str++;
			}
			i++;
		}
		str++;
	}
}
void Mission::getOP(char *str, char ops[])
{

	int i = 0;
	while (*str != '\0')
	{
		if (*str == '+' || *str == '-' || *str == '*' || *str == '/')
			ops[i++] = *str;
		str++;
	}
}
bool Mission::mathExe(int n)//7 - 
{
	char *str = new char[25];
	strcpy(str, mission7);
	str[24] = '\0';
	int nums[4] = { 0,0,0,0 };
	char ops[4] = "   ";
	getNums(str, nums);
	getOP(str, ops);
	for (int i = 0; i < 4; i++)
	{
		if (nums[i] == FreeSpace)
			nums[i] = n;
	}
	bool res = helperMath(nums, ops[0], ops[1]);
	return res;
}
bool Mission::helperMath(int nums[], char op1, char op2)
{
	switch (op1)
	{
	case '+':
		switch (op2)
		{
		case '+':
			return (nums[0] + nums[1] + nums[2] == nums[3]);
			break;
		case '-':
			return (nums[0] + nums[1] - nums[2] == nums[3]);
		case '*':
			return (nums[0] + nums[1] * nums[2] == nums[3]);
			break;
		case '/':
			return (nums[0] + nums[1] / nums[2] == nums[3] && nums[0] + nums[1] / nums[2] + 0.5 == nums[3]);
			break;
		}
	case '-':
		switch (op2)
		{
		case '+':
			return (nums[0] - nums[1] + nums[2] == nums[3]);
			break;
		case '-':
			return (nums[0] - nums[1] - nums[2] == nums[3]);
		case '*':
			return (nums[0] - nums[1] * nums[2] == nums[3]);
			break;
		case '/':
			return (nums[0] - nums[1] / nums[2] == nums[3] && 0.5 + nums[0] - nums[1] / nums[2] == nums[3]);
			break;
		}
	case '*':
		switch (op2)
		{
		case '+':
			return (nums[0] * nums[1] + nums[2] == nums[3]);
			break;
		case '-':
			return (nums[0] * nums[1] - nums[2] == nums[3]);
		case '*':
			return (nums[0] * nums[1] * nums[2] == nums[3]);
			break;
		case '/':
			return (nums[0] * nums[1] / nums[2] == nums[3] && 0.5 + nums[0] * nums[1] / nums[2] == nums[3]);
			break;
		}
	case '/':
		switch (op2)
		{
		case '+':
			return (nums[0] / nums[1] + nums[2] == nums[3] && 0.5 + nums[0] / nums[1] + nums[2] == nums[3]);
			break;
		case '-':
			return (nums[0] / nums[1] - nums[2] == nums[3] && 0.5 + nums[0] / nums[1] - nums[2] == nums[3]);
		case '*':
			return (nums[0] / nums[1] * nums[2] == nums[3] && 0.5 + nums[0] / nums[1] * nums[2] == nums[3]);
			break;
		case '/':
			return (nums[0] / nums[1] / nums[2] == nums[3] && 0.5 + nums[0] / nums[1] / nums[2] == nums[3]);
			break;
		}
	default:return false; break;
	}
}