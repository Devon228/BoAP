#include "header.h"

void cinN(int* num, int len) //O(len)
{
    char symb;
    for (int i = 0; i < len; i++)
    {
        std::cin >> symb;
        if (symb >= 'A')
            num[i] = (symb - 'A') + 10;
        else
            num[i] = (symb - '0');
    }
}