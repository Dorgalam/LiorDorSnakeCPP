#include "Bullet.h"
#include "TheSnakesGame.h"

void Bullet::moveB()
{
	setTextColor(color);
	G->updateBoard(p.getX(), p.getY(), ' ');
	p.draw(' ');
	p = p.next(direction);
	G->updateBoard(p.getX(), p.getY(), symbol);
	p.draw('*');
}
void Bullet::StartMove() {
	p = p.next(direction);
	setTextColor(color);
	G->updateBoard(p.getX(), p.getY(), '*');
	p.draw('*');
}
void Bullet::clearBul()
{
	p.draw(' ');
	G->updateBoard(p.getX(), p.getY(), ' ');
};