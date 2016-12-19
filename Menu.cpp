#include "Menu.h"
#include "TheSnakesGame.h"
#include <string>
void Menu::updateScoreBoard(int score1, int score2)
{
	char s1[3], s2[3];
	s1[0] = score1 / 10 + '0';
	s1[1] = score1 % 10 + '0';
	s2[0] = score2 / 10 + '0'; //go to all correct spots and update locations
	s2[1] = score2 % 10 + '0';
	s1[2] = '\0';
	s2[2] = '\0';
	edit(2, 76, s1);
	edit(3, 76, s2);
	print(WHITE);
} 
void Menu::displayStartMenu() {
	char key;
	bool goodChoice = false;
	clear();
	edit(1, 2, startMenu[0]);
	edit(2, 2, startMenu[1]);
	edit(3, 2, startMenu[2]);
	print(WHITE);
	while (!_kbhit()) //listen to a new key pressed in the keyboard
	{

	}
	key = _getch();
	while (!goodChoice)
	{
		switch (key) { //give correct output for all known results, otherwise look for another key
		case START:
			game->init();
			goodChoice = true;
			break;
		case INSTRUCTIONS:
			displayInstructions();
			goodChoice = true;
			break;
		case EXIT_START:
			exit(0);
			goodChoice = true;
			break;
		default:
			while (!_kbhit())
			{

			}
			key = _getch();
			break;
		}
	}
}
void Menu::displayWinningMenu(int num)
{
	clear(); //clears the screen and then shows who won
	edit(1, 2, snakeWonMission[num]); 
	print(YELLOW);
	Sleep(2000);
}
void Menu::displayVictoryMenu(int num)
{
	clear();
	edit(1, 2, victoryMenu[num]);
	print(GREEN);
	PlaySound(TEXT("applause3.wav"), NULL, SND_FILENAME);
	Sleep(2000);
}
void Menu::displayNumMenu(bool found)
{
	int num;
	if (found)
		num = 1;
	else
		num = 0;
	clear();
	edit(1, 2, Num60Menu[num]); 
	print(LIGHTCYAN);
	Sleep(2500);
}
int Menu::displayIngameMenu() {
	char key;
	clear();
	for (int i = 0; i < 6; i++) {
		edit((i % 3) + 1, 2 + 20 * (i / 3), inGameMenu[i]);
	}
	print(WHITE);
	while (!_kbhit()) //listens to a key and operates accordingly
	{

	}
	key = _getch();

	switch (key) {
	case EXIT_MID:
		exit(0);
		break;
	case MAIN_MENU:
		game->displayStartMenu();
		break;
	case RESUME:
		newMission(game->getCurrMission(), false);
		break;
	case RESTART_MISSION:
		newMission(game->getCurrMission(), false);
		break;
	case NEW_MISSION:
		game->startMission();
		break;
	case RESTART_GAME:
		game->init();

		break;
	}
	return (int)(key-'0');

}
char* Menu::castingOP(int op)
{
	switch (op)
	{
	case Plus:
		return "+";
		break;
	case Minus:
		return "-";
		break;
	case Mult:
		return "*";
		break;
	case Div:
		return "/";
		break;
	default:
		return "0";
		break;
	}
}
char* Menu::makeString(char* s1, char* s2, char* s3, char* s4, char* s5, char* s6)
{
	char str[25];
	strcpy(str, s1);
	strcat(str, " ");
	strcat(str, s2);
	strcat(str, " ");
	strcat(str, s3);
	strcat(str, " ");
	strcat(str, s4);
	strcat(str, " ");
	strcat(str, s5);
	strcat(str, " = ");
	strcat(str, s6);
	return str;
}
bool Menu::CheckValidation(int nums[], int place, char* operator1, char* operator2)
{
	char op1 = operator1[0], op2 = operator2[0];
	for (nums[place] = 1; nums[place] < 170; nums[place]++)
	{
		if (mission->helperMath(nums, op1, op2))
			return true;
	}
	return false;
}
void Menu::PickNums(int &place, int nums[], char* operator1, char * operator2)
{
	int i = 0, op1, op2;
	place = rand() % 4;
	nums[place] = 0;
	op1 = rand() % 4;
	op2 = rand() % 4;
	strcpy(operator1, castingOP(op1));
	strcpy(operator2, castingOP(op2));
	if (i == place)
		i++;
	nums[i++] = rand() % 169 + 1;
	if (i == place)
		i++;
	nums[i++] = rand() % 169 + 1;
	if (i == place)
		i++;
	nums[i] = rand() % 169 + 1;
}
void Menu::mathExe()//new mission - math exerecise complex of 3 random numbers and 2 random operators
{
	char *operator1 = new char[2], *operator2 = new char[2], *n1 = new char[4], *n2 = new char[4], *n3 = new char[4];
	bool Good = false;
	char str[25];
	int nums[4], i, place;
	while (!Good)
	{
		PickNums(place, nums, operator1, operator2);
		if (CheckValidation(nums, place, operator1, operator2))
			Good = true;
	}
	i = 0;
	if (i == place)
		i++;
	sprintf(n1, "%d", nums[i++]);
	if (i == place)
		i++;
	sprintf(n2, "%d", nums[i++]);
	if (i == place)
		i++;
	sprintf(n3, "%d", nums[i]);
	switch (place)
	{
	case 0://n op1 num1 op2 num2 = num3
		strcpy(str, makeString("___", operator1, n1, operator2, n2, n3));
		break;
	case 1://num1 op 1 n op2 num2 = num3
		strcpy(str, makeString(n1, operator1, "___", operator2, n2, n3));
		break;
	case 2://num1 op1 num2 op2 n = num3
		strcpy(str, makeString(n1, operator1, n2, operator2, "___", n3));
		break;
	case 3://num1 op1 num2 op2 num3 = n
		strcpy(str, makeString(n1, operator1, n2, operator2, n3, "___"));
		break;
	default:
		return;
		break;
	}
	missions[7] = new char[25];
	strcpy(missions[7], str);
}