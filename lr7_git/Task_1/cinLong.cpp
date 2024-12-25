#include "header.h"

void cinLong(ll& number)
{
    while (!(std::cin >> number) || (std::cin.peek() != '\n') || (number < 0))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');

        std::cout << "Wrong input. Type again\n";
    }
}