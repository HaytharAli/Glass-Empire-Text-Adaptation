#include "Card.h"

void Card::SetName(std::string name)
{
	this->name = name;
}

std::string Card::GetName()
{
	return this->name;
}

void Card::SetDescription(std::string description)
{
	this->description = description;
}

std::string Card::GetDescription()
{
	return this->description;
}

void Card::SetType(std::string type)
{
	this->type = type;
}

std::string Card::GetType()
{
	return this->type;
}
