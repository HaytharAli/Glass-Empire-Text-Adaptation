#pragma once
#include "Player.h"

class Event {
//Private
	static void gainCash(Player& triggerPlayer); // Add Cash to Player
	static void moverCash(Player& triggerPlayer, Player& other1, Player& other2, Player& other3); // Movers get cash
	static void enforcerCash(Player& triggerPlayer, Player& other1, Player& other2, Player& other3); // Enforcers get cash
	static void payDay(Player& triggerPlayer, Player& other1, Player& other2, Player& other3); // Everyone gets cash
	static void sting(Player& triggerPlayer); // Player goes to jail
	static void loseCash(Player& triggerPlayer); // Remove cash from player inventory
	static void HandoutCash(Player& triggerPlayer, Player& other1, Player& other2, Player& other3); // Player pays all other players
	static void swapResources(Player& triggerPlayer, Player& other1, Player& other2, Player& other3); //Swaps resources with a random player
	static void transit(Player& triggerPlayer); // Moves player to a random location on the map
	static void anonymousTip(Player& triggerPlayer, Player& other1, Player& other2, Player& other3); // Random Player goes to jail
						
						
	//void sale(); // Middleman store gets a multipier on sale prices

public:
	static void getEvent(Player &triggerPlayer, Player &other1, Player &other2, Player &other3);
};
