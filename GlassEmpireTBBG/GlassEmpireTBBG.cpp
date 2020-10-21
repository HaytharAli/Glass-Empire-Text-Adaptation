// GlassEmpireTBBG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	//Sets the initial scene - Menu
	int scene = 0;
	std::string input;

	//Initialize 4 Players of the Player Class. These will setup during the game set up.
	Player P1;
	Player P2;
	Player P3;
	Player P4;
	
	//Create a pointer array to easily call on the players
	Player* players[4];

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