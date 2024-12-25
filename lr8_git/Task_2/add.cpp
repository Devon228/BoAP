#include "header.h"

void add(Stud*& arr, int &sz)
{
    std::cout << "Menu for add\n";
    std::cout << "1. Add n new students\n";  
    std::cout << "2. Add student until a special student with type 0\n";
    std::cout << "3. Add each student after asking\n";
    
    ll option;
    cinLong(option);

    if (option == 1)
    {
        std::cout << "Enter the number of students n\n";
        ll n;
        cinLong(n);

        arr = (Stud*)realloc(arr, (sz + n) * sizeof(Stud));

        for (int i = sz; i < sz + n; i++)
        {
            inputOne(arr[i], i);
        }

        sz += n;
    }
    else if (option == 2)
    {
        int sz0 = 16;
        arr = (Stud*)realloc(arr, (sz + sz0) * sizeof(Stud));
        int i = 0;

        while (true)
        {
            if (!inputOne(arr[sz], sz))
                break;

            sz++;
            i++;
            if (sz0 == i)
            {
                sz0 *= 2;
                arr = (Stud*)realloc(arr, (sz + sz0) * sizeof(Stud));
            }
        }

        arr = (Stud*)realloc(arr, sz * sizeof(Stud));
    }
    else if (option == 3)
    {
        int sz0 = 16;
        arr = (Stud*)realloc(arr, (sz + sz0) * sizeof(Stud));
        int i = 0;

        while (true)
        {
            std::cout << "Do you want to continue input? yes : 1 | no : otherwise\n";
            ll option1;
            cinLong(option1);
            if (option1 != 1)
                break;

            inputOne(arr[sz], sz);
                
            sz++;
            i++;
            if (sz0 == i)
            {
                sz0 *= 2;
                arr = (Stud*)realloc(arr, (sz + sz0) * sizeof(Stud));
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