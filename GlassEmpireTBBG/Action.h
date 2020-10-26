#pragma once 
#include <iostream> 
#include <random>
#include <vector>
#include "Player.h" 
#include "Resource.h"

class Action
{
	std::vector<std::string> actionCards = { "Take Money", "Take Resource", "Force Trade", "Double Resource Price" };

public:
	void AddAction(Player& player);
	void RemoveAction(Player& player, std::string removeCard);
	void DoingAction(Player& player1, Player& player2, int actionTaken);
};