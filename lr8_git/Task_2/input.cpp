#include "header.h"

void input(Stud*& arr, int &sz)
{
    free(arr);

    std::cout << "Menu for input\n";
    std::cout << "1. Input array of n students\n";  
    std::cout << "2. Input students until a special student with full name 0\n";
    std::cout << "3. Input each student after asking\n";
    
    ll option;
    cinLong(option);

    if (option == 1)
    {
        std::cout << "Enter the number n\n";
        ll n;
        cinLong(n);

        sz = n;
        arr = (Stud*)malloc(sz * sizeof(Stud));

        for (int i = 0; i < n; i++)
        {
            inputOne(arr[i], i);
        }
    }
    else if (option == 2)
    {
        int sz0 = 16;
        sz = 0;
        arr = (Stud*)malloc(sz0 * sizeof(Stud));

        while (true)
        {
            if (!inputOne(arr[sz], sz))
                break;

            sz++;
            if (sz0 == sz)
            {
                sz0 *= 2;
                arr = (Stud*)realloc(arr, sz0 * sizeof(Stud));
            }
        }

        arr = (Stud*)realloc(arr, sz * sizeof(Stud));
    }
    else if (option == 3)
    {
        int sz0 = 16;
        sz = 0;
        arr = (Stud*)malloc(sz0 * sizeof(Stud));

        while (true)
        {
            std::cout << "Do you want to continue input? yes : 1 | no : otherwise\n";
            ll option1;
            cinLong(option1);
            if (option1 != 1)
                break;

            inputOne(arr[sz], sz);
                
            sz++;
            if (sz0 == sz)
            {
                sz0 *= 2;
                arr = (Stud*)realloc(arr, sz0 * sizeof(Stud));
            }
        }

        arr = (Stud*)realloc(arr, sz * sizeof(Stud));
    }
    else
    {
        std::cout << "Wrong option. Type again\n";
    }

    return;
}