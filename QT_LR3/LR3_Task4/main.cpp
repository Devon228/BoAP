#include <iostream>
#include <string>
#include <cmath>

long long hanoi (long long n, int from, int to, int buf)
{
    if (n == 1)
    {
        std::cout << "Move ring 1 from " << from << " to " << to << "\n";
        return 1;
    }

    long long res = hanoi(n-1, from, buf, to);
    std::cout << "Move ring " << n << " from " << from << " to " << to << "\n";
    res++;
    res += hanoi(n-1, buf, to, from);
    return res;
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

        long long num_rings;
        std::cout << "Enter a number of rings\n";
        std::cin >> num_rings;

        std::cout << hanoi(num_rings, 1, 3, 2) << " total moves\n";
    }

    return 0;
}
