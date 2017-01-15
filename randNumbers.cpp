#include "randNumbers.h"
#include "TheSnakesGame.h"


enum { OFFSET = 5 };
bool randNumbers::goodNum(int numMission, int num)
{
	return missions[numMission]->isCorrectNum(num);
}

bool randNumbers::showNumbers(int num)
{
	int size = numVec.size();
	bool findNum = false;
	for (int i = 0; i < size; i++) //loop through all numbers to find correct ones for this mission
	{
		if (goodNum(num, numVec[i].num))
		{
			game->flashNum(numVec[i], YELLOW); 
			findNum = true;
		}
	}
	if (findNum) //we want to show them for a coupele of seconds and then move on
	{
		Sleep(3000);
		for (int i = 0; i < size; i++)
		{
			if (goodNum(num, numVec[i].num))
			{
				game->flashNum(numVec[i], WHITE);
				findNum = true;
			}
		}
	}
	return findNum;

}
void randNumbers::removeAll() {
	int size = numVec.size();
	int x, y;
	for (int i = 0; i < size; i++) { //loop through all numbers in the vector and remove them from everywhere
		y = numVec[i].p.getY();
		x = numVec[i].p.getX();
		gotoxy(y, x + OFFSET);
		for (int j = 0; j < (int)(log10(numVec[i].num) + 1); j++) {
			cout << ' ';
			this->game->updateBoard(x, y + j, ' ');
		}
	}
	numVec.erase(numVec.begin(), numVec.begin() + size);
}
void randNumbers::removeHalf() {
	int size = numVec.size();
	int x, y;
	for (int i = 0; i < size / 2; i++) {
		y = numVec[i].p.getY();
		x = numVec[i].p.getX();
		gotoxy(y, x + OFFSET);
		for (int j = 0; j < (int)(log10(numVec[i].num) + 1); j++) {
			cout << ' ';
			this->game->updateBoard(x, y + j, ' ');
		}
	}
	numVec.erase(numVec.begin(), numVec.begin() + size / 2);
}
void randNumbers::addNumber() {
	numCoord newCoord = findSpot();
	numVec.push_back(newCoord);
	string str = to_string(newCoord.num);
	int x = newCoord.p.getX(), y = newCoord.p.getY();
 	for (int i = 0; i < newCoord.len; i++) {
		game->updateBoard(x, y + i, str[i]);
		gotoxy(y + i, x + OFFSET);
		cout << str[i];
	}
	
	
}

int randNumbers::generateNumber() {
	int odds;
	int generated;
	odds = rand() % 3;
	switch (odds) {
	case 0:
		generated = rand() % 25 + 1;
		break;
	case 1:
		generated = rand() % 56 + 26;
		break;
	case 2:
		generated = rand() % 88 + 82;
		break;
	default: 
		return 10;
		break;
	}
	return generated;
}
int randNumbers::whatNum(const Point& p) {
	int res = -1;
	Point left1(p.getX(), (p.getY() - 1) % 80), left2(p.getX(), (p.getY() -2) % 80);
	for (unsigned int i = 0; i < numVec.size(); i++) {
		if (numVec[i].p.isSame(p) || numVec[i].p.isSame(left1) || numVec[i].p.isSame(left2)) {
			res = numVec[i].num;
			swap(numVec[0], numVec[i]);
		}
	}
	return res;
}
void randNumbers::DeleteNum(const Point& p) {
	int res = -1, x, y;
	Point left1(p.getX(), (p.getY() - 1) % 80), left2(p.getX(), (p.getY() - 2) % 80);
	for (unsigned int i = 0; i < numVec.size(); i++) {
		if (numVec[i].p.isSame(p) || numVec[i].p.isSame(left1) || numVec[i].p.isSame(left2)) {
			y = numVec[i].p.getY();
			x = numVec[i].p.getX();
			gotoxy(y, x + OFFSET);
			for (int j = 0; j < (int)(log10(numVec[i].num) + 1); j++) {
				cout << ' ';
				this->game->updateBoard(x, y + j, ' ');
			}
			numVec.erase(numVec.begin() + i);
			return;
		}
	}
}
numCoord randNumbers::findSpot() {
	numCoord res;
	res.num = generateNumber();
	res.len = (int)(log10(double(res.num))) + 1;
	int x, y;
	bool goodSpot = false;
	while (!goodSpot) {
		x = rand() % 24;
		y = rand() % (80 - res.len);
		goodSpot = checkSpot(x, y, res.len);
	}
	res.p.set(x,y);
	return res;

}
bool randNumbers::checkSpot(const int& x, const int& y, const int& len) {
	bool res = true;
	char around[3];
	for (int i = 0; i < len; i++) {
		around[0] = game->boardChar(x, (y + i) % 80);
		around[1] = game->boardChar( (x + 1) % 24, (y + i) % 80);
		around[2] = game->boardChar( (x - 1) % 24, (y + i) % 80);
		//check spot for the length of the number (1 to 3) and it's above/below spot
		

		if ((around[0] != ' ' && around[0] != '\0') ||
			(around[1] != ' ' && around[1] != '\0') ||
			(around[2] != ' ' && around[2] != '\0')  ) res = false;
	}
	around[0] = game->boardChar( x, (y - 1) % 80);
	around[1] = game->boardChar( x, (y + len) % 80);
	if ((around[0] != ' ' && around[0] != '\0') || (around[1] != ' ' && around[1] != '\0')) res = false;
	return res;

}
int randNumbers::countSteps(const Point& p1, const Point& p2)
{
	int xdistance, ydistance;
	xdistance = (int)min(((24 - max(p1.getX(),p2.getX()))+ min(p1.getX(), p2.getX())),fabs(p1.getX() - p2.getX()));
	ydistance =(int)min(((80 - max(p1.getY(), p2.getY())) + min(p1.getY(), p2.getY())), fabs(p1.getY() - p2.getY()));
	return xdistance + ydistance;
}
int randNumbers::findCloseNum(const Point& p)
{
	int minSteps = 1000;
	Point res;
	bool found=false;
	for (int i = 0; i < numVec.size(); i++)
	{
		if (goodNum(game->getCurrMission(), numVec[i].num))
		{
			if (countSteps(p, numVec[i].p) < minSteps)
			{
				found = true;
				minSteps = countSteps(p, numVec[i].p);
				res = numVec[i].p;
			}
		}
	}
	if (!found)
		return 4;
	if (res.getY() < p.getY())
	{
		if ((80 - max(res.getY(), p.getY()) + min(res.getY(), p.getY())) >= fabs(res.getY() - p.getY()))
			return LEFT;
		else//Go through the wall 
			return RIGHT;
	}
	else if (res.getY() > p.getY())
	{
		if ((80 - max(res.getY(), p.getY()) + min(res.getY(), p.getY())) >= fabs(res.getY() - p.getY()))
			return RIGHT;
		else
			return LEFT;
	}
	else if (res.getX() < p.getX())
	{
		if ((24 - max(res.getX(), p.getX())) + min(res.getX(), p.getX()) >= fabs(res.getX() - p.getX()))
			return UP;
		else
			return DOWN;
	}
	else if (res.getX() > p.getX())
	{
		if ((24 - max(res.getX(), p.getX())) + min(res.getX(), p.getX()) >= fabs(res.getX() - p.getX()))
			return DOWN;
		else
			return UP;
	}
		
	else
		return 4;//DONT MOVE

}