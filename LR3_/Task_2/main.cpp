#include <iostream>
#define ll long long
#define ld long double

void init(short variant)
{
    std::cout << "The task is to calculate sum of a series with precision eps = 1e-3\nwhere i-th member is d[n] = 1 / 2^n + 1 / 3^n\n";
    std::cout << "Completed by Dzmitry Lukasnki, gr. 453502\n";
    if (variant != -1)
        std::cout << "Variant: " << variant << "\n";
    return;
}
ld cinLongD()
{
    ld number;

    while (!(std::cin >> number) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');

        std::cout << "Incorrect input. Please, write again\n";
    }

    return number;
}
ll cinLongL()
{
    ll number;

    while (!(std::cin >> number) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');

        std::cout << "Incorrect input. Please, write again\n";
    }

    return number;
}

int main()
{
    init(-1);

    while (true)
    {
        std::cout << "Enter 1 to continue, 2 to exit\n";
        short option = (short)cinLongL();
        
        if (option != 1 && option != 2)
        {
            std::cout << "Incorrect input. Please, write again\n";
            continue;
        }
        if (option == 2)
        {
            std::cout << "Goodbye";
            break;
        }

        ld eps = 1e-3;
        ld dn = 0, pw2 = 1/2.0, pw3 = 1/3.0, sum = 0;
        do
        {
            dn = pw2 + pw3;
            sum += dn;
            pw2 /= 2.0;
            pw3 /= 3.0;
        }
        while (dn >= eps);

        std::cout << "Answer is " << sum << '\n';
    }
    return 0;
}