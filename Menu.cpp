#include "Menu.h"
#include "TheSnakesGame.h"
#include <string>
void Menu::updateScoreBoard(int score1, int score2)
{
	char s1[3], s2[3];
	s1[0] = score1 / 10 + '0';
	s1[1] = score1 % 10 + '0';
	s2[0] = score2 / 10 + '0'; //go to all correct spots and update locations
	s2[1] = score2 % 10 + '0';
	s1[2] = '\0';
	s2[2] = '\0';
	edit(2, 76, s1);
	edit(3, 76, s2);
	print(WHITE);
} 
void Menu::displayStartMenu() {
	char key;
	bool goodChoice = false;
	clear();
	edit(1, 2, startMenu[0]);
	edit(2, 2, startMenu[1]);
	edit(3, 2, startMenu[2]);
	print(WHITE);
	while (!_kbhit()) //listen to a new key pressed in the keyboard
	{

	}
	key = _getch();
	while (!goodChoice)
	{
		switch (key) { //give correct output for all known results, otherwise look for another key
		case START:
			game->init();
			goodChoice = true;
			break;
		case INSTRUCTIONS:
			displayInstructions();
			goodChoice = true;
			break;
		case EXIT_START:
			exit(0);
			goodChoice = true;
			break;
		default:
			while (!_kbhit())
			{

			}
			key = _getch();
			break;
		}
	}
}
void Menu::displayWinningMenu(int num)
{
	clear(); //clears the screen and then shows who won
	edit(1, 2, snakeWonMission[num]); 
	print(YELLOW);
	Sleep(2000);
}
void Menu::displayVictoryMenu(int num)
{
	clear();
	edit(1, 2, victoryMenu[num]);
	print(GREEN);
	PlaySound(TEXT("applause3.wav"), NULL, SND_FILENAME);
	Sleep(2000);
}
void Menu::displayNumMenu(bool found)
{
	int num;
	if (found)
		num = 1;
	else
		num = 0;
	clear();
	edit(1, 2, Num60Menu[num]); 
	print(LIGHTCYAN);
	Sleep(2500);
}
int Menu::displayIngameMenu() {
	char key;
	clear();
	for (int i = 0; i < 6; i++) {
		edit((i % 3) + 1, 2 + 20 * (i / 3), inGameMenu[i]);
	}
	print(WHITE);
	while (!_kbhit()) //listens to a key and operates accordingly
	{

	}
	key = _getch();

	switch (key) {
	case EXIT_MID:
		exit(0);
		break;
	case MAIN_MENU:
		game->displayStartMenu();
		break;
	case RESUME:
		newMission(game->getCurrMission());
		break;
	case RESTART_MISSION:
		newMission(game->getCurrMission());
		break;
	case NEW_MISSION:
		game->startMission();
		break;
	case RESTART_GAME:
		game->init();

		break;
	}
	return (int)(key-'0');

}