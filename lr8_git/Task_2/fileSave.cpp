#include "header.h"

/*
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
*/

static void writeOneLineFile (Stud &arr, std::ofstream &out)
{
    char sep = '\t';
    char end = '\n';

    out << arr.n << sep << arr.fio << sep << arr.gr.i << sep << arr.mark << sep << arr.wage << end;
}


void writeFile (Stud*& arr, int sz, const std::string file)
{
    std::ofstream out(file, std::ios::out);
    if (!out)
    {
        std::cerr << "Error!\n";
        return;
    }

    out << "Num\tFio\tGroup\tMark\tWage\n" << std::setprecision(2) << std::fixed;
    for (int i = 0; i < sz; i++) 
    {
        writeOneLineFile(arr[i], out);
    }

    out.close();
}