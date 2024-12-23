#include "header.h"

void procAns(bool* alive, int j)
{
    std::cout << "Выжил ли раб " << j + 1 << "? Введите Да/Нет\n";
    std::string resp;
    while (1)
    {
        std::cin >> resp;
        if (resp == "Да")
        {
            alive[j] = 1;
            break;
        }
        else if (resp == "Нет")
        {
            alive[j] = 0;
            break;
        }
        else
        {
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "Введите Да/Нет\n";
        }
    }
}