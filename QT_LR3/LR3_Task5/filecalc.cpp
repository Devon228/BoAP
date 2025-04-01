#include "filecalc.h"

FileCalc::FileCalc()
{

}

std::pair <int, int> FileCalc::calcDirFile(std::string path)
{
    std::filesystem::path pathToDir = path;
    std::filesystem::directory_iterator dirIterator(pathToDir);

    std::pair <long long, long long> res = {0, 0};
    for (const auto& entry : dirIterator)
    {
        if (entry.is_directory())
        {
            std::pair <long long, long long> res_inner = calcDirFile(entry.path());
            res.first += 1 + res_inner.first;
            res.second += res_inner.second;
        }
        else //file
        {
            res.second += 1;
        }
    }

    return res;
}
