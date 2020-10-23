#pragma once
#include <iostream>
#include <algorithm>

class Player
{
//private:
	std::string name;
	bool isEnforcer; //if true, Enforcer, else a Mover
	int money;
	int resources[10]; //When collected, a slot in the array is filled with the correct resource identifier
	int street;
	int locOnStreet;

public:
	bool getIsEnforcer();
	void addResource(int type);
	void removeResource(int type);
	bool readyToWin();
	void addMoney(int profit); //Adds cash to player's wallet. Profit can be negative to reduce total, but the balance can't go below zero.
	int getBalance();
	std::string getName();
	void setStreet(int newStreet);
	void setLocOnStreet(int newLoc);
	int getStreet();
	int getLocOnStreet();

};
