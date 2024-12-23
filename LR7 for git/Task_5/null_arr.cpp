#include "header.h"

void null_arr (int* arr, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr[i*n + j] = 0;
}