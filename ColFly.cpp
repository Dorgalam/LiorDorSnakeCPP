#include "ColFly.h"
#include "TheSnakesGame.h"
void ColFly::move()
{
	if (!suspend)
	{
		if (dir == UP && p.getX() == 0 && ChangingSides)
			dir = DOWN;
		if (dir == DOWN && p.getX() == 23 && ChangingSides)
			dir = UP;
		Point nextPoint = p.next(dir);
		game->updateBoard(p.getX(), p.getY(), ' ');
		p.draw(' ');
		if (game->ObjectCollide(nextPoint, false, false))//this function need to kill all the enemy that we will run into
		{
			setTextColor(WHITE);
			p = p.next(dir);
			game->updateBoard(p.getX(), p.getY(), symbol);
			p.draw(symbol);
		}
		else
		{
			suspend = true;
		}
	}
}
