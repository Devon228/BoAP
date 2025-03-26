#include <iostream>
#define ld long double
#define ll long long

void init(short variant)
{
    std::cout << "The task is to find all Armstrong numbers less than x\n";
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

ll myPow (ll a, ll b)
{
    ll res = a;
    for (int i = 2; i <= b; i++)
        res *= a;
    return res;
}

ll sum_dig_pow (ll x)
{
    ll x_copy = x;
    
    int num_dig = 0;
    while (x)
    {
        x /= 10;
        num_dig++;
    }
    x = x_copy;

    ll res = 0;
    while (x)
    {
        int dig = x % 10;
        res += myPow(dig, num_dig);
        x /= 10;
    }

    return res;
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
        std::cout << "Enter x\n";
        ll x = cinLongL();

        for (ll i = 1, num = 1; i < x; i++)
        {
            if (sum_dig_pow(i) == i)
            {
                std::cout << num << " Armstrong number is " << i << "\n";
                num++;
            }
        }
    }

    return 0;
}