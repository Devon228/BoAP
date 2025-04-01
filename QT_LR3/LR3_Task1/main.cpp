#include <iostream>
#include <string>
#include <cmath>

std::string toBin (long long val)
{
    if (val == 0)
        return "0";
    if (val == 1)
        return "1";

    return toBin(val / 2) + std::to_string(val % 2);
}
std::string toBin (double fract)
{
    if (fract < 0.00001)
        return "";

    return std::to_string((int)trunc(fract)) + toBin((fract - trunc(fract)) *  2);
}

int main()
{
    while (1)
    {
        int option;
        std::cout << "Enter 1 to continue\n";
        std::cin >> option;
        if (option != 1)
            break;

        double num;
        std::cout << "Enter a decimal number\n";
        std::cin >> num;

        if (num < 0)
        {
            num = -num;
            std::cout << "-";
        }

        std::string z = toBin((long long)trunc(num));
        std::string fract = toBin(2 * (num - trunc(num)));

        std::cout << z;
        if (fract != "")
            std::cout << '.' + toBin(2 * (num - trunc(num))) << "\n";
    }

    return 0;
}
