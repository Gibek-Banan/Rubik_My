#include "CubeDisplay.h"
#include <iostream>
#include "Wall.h"

CubeDisplay::CubeDisplay(Wall *walls)
{
    if (walls == nullptr)
        std::abort();
    for (int i = 0; i < 6; i++)
    {
        this->walls[i] = walls[i];
    }
}

CubeDisplay::CubeDisplay()
{
    init();
}

CubeDisplay::~CubeDisplay()
{
    // std::cout << "CubeDisplay destructor" << std::endl;
}
void CubeDisplay::init()
{
    std::string temp[9];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            temp[j] = colors[i];
        }
        Wall w = Wall(temp);
        walls[i] = w;
    }
}

void CubeDisplay::show()
{
    std::string s[6];
    for (int i = 0; i < 6; i++)
    {
        s[i] = walls[i].getStr();
    }
    std::cout << "    " << s[0].substr(0, 3) << std::endl;
    std::cout << "    " << s[0].substr(3, 3) << std::endl;
    std::cout << "    " << s[0].substr(6, 3) << std::endl;
    std::cout << s[1].substr(0, 3) << " " << s[2].substr(0, 3) << " " << s[3].substr(0, 3) << " " << s[4].substr(0, 3) << std::endl;
    std::cout << s[1].substr(3, 3) << " " << s[2].substr(3, 3) << " " << s[3].substr(3, 3) << " " << s[4].substr(3, 3) << std::endl;
    std::cout << s[1].substr(6, 3) << " " << s[2].substr(6, 3) << " " << s[3].substr(6, 3) << " " << s[4].substr(6, 3) << std::endl;
    std::cout << "    " << s[5].substr(0, 3) << std::endl;
    std::cout << "    " << s[5].substr(3, 3) << std::endl;
    std::cout << "    " << s[5].substr(6, 3) << std::endl
              << std::endl;
}

// m1 - src = wall[4]; m2 - dst = wall[4]
void CubeDisplay::move(Wall &dst, int *dst_pos, Wall &src, int *src_pos, int mode)
{
    if (mode == 0)
    {
        for (int i = 0; i < 3; i++)
        {
            dst.e[dst_pos[i]] = src.e[src_pos[i]];
        }
    }
    // src == wall[4]
    else if (mode == 1)
    {
        dst.e[dst_pos[0]] = src.e[src_pos[2]];
        dst.e[dst_pos[1]] = src.e[src_pos[1]];
        dst.e[dst_pos[2]] = src.e[src_pos[0]];
    }
    // dst == wall[4]
    else if (mode == 2)
    {
        dst.e[dst_pos[2]] = src.e[src_pos[0]];
        dst.e[dst_pos[1]] = src.e[src_pos[1]];
        dst.e[dst_pos[0]] = src.e[src_pos[2]];
    }
}

void CubeDisplay::R(int n)
{
    Wall temp;
    for (int i = 0; i < n; i++)
    {
        move(temp, r, walls[2], r);
        move(walls[2], r, walls[5], r);
        move(walls[5], r, walls[4], r);
        move(walls[4], r, walls[0], r);
        move(walls[0], r, temp, r);

        walls[3].rotateR();
    }
}
void CubeDisplay::Ri(int n)
{
    Wall temp;
    for (int i = 0; i < n; i++)
    {
        move(temp, r, walls[2], r);
        move(walls[2], r, walls[0], r);
        move(walls[0], r, walls[4], r);
        move(walls[4], r, walls[5], r);
        move(walls[5], r, temp, r);

        walls[3].rotateL();
    }
}
// L
void CubeDisplay::L(int n)
{
    Wall temp;
    for (int i = 0; i < n; i++)
    {
        move(temp, l, walls[2], l);
        move(walls[2], l, walls[0], l);
        move(walls[0], l, walls[4], l);
        move(walls[4], l, walls[5], l);
        move(walls[5], l, temp, l);

        walls[1].rotateR();
    }
}
void CubeDisplay::Li(int n)
{
    Wall temp;
    for (int i = 0; i < n; i++)
    {
        move(temp, l, walls[2], l);
        move(walls[2], l, walls[5], l);
        move(walls[5], l, walls[4], l);
        move(walls[4], l, walls[0], l);
        move(walls[0], l, temp, l);

        walls[1].rotateL();
    }
}

// U
void CubeDisplay::U(int n)
{
    Wall temp;
    for (int i = 0; i < n; i++)
    {
        move(temp, t, walls[2], t);
        move(walls[2], t, walls[3], t);
        move(walls[3], t, walls[4], t, 1);
        move(walls[4], t, walls[1], t, 2);
        move(walls[1], t, temp, t);

        walls[0].rotateR();
    }
}
void CubeDisplay::Ui(int n)
{
    Wall temp;
    for (int i = 0; i < n; i++)
    {
        move(temp, t, walls[2], t);
        move(walls[2], t, walls[1], t);
        move(walls[1], t, walls[4], t, 1);
        move(walls[4], t, walls[3], t, 2);
        move(walls[3], t, temp, t);

        walls[0].rotateL();
    }
}
// D
void CubeDisplay::D(int n)
{
    Wall temp;
    for (int i = 0; i < n; i++)
    {
        move(temp, b, walls[2], b);
        move(walls[2], b, walls[1], b);
        move(walls[1], b, walls[4], b, 1);
        move(walls[4], b, walls[3], b, 2);
        move(walls[3], b, temp, b);

        walls[5].rotateR();
    }
}
void CubeDisplay::Di(int n)
{
    Wall temp;
    for (int i = 0; i < n; i++)
    {
        move(temp, b, walls[2], b);
        move(walls[2], b, walls[3], b);
        move(walls[3], b, walls[4], b, 1);
        move(walls[4], b, walls[1], b, 2);
        move(walls[1], b, temp, b);

        walls[5].rotateL();
    }
}
// F
void CubeDisplay::F(int n)
{
    Wall temp;
    for (int i = 0; i < n; i++)
    {
        move(temp, b, walls[0], b);
        move(walls[0], b, walls[1], r);
        move(walls[1], r, walls[5], t);
        move(walls[5], t, walls[3], l);
        move(walls[3], l, temp, b);

        walls[2].rotateR();
    }
}
void CubeDisplay::Fi(int n)
{
    Wall temp;
    for (int i = 0; i < n; i++)
    {
        move(temp, b, walls[0], b);
        move(walls[0], b, walls[3], l);
        move(walls[3], l, walls[5], t);
        move(walls[5], t, walls[1], r);
        move(walls[1], r, temp, b);

        walls[2].rotateL();
    }
}
// B
void CubeDisplay::B(int n)
{
    Wall temp;
    for (int i = 0; i < n; i++)
    {
        move(temp, t, walls[0], t);
        move(walls[0], t, walls[3], r);
        move(walls[3], r, walls[5], b);
        move(walls[5], b, walls[1], l);
        move(walls[1], l, temp, t);

        walls[4].rotateL();
    }
}
void CubeDisplay::Bi(int n)
{
    Wall temp;
    for (int i = 0; i < n; i++)
    {
        move(temp, t, walls[0], t);
        move(walls[0], t, walls[1], l);
        move(walls[1], l, walls[5], b);
        move(walls[5], b, walls[3], r);
        move(walls[3], r, temp, t);
        walls[4].rotateR();
    }
}