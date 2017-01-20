#include <windows.h>
#include <iostream>
using namespace std;
#include <math.h>
#include <vector>
#include "TheSnakesGame.h"
#include "_board.h"
#include "randNumbers.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <stdio.h>
/*Lior Rokach & Dor Galam - snakes Project
20.01.2017
This program is a game where two snakes battling over math exercise - each mission the winner gets a point,the game ends when one of the snakes has 12 points.
The snake has each mission 5 bullets,If bullet hit the other snake- He will be suspended from the game for a limited time, and the snake who shot the bullet gets a bullet,
Bullets hitting the numbers conceal them,there is some creatures that want to prevent the snakes from reaching the numbers and win,
also at the end of each mission there is an option for the user to press ESC and then choose option 7 for reply.
*/




int main() {
	TheSnakesGame game;
	game.setBoard(board);
	game.displayStartMenu();
	game.run();
}