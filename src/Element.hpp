#ifndef ELEMENTHPP
#define ELEMENTHPP
#include <iostream>
#include "ElementState.hpp"
class Element
{
public:
    std::string color;
    ElementState state;

    Element()
    {
        color = "N";
        state = ElementState::on;
    }
    Element(const std::string color) : color(color)
    {
        state = ElementState::on;
    }
    ~Element()
    {
        // std::cout << "Element destructor" << std::endl;
    }
};
#endif