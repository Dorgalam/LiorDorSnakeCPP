#include "Snake.h"
#include "TheSnakesGame.h"

void Snake::move(char opSymbol)
{
	Point nextPoint = body[0].next(direction);
	char nextSpot = theGame->boardChar(nextPoint);
	if (nextSpot >= '0' && nextSpot <= '9') {
		int numCollected = theGame->getNumFromArray(nextPoint);
		if (numCollected != -1) {
			gotoxy(0, 0);
			cout << "Collected " << numCollected;
		}
	}
	body[size - 1].draw(' ');
	theGame->updateBoard(body[size - 1].getX() , body[size - 1].getY(), ' ');
	for (int i = size - 1; i > 0; --i)
		body[i] = body[i - 1];
	theGame->updateBoard(nextPoint.getX() , nextPoint.getY(), symbol);
	body[0].move(direction);
	//theGame->printBoard();
	setTextColor(color);
	body[0].draw(symbol);
		
}
int Snake::getDirection(char key)
{
	for (int i = 0; i < SIZE - 1; i++)
	{
		if (key == arrowKeys[i])
			return i;
	}
	return -1;
}