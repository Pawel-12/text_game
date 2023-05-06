#include <gtest/gtest.h>
#include <iostream>
#include "../source/headers/Room.h"
#include "../source/headers/Command.h"

TEST(MapTest, Test1) {

    std::unordered_map<Cords, Room, CordsHasher> map
            {
                    {{0,0},{"City", "small town", {"N","E","S","W"},{"SHOP"}}},
                    {{0,1},{"Forest", "lot of trees", {"S"}}},
                    {{0,-1},{"Cave", "air is very humid here", {"N"}}},
                    {{1,0},{"Road", "dirt road", {"W"}}},
                    {{-1,0},{"Plains", "large fields of grass", {"E"}}}
            };


    for(auto & [key, value] : map)
    {
        std::cout<<key<<" "<<value.getName()<<std::endl;
        Cords temp = key;

        for(CommandName c : value.getExits())
        {
            switch (c[0]) {
                case 'N':
                    temp[1]++;
                    break;

                case 'E':
                    temp[0]++;
                    break;

                case 'S':
                    temp[1]--;
                    break;

                case 'W':
                    temp[0]--;
                    break;
            }

            try
            {
                map.at(temp);
            }
            catch (const std::exception& e)
            {
                std::cout << e.what()<<", "<<c<<" is invalid direction"<<std::endl;
                EXPECT_NO_THROW(map.at(temp));
            }
            temp = key;
        }

    }

}
