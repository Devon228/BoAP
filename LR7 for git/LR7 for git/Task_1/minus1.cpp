#include "header.h"

void minus1 (int* num, int len, int base) //O(n)
{
    for (int i = len - 1; i >= 0; i--) //O(n)
    {
        if (num[i] != 0)
        {
            num[i]--;
            break;
        }
        else
        {
            num[i] = base - 1;
        }
    }
}