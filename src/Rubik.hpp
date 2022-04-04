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

public:
    Rubik(const Wall &wFront, const Wall &wBack, const Wall &wTop, const Wall &wBottom, const Wall &wRight, const Wall &wLeft) : wFront(wFront), wBack(wBack), wTop(wTop), wBottom(wBottom), wRight(wRight), wLeft(wLeft)
    {
    }

    void show()
    {
        }
    void R()
    {
        // wBack.l() = wTop.r();
    }
};
#endif