// GlassEmpireTBBG.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "Player.h"
#include "Board.h"
using namespace std;


int gamePrint(Player &); //Prints basic things about a player, dev tool
void foo(Player&); //Rewritable function for bugfixing purposes

void playOutTurn(Player &); //Takes in a player, lets them select what to do

void roll(Player &); //rolls and moves player
void move(Player &, int); //Takes in player and the number of steps they need to take
void fork(Player &, int curStreet); //Takes in a player and their current street, lets them choose what street to fork to



void proposeTrade(Player); //proposes trade with other player
void checkMap(Player); //tells where they are on the map, what is around them
void checkInven(Player); //checks player inventory, can play action cards from here

int checkValidInput(int input, int min, int max); //Makes sure user inputs are valid, bare bones anti crasher.






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
	

	Board board();

	/* Checks data about players, used for debugging purposes
	playerList[0].printInfo();
	playerList[1].printInfo();
	playerList[2].printInfo();
	playerList[3].printInfo();
	*/

	//GAME LOOP\\
	

	// To remove
	//foo(playerList[0]);
	//playerList[0].printLocation();
	// Bugfixing

	while (true)
	{
		for (int i = 0; i < 4; i++) //Cycles through all players in the list
		{
			playOutTurn(playerList[i]);
		}
	}
}

void playOutTurn(Player &p)
{
	
	int choice;
	bool hasRolled = false; //Checks to see if the player has rolled this turn already

	while (true)
	{
		choice = gamePrint(p);
		cout << endl;
		switch (choice) //Performs the action based on the input
		{
		
			case 1: //Roll
				if (hasRolled)
				{
					cout << "You have already rolled this turn, you may only roll once a turn.\n Please choose another action or end your turn.\n";
				}
				else
				{
				roll(p); //Rolls and moves the player to a new spot
				cout << endl << endl;
				hasRolled = true;
				}
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
int gamePrint(Player &p)  //Prints options, returns an integer choice
{
	int temp;
	cout << "\nIt is " << p.getName() << "'s turn. Please pick an action by entering the corresponding number.\n\n"
		<< "1: Roll+move\n"
		<< "2: Trade\n"
		<< "3: Map\n"
		<< "4: Inventory\n"
		<< "5: End Turn\n";
	cin >> temp;
	return checkValidInput(temp, 1, 5);
}

void roll(Player &p)
{
	//Get starting location
	int curStreet = p.getStreet();
	int curLocOnStreet = p.getLocOnStreet();

	//Roll between 1-6
	srand(time(NULL));
	int rollResult = (rand() % 6) + 1; 
	cout << p.getName() << " rolled and moved " << rollResult << " space(s) forward.";
	//Move loop, input starting location, and number of steps you need to move forward.
	move(p, rollResult);
	//Use a for loop that is the number of steps long, and will check if its at the end of a path each time
	//if its at the end of a path, itll go into a fork function asking the player where they want to go, then set their location to board[chosen street][0]

	

}
void move(Player &p, int steps)
{

	
	for (int i = 0; i < steps; i++)
	{
		if (p.getLocOnStreet() < 5) //not at the end of the street
		{
			//pass over effects would also take place here
			p.setLocOnStreet(p.getLocOnStreet() + 1);
		}
		else //at end of street
		{
			fork(p, p.getStreet()); //At the end of the street, Lets the player choose which direction on the fork to go
			p.setLocOnStreet(0); //Sets player to the start of the new street
		}
		
	}

	
	//activate tile effect once finished moving

}
void fork(Player &p, int curStreet)
{
	int choice; // tracks fork selection
	cout << "You have reached the end of " << Board::streetName(curStreet) << endl; //change this if we have time so theres a name to all the streets. Right now it just shows a number from the array
																	//use a method like std::string streetName(curStreet);


	
	if (curStreet == 0 || curStreet == 2 || curStreet == 7) //Forked prompt
	{
		cout << "There is a fork in the road ahead of you.\nYou can either enter\n";

	}
	else //No fork prompt
		cout << "You have now entered: ";

	switch (curStreet)
	{

	//FORKS
	case 0: //Start; -> (connects to) Rerun 1, Forward 1
		cout << "1: " << Board::streetName(1) << endl
			<< "2: " << Board::streetName(2) << endl
			<< "Please type in a 1 or a 2 to make your selection.\n";
		cin >> choice;

		choice = checkValidInput(choice, 1, 2); //Checks valid input before returning

		if (choice == 1)
			p.setStreet(1);
		else
			p.setStreet(2);
		break;

	case 2: //Forward 1; -> split 1, split 2
		cout << "1: " << Board::streetName(3) << endl
			<< "2: " << Board::streetName(4) << endl
			<< "Please type in a 1 or a 2 to make your selection.\n";
		cin >> choice;

		choice = checkValidInput(choice, 1, 2); //Checks valid input before returning

		if (choice == 1)
			p.setStreet(3);
		else
			p.setStreet(4);
		break;

	case 7: //Split 4; -> Split 3, Forward 3
		cout << "1: " << Board::streetName(6) << endl
			<< "2: " << Board::streetName(8) << endl
			<< "Please type in a 1 or a 2 to make your selection.\n";
		cin >> choice;

		choice = checkValidInput(choice, 1, 2); //Checks valid input before returning

		if (choice == 1)
			p.setStreet(6);
		else
			p.setStreet(8);
		break;
	


	//NO FORKS
	case 1: //Rerun 1; -> Start
	case 8: //Forward 3 -> Start
		cout << Board::streetName(0) << endl;
		p.setStreet(0);
		break;

	case 3: //Split 1; -> Forward 2
	case 4: //Split 2; -> Forward 2
		cout << Board::streetName(5) << endl;
		p.setStreet(5);
		break;

	case 5: //Forward 2; -> Split 4
	case 6: //Split 3; -> Split 4
		cout << Board::streetName(7) << endl;
		p.setStreet(7);
		break;

	/*
	//start
	{ 0, 10, 7, 10, 1 }, //connects to rerun1, forward 1 
	//rerun 1
	{ 1,10,7,10,4 }, //connects to start
	//forward 1
	{ 10,7,0,7,0 }, //connects to split 1, split 2
	//split 1
	{ 0,1,7,10,4 }, // connects to forward 2
	//split 2
	{ 10,0,7,2,5 }, // connects to forward 2
	//forward 2
	{ 0,10,7,0,0 }, //connects to split 4
	//split 3
	{ 10,3,0,10,6 }, //connects to split 4
	//split 4
	{ 3,7,10,6,7 }, //connects to split 3, forward 3
	//forward 3
	{ 10,7,7,0,3 } //connects to start
	*/
	
	}
	
}


void proposeTrade(Player p)
{}
void checkMap(Player p)
{
	p.printLocation();
	//Change this so it also says the spaces in front of you
}
void checkInven(Player p)
{}

int checkValidInput(int input, int min, int max)
{
	while (true) //Checking for valid input
	{
		if (input < min || input > max) //Invalid inputs
		{
			cout << "That is not a valid choice, please input a number from: " << min << " to " << max << endl;
			cin >> input;
		}
		else //Valid input
			break;
	}
	return input;
}

void foo(Player &p)
{
	p.setLocOnStreet(3);
}
