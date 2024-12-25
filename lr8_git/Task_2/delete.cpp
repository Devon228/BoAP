#include "header.h"

void deleteS(Stud*& arr, int& sz)
{
    ll num;
    while (true)
    {
        std::cout << "Enter the number of the student to delete:\n";
        cinLong(num);

        if (1 <= num)
            break;
        std::cout << "Wrong number. Type again\n";
    }

    for (int i = 0; i < sz; i++)
    {
        if (arr[i].n == num)
        {
            for (int j = i; j < sz - 1; j++)
            {            
                arr[j] = arr[j+1];
            }

            sz--;
            arr = (Stud*)realloc(arr, sz * sizeof(Stud));
            break;
        }
    }

}