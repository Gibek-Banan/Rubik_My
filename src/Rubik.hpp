#ifndef RUBIKHPP
#define RUBIKHPP
#include <iostream>
#include "Wall.hpp"

class Rubik
{
private:
    // Wall wFront;
    // Wall wBack;
    // Wall wTop;
    // Wall wBottom;
    // Wall wRight;
    // Wall wLeft;
    Wall **walls;
    int r[3] = {2, 5, 8};
    int l[3] = {0, 3, 6};
    int t[3] = {0, 1, 2};
    int b[3] = {6, 7, 8};

public:
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
        std::string s[6];
        for (int i = 0; i < 6; i++)
        {
            s[i] = walls[i]->getStr();
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

    void move(Wall &dst, int *dst_pos, Wall &src, int *src_pos)
    {
        for (int i = 0; i < 3; i++)
        {
            dst.e[dst_pos[i]] = src.e[src_pos[i]];
        }
    }

    void R(int n = 1)
    {
        Wall temp;
        for (int i = 0; i < n; i++)
        {
            move(temp, r, *walls[2], r);
            move(*walls[2], r, *walls[5], r);
            move(*walls[5], r, *walls[4], r);
            move(*walls[4], r, *walls[0], r);
            move(*walls[0], r, temp, r);

            walls[3]->rotateR();
        }
    }
    void Ri(int n = 1)
    {
        Wall temp;
        for (int i = 0; i < n; i++)
        {
            move(temp, r, *walls[2], r);
            move(*walls[2], r, *walls[0], r);
            move(*walls[0], r, *walls[4], r);
            move(*walls[4], r, *walls[5], r);
            move(*walls[5], r, temp, r);

            walls[3]->rotateL();
        }
    }
    // L
    void L(int n = 1)
    {
        Wall temp;
        for (int i = 0; i < n; i++)
        {
            move(temp, l, *walls[2], l);
            move(*walls[2], l, *walls[0], l);
            move(*walls[0], l, *walls[4], l);
            move(*walls[4], l, *walls[5], l);
            move(*walls[5], l, temp, l);

            walls[1]->rotateR();
        }
    }
    void Li(int n = 1)
    {
        Wall temp;
        for (int i = 0; i < n; i++)
        {
            move(temp, l, *walls[2], l);
            move(*walls[2], l, *walls[5], l);
            move(*walls[5], l, *walls[4], l);
            move(*walls[4], l, *walls[0], l);
            move(*walls[0], l, temp, l);

            walls[1]->rotateL();
        }
    }

    // U
    void U(int n = 1)
    {
        Wall temp;
        for (int i = 0; i < n; i++)
        {
            move(temp, t, *walls[2], t);
            move(*walls[2], t, *walls[3], t);
            move(*walls[3], t, *walls[4], t);
            move(*walls[4], t, *walls[1], t);
            move(*walls[1], t, temp, t);

            walls[0]->rotateR();
        }
    }
    void Ui(int n = 1)
    {
        Wall temp;
        for (int i = 0; i < n; i++)
        {
            move(temp, t, *walls[2], t);
            move(*walls[2], t, *walls[1], t);
            move(*walls[1], t, *walls[4], t);
            move(*walls[4], t, *walls[3], t);
            move(*walls[3], t, temp, t);

            walls[0]->rotateL();
        }
    }
    // D
    void D(int n = 1)
    {
        Wall temp;
        for (int i = 0; i < n; i++)
        {
            move(temp, b, *walls[2], b);
            move(*walls[2], b, *walls[1], b);
            move(*walls[1], b, *walls[4], b);
            move(*walls[4], b, *walls[3], b);
            move(*walls[3], b, temp, b);

            walls[5]->rotateR();
        }
    }
    void Di(int n = 1)
    {
        Wall temp;
        for (int i = 0; i < n; i++)
        {
            move(temp, b, *walls[2], b);
            move(*walls[2], b, *walls[3], b);
            move(*walls[3], b, *walls[4], b);
            move(*walls[4], b, *walls[1], b);
            move(*walls[1], b, temp, b);

            walls[5]->rotateL();
        }
    }
    // F
    void F(int n = 1)
    {
        Wall temp;
        for (int i = 0; i < n; i++)
        {
            move(temp, b, *walls[0], b);
            move(*walls[0], b, *walls[1], r);
            move(*walls[1], r, *walls[5], t);
            move(*walls[5], t, *walls[3], l);
            move(*walls[3], l, temp, b);

            walls[2]->rotateR();
        }
    }
    void Fi(int n = 1)
    {
        Wall temp;
        for (int i = 0; i < n; i++)
        {
            move(temp, b, *walls[0], b);
            move(*walls[0], b, *walls[3], l);
            move(*walls[3], l, *walls[5], t);
            move(*walls[5], t, *walls[1], r);
            move(*walls[1], r, temp, b);

            walls[2]->rotateL();
        }
    }
    // B
    void B(int n = 1)
    {
        Wall temp;
        for (int i = 0; i < n; i++)
        {
            move(temp, t, *walls[0], t);
            move(*walls[0], t, *walls[3], r);
            move(*walls[3], r, *walls[5], b);
            move(*walls[5], b, *walls[1], l);
            move(*walls[1], l, temp, t);

            walls[4]->rotateR();
        }
    }
    void Bi(int n = 1)
    {
        Wall temp;
        for (int i = 0; i < n; i++)
        {
            move(temp, t, *walls[0], t);
            move(*walls[0], t, *walls[1], l);
            move(*walls[1], l, *walls[5], b);
            move(*walls[5], b, *walls[3], r);
            move(*walls[3], r, temp, t);
            walls[4]->rotateL();
        }
    }
};
#endif