#include "Command.h"

// true when command found
bool find(const std::vector<CommandName> & commands, const CommandName & input)
{
    return std::find(commands.begin(), commands.end(),input) != commands.end();
}

// true when one of objects contains command
bool IsValidCmd(const CommandName & input, const Room & room, const Player & player)
{
    bool exits       =  find(room.getExits(), input);       // check if Room exits contain input

    bool playercmds  = find(player.getCmds(), input);       // check if Room commands contain input

    bool roomcmds    = find(room.getCmds(), input);         // check if Player commands contain input

    return (exits || playercmds || roomcmds);
}


bool N(World & w)
{
    w.player.move(0,1);
    return true;
}

bool E(World & w)
{
    w.player.move(1, 0);
    return true;
}

bool S(World & w)
{
    w.player.move(0,-1);
    return true;
}

bool W(World & w)
{
    w.player.move(-1, 0);
    return true;
}

bool EQ(World &)
{
   std::cout<<"Showing Player Equipment"<<std::endl;
    return true;
}

bool SHOP(World &)
{
   std::cout<<"Showing SHOP"<<std::endl;
    return true;
}

