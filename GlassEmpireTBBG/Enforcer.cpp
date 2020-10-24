#include "Enforcer.h"

Enforcer::Enforcer(std::string playerName) : Player()
{
	name = playerName;
}

bool Enforcer::readyToWin()
{
	bool r1 = false;
	bool r2 = false;
	bool r3 = false;
	for (int i = 0; i < 10; i++) {
		if (this->resources[i] == 4) {
			r1 = true;
		}
		if (this->resources[i] == 5) {
			r2 = true;
		}
		if (this->resources[i] == 6) {
			r3 = true;
		}
	}
	if (r1 && r2 && r3) {
		return true;
	}
	return false;
}