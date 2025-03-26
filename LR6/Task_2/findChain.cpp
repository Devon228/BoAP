#include "header1.h"

long long findChain(char*& st, char*& fin, long long num, long long res[])
{
    long long max_len = 0, max_first = 0;
    for (int i = 0; i < num; i++)
    {
        bool visited[num]{};

        long long len = 1;
        long long next = fin[i];
        visited[i] = 1;

        while (1)
        {
            bool found = 0;
            for (int j = 0; j < num; j++)
                if (st[j] == next && !visited[j])
                {
                    len++;
                    next = fin[j];
                    visited[j] = 1;

                    found = 1;
                    break;
                }

            if (!found)
                break;
        }

        if (len > max_len)
        {
            max_len = len;
            max_first = i;
        }
    }

    
    bool visited[num]{};
    long long next = fin[max_first];
    visited[max_first] = 1;
    res[0] = max_first;
    for (int i = 1; i < max_len; i++)
    {
        for (int j = 0; j < num; j++)
            if (st[j] == next && !visited[j])
            {
                next = fin[j];
                visited[j] = 1;
                res[i] = j;
                
                break;
            }
    }


    return max_len;
}