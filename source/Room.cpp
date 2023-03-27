#include "Room.h"


 std::ostream & operator<<(std::ostream & os, const Room & r)
{
    os<<"\""<<r.name<<"\""<<std::endl;
    os<<"'"<<r.description<<"'"<<std::endl;

    if(!r.exits.empty())
    {
        os << "> ";
        for (const CommandName &d: r.exits) {
            os << d << " ";
        }
        os << std::endl;
    }

    if(!r.commands.empty())
    {
        os << "> ";
        for (const CommandName &d: r.commands) {
            os << d << " ";
        }
        os << std::endl;
    }
    return os;
}