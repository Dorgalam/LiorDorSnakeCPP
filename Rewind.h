#ifndef _REWIND_H
#include <vector>
#include <chrono>
#include "io_utils.h"
#include <iostream>

//class that saves mission data to be displayed when you want to replay
class Rewind {
	struct Change { //local struct, no need for it anywhere else
		int x, y, lag;
		char ch;
	};
	char startBoard[24][81];
	char startMenu[5][82];
	std::vector <Change> changes;
	long long int lastChange = 0;

public:
	void saveScreen(const char(&board)[24][81],  char (*menu)[82]) {
		memcpy(startBoard, board, sizeof(char) * 24 * 81); //copy contents of starting board & menu, this only needs to be done once every mission
		memcpy(startMenu, menu, sizeof(char) * 5 * 82);
		lastChange = timeMs(); //this is the time when we finished copying
		changes.clear(); //if this isn't the first mission, remove garbage left overs from last mission
	}
	void moreChanges(int x, int y, char ch) {
		Change cg; //create a struct and give it all the data we got
		cg.x = x;
		cg.y = y;
		cg.ch = ch;
		long long int now = timeMs(); //check the time right now (in MS) 
		cg.lag = int(now - lastChange); //difference between last edit and this one in MS, will be injected directly into Sleep
		lastChange = now; //this is the new last change time
		changes.push_back(cg);
	}
	long long int timeMs() {
		return std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch()).count(); //only thing this big line does is return the time (since epoch) in MS
	}
	void go(); //prints everything that we saved
};


#endif // !_REWIND_H