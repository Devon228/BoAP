#include "header.h"

bool check23(long long num) //O(log num)
{
    while (num > 23)
    {
        long long q = (num >> 3);
        long long r = (num & 7);
        num = q + r + r + r;
    }

    if (num == 23)
        return 1;
    else
        return 0;
}