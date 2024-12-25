#include "header.h"

void outTrainToPlace(Train*& arr, const int& sz)
{
    std::cout << "Enter the place where trains go: \n";
    char *place = new char[255];
    getchar();
    cinText(place, 255);
    
    std::cout << "All the trains going to place " << place << "\n";
    for (int i = 0; i < sz; i++)
    {
        if (strcmp(arr[i].place, place) == 0)
        {
            outputOne(arr[i]);
            std::cout << "\n";
        }
    }

    delete[] place;   
}

void outputTrainAll(Train*& arr, const int& sz)
{
    std::cout << "There are " << sz << " trains:\n";
    for (int i = 0; i < sz; i++)
    {
        outputOne(arr[i]);
        std::cout << "\n";
    }
}