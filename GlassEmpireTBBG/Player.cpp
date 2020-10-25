#include "Player.h"

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

void Player::addMoney(int profit)
{
	if ((this->money - profit) > 0) {
		this->money = this->getBalance() - profit;
	}
	else {
		std::cout << this->getName() << " does not have enough money for this transaction." << std::endl;
	}
}

int Player::getBalance()
{
	return this->money;
}

void Player::addResource(std::string type)
{
	//Check if inventory is full by checking if the last slot is occupied. Items are added to the end of the resouce list,
	//and when removed, the list is sorted to put the empty slots at the back
	if (this->resources[9].getName() != "") {
		std::cout << this->getName() << " has a full inventory, and picked nothing up." << std::endl;
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (this->resources[i].getName() == "") {
				this->resources[i].addResource(type);
				std::cout << type << " added to inventory" << std::endl;
				return;
			}
		}
	}
}

int Player::getResourceCost(std::string type)
{
	int i = getResource(type);
	if (i == 10) {
		std::cout << this->name << " does not have the resource \"" << type << "\"" << std::endl;
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

void Player::setStreet(int newStreet)
{
	this->street = street;
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
