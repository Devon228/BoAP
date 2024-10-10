#include <iostream>

int main() 
{
    long double x, y, z;
    std::cin >> x >> y >> z;

    if (x + y > z && x + z > y && y + z > x)
        std::cout << "YES";
    else
        std::cout << "NO";
    return 0;
}