#include "header.h"

void inv (int* num, int len, int base)
{
    for (int i = 1; i < len; i++)
    {
        num[i] = base - 1 - num[i];
    }
}