#include <iostream>
#include <string>
#include <cmath>

long long funAccerman(long long m, long long n)
{
    if (m == 0)
        return n + 1;
    else
        if (n == 0)
            return funAccerman(m-1, 1);
        else
            return funAccerman(m-1, funAccerman(m, n-1));
}

int main()
{
    while (1)
    {
        int option;
        std::cout << "Enter 1 to continue\n";
        std::cin >> option;
        if (option != 1)
            break;

        long long m, n;
        std::cout << "Enter m and n\n";
        std::cin >> m >> n;
        std::cout << funAccerman(m, n) << "\n";

    }

    return 0;
}
