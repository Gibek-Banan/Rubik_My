#ifndef RUBIKHPP
#define RUBIKHPP
#include <iostream>
#include "Wall.hpp"

class Rubik
{
private:
    Wall wFront;
    Wall wBack;
    Wall wTop;
    Wall wBottom;
    Wall wRight;
    Wall wLeft;
    Wall **walls;

public:
    // explicit Rubik(const Wall &wFront, const Wall &wBack, const Wall &wTop, const Wall &wBottom, const Wall &wRight, const Wall &wLeft) : wFront(wFront), wBack(wBack), wTop(wTop), wBottom(wBottom), wRight(wRight), wLeft(wLeft)
    // {
    // }
    Rubik(Wall **walls) : walls(walls)
    {
        if (walls == nullptr)
            std::abort();
    }
    ~Rubik()
    {
        for (int i = 0; i < 6; i++)
        {
            delete walls[i];
        }
        delete[] walls;
        // std::cout << "Rubik destructor" << std::endl;
    }
    void show()
    {
        for (int i = 0; i < 6; i++)
        {
            walls[i]->show();
            std::cout << std::endl;
        }
    }
    void R()
    {
        walls[0]->r() = walls[1]->r();
    }
};
#endif