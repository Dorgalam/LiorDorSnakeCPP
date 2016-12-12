#include "Mission.h"
#include "Menu.h"

bool Mission::isPrime(int n) {
	for (int i = 2; i <= n / 2; ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
void Mission::startMission() {
	bool correct = false;
	currMission = (rand() % 7);
	theMenu->newMission(currMission);
}
