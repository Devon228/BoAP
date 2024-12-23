#include "header.h"

bool check107(long long num) //O(log num)
{
    while (num > 107)
    {
        long long q = (num >> 2);
        long long r = (num & 3);
        long long r1 = 0;
        for (int i = 0; i < 27; i++)
            r1 += r;
        num = q + r1;
    }

    if (num == 107)
        return 1;
    else
        return 0;
}