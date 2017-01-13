#ifndef _THESNAKESGAME_H_
#define _THESNAKESGAME_H_
#include "io_utils.h"
#include "snake.h"
#include "Menu.h"
#include "randNumbers.h"
#include "Bullet.h"
//#include "creature.h"
#include "LineFly.h"
#include "numberEater.h"
#include "ColFly.h"
using namespace std;

enum { ROWS = 24, COLS = 80 ,SIZECR = 5};
enum { UP = 0, DOWN, LEFT, RIGHT };
class Bullet;
class Creature;
//class LineFly;
class TheSnakesGame {
	enum { ESC = 27 };
	Snake **s;
	Menu theMenu;
	Mission mission;
	randNumbers gameNumbers;
	int currMission;
	bool endMission=false;
	int shownNumbers[60];
	char originalBoard[ROWS][COLS + 1];	// this is the original board that we got (we need COLS+1 because we handle it as null terminated char*)
	char board[ROWS][COLS + 1];	// this is the actual board we play on, i.e. changes on board are done here
	vector <Bullet> bullets;
	//LineFly a;
	//numberEater b;
	Creature **cr;
public:
	TheSnakesGame()
		: theMenu(this), gameNumbers(this) //a(this,Point(23,30),false,RIGHT),b(this,Point(19,10))
	{
		 //(this, Point(30, 23), false, RIGHT);
		cr = new Creature*[SIZECR];
		cr[0] = new LineFly(this, Point(23, 30), false, RIGHT);
		cr[1] = new LineFly(this, Point(15, 50), true, LEFT);
		cr[2] = new ColFly(this, Point(23, 45), true, UP);
		cr[3] = new ColFly(this, Point(15, 55), false, DOWN);
		cr[4] = new numberEater(this, Point(19, 10));
		s = new Snake*[2];
		s[0] = new Snake(RIGHT, 3, '@', Point(9, 10), LIGHTMAGENTA, 'z');
		s[1] = new Snake(LEFT, 3, '#', Point(9, 70), LIGHTCYAN, 'n');
		system("mode con:cols=80 lines=30");
	}
	int getNumFromArray(const Point &p) { //pipe through the randNumbers class for easy access 
		return gameNumbers.whatNum(p);
	}
	int getCurrMission() {
		return currMission;
	}
	void startMission() { //create random display new mission in menu
		currMission = rand() % 8;
		theMenu.newMission(currMission);
		if (currMission == 7)
			mission.set7(theMenu.getM7());
	}
	void updateBullets(char symbol, int newAmount) {
		int row = (symbol == '#' ? 3 : 2);
		char numbers[2];
		numbers[0] = '0' + newAmount;
		numbers[1] = '\0';
		theMenu.edit(row, 76, numbers);
		theMenu.print(WHITE);
	}
	void printBoard();
	void updateBoard(int x, int y, const char let) {
		board[x][y] = let;
	}
	void setBoard(const char* boardToCopy[ROWS]);
	void init();
	void displayStartMenu() {
		s[0]->clearBody();
		s[1]->clearBody();
		s[0]->newSnake(9, 10, RIGHT);
		s[1]->newSnake(9, 70, LEFT);
		gameNumbers.removeAll();
		theMenu.updateScoreBoard(s[0]->getSize(), s[1]->getSize());
		theMenu.displayStartMenu();

	}
	void setSnakes();//set snakes places 
	bool isWall(const Point& p, char sym) {
		return board[p.getX()][p.getY()] == sym;
	}
	char boardChar(const Point& p) {
		return board[p.getX()][p.getY()];
	}
	char boardChar(const int &x, const int &y) {
		setTextColor(WHITE);
		return board[x][y];
	}
	void finishMission();//handle the end of the mission - clear the numbers ,the board and adjust the snake and then uses nextmission function 
	void handleMove(int snakeNum,int opsnakeNum,int missionend, int &counter);//handle the move of the snakes
	void run();//handle the run of the game including mission snakes and numbers
	void userSelectionMenu(char &key);//handle the user selection after he chose esc to see the menu-deal with resume,restart game and etc
	void nextMission();//get the next mission(random mission) and start the mission
	void flashNum(numCoord numVec, Color color);//this function flash all the correct answers
	Mission returnM()
	{//send the existing mission with all the mission values
		return mission;
	}
	void DeletNumFromArray(const Point &p) { //pipe through the randNumbers class for easy access 
		gameNumbers.DeleteNum(p);
	}
	void addShot(int numSnake);//add new shot - also check that there is any bullets left for the snake
	void deleteShot(int i) {
		if (bullets.size() == 1)
			bullets.clear(); 
		else
			bullets.erase(bullets.begin() + i);
	}
	void clearShoots();
	void moveBul();//this function manage the bullets movement including check if hit number or snake 
	bool bulletcollidesnake(Snake *s);//check if the snake hit his bullet or enemy bullet
	bool checkValidMove(Bullet b,int index);//check if the movement of the bullet is valid - if not handle each case(number or snake)
	void killShot(const Point &p,bool kill)
	{
		for (int i = 0; i < bullets.size(); i++)
		{
			if (bullets[i].getBullet().isSame(p))
			{
				if(!kill)
					bullets[i].getfSnake()->addBullet();
				bullets[i].clearBul();
				deleteShot(i);
				return;
			}
		}
	}
	int Creaturecollidesnake(Snake *s);
	bool ObjectCollide(Point p, bool killBul, bool killSnake);//this function handle object collide-and return if the object can do his next move (if free space or if he can kill the snake/bullet(whatever he ran into) and move on
		
	int getNextMove(const Point &p)
	{
		return gameNumbers.findCloseNum(p);
	}
};

#endif
