#include "randNumbers.h"
#include "TheSnakesGame.h"
#include <string>

void randNumbers::addNumber() {
	numCoord newCoord = findSpot();
	numVec.push_back(newCoord);
	string str = to_string(newCoord.num);
 	for (int i = 0; i < newCoord.len; i++) {
		int x = newCoord.p.getX(), y = newCoord.p.getY();
		game->updateBoard(x, y + i, str[i]);
		gotoxy(x+ i, y);
		cout << str[i];
	}
}

int randNumbers::generateNumber() {
	int odds;
	int generated;
	odds = rand() % 3;
	switch (odds) {
	case 0:
		generated = rand() % 26;
		break;
	case 1:
		generated = rand() % 56 + 26;
		break;
	case 2:
		generated = rand() % 88 + 82;
		break;
	}
	return generated;

}
int randNumbers::whatNum(const Point& p) {
	int res = -1;
	Point left1((p.getX() - 1) % 80 , p.getY()), left2((p.getX() - 2) % 80, p.getY());
	for (int i = 0; i < numVec.size(); i++) {
		if (numVec[i].p.isSame(p) || numVec[i].p.isSame(left1) || numVec[i].p.isSame(left2)) res = numVec[i].num;
	}
	return res;
}
numCoord randNumbers::findSpot() {
	numCoord res;
	res.num = generateNumber();
	res.len = (int)log10(res.num) + 1;
	int x, y;
	bool goodSpot = false;
	while (!goodSpot) {
		x = rand() % 24 + 5;
		y = rand() % (80 - res.len);
		goodSpot = checkSpot(x, y, res.len);
	}
	res.p.set(y, x);
	return res;

}
bool randNumbers::checkSpot(const int& x, const int& y, const int& len) {
	bool res = true;
	char around[3];
	for (int i = 0; i < len; i++) {
		around[0] = game->boardChar(x, (y + i) % 80);
		around[1] = game->boardChar((x + 1) % 24, (y + i) % 80);
		around[2] = game->boardChar((x - 1) % 24, (y + i) % 80);
		//check spot for the length of the number (1 to 3) and it's above/below spot
		

		if ((around[0] != ' ' && around[0] != '\0') ||
			(around[1] != ' ' && around[1] != '\0') ||
			(around[2] != ' ' && around[2] != '\0')  ) res = false;
	}
	around[0] = game->boardChar(x, (y - 1) % 80);
	around[1] = game->boardChar(x, (y + len) % 80);
	if ((around[0] != ' ' && around[0] != '\0') || (around[1] != ' ' && around[1] != '\0')) res = false;
	return res;

}