#include "header.h"

std::string toBase3 (int n) //O(log n)
{
    if (n == 0) {
        return "0";
    }

    std::string ternary = "";
    while (n > 0) {
        ternary = std::to_string(n % 3) + ternary;
        n /= 3;
    }

    const int sz = ternary.size();
    for (int i = 0; i < 5 - sz; i++)
        ternary = '0' + ternary;
    
    return ternary;
}