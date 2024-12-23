#include "header.h"

void cinLong(ll& number)
{
    while (!(std::cin >> number) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');

        std::cout << "Неверный ввод. Введите заново\n";
    }
}