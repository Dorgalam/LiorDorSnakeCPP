#include "Countdown.h"

void Countdown::printNumber(int addition, int order) {
	int i = (order == -1 ? 15 : 0);
	for (int count = 0; count < 16; count++) {
		gotoxy(x, y + i);
		std::cout << numbers[i + addition];
		i += order;
		Sleep(50);
	}
}
void Countdown::clearNumArea() {
	char empty[] = "                    ";
	for (int i = 0; i < 16; i++) {
		gotoxy(x, y + i);
		std::cout << empty;
		Sleep(10);
	}
}
void Countdown::start() {
	int i = 0, count = 0, j = 0, order = 1;
	for (; i < 3; i++) {
		printNumber(16 * i, order);
		clearNumArea();
		order *= -1;
	}
}