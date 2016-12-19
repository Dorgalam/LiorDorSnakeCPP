#ifndef _MENU_H
#define _MENU_H
#include "io_utils.h"
#include "Mission.h"

using namespace std;

enum { INSTRUCTIONS = '1', START='2', EXIT_START = '9' };
enum { EXIT_MID = '1', MAIN_MENU='2', RESUME='3', RESTART_MISSION='4', NEW_MISSION='5', RESTART_GAME='6' };
enum {Plus=0,Minus,Mult,Div};
class TheSnakesGame;
class Mission;

class Menu  {
	TheSnakesGame *game;
	Mission *mission;
	Color txtColor=WHITE;
	char screen[5][82] = {
		//		  10        20        30        40        50        60        70   
		//01234567890123456789012345678901234567890123456789012345678901234567890123456789 
		"--------------------------------------------------------------------------------",// 0
		"|                                                                  GAME SCORE: |",// 1
		"|                                                                  SNAKE 1:    |",// 2
		"|                                                                  SNAKE 2:    |",// 3
		"--------------------------------------------------------------------------------",// 4
	};
	char *startMenu[3] = {
		"(1) Instructions",
		"(2) Start",
		"(9) Exit",
	}; //string instructions
	char *inGameMenu[6] = {
		"(1) Exit",
		"(2) Main Menu",
		"(3) Resume",
		"(4) Restart Mission",
		"(5) New Mission",
	    "(6) Restart Game",
	}; //menu items
	char *missions[8] = {
		"Prime number",
		"Number divisible by 4",
		"Product of 7",
		"Squared Integer",
		"Divided by 7 remainder is 3",
		"Look for the number 169",
		"Find a Palindrome number",
	}; // string missions
	char *instructions = {
		"Two snakes battling over mathematical superiority.\nControl the greed $ snake with 'wxad', the more calculated # snake with 'ijkl'.\nComplete missions to score points and eventually win.\nBeware, wrong solutions will result in the other players point.\nThe first to get to 12 points win the Game(start from 3)!\nGood luck and may Sir Isaac Newton be with you!"
	}; //humoristic instructions
	char *snakeWonMission[2] = {
		"Snake 1 won this round",
		"Snake 2 won this round",
	};
	char *Num60Menu[2] = {
		"There is no correct number ,good try!!!",
		"All the yellow numbers were possible answers,try better next time",
	};
	char *victoryMenu[2] = {
		"congratulation:) snake 1 won the game!!!",
		"congratulation:) snake 2 won the game!!!",
	};
public:
	Menu(TheSnakesGame *_game) : game(_game) {}
	void print(Color c) {
		int i = 0;
		for (char *item : screen) {
			gotoxy(0, i++);
			//system("color f");
			setTextColor(c);
			cout << item;
		} //constructor, go over all items and print
	}
	void setColor(Color c) {
		txtColor = c;
	}
	void edit(int x, int y, char *str) {
		for (size_t i = 0; i < strlen(str); i++) {
			screen[x][y + i ] = str[i];
		}
	} //edit the menu

	void clear() {
		for (int i = 1; i < 4; i++) {
			for (int j = 1; j < 67; j++) screen[i][j] = ' ';
		}
	}//clear everytthing within the menu
	void newMission(int numMission, bool needUpdate = true) {
		clear();
		if (needUpdate&&numMission == 7)
			mathExe();
		edit(2, 33 - strlen(missions[numMission]) / 2, missions[numMission]);
		print(WHITE);
	}//print the new mission in the menu
	void displayStartMenu(); 
	void displayInstructions() {
		gotoxy(0, 5);
		cout << instructions;
		displayStartMenu();
	}
	int displayIngameMenu();
	void displayWinningMenu(int num);
	void displayVictoryMenu(int num);
	void displayNumMenu(bool num);
	void updateScoreBoard(int score1, int score2);
	//self explanatory function names
	char* castingOP(int op);
	char* makeString(char* s1, char* s2, char* s3, char* s4, char* s5, char* s6);
	void mathExe();//7 - 
	char* getM7()
	{
		return missions[7];
	}
	void Menu::PickNums(int &place, int nums[], char* operator1, char * operator2);
	bool CheckValidation(int nums[], int place, char* operator1, char* operator2);

};

#endif










/*char numbers[][50] =
{
" 333333333333333   ", " 222222222222222    ", " 1111111    ",
"3:::::::::::::::33 ", "2:::::::::::::::22  ", "1::::::1    ",
"3::::::33333::::::3", "2::::::222222:::::2 ", "1:::::::1   ",
"3333333     3:::::3", "2222222     2:::::2 ", "111:::::1   ",
"            3:::::3", "            2:::::2 ", "   1::::1   ",
"            3:::::3", "            2:::::2 ", "   1::::1   ",
"    33333333:::::3 ", "         2222::::2  ", "   1::::1   ",
"    3:::::::::::3  ", "    22222::::::22   ", "   1::::l   ",
"    33333333:::::3 ", "  22::::::::222     ", "   1::::l   ",
"            3:::::3", " 2:::::22222        ", "   1::::l   ",
"            3:::::3", "2:::::2             ", "   1::::l   ",
"            3:::::3", "2:::::2             ", "   1::::l   ",
"3333333     3:::::3", "2:::::2       222222", "111::::::111",
"3::::::33333::::::3", "2::::::2222222:::::2", "1::::::::::1",
"3:::::::::::::::33 ", "2::::::::::::::::::2", "1::::::::::1",
" 333333333333333   ", "22222222222222222222", "111111111111" };*/