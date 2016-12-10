#include "Point.h"

void Point::move() {
	int dir = rand() % 4;
	move(dir);
}

void Point::move(int dir) {
	switch (dir) {
	case 0: // UP
		--x;
		if (x < 1) {
			x = 28;
		}
		break;
	case 1: // DOWN
		++x;
		if (x > 28) {
			x = 1;
		}
		break;
	case 2: // LEFT
		--y;
		if (y < 1) {
			y = 79;
		}
		break;
	case 3: // RIGHT
		++y;
		if (y > 79) {
			y = 1;
		}
		break;
	}
}