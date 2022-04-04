#ifndef ELEMENTHPP
#define ELEMENTHPP
#include <iostream>
class Element
{
public:
    std::string color;

    Element()
    {
        color = "N";
    }
    Element(const std::string color) : color(color)
    {
    }
    ~Element()
    {
        // std::cout << "Element destructor" << std::endl;
    }
};
#endif