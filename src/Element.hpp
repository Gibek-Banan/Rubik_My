#ifndef ELEMENTHPP
#define ELEMENTHPP
#include <string>
#include "ToChange.hpp"
class Element
{
private:
    std::string color;
    ToChange state;

public:
    Element(const std::string &color) : color(color)
    {
        state = ToChange::dontChange;
    }
};
#endif