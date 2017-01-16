#ifndef _MENU_H
#define _MENU_H
#include "io_utils.h"
//#include "Mission.h"
#include "MissionBank.h"
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
enum { EASY = '1', HARD = '2', EXTREME = '3' };

enum { INSTRUCTIONS = '1', START='2', EXIT_START = '9' };
enum { EXIT_MID = '1', MAIN_MENU='2', RESUME='3', RESTART_MISSION='4', NEW_MISSION='5', RESTART_GAME='6' };
enum {Plus=0,Minus,Mult,Div};
class TheSnakesGame;
//class Mission;
class MissionBank;
class Menu  {
	TheSnakesGame *game;
	MissionBank **m;
	Color txtColor=WHITE;
	char screen[5][82] = {
		//		  10        20        30        40        50        60        70   
		//01234567890123456789012345678901234567890123456789012345678901234567890123456789 
		"--------------------------------------------------------------------------------",// 0
		"|                                                                  SCORE | MAG |",// 1
		"|                                                          SNAKE 1:      |  5  |",// 2
		"|                                                          SNAKE 2:      |  5  |",// 3
		"--------------------------------------------------------------------------------",// 4
	};
	
	char *startMenu[3] = {
		"(1) Instructions",
		"(2) Start",
		"(9) Exit",
	}; //string instructions
	char *level[3] = {
		"(1) easy",
		"(2) hard",
		"(3) Extreme",
	}; //string levels
	char *inGameMenu[6] = {
		"(1) Exit",
		"(2) Main Menu",
		"(3) Resume",
		"(4) Restart Mission",
		"(5) New Mission",
	    "(6) Restart Game",
	}; //menu items
	char *missions[8] = {
		"Look for: Prime number",
		"Look for: Number divisible by 4",
		"Look for: Product of 7",
		"Look for: Squared Integer",
		"Look for: Divided by 7 remainder is 3",
		"Look for the number 13^2",
		"Look for: Palindrome number",
	}; // string missions
	char *missionsBank[8] = {
		
	}; // string missions
	char *instructions = {
		"Two snakes battling over mathematical superiority.\nControl the greed $ snake with 'wxad' shoot by 'z',\nthe more calculated # snake with 'ijkl' shoot by 'n'.\nThe snake have each mission 5 bullets,\nIf one of the bullets hit the other snake, he gets another bullet,\nBullets hitting the numbers conceal them, \nComplete missions to score points and eventually win.\nBeware, wrong solutions will result in the other players point.\nThe first to get to 12 points win the Game!\nGood luck and may Sir Isaac Newton be with you!"
	}; //humoristic instructions
	char *snakeWonMission[2] = {
		"Snake 1 won this round",
		"Snake 2 won this round",
	};
	char *Num60Menu[2] = {
		"There is no correct number ,good try!!!",
		"The yellow numbers were possible answers,try better",
	};
	char *victoryMenu[2] = {
		"congratulation:) snake 1 won the game!!!",
		"congratulation:) snake 2 won the game!!!",
	};
public:
	Menu(TheSnakesGame *_game, MissionBank **_m) : game(_game) ,m(_m){}
	void setG(TheSnakesGame *_game)
	{
		game = _game;
	}
	void print(Color c);
	void setColor(Color c) {
		txtColor = c;
	}
	void edit(int x, int y, char *str);//edit the menu

	void clear();//clear everytthing within the menu
	void newMission(int numMission, bool needUpdate = true);//print the new mission in the menu
	void displayStartMenu(); 
	void displayInstructions() {
		gotoxy(0, 5);
		cout << instructions;
		displayStartMenu();
	}
	int displayIngameMenu();//print the menu options
	void displayWinningMenu(int num);//display the snake that won the mission
	void displayVictoryMenu(int num);//display the snake that won the game
	void displayNumMenu(bool num);//display all the numbers that are correct answers mark
	void updateScoreBoard(int score1, int score2);//manage the score board - same as the snakes length
	//self explanatory function names
	char* castingOP(int op);// 0='+' , 1='-' ,2='*' , 3='/'
	char* makeString(char* s1, char* s2, char* s3, char* s4, char* s5, char* s6);//make the mission string  that need to display on the screen
	void mathExe();//7 - 
	char* getM7()
	{
		return missions[7];
	}
	void PickNums(int &place, int nums[], char* operator1, char * operator2);//get random numbers and random operators
	bool CheckValidation(int nums[], int place, char* operator1, char* operator2);//check if there is a correct answer in the range(1-169) to the random mission
	void setMission(int i)
	{
		m[i]->makeValidExe();
		missionsBank[i] = m[i]->getMission();
	}
	void setBank(MissionBank ** _m)
	{
		m = _m;
	}
	void Menu::pickDifficulty();
};

#endif