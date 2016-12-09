#include "Menu.h"
#include "TheSnakesGame.h"


void Menu::displayStartMenu() {
	int choice;
	clear();
	edit(1, 2, startMenu[0]);
	edit(2, 2, startMenu[1]);
	edit(3, 70, startMenu[2]);
	print();
	cin >> choice;
	switch (choice) {
	case START:
		game->init();
		break;
	case INSTRUCTIONS:
		displayInstructions();
		break;
	case EXIT_START:
		//game->over();
		break;

	}
	
}
void  Menu::displayIngameMenu() {
	int choice;
	for (int i = 0; i < 6; i++) {
		edit((i % 3) + 1, 2 + 20 * (i / 3), inGameMenu[i]);
	}
	print();
	cin >> choice;
	switch (choice) {
	case EXIT_MID:
		break;
	case MAIN_MENU:
		game->displayStartMenu();
		break;
	case RESUME:
		break;
	case RESTART_MISSION:
		break;
	case NEW_MISSION:
		break;
	case RESTART_GAME:
		game->init();
		break;
	}

}