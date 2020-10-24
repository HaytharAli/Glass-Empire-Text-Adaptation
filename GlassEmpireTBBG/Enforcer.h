#pragma once
#include "Player.h"
class Enforcer :
    public Player
{


public:
    Enforcer(std::string = "Unnamed Enforcer");
    bool readyToWin();

};
