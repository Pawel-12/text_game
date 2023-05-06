#pragma once

#include <string>

// abstract parent class for contents inside room like player, item, object etc.
class Content {
private:
    std::string name;                    // name of content object
    std::string description;             // description of content object
    //std::vector<Command> commands;
public:
        virtual bool execute(std::string xd) = 0;
};


