#ifndef _THESNAKESGAME_H_
#define _THESNAKESGAME_H_

#include "io_utils.h"
#include "Snake.h"
#include "Menu.h"
#include "randNumbers.h"

enum { ROWS = 24, COLS = 80 };


class TheSnakesGame {
	enum { ESC = 27 };
	Snake **s;
	Menu theMenu;
	randNumbers gameNumbers;
	int currMission;
	int shownNumbers[60];
	char originalBoard[ROWS][COLS + 1];	// this is the original board that we got (we need COLS+1 because we handle it as null terminated char*)
	char board[ROWS][COLS + 1];	// this is the actual board we play on, i.e. changes on board are done here
public:
	TheSnakesGame()
		: theMenu(this), gameNumbers(this)
	{
		s = new Snake*[2];
		s[0] = new Snake(3, '$', Point(7, 7), LIGHTBLUE);
		s[1] = new Snake(3, '#', Point(5, 12), RED);
		system("mode con:cols=80 lines=30");
	}
	int getNumFromArray(const Point &p) {
		return gameNumbers.whatNum(p);
	}
	
	void startMission() {
		currMission = rand() % 5;
		theMenu.newMission(currMission);
	}
	void printBoard();
	void updateBoard(int x, int y, const char let) {
		board[x][y] = let;
	}
	void setBoard(const char* boardToCopy[ROWS]);
	//void initBoard();
	void init();
	void displayStartMenu() {
		theMenu.displayStartMenu();
	}
	bool isWall(const Point& p, char sym) {
		return board[p.getX()][p.getY()] == sym;
	}
	char boardChar(const Point& p) {
		return board[p.getX()][p.getY()];
	}
	char boardChar(const int &x, const int &y) {
		setTextColor(WHITE);
		return board[x][y];
	}
	void run();
	
};

#endif
