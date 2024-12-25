#include "header.h"

void inputTrain(Train*& arr, int &sz)
{
    for (int i = 0; i < sz; i++)
    {
        delete[] arr[i].type;
        delete[] arr[i].place;
    }
    free(arr);

    std::cout << "Menu for input\n";
    std::cout << "1. Input array of n trains\n";  
    std::cout << "2. Input trains until a special train with type 0\n";
    std::cout << "3. Input each train after asking\n";
    
    ll option;
    cinLong(option);

    if (option == 1)
    {
        std::cout << "Enter the number of trains n\n";
        ll n;
        cinLong(n);

        sz = n;
        arr = (Train*)malloc(sz * sizeof(Train));

        for (int i = 0; i < n; i++)
        {
            inputOne(arr[i], i);
        }
    }
    else if (option == 2)
    {
        int sz0 = 16;
        sz = 0;
        arr = (Train*)malloc(sz0 * sizeof(Train));

        while (true)
        {
            if (!inputOne(arr[sz], sz))
                break;

            sz++;
            if (sz0 == sz)
            {
                sz0 *= 2;
                arr = (Train*)realloc(arr, sz0 * sizeof(Train));
            }
        }

        arr = (Train*)realloc(arr, sz * sizeof(Train));
    }
    else if (option == 3)
    {
        int sz0 = 16;
        sz = 0;
        arr = (Train*)malloc(sz0 * sizeof(Train));

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
                arr = (Train*)realloc(arr, sz0 * sizeof(Train));
            }
        }

        arr = (Train*)realloc(arr, sz * sizeof(Train));
    }
    else
    {
        std::cout << "Wrong option. Type again\n";
    }

    return;
}