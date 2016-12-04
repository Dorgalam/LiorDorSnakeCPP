#ifndef _THESNAKESGAME_H_
#define _THESNAKESGAME_H_

#include "io_utils.h"
#include "Snake.h"

enum { ROWS = 24, COLS = 80 };

class TheSnakesGame {
	enum { ESC = 27 };
	Snake **s;
	char originalBoard[ROWS][COLS + 1];	// this is the original board that we got (we need COLS+1 because we handle it as null terminated char*)
	char board[ROWS][COLS + 1];	// this is the actual board we play on, i.e. changes on board are done here
public:
	TheSnakesGame()
	{
		s = new Snake*[2];
		s[0] = new Snake(6, '@', Point(7, 9), LIGHTBLUE);
		s[1] = new Snake(3, '&', Point(2, 4), RED);
	}
	void updateBoard(const int x, const int y, const char let) {
		board[x][y] = let;
	};
	void setBoard(const char* boardToCopy[ROWS]);
	//void initBoard();
	void init();
	bool isWall(const Point& p, char sym) {
		return board[p.getY()][p.getX()] == sym;
	}
	void run();
};

#endif
