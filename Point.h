#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include "io_utils.h"

using namespace std;
//x represents row, y column
class Point {
	int x, y;
public:
	Point(int x1 = 1, int y1 = 6)
	{
		x = x1;
		y = y1;
	}
	int getX() const {
		return x;
	}
	int getY() const {
		return y;
	}
	void set(int _x, int _y) {
		x = _x;
		y = _y;
	}
	void draw(char ch) {
		gotoxy(y, x+5);
		cout << ch;
		cout.flush();
	}
	void move();
	void move(int direction);
	Point next(int direction) {
		Point next = *this;
		next.move(direction);
		return next;
	}
	bool isSame(const Point& p) const {
		return x == p.x && y == p.y;
	}
	void print() {
		cout << x << ' ' << y;
	}

};

#endif