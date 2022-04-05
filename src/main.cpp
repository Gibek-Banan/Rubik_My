#include <iostream>
#include "CubeDisplay.h"
#include "Wall.h"
#include <random>

void shuffle(CubeDisplay &cd)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 2); // distribution in range [1, 6]

    // int n;
    // n = dist6(rng);
    // cd.R(n);
    // n = dist6(rng);
    // cd.L(n);
    // n = dist6(rng);
    // cd.U(n);
    // n = dist6(rng);
    // cd.D(n);
    // n = dist6(rng);
    // cd.F(n);
    // n = dist6(rng);
    // cd.B(n);

    cd.R();
    cd.L();
    cd.U();
    cd.D();
    cd.F();
    cd.B();
}

int main()
{
    // std::string s1[9] = {"a", "a", "a", "a", "a", "a", "a", "a", "a"};
    // Wall w1(s1);
    // Wall walls[6] = {w1, w1, w1, w1, w1, w1};
    // CubeDisplay cd(walls);
    CubeDisplay cd;
    //  shuffle(cd);
    cd.show();

    int input = 0;
    while (1)
    {
        std::cout << "1. R";
        std::cout << " / 11. Ri" << std::endl;
        std::cout << "2. L";
        std::cout << " / 22. Li" << std::endl;
        std::cout << "3. U";
        std::cout << " / 33. Ui" << std::endl;
        std::cout << "4. D";
        std::cout << " / 44. Di" << std::endl;
        std::cout << "5. F";
        std::cout << " / 55. Fi" << std::endl;
        std::cout << "6. B";
        std::cout << " / 66. Bi" << std::endl;
        std::cout << "7. Initial state" << std::endl;
        std::cout << "8. Shuffle" << std::endl;
        std::cout << "9. End" << std::endl
                  << std::endl;
        std::cout << "Operation = ";
        std::cin >> input;
        switch (input)
        {
        case 1:
            cd.R();
            cd.show();
            break;
        case 11:
            cd.Ri();
            cd.show();
            break;
        case 2:
            cd.L();
            cd.show();
            break;

        case 22:
            cd.Li();
            cd.show();
            break;

        case 3:
            cd.U();
            cd.show();
            break;

        case 33:
            cd.Ui();
            cd.show();
            break;

        case 4:
            cd.D();
            cd.show();
            break;

        case 44:
            cd.Di();
            cd.show();
            break;

        case 5:
            cd.F();
            cd.show();
            break;

        case 55:
            cd.Fi();
            cd.show();
            break;

        case 6:
            cd.B();
            cd.show();
            break;

        case 66:
            cd.Bi();
            cd.show();
            break;

        case 7:
            cd.init();
            cd.show();
            break;
        case 8:
            shuffle(cd);
            cd.show();
            break;
        case 9:
            return 0;
            break;

        default:
            std::cout << "Wrong key!" << std::endl;
        }
    }
}