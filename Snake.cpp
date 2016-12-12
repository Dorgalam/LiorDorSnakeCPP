#include "Snake.h"
#include "TheSnakesGame.h"
void Snake:: clearSnake()
{
	for (int i = 0; i < size; i++) {
		theGame->updateBoard(body[i].getX(), body[i].getY(), ' ');
		body[i].draw(' ');
	}
	if(direction==4) direction = 3;
	
}
bool Snake::goodNum(int numMission,int num)
{
	switch (numMission) {
	case 0:
		return m.isPrime(num);
		break;
	case 1:
		return m.div4(num);
		break;
	case 2:
		return m.div7(num);
		break;
	case 3:
		return m.isSquare(num);
		break;
	case 4:
		return m.div7rem3(num);
		break;
	case 5:
		return m.is169(num);
		break;
	case 6:
		return m.isPalindrom(num);
	default:
		return false;
		break;
	}
}
int Snake::move(char opSymbol,int numOfMission)
{
	Point nextPoint = body[0].next(direction);
	char nextSpot = theGame->boardChar(nextPoint);
	if (nextSpot >= '0' && nextSpot <= '9') {
		int numCollected = theGame->getNumFromArray(nextPoint);
		if (goodNum(numOfMission, numCollected)) {
			gotoxy(0, 0);
			body.push_back(body[size - 1]);
			size++;
			PlaySound(TEXT("eat.wav"), NULL, SND_FILENAME);
			return 1;
		}
		else
			PlaySound(TEXT("wrong.wav"), NULL, SND_FILENAME);
			return 2;}
	if (!theGame->isWall(nextPoint, symbol))//next direction free
		stuck = false;
	if ((theGame->isWall(nextPoint, symbol) || theGame->isWall(nextPoint, opSymbol)) && direction != 4)
	{//check if the next direction is already taken - stop the snake movement
		direction = 4;
		stuck = true;
		PlaySound(TEXT("punch.wav"), NULL, SND_FILENAME);
	}
	if (!stuck)
	{//move the snake on the board
		body[size - 1].draw(' ');
		theGame->updateBoard(body[size - 1].getX(), body[size - 1].getY(), ' ');
		for (int i = size - 1; i > 0; --i)
			body[i] = body[i - 1];
		theGame->updateBoard(nextPoint.getX(), nextPoint.getY(), symbol);
		body[0].move(direction);
		setTextColor(color);
		body[0].draw(symbol);
	}
	return 0;
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