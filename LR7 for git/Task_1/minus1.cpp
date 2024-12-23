#include "header.h"

void minus1 (int* num, int len, int base)
{
    for (int i = len - 1; i >= 0; i--)
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