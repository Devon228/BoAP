#include "header.h"

void change(Stud*& arr, const int& sz)
{
    ll num;
    while (true)
    {
        std::cout << "Enter the number of the student to change:\n";
        cinLong(num);

        if (1 <= num)
            break;
        std::cout << "Wrong number. Type again\n";
    }

    for (int i = 0; i < sz; i++)
    {
        if (arr[i].n == num)
        {
            inputOne(arr[i], num);
            break;
        }
    }
}