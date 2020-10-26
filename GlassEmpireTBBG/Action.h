#pragma once 
#include <iostream> 
#include <random>
#include <vector>
#include "Player.h" 
#include "Resource.h"

class Action {
	std::string name;
	std::string description; //Describes what the card does

	//Here we should have all the possible action card effects, each in a seperate function. Check the event functions for a format to reference.
	//Each of these should pass in the triggerplayer, and any other players it may affect.
	//If you could target it at one specific player, pass all other players in and let the player choose inside the actioneffect function

	//ActionEffect1(player triggerPlayer, player other1, player other2, player other3); // This effect takes money from a player of the triggerplayer's choice and gives it to trigger player

public:
	std::string getName(); // Return the name of the card;
	void printDescription(); //cout the description of what the card does

	void createCard(); //Randomly selects a card name from the names available, then fills in the description variable.

	void useAction(); //Checks the name of the Action Card, then calls the appropriate ActionEffect Function, then clears itself
	// Ideally this goes through if gates (switch statements dont work on strings), finds whichever Effect Function corrolates with the name, then pulls a clear();
	void clear(); //Clears out all the member variables so that the card becomes empty again


	Action(); //Constructor - CREATE A BLANK, EMPTY CARD
	// When you make an array, it automatically initializes every single variable within the array.
	// We don't want the player to start off with 10 Action Cards, we will add those later.
};