#include "Event.h"

void Event::gainCash(Player triggerPlayer)
{
	int cash = rand() % 170 + 31;
	triggerPlayer.addMoney(cash);

	//Random Reasoning
	int rando = rand() % 10;
	std::string reason;
	switch (rando) {
	case 0:
		reason = "off the ground.";
		break;
	case 1:
		reason = "in some guys pocket.";
		break;
	case 2:
		reason = "in their pocket.";
		break;
	case 3:
		reason = "in their sock.";
		break;
	case 4:
		reason = "in their collector's edition copy of Breaking Bad Season 4.";
		break;
	case 5:
		reason = "in their car.";
		break;
	case 6:
		reason = "between some cushions.";
		break;
	case 7:
		reason = "in their copy of Monopoly.";
		break;
	case 8:
		reason = "in their bank account.";
		break;
	case 9:
		reason = "in their Los Pollos Hermanos Super Chicken Deluxe Ultimate Sandwish Meal, inside the actual sandwich between the lettuce and the tomatoes.";
		break;
	}

	std::cout << triggerPlayer.getName() << " found $" << cash << " " << reason;
}

void Event::moverCash(Player triggerPlayer, Player other1, Player other2, Player other3)
{
	//Payout
	int cash = rand() % 170 + 31;
	if (!triggerPlayer.getIsEnforcer()) {
		triggerPlayer.addMoney(cash);
	}
	if (!other1.getIsEnforcer()) {
		other1.addMoney(cash);
	}
	if (!other2.getIsEnforcer()) {
		other2.addMoney(cash);
	}
	if (!other3.getIsEnforcer()) {
		other3.addMoney(cash);
	}

	//Random Reasoning
	int rando = rand() % 10;
	std::string reason;
	switch (rando) {
	case 0:
		reason = " in the trash.";
		break;
	case 1:
		reason = " from dealing.";
		break;
	case 2:
		reason = " from their grandma.";
		break;
	case 3:
		reason = " from friends.";
		break;
	case 4:
		reason = " by robbing people";
		break;
	case 5:
		reason = ", placed behind their ears.";
		break;
	case 6:
		reason = "... somehow.";
		break;
	case 7:
		reason = " for being so nice to others :)";
		break;
	case 8:
		reason = " from a banking error.";
		break;
	case 9:
		reason = " inside specially marked boxes of Honey Nut Cherrios, now for a limited time!";
		break;
	}

	std::cout << "Movers received $" << cash << reason;
}

void Event::enforcerCash(Player triggerPlayer, Player other1, Player other2, Player other3)
{
	//Payout
	int cash = rand() % 170 + 31;
	if (triggerPlayer.getIsEnforcer()) {
		triggerPlayer.addMoney(cash);
	}
	if (other1.getIsEnforcer()) {
		other1.addMoney(cash);
	}
	if (other2.getIsEnforcer()) {
		other2.addMoney(cash);
	}
	if (other3.getIsEnforcer()) {
		other3.addMoney(cash);
	}

	//Random Reasoning
	int rando = rand() % 10;
	std::string reason;
	switch (rando) {
	case 0:
		reason = " from their boss.";
		break;
	case 1:
		reason = " by mugging totally innocent people.";
		break;
	case 2:
		reason = " from their grandma.";
		break;
	case 3:
		reason = " from friends... willingly.";
		break;
	case 4:
		reason = " from walking into a bank (for some reason everyone got scared and just started handing them their cash).";
		break;
	case 5:
		reason = " from their piggy bank.";
		break;
	case 6:
		reason = " for doing a little dance for someone.";
		break;
	case 7:
		reason = " from their lemonade stand.";
		break;
	case 8:
		reason = " from a banking error... yeah, that\'s what we'll call it.";
		break;
	case 9:
		reason = " for saying something nice about the developers :)";
		break;
	}

	std::cout << "Movers received $" << cash << reason;
}

void Event::payDay(Player triggerPlayer, Player other1, Player other2, Player other3)
{
	//Payout
	int cash = rand() % 170 + 31;
	triggerPlayer.addMoney(cash);
	other1.addMoney(cash);
	other2.addMoney(cash);
	other3.addMoney(cash);

	//Random Reasoning
	int rando = rand() % 10;
	std::string reason;
	switch (rando) {
	case 0:
		reason = " from CERB.";
		break;
	case 1:
		reason = " for giving the devs a 100% on this assignment.";
		break;
	case 2:
		reason = " when they punched a block of bricks.";
		break;
	case 3:
		reason = " from Mr. Beast.";
		break;
	case 4:
		reason = " by commiting Tax Fraud.";
		break;
	case 5:
		reason = " because the person that wrote all these felt like it.";
		break;
	case 6:
		reason = ".";
		break;
	case 7:
		reason = ". It could have been way more, but " + other2.getName() + " was kinda rude :(.";
		break;
	case 8:
		reason = " because they were all wearing masks and doing their part to stop the spread of COVID-19.\nThat's why they're wearing masks, right?";
		break;
	case 9:
		reason = " from Tax Returns.";
		break;
	}

	std::cout << "Everyone received $" << cash << reason;
}

