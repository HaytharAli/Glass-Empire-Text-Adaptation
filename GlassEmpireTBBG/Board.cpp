#include "Board.h"
using namespace std;


void spaceValues(int board[][5], int space, int street, Player player) {
	//method is sent board and players street and space 


		//
	switch (board[space][street]) {
	case 0:
		cout << "You landed on an empty space." << endl;
		//nothing happens
		break;
	case 1:
		cout << "You've found some Mover fingerprints, it has been added to your inventory.\n";
		player.addResource("Prints");
		//add item 1 to player
		break;
	case 2:
		cout << "You've found a witness willing to testify against the Movers, Their testimony has been added to your inventory.\n";
		player.addResource("Witness");
		//add item 2 to player
		break;
	case 3:
		cout << "You've found an incriminating photo of the Movers, it has been added to your inventory.\n";
		player.addResource("Photo");
		//add item 3 to player
		break;
	case 4:
		cout << "You've found a stockpile of chemicals perfect for cooking Glass, they have been added to your inventory.\n";
		player.addResource("Chems");
		//add item 1 to player
		break;
	case 5:
		cout << "You've found some gas tanks designed for a Glass lab, they have been added to your inventory.\n";
		player.addResource("Gas");
		//add item 2 to player
		break;
	case 6:
		cout << "You've found a checmical boiling flask, it has been added to your inventory.\n";
		player.addResource("Flask");
		//add item 3 to player
		break;
	case 7:
		cout << "You've landed on an event space! \n";
		//send to event card method
		break;
	case 8:
		cout << "You have landed on the middleman spot. \n";
		//make/send to middleman method
		break;
	case 9:
		cout << "sting! You have been placed in lockup. \n";
		player.setLocOnStreet(4);
		player.setStreet(6);
		//move player to sting spot
		break;
	case 10:
		cout << "You've stumled upon some cash, it has been added to your inventory. \n";
		player.addMoney(100);

		//give player x amount of money(random??)
		break;
	case 11:
		cout << "You landed on the Enforcer home base. \n";
		//send to check enforcer win method
		player.readyToWin();
		break;
	case 12:
		cout << "You landed on the Mover home base. \n";
		player.readyToWin();
		//send to check mover win method
		break;
	}
}


Board::Board()
{
	/*board space list
	* 0 nothing
	* 1 enforcer win material 1
	* 2 enforcer win material 2
	* 3 enforcer win material 3
	* 4 mover win material 1
	* 5 mover win material 2
	* 6 mover win material 3
	* 7 event space
	* 8 middleman shop
	* 9 sting!
	* 10 money space
	* 11 enforcer win
	* 12 mover win
	* 13 start
		*/
	int tempBoard[9][5] = {
		//start
		{ 0,10,7,10,1 },
		//rerun 1
		{ 1,10,7,10,4 },
		//forward 1
		{10,7,0,7,0},
		//split 1
		{ 0,1,7,10,4 },
		//split 2
		{ 10,0,7,2,5 },
		//forward 2
		{ 0,10,7,0,0 },
		//split 3
		{ 10,3,0,10,6 },
		//split 4
		{ 3,7,10,6,7 },
		//forward 3
		{ 10,7,7,0,3 }
	};

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++) {
			this->board[i][j] = tempBoard[i][j];
		}
	}
}
