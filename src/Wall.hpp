#ifndef WALLHPP
#define WALLHPP
#include <iostream>
#include <array>
#include "Element.hpp"
#include "ElementState.hpp"
class Wall
{
private:
    Element e[9];

public:
    Wall()
    {
        for (int i = 0; i < 9; i++)
        {
            e[i].color = "N";
        }
    }
    Wall(const std::string s[9])
    {
        for (int i = 0; i < 9; i++)
        {
            e[i].color = s[i];
        }
    }
    ~Wall()
    {
        // std::cout << "Wall destructor" << std::endl;
    }
    void show()
    {
        std::string temp = "";
        for (int i = 0; i < 9; i++)
        {
            temp += e[i].color;
            if (i == 2 || i == 5 || i == 8)
                temp += "\n";
        }
        std::cout << temp;
    }
    Wall &r()
    {
        e[0].state = ElementState::off;
        e[1].state = ElementState::off;
        e[3].state = ElementState::off;
        e[4].state = ElementState::off;
        e[6].state = ElementState::off;
        e[7].state = ElementState::off;
        return *this;
    }

    Wall &operator=(Wall &w)
    {
        for (int i = 0; i < 9; i++)
        {
            if (e[i].state == ElementState::on && w.e[i].state == ElementState::on)
                e[i].color = w.e[i].color;
        }
        for (int i = 0; i < 9; i++)
        {
            e[i].state = ElementState::on;
            w.e[i].state = ElementState::on;
        }
        return *this;
    }
};

#endif