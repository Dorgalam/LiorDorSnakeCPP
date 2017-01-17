#include "TheSnakesGame.h"
#include "Bullet.h"
#include "Creature.h"
void TheSnakesGame::startMission() { //create random display new mission in menu
	currMission = rand() % 8;
	theMenu.newMission(currMission);//set the mission - on the menu
	gameNumbers.setMissin(m[currMission], currMission);//set the mission - the rand numbers
}
void TheSnakesGame::finishMission()
{
	m[currMission]->initMis();
	s[0]->clearSnake();
	s[1]->clearSnake();
	theMenu.updateScoreBoard(s[0]->getSize(), s[1]->getSize());
	gameNumbers.removeHalf();//clean the half board and the snakes
	nextMission();//go to next mission
	theMenu.updateScoreBoard(s[0]->getSize(), s[1]->getSize());
}
void TheSnakesGame::updateBullets(char symbol, int newAmount) {
	int row = (symbol == '#' ? 3 : 2);
	char numbers[2];
	numbers[0] = '0' + newAmount;
	numbers[1] = '\0';
	theMenu.edit(row, 76, numbers);
	theMenu.print(WHITE);
}
void TheSnakesGame::clearShoots()
{
	for (unsigned int i = 0; i < bullets.size(); i++)
	{
		bullets[i].clearBul();
	}
	bullets.clear();
}
void TheSnakesGame::displayStartMenu() {
	s[0]->clearBody();
	s[1]->clearBody();
	s[0]->newSnake(9, 10, RIGHT);
	s[1]->newSnake(9, 70, LEFT);
	gameNumbers.removeAll();
	theMenu.updateScoreBoard(s[0]->getSize(), s[1]->getSize());
	theMenu.displayStartMenu();

}
void TheSnakesGame::setSnakes()
{
	s[0]->Setsuspend(false);
	s[1]->Setsuspend(false);
	if (gameNumbers.getSize() != 0)
	{//make sure that the snake wont be on a number
		s[0]->findFreeSpot(s[1]);
		s[1]->findFreeSpot(s[0]);
	}
	else {
		s[0]->backToStart(9, 10, RIGHT);
		s[1]->backToStart(9, 70, LEFT);
	}
	s[0]->setBul(5);
	s[1]->setBul(5);
	clearShoots();
}
void TheSnakesGame::flashNum(numCoord numVec, Color color)
{
	setTextColor(color);
	string str = to_string(numVec.num);
	int x = numVec.p.getX(), y = numVec.p.getY();
	for (int i = 0; i < numVec.len; i++) {
		updateBoard(x, y + i, str[i]);
		gotoxy(y + i, x + 5);
		cout << str[i];
	}
	setTextColor(WHITE);
}
void TheSnakesGame::nextMission()
{
	startMission();
	for (int i = 0; i < SIZECR; i++)
		cr[i]->setSuspend(false);
	setSnakes();
 }
void TheSnakesGame::setBoard(const char* boardToCopy[ROWS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			originalBoard[i][j] = boardToCopy[i][j];
		}
		originalBoard[i][COLS] = '\0';
	}
}

