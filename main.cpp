#include <windows.h>
#include <iostream>
//#include "Menu.h"
using namespace std;
#include <math.h>
#include <vector>
#include "TheSnakesGame.h"
#include "_board.h"
#include "randNumbers.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

void printNumbers()
{//every five steps of the snake
	int numbers[60];
	int random = rand() % 3;
	switch (random) {
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	}
	
	int place = 0;
	numbers[place++] = rand() % 26;
	numbers[place++] = rand() % 56 + 26;
	numbers[place++] = rand() % 88 + 82;
}



int main() {
	//printNumbers();
	TheSnakesGame game;
	game.setBoard(board);
	game.displayStartMenu();
	game.run();

}