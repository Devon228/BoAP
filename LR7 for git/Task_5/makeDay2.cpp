#include "header.h"

void makeDay2 (int* num_barr, int* cur_barr, bool* alive)
{
    for (int i = 1; i <= 240; i++)
        {
            std::string ternary = toBase3(i);
            for (int j = 0; j < 5; j++)
            {
                if (alive[j] == 1 && ternary[j] == '1')
                {
                    num_barr[j*240+cur_barr[j]] = i;
                    cur_barr[j]++;
                }
            }
        }

    for (int j = 0; j < 5; j++)
    {
        if (alive[j] == 0) 
            continue;
            
        std::cout << "За первые пару минут 2 дня раб " << j + 1 << " выпивает из бочек: ";
        for (int i = 0; num_barr[j*240+i] != 0; i++)
        {
            std::cout << num_barr[j*240+i] << " ";
        }
        std::cout << "\n";
    }
}