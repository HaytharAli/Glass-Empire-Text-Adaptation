#pragma once
#include "Player.h"
using namespace std;
class Board
{
	void spaceValues(int board[][5], int space, int street);
public:

	Board();
	int board[9][5];
};
