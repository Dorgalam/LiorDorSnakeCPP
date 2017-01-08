#ifndef _THESNAKESGAME_H_
#define _THESNAKESGAME_H_
#include "io_utils.h"
#include "snake.h"
#include "Menu.h"
#include "randNumbers.h"
#include "Bullet.h"

using namespace std;

enum { ROWS = 24, COLS = 80 };
enum { UP = 0, DOWN, LEFT, RIGHT };
class Bullet;
class TheSnakesGame {
	enum { ESC = 27 };
	Snake **s;
	Menu theMenu;
	Mission mission;
	randNumbers gameNumbers;
	int currMission;
	int shownNumbers[60];
	char originalBoard[ROWS][COLS + 1];	// this is the original board that we got (we need COLS+1 because we handle it as null terminated char*)
	char board[ROWS][COLS + 1];	// this is the actual board we play on, i.e. changes on board are done here
	vector <Bullet> bullets;
public:
	TheSnakesGame()
		: theMenu(this), gameNumbers(this)
	{
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
};

#endif
