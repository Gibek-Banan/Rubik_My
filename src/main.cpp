#include <iostream>
#include "Rubik.hpp"
#include "Wall.hpp"
#include <random>

void shuffle(Rubik &rubik)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 3); // distribution in range [1, 6]

    int n;
    n = dist6(rng);
    for (int i = 0; i < n; i++)
    {
        rubik.R();
    }
    n = dist6(rng);
    for (int i = 0; i < n; i++)
    {
        rubik.L();
    }
    n = dist6(rng);
    for (int i = 0; i < n; i++)
    {
        rubik.U();
    }
    n = dist6(rng);
    for (int i = 0; i < n; i++)
    {
        rubik.D();
    }
    n = dist6(rng);
    for (int i = 0; i < n; i++)
    {
        rubik.F();
    }
    n = dist6(rng);
    for (int i = 0; i < n; i++)
    {
        rubik.B();
    }
}

int main()
{
    // std::string s1[9] = {"a", "a", "a", "a", "a", "a", "a", "a", "a"};
    // Wall w1(s1);
    // Wall walls[6] = {w1, w1, w1, w1, w1, w1};
    // Rubik rubik(walls);
    Rubik rubik;
    // shuffle(rubik);
    rubik.show();

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
            rubik.R();
            rubik.show();
            break;
        case 11:
            rubik.Ri();
            rubik.show();
            break;
        case 2:
            rubik.L();
            rubik.show();
            break;

        case 22:
            rubik.Li();
            rubik.show();
            break;

        case 3:
            rubik.U();
            rubik.show();
            break;

        case 33:
            rubik.Ui();
            rubik.show();
            break;

        case 4:
            rubik.D();
            rubik.show();
            break;

        case 44:
            rubik.Di();
            rubik.show();
            break;

        case 5:
            rubik.F();
            rubik.show();
            break;

        case 55:
            rubik.Fi();
            rubik.show();
            break;

        case 6:
            rubik.B();
            rubik.show();
            break;

        case 66:
            rubik.Bi();
            rubik.show();
            break;

        case 7:
            rubik.init();
            rubik.show();
            break;
        case 8:
            shuffle(rubik);
            rubik.show();
            break;
        case 9:
            return 0;
            break;

        default:
            std::cout << "Wrong key!" << std::endl;
        }
    }
}