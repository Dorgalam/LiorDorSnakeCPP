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
#pragma comment(lib, "winmm.lib")





int main() {
	TheSnakesGame game;
	game.setBoard(board);
	game.displayStartMenu();
	game.run();
}