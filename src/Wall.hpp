#ifndef WALLHPP
#define WALLHPP
#include <iostream>
#include <array>
#include "Element.hpp"
class Wall
{
private:
public:
    Element e[9];
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
    std::string getStr()
    {
        std::string temp = "";
        for (int i = 0; i < 9; i++)
        {
            temp += e[i].color;
        }
        return temp;
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

    void rotateR()
    {
        std::string temp0 = e[0].color;
        std::string temp1 = e[1].color;
        std::string temp2 = e[2].color;
        e[2].color = temp0;
        e[1].color = e[3].color;
        e[0].color = e[6].color;
        e[3].color = e[7].color;
        e[6].color = e[8].color;
        e[7].color = e[5].color;
        e[8].color = temp2;
        e[5].color = temp1;
    }

    void rotateL()
    {
        std::string temp0 = e[0].color;
        std::string temp1 = e[1].color;
        std::string temp2 = e[2].color;
        e[0].color = temp2;
        e[1].color = e[5].color;
        e[2].color = e[8].color;
        e[5].color = e[7].color;
        e[8].color = e[6].color;
        e[7].color = e[3].color;
        e[6].color = temp0;
        e[3].color = temp1;
    }

    Wall &operator=(Wall &w)
    {
        for (int i = 0; i < 9; i++)
        {
            e[i].color = w.e[i].color;
        }
        return *this;
    }
};

#endif