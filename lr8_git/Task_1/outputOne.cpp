#include "header.h"

static int to2 (int hh) //ведущие нули
{
    if (hh <= 9)
        std::cout << 0;

    return hh;
}

void outputOne (Train &arr) //вывод в строку всех полей
{
    std::cout << "Number: " << arr.n.n32 << "\t";
    std::cout << "Type: " << arr.type << "\t";
    std::cout << "Depatrure: " << to2(arr.start.hh) << ":" << to2(arr.start.mm) << "\t";
    std::cout << "Arrival: "  << to2(arr.arrive.hh) << ":" << to2(arr.arrive.mm) << "\t";
    std::cout << "Place of arrival: " << arr.place << "\t";
    std::cout << "Number of free seats: " << arr.seats;
}

