#include "header1.h"

void cinLong(ll& number)
{
    while (!(std::cin >> number) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');

        std::cout << "Incorrect input. Please, write again\n";
    }
}