#include "Creature.h"
<<<<<<< HEAD
#include "TheSnakesGame.h"
void Creature::clearCr() {
	game->updateBoard(p.getX(), p.getY(), ' ');
	p.draw(' ');
}
=======

>>>>>>> master
void Creature::move()
{
	p.move(dir);
}