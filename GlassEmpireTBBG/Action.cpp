#include "Action.h" 

void Action::AddAction(Player& player)
{

	if (actionCards.size() > 0)
	{
		int actionCount = actionCards.size() - 1;
		int x = rand() % (actionCount + 1);
		int i = 0;
		bool exitFlag = false;

		while (exitFlag == false && i <= x)
		{
			if (player.actions[i] == "0")
			{
				player.actions[i] = actionCards[x];
				actionCards.erase(actionCards.begin() + x);
				exitFlag = true;
			}
			else
			{
				i += 1;
			}
		}
	}
	else
	{
		std::cout << "Error: no more action cards\n";
	}
}

void Action::RemoveAction(Player& player, std::string removeCard)
{

	// remvoing action cards

	int i = 0;
	bool exitFlag = false;

	while (exitFlag == false && i < 10)
	{
		if (player.actions[i] == removeCard)
		{
			player.actions[i] = "0";
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
			if (player.actions[i] == "0" && player.actions[i + 1] == "0")
			{
				exitFlag = true;
			}
			else
			{
				player.actions[i] = player.actions[i + 1];
				player.actions[i + 1] = "0";
				i += 1;
			}
		}
	}
}

void Action::DoingAction(Player& fromPlayer, Player& toPlayer, int actionTaken)
{
	int switchCount;

	if (fromPlayer.actions[actionTaken - 1] == "Take Money") switchCount = 1;
	if (fromPlayer.actions[actionTaken - 1] == "Take Resource") switchCount = 2;
	if (fromPlayer.actions[actionTaken - 1] == "Force Trade") switchCount = 3;
	if (fromPlayer.actions[actionTaken - 1] == "Double Resource Price") switchCount = 4;

	switch (switchCount)
	{
	case 1:
		fromPlayer.addMoney(50);	// Placeholder
		toPlayer.addMoney(-50);		// Placeholder	
	case 2:
		fromPlayer.addResource("");	 // Placeholder
		toPlayer.removeResource("");  // Placeholder
	case 3:


	case 4:
//		fromPlayer.cost - fromPlayer.getResourceCost("")

	default:
		std::cout << "Error, this is not an action";
		break;
	}


}
