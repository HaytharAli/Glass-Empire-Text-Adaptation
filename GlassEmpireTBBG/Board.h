#pragma once
#include "Player.h"
using namespace std;
class Board
{
	int board[9][5];

public:
	void spaceValues(int board[][5], int space, int street, Player player);	
	Board();
};
