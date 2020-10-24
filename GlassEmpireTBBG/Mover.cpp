#include "Mover.h"

Mover::Mover(std::string playerName) : Player()
{
	name = playerName;
}

bool Mover::readyToWin()
{
	bool r1 = false;
	bool r2 = false;
	bool r3 = false;
		for (int i = 0; i < 10; i++) {
			if (this->resources[i] == 1) {
				r1 = true;
			}
			if (this->resources[i] == 2) {
				r2 = true;
			}
			if (this->resources[i] == 3) {
				r3 = true;
			}
		}
	if (r1 && r2 && r3) {
		return true;
	}
	return false;
}