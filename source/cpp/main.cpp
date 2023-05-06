#include "main.h"

int main() {

    std::unique_ptr<MapContainer> loaded_map {LoadMapFile()};
    Player player{{0, 0}};

    MapContainer map
    {
        {{0,0},{"City", "small town", {"N","E","S","W"},{"SHOP"}}},
        {{0,1},{"Forest", "lot of trees", {"S"}}},
        {{0,-1},{"Cave", "air is very humid here", {"N"}}},
        {{1,0},{"Road", "dirt road", {"W"}}},
        {{-1,0},{"Plains", "large fields of grass", {"E"}}}

    };

    std::cout << "You wake up in small city."<<std::endl;


    const Room * room = &map.at(player.getPos());
    CommandName input;

    World world{player, map, &map.at(player.getPos())};


    while (true)
    {
        std::cout<<*room;

        getInput(input);

        while (not IsValidCmd(input, *room, player))
        {
            std::cout << "Wrong input!"<<std::endl;
            getInput(input);
        }

        cmd.at(input)(world);
        room = &map.at(player.getPos());
        world.room = &map.at(player.getPos());
    }




    getchar();
    return 0;
}
