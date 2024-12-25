#include "header.h"

void outputOne (Stud &arr)
{
    std::cout << "Number: " << arr.n << "\t";
    std::cout << "FIO: " << arr.fio << "\t";
    std::cout << "Group: " << arr.gr.i << "\t";
    std::cout << "Average mark: " << arr.mark << "\t";
    std::cout << "Average wage of the family: " << arr.wage << "\t";
}