void Event::sting(Player triggerPlayer)
{
	triggerPlayer.setLocOnStreet(0);
	triggerPlayer.setStreet(0);
	std::cout << "Someone called the cops! You're going to the police station, but they\'ll let you go on lack of evidence."
}

void Event::loseCash(Player triggerPlayer)
{
	//Payout
	int cash = rand() % -31 + -170;
	if (cash < triggerPlayer.getBalance()) {
		cash = triggerPlayer.getBalance();
	}
	triggerPlayer.addMoney(cash);

	//Random Reasoning
	int rando = rand() % 10;
	std::string reason;
	switch (rando) {
	case 0:
		reason = " to repair their car.";
		break;
	case 1:
		reason = " on Oreos. Was it worth it?";
		break;
	case 2:
		reason = " replacing damaged wares.";
		break;
	case 3:
		reason = " on a deal that fell through.";
		break;
	case 4:
		reason = " on a hotel room while you tried to lay low.";
		break;
	case 5:
		reason = " on a pet rock. Congrats.";
		break;
	case 6:
		reason = " on Microtransactions.";
		break;
	case 7:
		reason = " on food. On a looooot of food lol.";
		break;
	case 8:
		reason = " on a new GPU. I swear this one will last me a long time.";
		break;
	case 9:
		reason = " on a materials that didn't work out. What a waste.";
		break;
	}

	std::cout << triggerPlayer.getName() << " spent $" << cash << reason;
}

void Event::HandoutCash(Player triggerPlayer, Player other1, Player other2, Player other3)
{
	if (triggerPlayer.getBalance() > 100) {
		triggerPlayer.addMoney(-100);
		other1.addMoney(33);
		other2.addMoney(34);
		other3.addMoney(33);
	}
	else {
		std::cout << triggerPlayer.getName() << " was supposed to pay everyone, but he doesn't have enough money.";
	}
}

void Event::swapResources(Player triggerPlayer, Player other1, Player other2, Player other3)
{
	int rando = rand() % 3;
	switch (rando) {
	case 0:
		//Switch Trigger and Player 1
		break;
	case 1:
		//Switch Trigger and Player 2
		break;
	case 2:
		//Switch Trigger and Player 3
		break;
	}
}

void Event::transit(Player triggerPlayer)
{
	int rando = rand() % 3;
	switch (rando) {
	case 0:
		triggerPlayer.setStreet(0);
		triggerPlayer.setLocOnStreet(0);
		break;
	case 1:
		triggerPlayer.setStreet(3);
		triggerPlayer.setLocOnStreet(0);
		break;
	case 2:
		triggerPlayer.setStreet(6);
		triggerPlayer.setLocOnStreet(0);
		break;
	}
}

void Event::anonymousTip(Player triggerPlayer, Player other1, Player other2, Player other3)
{
	int rando = rand() % 3;
	switch (rando) {
	case 0:
		other1.setStreet(7);
		other1.setLocOnStreet(0);
		break;
	case 1:
		other2.setStreet(7);
		other2.setLocOnStreet(0);
		break;
	case 2:
		other3.setStreet(7);
		other3.setLocOnStreet(0);
		break;
	}
}

void Event::getEvent(Player triggerPlayer, Player other1, Player other2, Player other3)
{
	int rando = rand() % 10;
	switch (rando) {
	case 0:
		gainCash(triggerPlayer);
		break;
	case 1:
		moverCash(triggerPlayer, other1, other2, other3);
		break;
	case 2:
		enforcerCash(triggerPlayer, other1, other2, other3);
		break;
	case 3:
		payDay(triggerPlayer, other1, other2, other3);
		break;
	case 4:
		sting(triggerPlayer);
		break;
	case 5:
		loseCash(triggerPlayer);
		break;
	case 6:
		HandoutCash(triggerPlayer, other1, other2, other3);
		break;
	case 7:
		swapResources(triggerPlayer, other1, other2, other3);
		break;
	case 8:
		transit(triggerPlayer);
		break;
	case 9:
		anonymousTip(triggerPlayer, other1, other2, other3);
		break;
	}
}
