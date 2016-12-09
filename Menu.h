#ifndef _MENU_H
#define _MENU_H
#include "io_utils.h"
#include "Mission.h"

using namespace std;

enum { INSTRUCTIONS = 1, START, EXIT_START = 9 };
enum { EXIT_MID = 1, MAIN_MENU, RESUME, RESTART_MISSION, NEW_MISSION, RESTART_GAME };

class TheSnakesGame;


class Menu  {
	TheSnakesGame *game;
	Mission *mission;
	char screen[5][82] = {
		//		  10        20        30        40        50        60        70   
		//01234567890123456789012345678901234567890123456789012345678901234567890123456789 
		"--------------------------------------------------------------------------------",// 0
		"|                                                                              |",// 1
		"|                                                                              |",// 2
		"|                                                                              |",// 3
		"--------------------------------------------------------------------------------",// 4
	};
	char *startMenu[3] = {
		"(1) Instructions",
		"(2) Start",
		"(9) Exit"
	};
	char *inGameMenu[6] = {
		"(1) Exit",
		"(2) Main Menu",
		"(3) Resume",
		"(4) Restart Mission",
		"(5) New Mission",
		"(6) Restart Game"
	};
	char *missions[5] = {
		"Prime number",
		"Number divisible by 4",
		"Product of 7",
		"Squared Integer",
		"Divided by 7 remainder is 3"
	};
public:
	Menu(TheSnakesGame *_game) : game(_game) {}
	void print() {
		int i = 0;
		gotoxy(0, 0);
		for (char *item : screen) {
			gotoxy(0, i++);
			cout << item;
		}
	}

	void edit(int x, int y, char *str) {
		for (size_t i = 0; i < strlen(str); i++) {
			screen[x][y + i ] = str[i];
		}
	}
	void clear() {
		for (int i = 1; i < 4; i++) {
			for (int j = 1; j < 78; j++) screen[i][j] = ' ';
		}
	}
	void newMission(int numMission) {
		this->clear();
		edit(2, 39 - strlen(missions[numMission]) / 2, missions[numMission]);
	}
	void displayStartMenu();
	void displayInstructions() {
		char *instructions = "just get on with it and play this freaking game!";
		edit(3, 3, instructions);
	}
	void displayIngameMenu();

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