#include "TheSnakesGame.h"


 
void TheSnakesGame::setBoard(const char* boardToCopy[ROWS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			originalBoard[i][j] = boardToCopy[i][j];
		}
		originalBoard[i][COLS] = '\0';
	}
}

void TheSnakesGame::init()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			gotoxy(j , i + 5);
			cout << originalBoard[i][j];
			cout.flush();
			board[i][j] = originalBoard[i][j];
		}
		board[i][COLS] = '\0';
	}
	s[0]->setGame(this);
	s[1]->setGame(this);
	s[0]->setArrowKeys("wsad");
	s[1]->setArrowKeys("8546");
}
void TheSnakesGame::printBoard() {
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			gotoxy(j, i);
			cout << board[i][j];
			cout.flush();
		}
	}
}
void TheSnakesGame::run()
{
	int count = 0;
	char key = 0;
	int dir;
	do
	{

		if (count % 5 == 0) {
			count = 0;
			this->gameNumbers.addNumber();
		}
	
		if (_kbhit())
		{
			key = _getch();
			if ((dir = s[0]->getDirection(key)) != -1)
				s[0]->setDirection(dir);
			else if ((dir = s[1]->getDirection(key)) != -1)
				s[1]->setDirection(dir);
		}
		s[0]->move(s[1]->getSymbol());
		s[1]->move(s[0]->getSymbol());
		count++;
		Sleep(300);
	} while (key != ESC);
	theMenu.displayIngameMenu();
}