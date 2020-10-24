#include "Resource.h"
#
Resource::Resource(std::string name, int val)
{
	itemName = name;
	value = val;
}
std::string getName();
std::string getValue();