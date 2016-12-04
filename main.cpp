#include <windows.h>
#include <iostream>
//#include "Menu.h"
using namespace std;
#include <vector>
#include "TheSnakesGame.h"
#include "_board.h"
//template <Point> vector;
int main() {
	
	TheSnakesGame game;
	game.setBoard(board);
	game.init();
	game.run();

}