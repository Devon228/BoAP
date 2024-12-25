#include "header.h"

void deleteTrain(Train*& arr, int& sz, std::string file)
{
    ll num;
    while (true)
    {
        std::cout << "Enter the number of the train to delete:\n";
        cinLong(num);

        if (1 <= num)
            break;
        std::cout << "Wrong number. Type again\n";
    }

    for (int i = 0; i < sz; i++)
    {
        if (arr[i].n.n32 == num)
        {
            for (int j = i; j < sz - 1; j++)
            {            
                delete[] arr[j].type;
                delete[] arr[j].place;
                arr[j] = arr[j+1];
            }

            delete[] arr[sz-1].type;
            delete[] arr[sz-1].place;
            sz--;
            arr = (Train*)realloc(arr, sz * sizeof(Train));

            writeFile(arr, i,  sz, file);
            break;
        }
    }

}