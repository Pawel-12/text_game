#include <iostream>

#include "Cords.h"


int & Cords::operator[](const int & index)
{
    if(!index)
    {
        return x;
    }
    else if(index == 1)
    {
        return y;
    }
    else
    {
        std::cout<<"bad index"<<std::endl;
        return x;
    }
}

const int & Cords::operator[](const int & index)const
{
    if(!index)
    {
        return x;
    }
    else if(index == 1)
    {
        return y;
    }
    else
    {
        std::cout<<"bad index"<<std::endl;
        return x;
    }
}

bool Cords::operator==(const Cords & b) const
{
    return x == b.x && y == b.y;
}

std::ostream & operator<<(std::ostream & os, const Cords & c)
{
    os<<"["<<c[0]<<","<<c[1]<<"]";
    return os;
}
