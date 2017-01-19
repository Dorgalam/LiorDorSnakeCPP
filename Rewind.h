#ifndef _REWIND_H
#include <vector>
#include <chrono>
#include "io_utils.h"
#include <iostream>


class Rewind {
	struct Change {
		int x, y, lag;
		char ch;
	};
	char startBoard[24][81];
	char startMenu[5][82];
	std::vector <Change> changes;
	long long int lastChange = 0;

public:
	void saveScreen(const char(&board)[24][81],  char (*menu)[82]) {
		memcpy(startBoard, board, sizeof(char) * 24 * 81);
		memcpy(startMenu, menu, sizeof(char) * 5 * 82);
		lastChange = timeMs();
		changes.clear();
	}
	void moreChanges(int x, int y, char ch) {
		Change cg;
		cg.x = x;
		cg.y = y;
		cg.ch = ch;
		long long int now = timeMs();
		cg.lag = int(now - lastChange);
		lastChange = now;
		changes.push_back(cg);
	}
	long long int timeMs() {
		return std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch()).count();
	}
	void go() {
		int i, j;
		for (i = 0; i < 5; ++i) {
			for (j = 0; j < 80; ++j ) {
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
			Sleep(item.lag);
			gotoxy(item.y, item.x);
			std::cout << item.ch;
		}
		Sleep(2000);
	}
};


#endif // !_REWIND_H
