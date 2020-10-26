#pragma once
#include "Player.h"
#include "Event.h"

using namespace std;
class Board
{
	
public:
	void spaceValues(int board[][5], int space, int street, Player p);
	Board();
	int board[9][5];
};
