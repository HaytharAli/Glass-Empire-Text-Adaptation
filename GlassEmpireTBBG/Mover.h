#pragma once
#include "Player.h"
class Mover :
    public Player
{
   
    
public: 
    Mover(std::string = "Unnamed Mover");
    bool readyToWin();
    
};

