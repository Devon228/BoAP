#include <iostream>
#include <string>
#include <cmath>

long long num_len (long long n)
{
    if (n == 0)
        return 0;

    return 1 + num_len(n / 10);
}
long long pow10 (long long st)
{
    if (st == 0)
        return 1;

    return 10 * pow10(st - 1);
}
long long reverse (long long n, long st)
{
    if (n == 0)
        return 0;

    return (n % 10) * pow10(st) + reverse(n / 10, st - 1);
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

        long long num;
        std::cout << "Enter a number\n";
        std::cin >> num;

        if (num < 0)
        {
            num = -num;
            std::cout << "-";
        }
        std::cout << reverse(num, num_len(num) - 1) << "\n";
    }

    return 0;
}
