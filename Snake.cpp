#include "Snake.h"
#include "TheSnakesGame.h"

void Snake::move(char opSymbol)
{
	Point nextPoint = body[0].next(direction);
	char nextSpot = theGame->boardChar(nextPoint);
	if (nextSpot >= '0' && nextSpot <= '9') {
		int numCollected = theGame->getNumFromArray(nextPoint);
		if (numCollected != -1) cout << "SUCCESS!";
	}



	bool missionSuccess = false; 
	bool stop = (nextSpot == symbol);
	if (!theGame->isWall(body[0].next(direction), symbol))//next direction free
		stuck = false;
	if (theGame->isWall(body[0].next(direction), '8'))
	{//check food
		body.insert(body.end(), body[size - 1]);
		size++;
	}
	if ((theGame->isWall(body[0].next(direction), symbol)|| theGame->isWall(body[0].next(direction), opSymbol))&&direction!=4)
	{//check if the next direction is already taken - stop the snake movement
		direction = 4;
		stuck = true;
	}
	if (!stuck)
	{//move the snake on the board
		body[size - 1].draw(' ');
		theGame->updateBoard(body[size - 1].getX(), body[size - 1].getY(), ' ');
		for (int i = size - 1; i > 0; --i)
			body[i] = body[i - 1];
		theGame->updateBoard(body[0].next(direction).getX(), body[0].next(direction).getY(), symbol);
		body[0].move(direction);
		setTextColor(color);
		body[0].draw(symbol);
	}
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