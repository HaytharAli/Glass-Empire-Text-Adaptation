#include "Action.h"  

void Action::AddAction(Player player)
{
	int r = rand() % 3;
	int i = 0;
	bool exitFlag = false;

	while (exitFlag == false && i < 10)
	{
		if (player.actions[i] == 0)
		{
			std::cout << actionCards[r] << " added to action cards";
			player.actions[i] = actionCards[r];
			exitFlag = true;
		}
		else
		{
			i += 1;
		}
	}

	if (i == 10)
	{
		std::cout << "You are full";
	}
}

void Action::RemoveAction(Player player, std::string removeCard)
{

	// remvoing action cards 

	int i = 0;
	bool exitFlag = false;

	while (exitFlag == false && i < 10)
	{
		if (player.actions[i] == removeCard)
		{
			player.actions[i] = 0;
			exitFlag = true;
		}
		else
		{
			i += 1;
		}
	}

	// reording the action cards 

	if (i == 10)
	{
		std::cout << "Can't find " << removeCard << " in action cards";
	}
	else
	{
		exitFlag = false;
		while (exitFlag == false && i < 9)
		{
			if (player.actions[i] == 0 && player.action[i + 1] == 0)
			{
				exitFlag = true;
			}
			else
			{
				player.actions[i] = player.action[i + 1];
				player.actions[i + 1] = 0;
				i += 1;
			}
		}
	}
}

void Action::CheckAction(Player player, std::string checkCard)
{
	int i = 0;
	bool exitFlag = false;

	while (exitFlag == false && i < 10)
	{
		if (player.actions[i] == checkCard)
		{
			std::cout << "Found " << checkCard << " at " << i;
			exitFlag = true;
		}
		else
		{
			i += 1;
		}
	}

	if (i == 10)
	{
		std::cout << "Could not find action card";
	}
}

void Action::DoingAction(Player player1, Player player2)
{
	int i = 0;
	bool exitFlag = false;

	while (exitFlag == false && i < 10)
	{
		if (player1.actions[i] == "Take Money")
		{
			player1.addMoney(50);		// Placeholder number 
			player2.addMoney(-50);		// Placeholder number 
		}
		if (player1.actions[i] == "Take Resource")
		{
			player1.addResource(1);		// Placeholder number 
			player2.removeResource(1);  // Placeholder number 
		}
		if (player1.actions[i] == "Force Trade")
		{

		}
	}


}
