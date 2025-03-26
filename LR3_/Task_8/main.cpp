#include <iostream>
#define ld long double
#define ll long long

void init(short variant)
{
    std::cout << "The task is to calculate value a[0] - 2*a[1] + 4*a[2] - 8*a[3] + ... + (-1)^(n-1) * 2^(n-1) * a[n-1]\n";
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
        ll n = -1;
        std::cout << "Enter the number of numbers\n";
        while (true)
        {
            n = cinLongL();
            if (n < 0 || n > 61)
            {
                std::cout << "Incorrect input. Please, write again\n";
                continue;
            }
            else
                break;
        }

        ll res = 0, pow2 = 1;
        std::cout << "Enter a[" << 0 << "]\n";
        ll a0 = cinLongL();
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
                res -= a0 * pow2;
            else
                res += a0 * pow2;
            pow2 *= 2;
        }

        std::cout << "Answer is " << res << '\n';
    }

    return 0;
}