#include <iostream>
#define ld long double
#define ll long long

void init(short variant)
{
    std::cout << "The task is to find approximate root of the equation f(x) = (sin(x) + tan(x) - 1 / (1 + x^2)) = 0\nfor x from -1 to 1\nwe divide interval into some parts and find x with minimum modulo of f(x) from all parts\n";
    std::cout << "Completed by Dzmitry Lukanski, gr. 453502\n";
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

ld mySin (ld x)
{
    ld res = 0, x_pow = x, fact = 1;
    for (ld i = 1; i <= 10; i++)
    {
        if ((int)i % 2)
            res += x_pow / fact;
        else
            res -= x_pow / fact;
        fact *= (2 * i) * (2 * i + 1);
        x_pow *= x * x;
    }

    return res;
}
ld myCos(ld x)
{
    ld res = 1, x_pow = x * x, fact = 2;
    for (ld i = 2; i <= 10; i++)
    {
        if ((int)i % 2)
            res += x_pow / fact;
        else
            res -= x_pow / fact;
        fact *= (2 * i - 1) * (2 * i);
        x_pow *= x * x;
    }

    return res;
}
ld myTan (ld x)
{
    return mySin(x) / myCos(x);
}
ld myFabs (ld x)
{
    return (x >= 0.0 ? x : -x);
}

int main() 
{
    init(13);

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
        std::cout << "Enter the number of parts to divide interval [-1,1]\n";
        ll num_parts;
        while (true) 
        {
            num_parts = cinLongL();
            if (num_parts <= 0) 
            {
                std::cout << "Incorrect input. Please, write again\n";
                continue;
            }
            else
                break;
        }

        ld step = 2.0 / (ld)num_parts;
        ld best = 1e18;
        ld root = 0;
        for (ll i = 0; i <= num_parts; i++)
        {
            ld x = -1.0 + i * step;
            ld val = mySin(x) + myTan(x) - 1.0 / (1.0 + x * x);

            if (myFabs(val) < best)
            {
                best = myFabs(val);
                root = x;
            }

        }

        std::cout << "Approximate root is " << root << "\n";
    }

    return 0;
}