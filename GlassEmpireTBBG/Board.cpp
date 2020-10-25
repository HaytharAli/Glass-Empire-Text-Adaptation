#include "Board.h"
using namespace std;


void spaceValues(int board[][5], int space, int street, Player player) {
	//method is sent board and players street and space 


		//
	switch (board[space][street]) {
	case 0:
		cout << "you landed on an empty space" << endl;
		//nothing happens
		break;
	case 1:

		player.addResource("Prints");
		//add item 1 to player
		break;
	case 2:

		player.addResource("Witness");
		//add item 2 to player
		break;
	case 3:

		player.addResource("Photo");
		//add item 3 to player
		break;
	case 4:

		player.addResource("Chems");
		//add item 1 to player
		break;
	case 5:

		player.addResource("Gas");
		//add item 2 to player
		break;
	case 6:

		player.addResource("Flask");
		//add item 3 to player
		break;
	case 7:
		cout << "youve landed on an event space!";
		//send to event card method
		break;
	case 8:
		cout << "you have landed on the middleman spot";
		//make/send to middleman method
		break;
	case 9:
		cout << "sting!";
		player.setLocOnStreet(4);
		player.setStreet(6);
		//move player to sting spot
		break;
	case 10:
		cout << "money";
		player.addMoney(100);

		//give player x amount of money(random??)
		break;
	case 11:
		cout << "You landed on the enforcer win spot";
		//send to check enforcer win method
		player.readyToWin();
		break;
	case 12:
		cout << "You landed on the mover win spot";
		player.readyToWin();
		//send to check mover win method
		break;
	}
}


void main() {
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
	int board[9][5] = {
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
		{ 10,7,7,0,3 } };


}