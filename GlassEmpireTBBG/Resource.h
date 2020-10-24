#pragma once
#include <string>
class Resource
{
protected:
	std::string itemName;
	int value;
public: 
	
	Resource(std::string, int val = 50);
	std::string getName();
	std::string getValue();
};

