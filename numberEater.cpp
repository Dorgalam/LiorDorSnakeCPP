#include "numberEater.h"
#include "TheSnakesGame.h"
void numberEater::setDraw()
{
	setTextColor(WHITE);
	p.draw(symbol);
	game->updateBoard(p.getX(), p.getY(), symbol);
}
void numberEater::move()
{
	//first lets find the movement-there is one only if there is a correct number
	dir = game->getNextMove(p);
	if (dir != 4&&!suspend)
	{
		game->updateBoard(p.getX(), p.getY(), ' ');
		p.draw(' ');
		if (game->ObjectCollide(p.next(dir), false, true))//kill snakes ,die from bullets
		{
			setTextColor(WHITE);
			p = p.next(dir);
			game->updateBoard(p.getX(), p.getY(), symbol);
			p.draw(symbol);
		}
		else
		{
			dir = 4;
			suspend = true;
		}
	}
	else if (!suspend)
	{
		game->updateBoard(p.getX(), p.getY(), symbol);
		p.draw(symbol);
	}
}