#include "Resource.h"

void Resource::setName(std::string name)
{
	this->name = name;
}

void Resource::setCost()
{
	if (this->name == "Chems") {
		this->cost = 100;
	}
	else if (this->name == "Gas") {
		this->cost = 100;
	}
	else if (this->name == "Flask") {
		this->cost = 100;
	}
	else if (this->name == "Prints") {
		this->cost = 100;
	}
	else if (this->name == "Witness") {
		this->cost = 100;
	}
	else if (this->name == "Photo") {
		this->cost = 100;
	}
	else if (this->name == "") {
		this->cost = 0;
	}
}

std::string Resource::getName()
{
	return this->name;
}

int Resource::getCost()
{
	return this->cost;
}

void Resource::addResource(std::string name)
{
	setName(name);
	setCost();
}

void Resource::clear() {
	setName("");
	setCost();
}

Resource::Resource()
{
	this->setName("");
}
