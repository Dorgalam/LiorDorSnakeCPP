#include "Mission.h"
#include "Menu.h"

bool Mission::isPrime(int n) {
	bool res = (n % 2 == 0 ? true : false);
	for (int i = 3; i <= sqrt(n) && res; i += 2)
	{
		(n % i == 0 ? res = false : 0);
	}
	return res;
}
void Mission::startMission() {
	bool correct = false;
	currMission = (rand() % 5);
	theMenu->newMission(currMission);
}
