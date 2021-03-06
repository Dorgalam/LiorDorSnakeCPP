#include "Rewind.h"

void Rewind::go() {
	int i, j;
	for (i = 0; i < 5; ++i) {
		for (j = 0; j < 80; ++j) {
			gotoxy(j, i);
			std::cout << startMenu[i][j];
		}
	}
	for (i = 0; i < 24; i++) {
		for (j = 0; j < 80; j++) {
			gotoxy(j, i + 5);
			std::cout << startBoard[i][j];
		}
	}
	for (auto item : changes) {
		if (item.lag > 1000)
			item.lag = 500;
		Sleep(item.lag);
		gotoxy(item.y, item.x);
		std::cout << item.ch;
	}
	Sleep(2000);
}