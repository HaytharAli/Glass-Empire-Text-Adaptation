#include "Player.h"

bool Player::getIsEnforcer()
{
	return this->isEnforcer;
}

void Player::addResource(int type)
{
	//Check if inventory is full by checking if the last slot is occupied. Items are added to the end of the resouce list,
	//and when removed, the list is sorted to put the empty slots at the back
	if (this->resources[9] > 0) {
		std::cout << this->getName() << " has a full inventory, and picked nothing up." << std::endl;
	}
	else {
		bool itemAdded = false;
		for (int i = 0; i < 10; i++) {
			if (this->resources[i] == 0) {
				if (!itemAdded) {
					itemAdded = true;
					this->resources[i] = type;
				}
			}
		}
	}
}

void Player::removeResource(int type)
{
	bool itemRemoved = false;
	for (int i = 0; i < 10; i++) {
		if (this->resources[i] == type) {
			if (!itemRemoved) {
				itemRemoved = false;
				this->resources[i] = 0;
			}
		}
	}
	//Sorts inventory from least to greatest, then reverses it so that zeroes are at the back
	std::sort(std::begin(this->resources), std::end(this->resources));
	std::reverse(std::begin(this->resources), std::end(this->resources));
}

bool Player::readyToWin()
{
	bool r1 = false;
	bool r2 = false;
	bool r3 = false;
	if (!this->getIsEnforcer()) {
		for (int i = 0; i < 10; i++) {
			if (this->resources[i] == 1) {
				r1 = true;
			}
			if (this->resources[i] == 2) {
				r2 = true;
			}
			if (this->resources[i] == 3) {
				r3 = true;
			}
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (this->resources[i] == 4) {
				r1 = true;
			}
			if (this->resources[i] == 5) {
				r2 = true;
			}
			if (this->resources[i] == 6) {
				r3 = true;
			}
		}
	}
	if (r1 && r2 && r3) {
		return true;
	}
	return false;
}

bool Player::addMoney(int profit)
{
	if ((this->money - profit) > 0) {
		this->money = this->getBalance() - profit;
		return true;
	}
	else {
		std::cout << this->getName() << " does not have enough money for this transaction." << std::endl;
		return false;
	}
}

int Player::getBalance()
{
	return this->money;
}

std::string Player::getName()
{
	return this->name;
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
