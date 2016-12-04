#include "Snake.h"
#include "TheSnakesGame.h"
#include <list>

void Snake::move()
{
	body->back().draw(' ');
	//body[SIZE - 1].draw(' ');
	for (int i = SIZE - 1; i > 0; --i)
		body[i] = body[i - 1];
		

	if (theGame->isWall(body->pop_front.next(direction), this->symbol))
		direction = 4;
	theGame->updateBoard(body->pop_front.next(direction).getX(), body->pop_front.next(direction).getY(), symbol);
	body->pop_front.move(direction);
	setTextColor(color);
	body->pop_front.draw(symbol);
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