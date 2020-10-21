#pragma once
#include <string>

class Card
{
	std::string name;
	std::string description;
	std::string type;

public:
	//Setters & Getters
	void SetName(std::string name);
	std::string GetName();
	void SetDescription(std::string description);
	std::string GetDescription();
	void SetType(std::string type);
	std::string GetType();
};

