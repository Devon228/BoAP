#include "header.h"

static void clearFile (const std::string file)
{
    std::ofstream out(file, std::ios::binary | std::ios::trunc);
    if (!out) {
        std::cerr << "Failed to open file!\n";
        return;
    }

    out.close();
}


static void writeStrFile(std::ofstream &out, char*& str, int len) 
{
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(str, len);
}


void writeTrainFile (Train &arr, std::ofstream &out)
{
    out.write(reinterpret_cast<const char*>(&arr.n.n32), sizeof(arr.n.n32));

    writeStrFile(out, arr.type, 5);

    out.write(reinterpret_cast<const char*>(&arr.start.hh), sizeof(arr.start.hh));
    out.write(reinterpret_cast<const char*>(&arr.start.mm), sizeof(arr.start.mm));
    out.write(reinterpret_cast<const char*>(&arr.start.tim), sizeof(arr.start.tim));

    out.write(reinterpret_cast<const char*>(&arr.arrive.hh), sizeof(arr.arrive.hh));
    out.write(reinterpret_cast<const char*>(&arr.arrive.mm), sizeof(arr.arrive.mm));
    out.write(reinterpret_cast<const char*>(&arr.arrive.tim), sizeof(arr.arrive.tim));

    writeStrFile(out, arr.place, 255);

    out.write(reinterpret_cast<const char*>(&arr.seats), sizeof(arr.seats));
}


void writeFile (Train*& arr, int sz_start,  int sz, const std::string file)
{
    if (sz_start == 0)
    {
        clearFile(file);
        //std::ofstream out(file, std::ios::binary | std::ios::ate);
        //out.write(reinterpret_cast<const char*>(&sz), sizeof(sz));
    }

    std::ofstream outsz(file, std::ios::binary | std::ios::in | std::ios::out);
    //outsz.seekp(0L,std::ios::beg);
    outsz.write(reinterpret_cast<const char*>(&sz), sizeof(sz));
    //std::cout << sz << "\n";
    outsz.close();

    std::ofstream out(file, std::ios::binary | std::ios::ate |std::ios::app);
    //out.seekp(0L,std::ios::beg);
    //out.write(reinterpret_cast<const char*>(&sz), sizeof(sz));
    //out.close();
    //out.seekp(0L,std::ios::end);

    if (!out)
    {
        std::cerr << "Error!\n";
        return;
    }

    for (int i = sz_start; i < sz; i++) 
    {
        //std::cout << "WRITE SMTH";
        //if (sz_start > 0) break;
        writeTrainFile(arr[i], out);
    }

    //out.seekp(0L,std::ios::beg);
    //std::cout << file << "\n";

    out.close();
}