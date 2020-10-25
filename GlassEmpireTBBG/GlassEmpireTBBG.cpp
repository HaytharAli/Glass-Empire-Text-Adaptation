// GlassEmpireTBBG.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include "Player.h"
using namespace std;


int gamePrint(Player);
void playOutTurn(Player);
void roll(Player);
void proposeTrade(Player);
void checkMap(Player);
void checkInven(Player);

int main()
{
	//Useful variables
	


	//SET UP: I tried making this into a seperate method, but pointers were giving me trouble with the array. If someone can fix it, give it a go

	Player playerList[4]; 

	Player Enf1("Enforcer1", true); //default names, we can allow the user to input them if they have time.
	Player Enf2("Enforcer2", true);
	Player Mov1("Mover1", false);
	Player Mov2("Mover2", false);

	playerList[0] = Enf1;
	playerList[1] = Enf2;
	playerList[2] = Mov1;
	playerList[3] = Mov2;

	/* Checks data about players, used for debugging purposes
	playerList[0].printInfo();
	playerList[1].printInfo();
	playerList[2].printInfo();
	playerList[3].printInfo();
	*/

	//GAME LOOP\\
	
	while (true)
	{
		for (int i = 0; i < 4; i++) //Cycles through all players in the list
		{
			playOutTurn(playerList[i]);
		}
	}
}

void playOutTurn(Player p)
{
	int choice;
	bool hasRolled = false; //Checks to see if the player has rolled this turn already

	while (true)
	{
		choice = gamePrint(p);
		switch (choice) //Performs the action based on the input
		{
		
			case 1: //Roll
				if (hasRolled)
				{
					cout << "You have already rolled this turn, you may only roll once a turn.\n Please choose another action or end your turn.\n";
				}
				else
					roll(p); //Rolls and moves the player to a new spot

				break;

			case 2: //Trade
				proposeTrade(p); //allows the player to ask another player if they would like to trade, if yes, they will both be put into a trade function
				break;
			case 3: //Map
				checkMap(p);
				break;
			case 4: //Inventory
				checkInven(p);
				break;
			case 5: //End turn
				return;
				
				
		}
	}
}
int gamePrint(Player p)  //Prints options, returns an integer choice
{
	int temp;
	cout << "It is now " << p.getName() << "'s turn. Please pick an action by entering the corresponding number.\n"
		<< "1: Roll+move\n"
		<< "2: Trade\n"
		<< "3: Map\n"
		<< "4: Inventory\n"
		<< "5: End Turn\n";
	cin >> temp;
	while (true) //Checking for valid input
	{
		if (temp < 1 || temp > 5) //Invalid inputs
		{
			cout << "That is not a valid choice, please input a number from 1-5";
			cin >> temp;
		}
		else //Valid input
			break;
	}
	return temp;
}

void roll(Player p)
{}
void proposeTrade(Player p)
{}
void checkMap(Player p)
{}
void checkInven(Player p)
{}
