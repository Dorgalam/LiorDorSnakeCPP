#include "snake.h"
#include "TheSnakesGame.h"
void Snake::setArrowKeys(const char* keys) {
	arrowKeys[0] = keys[0];
	arrowKeys[1] = keys[1];
	arrowKeys[2] = keys[2];
	arrowKeys[3] = keys[3];
}
void Snake::backToStart(int x, int y, int dir)
{
	for (unsigned int i = 0; i < body.size(); i++)
		body[i].set(x, y);
	direction = dir;
}
void Snake:: clearSnake()
{
	for (unsigned int i = 0; i < body.size(); i++) {
		theGame->updateBoard(body[i].getX(), body[i].getY(), ' ');
		body[i].draw(' ');
	}
	if(direction==4) direction = 3;
	//direction = 4;
	
}
bool Snake::checkNotSnake(Snake *s, Point p) {//check that the snake's body is not in this point
	for (unsigned int i = 0; i < s->body.size(); i++)
	{
		if (s->body[i].isSame(p))
			return false;
	}
	return true;
}
bool Snake::deleteBullet()
{
	if (numBul > 0)
	{
		numBul--;
		updateBullets();
		return true;
	}
	return false;
}
void Snake::updateBullets() {
	if (theGame == nullptr) 
		return;
	theGame->updateBullets(symbol, numBul);
}
bool Snake::goodNum(int numMission,int num)
{
	switch (numMission) {
	case 0:
		return m.isPrime(num);
		break;
	case 1:
		return m.div4(num);
		break;
	case 2:
		return m.div7(num);
		break;
	case 3:
		return m.isSquare(num);
		break;
	case 4:
		return m.div7rem3(num);
		break;
	case 5:
		return m.is169(num);
		break;
	case 6:
		return m.isPalindrom(num);
	default:
	case 7:
		getGameM(theGame->returnM());
		return m.mathExe(num);
		break;
		return false;
		break;
	}
}
int Snake::move(char opSymbol, int numOfMission)
{
	Point nextPoint = body[0].next(direction);
	char nextSpot = theGame->boardChar(nextPoint);
	int res=0;
	if (nextSpot >= '0' && nextSpot <= '9') {
		int numCollected = theGame->getNumFromArray(nextPoint);
		if (goodNum(numOfMission, numCollected)) {
			gotoxy(0, 0);
			body.push_back(body[body.size() - 1]);
			//size++;
			if (ifstream("eat.wav"))
				PlaySound(TEXT("eat.wav"), NULL, SND_FILENAME);
			return 1;
		}
		else if (ifstream("wrong.wav"))
			PlaySound(TEXT("wrong.wav"), NULL, SND_FILENAME);
		return 2;
	}
	else if (theGame->isWall(nextPoint, ' '))//next direction free
		stuck = false;
	else if ((theGame->isWall(nextPoint, symbol) || theGame->isWall(nextPoint, opSymbol)) && direction != 4)
	{//check if the next direction is already taken - stop the snake movement
		direction = 4;
		stuck = true;
		if (ifstream("punch.wav"))
			PlaySound(TEXT("punch.wav"), NULL, SND_FILENAME);
	}
	else if (theGame->isWall(nextPoint, '*'))
	{
		bool opbul = theGame->bulletcollidesnake(this);//check which bullet it is and take action as needed
		if(opbul)//true only if the bullet was of the other snake
			return 3;
	}
	res = theGame->Creaturecollidesnake(this);

	if (!stuck&&!suspended&&res==0)
	{//move the snake on the board
		body[body.size() - 1].draw(' ');
		theGame->updateBoard(body[body.size() - 1].getX(), body[body.size() - 1].getY(), ' ');
		for (int i = body.size() - 1; i > 0; --i)
			body[i] = body[i - 1];
		theGame->updateBoard(nextPoint.getX(), nextPoint.getY(), symbol);
		body[0].move(direction);
		setTextColor(color);
		body[0].draw(symbol);
	}
	return res;
}
int Snake::getDirection(char key)
{
	for (int i = 0; i < SIZE - 1; i++)
	{
		if (key == arrowKeys[i])
			return i;
	}
	return -1;
}
void Snake::newSnake(int x, int y, int dir)
{
	Point p;
	p.set(x, y);
	body.clear();
	for (int i = 0; i < 3; i++)
	{
		body.push_back(p);
	}
	direction = dir;
}

void Snake::findFreeSpot(Snake *s)
{
	int randx , randy;
	Point p;
	do {
		randx = rand() % 24;
		randy = rand() % 80;
		p.set(randx, randy);
	} while (!checkNotSnake(s,p)&&!theGame->creaturePlace(p));
	if (theGame->getNumFromArray(p) != -1)
		theGame->DeletNumFromArray(p);
	backToStart(p.getX(), p.getY(), direction);
}

