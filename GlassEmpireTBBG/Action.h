#pragma once 
#include <iostream> 
#include <random>
#include "Player.h" 
#include "Resource.h"

class Action
{
	std::string actionCards[10];


public:
	void AddAction(Player player);
	void RemoveAction(Player player, std::string removeCard);
	void CheckAction(Player player, std::string checkCard);
	void DoingAction(Player player1, Player player2);
};

