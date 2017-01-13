#include "Creature.h"
#include "TheSnakesGame.h"
void Creature::clearCr() {
	game->updateBoard(p.getX(), p.getY(), ' ');
	p.draw(' ');
}
void Creature::move()
{
	p.move(dir);
}