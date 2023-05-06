#pragma once

#include <iostream>
#include <unordered_map>

#include "Room.h"
#include "Player.h"
#include "Command.h"
#include "Cords.h"

void getInput(CommandName & input)
{
    std::cout << "<Player> ";
    std::cin >> input;
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
}

#include <fstream>
#include <sstream>
#include <memory>

using MapContainer = std::unordered_map<Cords, Room, CordsHasher>;

std::vector<std::string> split(const std::string & strToSplit, const char & delimeter)
{
    if(!strToSplit.length())
        return {};

    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;

    while (std::getline(ss, item, delimeter))
    {
        if(item[0] == ' ')
            item.erase(0,1);

        splittedStrings.push_back(item);
    }
    return splittedStrings;
}

MapContainer * LoadMapFile()
{
    std::ifstream mapfile;
    mapfile.open("../data/map.txt");

    if (!mapfile)
    {
        std::cerr << "map.txt could not be opened for reading!\n";
        return nullptr;
    }

    auto map_p = new MapContainer;

    std::string s;
    while (mapfile && std::getline(mapfile,s))
    {
        std::vector<std::string> roomdata = split(s,',');

        std::vector<std::string> xy = split(roomdata[0], ' ');
        std::vector<CommandName> exits = split(roomdata[3], ' ');
        std::vector<CommandName> cmds {};

        if(roomdata.size() >= 5)
            cmds = split(roomdata[4], ' ');


        map_p->insert({{std::stoi(xy[0]), std::stoi(xy[1])},{roomdata[1], roomdata[2], exits, cmds}});


        for(const auto & xd : *map_p)
        {
            std::cout<<xd.first<<" "<<xd.second;
        }

    }


    mapfile.close();
    return map_p;
}
