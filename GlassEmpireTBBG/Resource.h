#pragma once
#include <iostream>

class Resource
{
	std::string name;
	int cost;

	void setName(std::string name);
	void setCost();
public:

	std::string getName();
	int getCost();
	void addResource(std::string name);
	void clear();

	Resource();
};

