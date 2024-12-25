#include "header.h"

void changeTrain(Train*& arr, const int& sz, std::string file)
{
    ll num;
    while (true)
    {
        std::cout << "Enter the number of the train to change:\n";
        cinLong(num);

        if (1 <= num && num <= sz)
            break;
        std::cout << "Wrong number. Type again\n";
    }

    for (int i = 0; i < sz; i++)
    {
        if (arr[i].n.n32 == num)
        {
            delete[] arr[i].type;
            delete[] arr[i].place;

            inputOne(arr[i], num);

            int pos = sizeof(sz) + i * sizeof(Train);

            std::ofstream out(file, std::ios::binary | std::ios::app);
            out.seekp(0L,std::ios::beg);
            
            writeTrainFile(arr[i], out);
            break;
        }
    }
}