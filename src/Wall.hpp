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
    Wall &r()
    {
        for (int i = 0; i < 9; i++)
        {
            if (i != 2 && i != 5 && i != 8)
            {
                e[i].state = ElementState::off;
            }
        }
        return *this;
    }
    Wall &l()
    {
        for (int i = 0; i < 9; i++)
        {
            if (i != 0 && i != 3 && i != 6)
            {
                e[i].state = ElementState::off;
            }
        }
        return *this;
    }
    Wall &t()
    {
        for (int i = 0; i < 9; i++)
        {
            if (i != 0 && i != 1 && i != 2)
            {
                e[i].state = ElementState::off;
            }
        }
        return *this;
    }
    Wall &b()
    {
        for (int i = 0; i < 9; i++)
        {
            if (i != 6 && i != 7 && i != 8)
            {
                e[i].state = ElementState::off;
            }
        }
        return *this;
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
        bool rotatedR = false;
        bool rotatedL = false;
        bool rotated180 = false;
        std::string colorPrev[9];
        for (int i = 0; i < 9; i++)
        {
            colorPrev[i] = e[i].color;
            if (e[i].state == ElementState::on && w.e[i].state == ElementState::on)
            {
                e[i].color = w.e[i].color;
                if (e[i].color == "N")
                {
                    for (int j = 0; j < i; j++)
                    {
                        e[j].color = colorPrev[j];
                    }
                    if (!rotatedR)
                    {
                        w.rotateR();
                        rotatedR = true;
                        std::cout << "RotatedR, i = " << i << std::endl;
                        i = 0;
                    }
                    else if (!rotatedL)
                    {
                        w.rotateL();
                        w.rotateL();
                        rotatedL = true;
                        std::cout << "RotatedL, i = " << i << std::endl;
                        i = 0;
                    }
                    else if (!rotated180)
                    {
                        w.rotateL();
                        rotated180 = true;
                        std::cout << "Rotated180, i = " << i << std::endl;
                        i = 0;
                    }
                }
            }
        }
        if (rotatedR && !rotatedL && !rotated180)
            w.rotateL();
        if (rotatedR && rotatedL && !rotated180)
            w.rotateR();
        if (rotated180)
        {
            w.rotateL();
            w.rotateL();
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