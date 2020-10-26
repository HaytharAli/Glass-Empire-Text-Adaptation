#pragma once
#include "Player.h"
#include "Event.h"

using namespace std;
class Board
{
	int board[9][5];
	
public:
	void spaceValues(int space, int street, Player p);
	static std::string streetName(int);
	
	Board();
	
};
