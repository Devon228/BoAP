#include "header.h"

void outputOrder(Stud*& arr, const int& sz, const double& minwage)
{
    for (int i = 1; i < sz; i++)
    {
        for (int j = i; j - 1 >= 0; j--)
        {
            if (arr[j-1].mark < arr[j].mark) 
            {
                std::swap(arr[j-1], arr[j]);
            }
        }
    }

    std::cout << "All the correct order of students from high to low priority of getting a dormitory room" << "\n";
    std::cout << "Wage less then double minimum wage:\n";
    for (int i = 0; i < sz; i++)
    {
        if (arr[i].wage < 2 * minwage)
        {
            outputOne(arr[i]);
            std::cout << "\n";
        }
    }
    std::cout << "Other students:\n";
    for (int i = 0; i < sz; i++)
    {
        if (arr[i].wage >= 2 * minwage)
        {
            outputOne(arr[i]);
            std::cout << "\n";
        }
    }
}

void outputAll(Stud*& arr, const int& sz)
{
    std::cout << "There are " << sz << " students:\n";
    for (int i = 0; i < sz; i++)
    {
        outputOne(arr[i]);
        std::cout << "\n";
    }
}