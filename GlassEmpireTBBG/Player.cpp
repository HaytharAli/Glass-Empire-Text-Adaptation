#pragma once
#include "Player.h"
#include "Board.h"


//Private:

int Player::getResource(std::string type)
{
	for (int i = 0; i < 10; i++) {
		if (this->resources[i].getName() == type) {
			return i;
		}
	}
	return 10;
}

//Public:

std::string Player::getName()
{
	return this->name;
}

bool Player::getIsEnforcer()
{
	return this->isEnforcer;
}

bool Player::addMoney(int amount)
{
	this->money = this->getBalance() + amount;
	if (this->money < 0)//checking for having less than 0 money
	{
		this->money = 0;
		return false;
	}

	if (amount > 0) {
		std::cout << this->getName() << " gained " << amount << " and now has a balance of " << this->getBalance() << std::endl;
	}
	else if (amount < 0) {
		std::cout << this->getName() << " lost " << -1*amount << " and now has a balance of " << this->getBalance() << std::endl;
	}
	else {
		std::cout << this->getName() << "did not have his cash balance change.";
	}
	return true;
}

int Player::getBalance()
{
	return this->money;
}

void Player::addResource(std::string type)
{
	for (int i = 0; i < 10; i++) {
		if (this->resources[i].getName() == "") {
			this->resources[i].addResource(type);
			std::cout << type << " added to " << this->getName() << "'s inventory" << std::endl;
			return;
		}
	}
	std::cout << this->getName() << " has a full resource inventory, and picked nothing up." << std::endl;
}

int Player::getResourceCost(std::string type)
{
	int i = getResource(type);
	if (i == 10) {
		//std::cout << this->name << " does not have the resource \"" << type << "\"" << std::endl;
		return 0;
	}
	else {
		return resources[i].getCost();
	}
}

void Player::removeResource(std::string type)
{
	for (int i = 0; i < 10; i++) {
		if (this->resources[i].getName() == type) {
			this->resources[i].clear();
			return;
		}
	}
}
/*
void Player::addActionCard()
{
	for (int i = 0; i < 10; i++) {
		if (this->aCards[i].getName() == "") {
			this->aCards[i].createCard();
			std::cout << this->aCards[i].getName() << " added to " << this->getName() << "'s inventory" << std::endl;
			return;
		}
	}
	std::cout << this->getName() << " has a full Action Card inventory, and picked nothing up." << std::endl;
}

bool Player::useActionCard(std::string type)
{
	for (int i = 0; i < 10; i++) {
		if (this->aCards[i].getName() == type) {
			this->aCards[i].useAction();
			return true;
		}
	}
	std::cout << this->getName() << " does not have card \"" << type << "\"" << std::endl;
	return false;
}

*/
void Player::printInv()
{
	if (this->getIsEnforcer())
		std::cout << this->name << "is an" << " Enforcer" << endl;
	else
		std::cout << this->name << "is a" << " Mover" << endl;	
	std::cout << this->name << " has the following items:" << std::endl
		<< "Cash: " << this->getBalance() << endl;
	
	std::cout << "Current Resources in Inventory:" << std::endl;
	{
		int chems = 0;
		int gas = 0;
		int flask = 0;
		int prints = 0;
		int witness = 0;
		int photo = 0;

		for (int i = 0; i < 10; i++) {
			if (resources[i].getName() == "Chems") {
				chems++;
			}
			else if (resources[i].getName() == "Gas") {
				gas++;
			}
			else if (resources[i].getName() == "Flask") {
				flask++;
			}
			else if (resources[i].getName() == "Prints") {
				prints++;
			}
			else if (resources[i].getName() == "Witness") {
				witness++;
			}
			else if (resources[i].getName() == "Photo") {
				photo++;
			}
		}
		if (chems != 0)
		std::cout << "Chemicals: " << chems << std::endl;
		if (gas != 0)
		std::cout << "Acetylene Fuel: " << gas << std::endl;
		if (flask != 0)
		std::cout << "Boiling Flasks: " << flask << std::endl;
		if (prints != 0)
		std::cout << "Fingerprints: " << prints << std::endl;
		if (witness != 0)
		std::cout << "Witness Testimony: " << witness << std::endl;
		if (photo != 0)
		std::cout << "Incriminating Photos: " << photo << std::endl;
	}
	/*
	std::cout << "Action Cards:" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << aCards[i].getName() << std::endl;
		}*/
	
}


void Player::setStreet(int newStreet)
{
	this->street = newStreet;
}

void Player::setLocOnStreet(int newLoc)
{
	this->locOnStreet = newLoc;
}

int Player::getStreet()
{
	return this->street;
}

int Player::getLocOnStreet()
{
	return this->locOnStreet;
}

bool Player::readyToWin()
{
	bool r1 = false;
	bool r2 = false;
	bool r3 = false;
	if (!this->getIsEnforcer()) {
		for (int i = 0; i < 10; i++) {
			if (this->resources[i].getName() == "Chems") {
				r1 = true;
			}
			if (this->resources[i].getName() == "Gas") {
				r2 = true;
			}
			if (this->resources[i].getName() == "Flask") {
				r3 = true;
			}
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (this->resources[i].getName() == "Prints") {
				r1 = true;
			}
			if (this->resources[i].getName() == "Witness") {
				r2 = true;
			}
			if (this->resources[i].getName() == "Photo") {
				r3 = true;
			}
		}
	}
	if (r1 && r2 && r3) {
		return true;
	}
	//Feedback
	if (!r1) {
		if (!isEnforcer) {
			std::cout << "Chems Required" << std::endl;
		}
		else {
			std::cout << "Prints Required" << std::endl;
		}
	}
	if (!r2) {
		if (!isEnforcer) {
			std::cout << "Gas Required" << std::endl;
		}
		else {
			std::cout << "Witness Required" << std::endl;
		}
	}
	if (!r3) {
		if (!isEnforcer) {
			std::cout << "Flask Required" << std::endl;
		}
		else {
			std::cout << "Photo Required" << std::endl;
		}
	}
	return false;
}

void Player::printInfo()
{
	std::cout << "Heres some info about player " << getName() << std::endl
		<< "They are a: ";
	if (isEnforcer)
		std::cout << "Enforcer\n";
	else
		std::cout << "Mover\n";
	std::cout << "Current cash: " << getBalance() << std::endl;



	std::cout << "\n\n\n"; //Kepe this at the end. Space out player info to make it more discenable when player 1 info stops and player 2 info starts

}
void Player::printLocation()
{
	std::cout << "You are currently on: " << Board::streetName(this->street) << std::endl
		<< "Specifically, space: " << this->locOnStreet + 1 << " out of 6" << std::endl;

}
void Player::takeAStep()
{
	int curLoc = getLocOnStreet();
	setLocOnStreet(curLoc + 1);
}

Player::Player(std::string name, bool isEnforcer)
{
	this->name = name;
	this->isEnforcer = isEnforcer;
	if (!isEnforcer) {
		this->money = 500;
	}
	else {
		this->money = 0;
	}
	this->street = 0;
	this->locOnStreet = 0;
}
void Player::setMoney(int amount)
{
	this->money = amount;
}
