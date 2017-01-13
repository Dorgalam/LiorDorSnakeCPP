#include "LineFly.h"
#include "TheSnakesGame.h"
void LineFly::move()
{
	
	if (dir == LEFT&&p.getX() == 0 && ChangingSides)
		dir = RIGHT;
	if (dir == RIGHT &&p.getX() == 79 && ChangingSides)
		dir = LEFT;
	Point nextPoint = p.next(dir);
	game->ObjectCollide(nextPoint, true, false);//this function need to kill all the enemy that we will run into
	setTextColor(WHITE);
	game->updateBoard(p.getX(), p.getY(), ' ');
	p.draw(' ');
	p = p.next(dir);
	game->updateBoard(p.getX(), p.getY(), symbol);
	p.draw(symbol);
}
