#pragma once
#include "Player.h"

class Event {
//Private
	void gainCash(Player triggerPlayer); // Add Cash to Player
	void moverCash(Player triggerPlayer, Player other1, Player other2, Player other3); // Movers get cash
	void enforcerCash(Player triggerPlayer, Player other1, Player other2, Player other3); // Enforcers get cash
	void payDay(Player triggerPlayer, Player other1, Player other2, Player other3); // Everyone gets cash
	void sting(Player triggerPlayer); // Player goes to jail
	void loseCash(Player triggerPlayer); // Remove cash from player inventory
	void HandoutCash(Player triggerPlayer, Player other1, Player other2, Player other3); // Player pays all other players
	void swapResources(Player triggerPlayer, Player other1, Player other2, Player other3); //Swaps resources with a random player
	void transit(Player triggerPlayer); // Moves player to a random location on the map
	void anonymousTip(Player triggerPlayer, Player other1, Player other2, Player other3); // Random Player goes to jail
						
						
	//void sale(); // Middleman store gets a multipier on sale prices

public:
	void getEvent(Player triggerPlayer, Player other1, Player other2, Player other3);
};
