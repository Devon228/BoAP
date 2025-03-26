#include "header1.h"

void decompose(char*& str, char *&symb)
{
    short str_size = (short)strlen(str);
    int cur = 0;

    for (int i = 0; i < str_size; i++)
    {
        bool fnew = 1;
        for (int j = 0; j < cur; j++)
            if (str[i] == symb[j])
            {
                fnew = 0;
                break;
            }

        if (fnew)
            symb[cur++] = str[i];
    }

    symb[cur++] = '\0';
}