#include "header.h"

void sortTrain (Train*& arr, const int& sz)
{
    for (int i = 1; i < sz; i++)
    {
        for (int j = i; j - 1 >= 0; j--)
        {
            if (arr[j-1].seats > arr[j].seats) 
            {
                std::swap(arr[j-1], arr[j]);
            }
        }
    }

    return;
}