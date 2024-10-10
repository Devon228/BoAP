#include <iostream>
#include <cmath>

int main()
{
    long long N;
    long double z, x, n, k, m, f;
    std::cout << "Enter z, n, k, m\n";
    std::cin >> z >> n >> k >> m;



    long long option;
    std::cout << "Choose f(x) options 1, 2, or 3\n1: f(x) = 2x | 2: f(x) = x^3 | 3: f(x) = x/3\nEnter 1, 2 or 3\n";
    std::cin >> option;

    if (z > 1)
    {
        std::cout << "z > 1 then x = z\n";
        x = z;
    }
    else
    {
        std::cout << "z <= 1 then x = z^2 + 1\n";
        x = z * z + 1;
    }

    switch (option)
    {
        case 1:
            f = 2 * x;
            std::cout << "Option 1: f(x) = 2 * x\n";
            break;
        case 2:
            f = x * x * x;
            std::cout << "Option 2: f(x) = x ^ 3\n";
            break;
        case 3:
            f = x / 3;
            std::cout << "Option 3: f(x) = x / 3\n";
            break;
        default:
            f = 2 * x;
            std::cout << "Wrong option! f(x) = 2 * x\n";
            break;

    }

    long double y = sin(n*f) + cos(k*x) + log(m*x);

    std::cout << "y = " << y;
    return 0;
}