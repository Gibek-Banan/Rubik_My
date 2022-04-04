#include <iostream>
#include "Rubik.hpp"
#include "Wall.hpp"

void createWallStr(std::string wallStr[9], const std::string &color)
{
    for (int i = 0; i < 9; i++)
    {
        wallStr[i] = color;
    }
}

void log(const std::string &s)
{
    std::cout << s << std::endl;
}

void log(const std::string s[9])
{
    for (int i = 0; i < 9; i++)
    {
        std::cout << s[i] << std::endl;
    }
}

Wall **initRubik(Wall **walls, std::string *colors)
{
    walls = new Wall *[6];
    std::string temp[9];
    for (int i = 0; i < 6; i++)
    {
        createWallStr(temp, colors[i]);
        walls[i] = new Wall(temp);
    }
    return walls;
}

class Entity
{
public:
    int p[2];
    int a = 0;
    Entity()
    {
        a = 2;
    }
};
int main()
{
    Wall **walls;
    std::string colors[6] = {"W", "R", "G", "U", "Y", "O"};
    std::string temp[9];
    createWallStr(temp, colors[0]);
    walls = initRubik(walls, colors);
    log(temp);
    Rubik rubik(walls);
    rubik.show();
    rubik.R();
    rubik.show();
    // Entity e[9];
    // std::cout << e[2].a;
}