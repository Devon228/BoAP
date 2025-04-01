#ifndef FILECALC_H
#define FILECALC_H

#include <string>
#include <filesystem>

class FileCalc
{
    public:
        FileCalc();

        static std::pair <int, int> calcDirFile(std::string path);
};

#endif // FILECALC_H