void TheSnakesGame::init()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			gotoxy(j , i + 5);
			cout << originalBoard[i][j];
			cout.flush();
			board[i][j] = originalBoard[i][j];
		}
		board[i][COLS] = '\0';
	}
	nextMission();
	s[0]->setGame(this);
	s[1]->setGame(this);
	s[0]->setArrowKeys("wxad");
	s[1]->setArrowKeys("imjl");
}
void TheSnakesGame::printBoard() {
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			gotoxy(j, i + 5);
			cout << board[i][j];
			cout.flush();
		}
	}
}
void TheSnakesGame::handleMove(int snakeNum,int opsnakeNum ,int missionEnd,int &counter)
{
	moveBul();
	if (!s[snakeNum]->isSuspend())
	{
		missionEnd = s[snakeNum]->move(s[opsnakeNum]->getSymbol(), currMission);
		if (missionEnd == 2)
		{//ate a wrong number-erase the snakes from the board and screen+remove half of the numbers
			s[opsnakeNum]->snakeGrow();
			theMenu.displayWinningMenu(opsnakeNum);
			gameNumbers.showNumbers(currMission);
			finishMission();
		}
		else if (missionEnd == 3)
			s[opsnakeNum]->addBullet();
		else if (missionEnd)
		{//ate a correct number
			theMenu.displayWinningMenu(snakeNum);
			finishMission();
		}
	}
	else
		counter++;
}
void TheSnakesGame::userSelectionMenu(char &key)
{
	int clickedEscape = theMenu.displayIngameMenu();
	if (clickedEscape != 1) {
		key = rand() % 4;
		if (clickedEscape != 3)
		{
			for (int i = 0; i < SIZECR; i++)
				cr[i]->setSuspend(false);
		}
		if (clickedEscape != 3 && clickedEscape != 6 && clickedEscape != 2)
		{
			s[0]->clearSnake();
			s[1]->clearSnake();
			setSnakes();
			if (clickedEscape == 4)
				gameNumbers.removeAll();
		}
		else if (clickedEscape == 6)
		{
			s[0]->clearBody();
			s[1]->clearBody();
			s[0]->newSnake(9, 10, RIGHT);
			s[1]->newSnake(9, 70, LEFT);
			gameNumbers.removeAll();
			theMenu.updateScoreBoard(s[0]->getSize(), s[1]->getSize());

		}
	}
	else
		key = ESC;
}
void TheSnakesGame::handleCreatureMove()
{
	for (int i = 0; i < SIZECR; i++)
	{
		cr[i]->move();
		if (typeid(*cr[i]) != typeid(ColFly))
			cr[i]->move();
	}
}
void TheSnakesGame::run()
{
	int count = 1,susCount1 = 1,susCount2 = 1,dir,missionEnd;
	char key = 0;
	theMenu.print(WHITE);//print the instruction
	theMenu.updateScoreBoard(s[0]->getSize(), s[1]->getSize());
	do
	{
		if (count % 5 == 0) {
			count = 0;
			this->gameNumbers.addNumber();

		}
		if (susCount1 % 25 == 0)
		{
			susCount1 = 1;
			s[0]->Setsuspend(false);
			s[0]->findFreeSpot(s[1]);

		}
		if (susCount2 % 25 == 0)
		{
			susCount2 = 1;
			s[1]->Setsuspend(false);
			s[1]->findFreeSpot(s[0]);

		}
		missionEnd = 0;
		if (_kbhit())
		{
			key = _getch();
			if (key == s[0]->getShoot()&& s[0]->isSuspend() == false)
			{//'z'- shoot been pick
				addShot(0);
			}
			if (key == s[1]->getShoot() && s[1]->isSuspend() == false)
			{//'n' 
				addShot(1);
			}
			if ((dir = s[0]->getDirection(key)) != -1)
				s[0]->setDirection(dir);
			else if ((dir = s[1]->getDirection(key)) != -1)
				s[1]->setDirection(dir);
		}
		handleMove(0, 1, missionEnd, susCount1);//moving the snake and handle avery possible case(eating number,coliide with bullet and so on)
		handleMove(1, 0, missionEnd, susCount2);
		handleCreatureMove();
		if (gameNumbers.getSize() == 60)
		{
			bool wasCorrectAnswer = gameNumbers.showNumbers(currMission);//show the numbers that is correct
			theMenu.displayNumMenu(wasCorrectAnswer);
			finishMission();
		}
		count++;
		Sleep(200);
		if (key == ESC) {
			count = 1;
			userSelectionMenu(key);
		}
		if (s[0]->getSize() == 15)
		{//earned 12 points
			key = ESC;
			theMenu.displayVictoryMenu(0);
		}
		if (s[1]->getSize() == 15)
		{
			key = ESC;
			theMenu.displayVictoryMenu(1);
		}
	} while (key != ESC);
	s[0]->~Snake();
	s[1]->~Snake();

}
bool TheSnakesGame::checkValidMove(Bullet b, int index)
{
	Point nextPoint = b.GetNext();//b.next
	char nextSpot = boardChar(nextPoint);
	if (nextSpot >= '0' && nextSpot <= '9') {
		b.clearBul();
		deleteShot(index);
		DeletNumFromArray(nextPoint);//kill the number
	}
	else if (nextSpot == s[0]->getSymbol())//check if the next direction is already taken - 
	{
		if (b.getfSnake()->getSymbol() != s[0]->getSymbol())
			s[1]->addBullet();//add bullet as reward for killing the rival's snake
		b.clearBul();
		deleteShot(index);//delete shot
		s[0]->clearSnake();
		s[0]->Setsuspend(true);//kill snake
	}
	else if (nextSpot == s[1]->getSymbol())//check if the next direction is already taken - 
	{
		if (b.getfSnake()->getSymbol() != s[1]->getSymbol())
			s[0]->addBullet();//add bullet as reward for killing the rival's snake
		b.clearBul();
		deleteShot(index);//delete shot
		s[1]->clearSnake();
		s[1]->Setsuspend(true);//kill snake
	}
	else if (nextSpot == '*')
	{//check for shots collide - in this case delete the shots
		for (unsigned int j = 0; j < bullets.size(); j++)
		{
			//if (bullets[i].getBullet().getX() != bullets[j].getBullet().getX()&& bullets[i].getBullet().getY() != bullets[j].getBullet().getY())
			if (nextPoint.isSame(bullets[j].getBullet()))
			{//shots COLLIDE
				b.clearBul();
				bullets[j].clearBul();
				deleteShot(max(j, (unsigned int)index));//delete shot 2
				deleteShot(min((unsigned int)index, j));//delete shot 1
				j = bullets.size();
			}
		}
	}
	else if (nextSpot != ' ')
	{
		handleCreatureCollideBul(index,nextPoint);
		bullets[index].clearBul();
		deleteShot(index);//delete shot
		//deal with the object - can do switch case
	}
	else
		return true;
	return false;
}
void TheSnakesGame::moveBul()
{//this function go over all the bullets and move them one step(point) if there is a collision taking care of it as required
	for (unsigned int i = 0; i < bullets.size();)
	{
		if(checkValidMove(bullets[i],i))
		{//next direction free - move the shot
			bullets[i].moveB();
			i++;
		}
	}
}
void TheSnakesGame::deleteShot(int i) {
	if (bullets.size() == 1)
		bullets.clear();
	else
		bullets.erase(bullets.begin() + i);
}
void TheSnakesGame::killShot(const Point &p, bool kill)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].getBullet().isSame(p))
		{
			if (!kill)
				bullets[i].getfSnake()->addBullet();
			bullets[i].clearBul();
			deleteShot(i);
			return;
		}
	}
}
void TheSnakesGame::addShot(int numSnake)
{
	bool havebul = s[numSnake]->deleteBullet();//the snake down one bullet(if he has any left)
	if (havebul && s[numSnake]->getDirection() != 4)
	{
		if (ifstream("shoot.wav"))
			PlaySound(TEXT("shoot.wav"), NULL, SND_FILENAME);
		Point p = s[numSnake]->getbodyPlace();
		//p.move(s[numSnake]->getDirection());
		Bullet b(this, s[numSnake], p, s[numSnake]->getDirection(), s[numSnake]->getColor());//creating the bullet
		bullets.push_back(b);//put in the vector
		if(checkValidMove(b, bullets.size() - 1))
			bullets[bullets.size() - 1].StartMove();
	}
}
bool TheSnakesGame::bulletcollidesnake(Snake *s)
{
	bool enemybullet = false;
	for (unsigned int i = 0; i < bullets.size(); i++)
	{
		Point nextPoint = s->getbodyPlace().next(s->getDirection());
		if (nextPoint.isSame(bullets[i].getBullet()))
		{
			if (bullets[i].getfSnake()->getSymbol() != s->getSymbol())
				enemybullet = true;  //other s->addBullet();//add bullet as reward for killing the rival's snake
			bullets[i].clearBul();
			deleteShot(i);//delete shot
			s->clearSnake();
			s->Setsuspend(true);//kill snake
			return enemybullet;
		}
	}
	return enemybullet;
}
int TheSnakesGame::Creaturecollidesnake(Snake *s)
{
	Point nextPoint = s->getbodyPlace().next(s->getDirection());
	for (unsigned int i = 0; i < SIZECR; i++)
	{
		if (nextPoint.isSame(cr[i]->getPoint())&&!cr[i]->isSuspend())
		{
			s->Setsuspend(true);
			s->clearSnake();
			if (typeid(*cr[i]) == typeid(numberEater))//if you are number eater
			{
				Sleep(150);
				return 2;
			}
			else 
			{
				Creature *derived = dynamic_cast<Creature*>(cr[i]);
				if (derived)
				{
					//if (typeid(derived) != typeid(LineFly))
						//return 3;
					return 3;//3
				}
			}
		}
	}
	return 0;
}
bool TheSnakesGame::ObjectCollide(Point p, bool killBul, bool killSnake)
{//this function handle object collide-and return if the object can do his next move (if free space or if he can kill the snake/bullet(whatever he ran into) and move on
	if (isWall(p, s[0]->getSymbol()))
	{
		if (killSnake)
		{
			s[0]->clearSnake();
			Sleep(150);
			s[0]->Setsuspend(true);
			s[1]->snakeGrow();
			theMenu.displayWinningMenu(1);
			gameNumbers.showNumbers(currMission);
			finishMission();
		}
		else
		{
			s[0]->clearSnake();
			s[0]->Setsuspend(true);
		}
		return killSnake;
	}
	if (isWall(p, s[1]->getSymbol()))
	{
		if (killSnake)
		{
			s[1]->clearSnake();
			Sleep(150);
			s[1]->Setsuspend(true);
			s[0]->snakeGrow();
			theMenu.displayWinningMenu(0);
			gameNumbers.showNumbers(currMission);
			finishMission();
		}
		else
		{
			s[1]->clearSnake();
			s[1]->Setsuspend(true);
		}
		return killSnake;
	}
	if (isWall(p, '*'))
	{
		killShot(p, killBul);
		return killBul;
	}
	if ('0' <= boardChar(p) <= '9')
	{
		gameNumbers.DeleteNum(p);
	}
	////need to add the other objects - decide to do nothing or to kill both
	return true;
}
void TheSnakesGame::handleCreatureCollideBul(int index,const Point& p)
{
	for (int i = 0; i < SIZECR; i++)
	{
		if ((typeid(*cr[i]) == typeid(numberEater) || typeid(*cr[i]) == typeid(ColFly))&& cr[i]->getPoint().isSame(p) && !cr[i]->isSuspend())
		{//if you kind of creature that sensitive to bullet 
			bullets[index].getfSnake()->addBullet();
			cr[i]->setSuspend(true);
			cr[i]->clearCr();
			return;
		}
	}
}
bool TheSnakesGame::creaturePlace(const Point &p)
{
	for (int i = 0; i < SIZECR; i++)
	{
		if (cr[i]->getPoint().isSame(p))
			return true;
	}
	return false;
}