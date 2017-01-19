#ifndef _THESNAKESGAME_H_
#define _THESNAKESGAME_H_
#include <typeinfo>
#include "io_utils.h"
#include "snake.h"
#include "Menu.h"
#include "randNumbers.h"
#include "Bullet.h"
#include "LineFly.h"
#include "numberEater.h"
#include "ColFly.h"
#include "oneOP.h"
#include "twoOP.h"
#include "threeOP.h"
#include "fiveOP.h"
#include "Rewind.h"

using namespace std;

enum { ROWS = 24, COLS = 80 ,SIZECR = 5};
enum { UP = 0, DOWN, LEFT, RIGHT };
class Bullet;
class Creature;
class MissionBank;

class TheSnakesGame {
	enum { ESC = 27 };
	Snake **s;
	Menu theMenu;
	//Mission mission;
	randNumbers gameNumbers;
	Rewind rwind;
	int currMission;
	int shownNumbers[60];
	char originalBoard[ROWS][COLS + 1];	// this is the original board that we got (we need COLS+1 because we handle it as null terminated char*)
	char board[ROWS][COLS + 1];	// this is the actual board we play on, i.e. changes on board are done here
	vector <Bullet> bullets;
	MissionBank **m;
	Creature **cr;
public:
	
	TheSnakesGame()
		: theMenu(this,m), gameNumbers(this,m) //a(this,Point(23,30),false,RIGHT),b(this,Point(19,10))
	{
		//CreateMissions();
		//theMenu.setBank(m);
		//gameNumbers.setBank(m);
		//theMenu.setMission(2);
		createCreatures();
		system("mode con:cols=80 lines=30");
	}
	void addChangesToRewind(int x, int y, char let) {
		rwind.moreChanges(x, y, let);
	}
	void setCreatures()
	{
		for (int i = 0; i < SIZECR; i++)
		{
			cr[i]->setG(this);
		}
		s[0]->setM(m);
		s[1]->setM(m);
	}
	void createCreatures()
	{
		cr = new Creature*[SIZECR];
		cr[0] = new LineFly(this, Point(23, 30), false, RIGHT);
		cr[1] = new LineFly(this, Point(15, 50), true, LEFT);
		cr[2] = new ColFly(this, Point(23, 45), true, UP);
		cr[3] = new ColFly(this, Point(15, 55), false, DOWN);
		cr[4] = new numberEater(this, Point(19, 10));
		s = new Snake*[2];
		s[0] = new Snake(RIGHT, 3, '@', Point(9, 10), LIGHTMAGENTA, 'z', m);
		s[1] = new Snake(LEFT, 3, '#', Point(9, 70), LIGHTCYAN, 'n', m);
	}
	void CreateMissions(const char *fileName);//this function build the missions bank from the txt file that given
	MissionBank* buildEXE(char *str);//creating the mission for the given string by number of operators construct the mission
		
	int getNumFromArray(const Point &p) { //pipe through the randNumbers class for easy access 
		return gameNumbers.whatNum(p);
	}
	int getCurrMission() {
		return currMission;
	}
	void rewindNow() {
		rwind.go();
	}
	void startMission();
	void updateBullets(char symbol, int newAmount);
	void printBoard();
	void updateBoard(int x, int y, const char let);
	void setBoard(const char* boardToCopy[ROWS]);
	void init();
	void displayStartMenu();
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
	//Mission returnM(){return mission;}//send the existing mission with all the mission values
	void DeletNumFromArray(const Point &p) { //pipe through the randNumbers class for easy access 
		gameNumbers.DeleteNum(p);
	}
	void addShot(int numSnake);//add new shot - also check that there is any bullets left for the snake
	void deleteShot(int i);
	void clearShoots();
	void moveBul();//this function manage the bullets movement including check if hit number or snake 
	bool bulletcollidesnake(Snake *s);//check if the snake hit his bullet or enemy bullet
	bool checkValidMove(Bullet b,int index);//check if the movement of the bullet is valid - if not handle each case(number or snake)
	void killShot(const Point &p, bool kill);
	int Creaturecollidesnake(Snake *s);//this function check if the snake's next move is one of the creatures- and handle each case .
	bool ObjectCollide(Point p, bool killBul, bool killSnake);//this function handle object collide-and return if the object can do his next move (if free space or if he can kill the snake/bullet(whatever he ran into) and move on 
    //this function go to the randNumbers on the board and check which correct number closer to the given point and return the next direction where to move to get closer .if there is no correct number return 4(don’t move)
	int getNextMove(const Point &p){return gameNumbers.findCloseNum(p);}
	bool creaturePlace(const Point &p);//this function check if the point is a creature 
	void handleCreatureCollideBul(int index, const Point& p);
	void handleCreatureMove();//this function move the creatures,number eaters and Line fly double speed
};

#endif
