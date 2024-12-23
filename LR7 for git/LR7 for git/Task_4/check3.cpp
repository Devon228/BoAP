#include "header.h"

bool check3(long long num) //O(log num)
{
    while (num > 3)
    {
        long long q = (num >> 1);
        long long r = (num & 1) << 1;
        num = q + r;
    }

    if (num == 3)
        return 1;
    else
        return 0;
}