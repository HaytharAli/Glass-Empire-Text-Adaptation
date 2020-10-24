#pragma once
#include <iostream>
#include <algorithm>
#include <string>

class Player
{
protected:
	std::string name;
	
	int money;
	int resources[10]; //When collected, a slot in the array is filled with the correct resource identifier //this should be changed to an array of resource items (a class that needs to be made), not integers.
	int street;
	int locOnStreet;

public:
	//creates a player
	Player();
	
	void addResource(int type);
	void removeResource(int type);
	
	void addMoney(int profit); //Adds cash to player's wallet. Profit can be negative to reduce total, but the balance can't go below zero.
	int getBalance();
	std::string getName();
	void setStreet(int newStreet);
	void setLocOnStreet(int newLoc);
	int getStreet();
	int getLocOnStreet();

};
