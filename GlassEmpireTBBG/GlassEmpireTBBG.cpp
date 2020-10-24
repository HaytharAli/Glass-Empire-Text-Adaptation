// GlassEmpireTBBG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Enforcer.h"
#include "Mover.h"

int main()
{
	//Sets the initial scene - Menu
	int scene = 0;
	std::string input;

	//Initialize 4 Players of the Player Class. These will setup during the game set up.
	Enforcer E1;
	Enforcer E2;
	Mover M1;
	Mover M2;
	
	//Create a pointer array to easily call on the players
	Player* players[4]; //This is a test comment 

	//Load the splash screen from XML and print it
	gamePrint(); //<--- To be implemented!!!

	//Display the options available to the player from the current scene
	displayOptions(scene); //<--- To be implemented!!!
	//Takes player input
	std::cin >> input;
	//Performs the action based on the input
	//Include a pointer to any game elements the actions could change
	action(input, &scene, players);


}