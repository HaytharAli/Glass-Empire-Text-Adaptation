#pragma once
#include <iostream>
#include "Resource.h"

class Player
{
//private:
	std::string name; // The player name
	bool isEnforcer; //if true, Enforcer, else a Mover
	int money; // How much money the player has
	Resource resources[10];
	int street;
	int locOnStreet;

	int getResource(std::string type);

public:
	std::string getName();

	bool getIsEnforcer();

	bool addMoney(int profit); //Adds cash to player's wallet. Profit can be negative to reduce total, but the balance can't go below zero.
	//Returns bool stating whether the transaction was successful, and print's out a statement on the transaction.
	int getBalance();

	void addResource(std::string type);
	int getResourceCost(std::string type); // Returns the value of the resource in the player's inventory
	void removeResource(std::string type);

	void setStreet(int newStreet);
	void setLocOnStreet(int newLoc);
	int getStreet();
	int getLocOnStreet();
	void takeAStep();//moves 1 step forward
	
	bool readyToWin(); // Checks Win Condition, can also be used by player to see what they still need!

	void printInfo(); //Gives information about a player, used for troubleshooting purposes.
	void printLocation();

	Player(std::string name = "", bool isEnforcer = false);

};
