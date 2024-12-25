#include "header.h"

static void readStrFile(std::ifstream& in, char*& text, int sz)
{
    in.read(reinterpret_cast<char*>(&sz), sizeof(sz));
    //std::cout << sz << "\n"; 
    in.read(text, sz);
}

static void loadTrainFile(Train& arr, std::ifstream& in)
{
    in.read(reinterpret_cast<char*>(&arr.n.n32), sizeof(arr.n.n32));

    arr.type = new char[5];
    readStrFile(in, arr.type, 5);

    in.read(reinterpret_cast<char*>(&arr.start.hh), sizeof(arr.start.hh));
    in.read(reinterpret_cast<char*>(&arr.start.mm), sizeof(arr.start.mm));
    in.read(reinterpret_cast<char*>(&arr.start.tim), sizeof(arr.start.tim));

    in.read(reinterpret_cast<char*>(&arr.arrive.hh), sizeof(arr.arrive.hh));
    in.read(reinterpret_cast<char*>(&arr.arrive.mm), sizeof(arr.arrive.mm));
    in.read(reinterpret_cast<char*>(&arr.arrive.tim), sizeof(arr.arrive.tim));

    arr.place = new char[255];
    readStrFile(in, arr.place, 255);

    in.read(reinterpret_cast<char*>(&arr.seats), sizeof(arr.seats));
}

void loadFile(std::string file, Train*& arr, int& sz)
{
    std::ifstream in(file, std::ios::binary);
    if (!in) {
        std::cerr << "Error!.\n";
        return;
    }

    for (int i = 0; i < sz; i++)
    {
        delete[] arr[i].type;
        delete[] arr[i].place;
    }
    free(arr);

    in.read(reinterpret_cast<char*>(&sz), sizeof(sz));
    arr = (Train*)malloc(sz * sizeof(Train));
    std::cout << sz << "\n";

    for (int i = 0; i < sz; i++)
    {
        loadTrainFile(arr[i], in);
    }

    in.close();
}