#pragma once

#include <iostream>

class Cords{
private:
    int x;
    int y;

public:
    Cords(const int& x1, const int & y1):x{x1}, y{y1}{}
    int & operator[](const int & index);
    const int & operator[](const int & index)const;
    bool operator==(const Cords & b) const;
    friend std::ostream & operator<<(std::ostream & os, const Cords & c);
};

struct CordsHasher {
    std::size_t operator()(const Cords & a) const {
        std::size_t h = 0;

        for (int i = 0; i < 2; i++) {
            h ^= std::hash<int>{}(a[i])  + 0x9e3779b9 + (h << 6) + (h >> 2);
        }
        return h;
    }
};
