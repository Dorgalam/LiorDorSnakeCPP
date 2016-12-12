#include "TheSnakesGame.h"
#include <string>
void TheSnakesGame::finishMission()
{
	s[0]->clearSnake();
	s[1]->clearSnake();
	theMenu.updateScoreBoard(s[0]->getSize(), s[1]->getSize());
	gameNumbers.removeHalf();//clean the half board and the snakes
	nextMission();//go to next mission
	theMenu.updateScoreBoard(s[0]->getSize(), s[1]->getSize());
}
void TheSnakesGame::flashNum(numCoord numVec, Color color)
{
	setTextColor(color);
	string str = to_string(numVec.num);
	int x = numVec.p.getX(), y = numVec.p.getY();
	for (int i = 0; i < numVec.len; i++) {
		updateBoard(x, y + i, str[i]);
		gotoxy(y + i, x + 5);
		cout << str[i];
	}
	setTextColor(WHITE);
}
void TheSnakesGame::nextMission()
{
	startMission();
	s[0]->backToStart(9, 10, RIGHT);
	s[1]->backToStart(9, 70, LEFT);

 }
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
	nextMission();
	s[0]->setGame(this);
	s[1]->setGame(this);
	s[0]->setArrowKeys("wxad");
	s[1]->setArrowKeys("imjl");
}
void TheSnakesGame::printBoard() {
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			gotoxy(j, i + 5);
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
	int missionEnd;
	theMenu.print(WHITE);//print the instruction
	theMenu.updateScoreBoard(s[0]->getSize(), s[1]->getSize());
		do
		{
			if (count % 5 == 0) {
				count = 0;
				this->gameNumbers.addNumber();
			}
			missionEnd = 0;
			if (_kbhit())
			{
				key = _getch();
				if ((dir = s[0]->getDirection(key)) != -1)
					s[0]->setDirection(dir);
				else if ((dir = s[1]->getDirection(key)) != -1)
					s[1]->setDirection(dir);
			}
			missionEnd = s[0]->move(s[1]->getSymbol(), currMission);
			if (missionEnd == 2)
			{//ate a wrong number-erase the snakes from the board and screen+remove half of the numbers
				s[1]->snakeGrow();
				theMenu.displayWinningMenu(1);
				gameNumbers.showNumbers(currMission);
				finishMission();
			}
			else if (missionEnd)
			{//ate a correct number
				theMenu.displayWinningMenu(0);
				finishMission();
			}
			missionEnd = s[1]->move(s[0]->getSymbol(), currMission);
			if (missionEnd == 2)
			{//ate a wrong number
				s[0]->snakeGrow();
				theMenu.displayWinningMenu(0);
				gameNumbers.showNumbers(currMission);
				finishMission();
			}
			else if (missionEnd)
			{
				theMenu.displayWinningMenu(1);
				finishMission();
			}
			if (gameNumbers.getSize() == 60)
			{
				bool wasCorrectAnswer=gameNumbers.showNumbers(currMission);//show the numbers that is correct
				theMenu.displayNumMenu(wasCorrectAnswer);
				finishMission();
			}
			count++;
			Sleep(200);
			if (key == ESC) {
				int clickedEscape = theMenu.displayIngameMenu();
				if (clickedEscape != 1) {
					key = rand() % 4;
					if (clickedEscape != 3 && clickedEscape != 6 && clickedEscape != 2)
					{
						s[0]->clearSnake();
						s[1]->clearSnake();
						s[0]->backToStart(9, 10, RIGHT);
						s[1]->backToStart(9, 70, LEFT);
						if (clickedEscape == 4)
							gameNumbers.removeAll();
					}
					else if (clickedEscape == 6)
					{
						s[0]->clearBody();
						s[1]->clearBody();
						s[0]->newSnake(9,10,RIGHT);
						s[1]->newSnake(9,70,LEFT);
						gameNumbers.removeAll();
						theMenu.updateScoreBoard(s[0]->getSize(), s[1]->getSize());
						
					}
				}
			}
			if (s[0]->getSize() == 12)
			{
				key = ESC;
				theMenu.displayVictoryMenu(0);
			}
			if (s[1]->getSize() == 12)
			{
				key = ESC;
				theMenu.displayVictoryMenu(1);
			}
		} while (key != ESC);
		s[0]->~Snake();
		s[1]->~Snake();

}