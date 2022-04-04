#ifndef WALLHPP
#define WALLHPP
#include <iostream>
#include <array>
#include "ELement.hpp"
#include "ToChange.hpp"
class Wall
{
private:
    std::string s[9];
    std::array<ToChange, 9> ar_tc;

public:
    Wall(const std::string s[9])
    {
        for (int i = 0; i < 9; i++)
        {
            this->s[i] = s[i];
            this->ar_tc[i] = ToChange::dontChange;
        }
    }

    Wall &r()
    {

        return *this;
    }

    Wall &operator=(const Wall &w)
    {
        return *this;
    }
};

#endif