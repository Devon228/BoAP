#include "header.h"

void changeTrain(Train*& arr, const int& sz, std::string file)
{
    ll num;
    while (true)
    {
        std::cout << "Enter the number of the train to change:\n";
        cinLong(num);

        if (1 <= num)
            break;
        std::cout << "Wrong number. Type again\n";
    }

    int sztrain = 4 + 4 + 5 + 12 + 12 + 4 + 255 + 4;
    for (int i = 0; i < sz; i++)
    {
        if (arr[i].n.n32 == num)
        {
            delete[] arr[i].type;
            delete[] arr[i].place;

            inputOne(arr[i], num - 1);

            int pos = sizeof(sz) + i * sztrain;
            std::cout << pos << "\n";

            std::ofstream out(file, std::ios::binary | std::ios::in | std::ios::out);
            out.seekp(pos,std::ios::beg);

            writeTrainFile(arr[i], out);
            break;
        }
    }
}