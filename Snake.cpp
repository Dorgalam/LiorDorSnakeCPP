#include "Snake.h"
#include "TheSnakesGame.h"

void Snake::move()
{
	body[SIZE - 1].draw(' ');
	for (int i = SIZE - 1; i > 0; --i)
		body[i] = body[i - 1];

	if (theGame->isWall(body[0].next(direction), this->symbol))
		direction = 4;
	theGame->updateBoard(body[0].next(direction).getX(), body[0].next(direction).getY(), symbol);
	body[0].move(direction);
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