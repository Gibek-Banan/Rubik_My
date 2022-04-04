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
    void R(int n = 1)
    {
        for (int i = 0; i < n; i++)
        {
            Wall temp;
            temp = walls[2]->r();
            walls[2]->r() = walls[5]->r();
            walls[5]->r() = walls[4]->r();
            walls[4]->r() = walls[0]->r();
            walls[0]->r() = temp;
            walls[3]->rotateR();
        }
    }
    void Ri(int n = 1)
    {
        for (int i = 0; i < n; i++)
        {
            Wall temp;
            temp = walls[2]->r();
            walls[2]->r() = walls[0]->r();
            walls[0]->r() = walls[4]->r();
            walls[4]->r() = walls[5]->r();
            walls[5]->r() = temp;

            walls[3]->rotateL();
        }
    }
    // L
    void L(int n = 1)
    {
        for (int i = 0; i < n; i++)
        {
            Wall temp;
            temp = walls[2]->l();
            walls[2]->l() = walls[0]->l();
            walls[0]->l() = walls[4]->l();
            walls[4]->l() = walls[5]->l();
            walls[5]->l() = temp;
            walls[1]->rotateR();
        }
    }
    void Li(int n = 1)
    {
        for (int i = 0; i < n; i++)
        {
            Wall temp;
            temp = walls[2]->l();
            walls[2]->l() = walls[5]->l();
            walls[5]->l() = walls[4]->l();
            walls[4]->l() = walls[0]->l();
            walls[0]->l() = temp;

            walls[1]->rotateL();
        }
    }

    // U
    void U(int n = 1)
    {
        for (int i = 0; i < n; i++)
        {
            Wall temp;
            temp = walls[2]->t();
            walls[2]->t() = walls[3]->t();
            walls[3]->t() = walls[4]->t();
            walls[4]->t() = walls[1]->t();
            walls[1]->t() = temp;
            walls[0]->rotateR();
        }
    }
    void Ui(int n = 1)
    {
        for (int i = 0; i < n; i++)
        {
            Wall temp;
            temp = walls[2]->t();
            walls[2]->t() = walls[1]->t();
            walls[1]->t() = walls[4]->t();
            walls[4]->t() = walls[3]->t();
            walls[3]->t() = temp;
            walls[0]->rotateL();
        }
    }
    // D
    void D(int n = 1)
    {
        for (int i = 0; i < n; i++)
        {
            Wall temp;
            temp = walls[2]->b();
            walls[2]->b() = walls[1]->b();
            walls[1]->b() = walls[4]->b();
            walls[4]->b() = walls[3]->b();
            walls[3]->b() = temp;
            walls[5]->rotateR();
        }
    }
    void Di(int n = 1)
    {
        for (int i = 0; i < n; i++)
        {
            Wall temp;
            temp = walls[2]->b();
            walls[2]->b() = walls[3]->b();
            walls[3]->b() = walls[4]->b();
            walls[4]->b() = walls[1]->b();
            walls[1]->b() = temp;
            walls[5]->rotateL();
        }
    }
    // F
    void F(int n = 1)
    {
        for (int i = 0; i < n; i++)
        {
            Wall temp;
            temp = walls[0]->b();
            walls[0]->b() = walls[1]->r();
            walls[1]->r() = walls[5]->t();
            walls[5]->t() = walls[3]->l();
            walls[3]->l() = temp;

            walls[2]->rotateR();
        }
    }
    void Fi(int n = 1)
    {
        for (int i = 0; i < n; i++)
        {
            Wall temp;
            temp = walls[0]->b();
            walls[0]->b() = walls[3]->r();
            walls[3]->r() = walls[5]->t();
            walls[5]->t() = walls[1]->l();
            walls[1]->l() = temp;

            walls[2]->rotateL();
        }
    }
    // B
    void B(int n = 1)
    {
        for (int i = 0; i < n; i++)
        {
            Wall temp;
            temp = walls[0]->t();
            walls[0]->t() = walls[3]->r();
            walls[3]->r() = walls[5]->b();
            walls[5]->b() = walls[1]->l();
            walls[1]->l() = temp;
            walls[4]->rotateR();
        }
    }
    void Bi(int n = 1)
    {
        for (int i = 0; i < n; i++)
        {
            Wall temp;
            temp = walls[0]->t();
            walls[0]->t() = walls[1]->r();
            walls[1]->r() = walls[5]->b();
            walls[5]->b() = walls[3]->l();
            walls[3]->l() = temp;
            walls[4]->rotateR();
        }
    }
};
#endif