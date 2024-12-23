#include "header.h"

void coutN (int* num, int len, int base) //O(len)
{
    for (int i = 0; i < len; i++)
    {
        if (num[i] < 10)
            std::cout << num[i];
        else
            std::cout << 'A' + (num[i] - 10);
    }
    std::cout << "\n";
}