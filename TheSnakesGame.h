#ifndef _THESNAKESGAME_H_
#define _THESNAKESGAME_H_

#include "io_utils.h"
#include "Snake.h"
#include "Menu.h"
#include "randNumbers.h"

enum { ROWS = 24, COLS = 80 };

enum { UP = 0, DOWN, LEFT, RIGHT };
class TheSnakesGame {
	enum { ESC = 27 };
	Snake **s;
	Menu theMenu;
	randNumbers gameNumbers;
	int currMission;
	int shownNumbers[60];
	char originalBoard[ROWS][COLS +1];	// this is the original board that we got (we need COLS+1 because we handle it as null terminated char*)
	char board[ROWS][COLS +1];	// this is the actual board we play on, i.e. changes on board are done here
public:
	TheSnakesGame()
		: theMenu(this), gameNumbers(this)
	{
		s = new Snake*[2];
		s[0] = new Snake(3,3, '@', Point(9, 10), LIGHTBLUE);
		s[1] = new Snake(2,3, '#', Point(9, 70), RED);
		system("mode con:cols=80 lines=30");
	}
	int getNumFromArray(const Point &p) {
		return gameNumbers.whatNum(p);
	}
	int getCurrMission() {
		return currMission;
	}
	void startMission() { //create random display new mission in menu
		currMission = rand() % 7;
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
		s[0]->clearBody();
		s[1]->clearBody();
		s[0]->newSnake(9, 10, RIGHT);
		s[1]->newSnake(9, 70, LEFT);
		gameNumbers.removeAll();
		theMenu.updateScoreBoard(s[0]->getSize(), s[1]->getSize());
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
	void finishMission();
	void run();
	void nextMission();
	void flashNum(numCoord numVec, Color color);
};

#endif
