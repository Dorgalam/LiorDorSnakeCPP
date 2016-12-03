#include <windows.h>
#include <iostream>
#include "Menu.h"
using namespace std;

#include "TheSnakesGame.h"
#include "_board.h"
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
class Menu {
	char screen[5][81] = {
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
	void print() {
		gotoxy(0, 0);
		for (char *item : screen) cout << item;
	}
	void edit(int x, int y, char *str) {
		for (int i = 0; i < strlen(str); i++) {
			screen[x][y + i] = str[i];
		}
	}
	void clear() {
		for (int i = 1; i < 4; i++) {
			for (int j = 1; j < 78; j++) screen[i][j] = ' ';
		}
	}
	void newMission(int numMission) {
		this->clear();
		edit(2, 39 - strlen(missions[numMission])/2 , missions[numMission]);
	}
	void displayStartMenu() {
		edit(1, 2, startMenu[0]);
		edit(2, 2, startMenu[1]);
		edit(3, 70, startMenu[2]);
	}
	void displayIngameMenu() {
		edit(1, 2, inGameMenu[0]);
		edit(2, 2, inGameMenu[1]);
		edit(3, 2, inGameMenu[2]);
		edit(1, 22, inGameMenu[3]);
		edit(2, 22, inGameMenu[4]);
		edit(3, 22, inGameMenu[5]);
	}

};

int main() {
	cout << 4;
	Menu a;
	a.displayStartMenu();
	a.print();
	Sleep(1000);
	a.newMission(3);
	a.print();
	/*TheSnakesGame game;
	game.setBoard(board);
	game.init();
	game.run();*/

}