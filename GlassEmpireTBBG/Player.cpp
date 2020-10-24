#include "Player.h"



Player::Player() //creates a player
{
	
	money = 100; //PLACEHOLDER VALUE
	street = 0; //Starting street
	locOnStreet = 0; //Beginning of the street

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
