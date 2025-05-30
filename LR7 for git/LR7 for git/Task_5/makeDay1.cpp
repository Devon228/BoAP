#include "header.h"

void makeDay1 (int* num_barr, int* cur_barr) //O(1000 = кол-во_рабов * кол-во_бочек)
{
    for (int i = 1; i <= 240; i++) //O(1000 = кол-во_рабов * кол-во_бочек)
    {
        std::string ternary = toBase3(i);
        for (int j = 0; j < 5; j++)
        {
            if (ternary[j] == '0')
            {
                num_barr[j*240 + cur_barr[j]] = i;
                cur_barr[j]++;
            }
        }
    }
 
    for (int j = 0; j < 5; j++) //O(1000 = кол-во_рабов * кол-во_бочек)
    {
        std::cout << "За первые пару минут 1 дня раб " << j + 1 << " выпивает из бочек: ";
        for (int i = 0; num_barr[j*240+i] != 0; i++)
        {
            std::cout << num_barr[j*240+i] << " ";
        }
        std::cout << "\n";
    }
}