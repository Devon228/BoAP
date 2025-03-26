#include <iostream>
#include <cmath>
#define ld long double
#define ll long long

const ld PI = 3.14159265359;
const ld LN2 = 0.69314718056;

void init(short variant)
{
    std::cout << "The task is to calculate value of y = ln(1 / (2 + 2 * x + 2 * x ^ 2)) for some points using standart C++ library and using series with number of members entered\n";
    std::cout << "Completed by Dzmitry Lukasnki/ gr. 453502\n";
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

ld calcSeries(ld x, ll num_memb)
{
    ld res = -LN2, x_pow = (x + x*x);
    for (ll i = 1; i <= num_memb; i++)
    {
        if (i % 2)
            res -= x_pow / (ld)i;
        else
            res += x_pow / (ld)i;
        x_pow *= (x + x*x);
    }

    return res;
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

        std::cout << "Enter number of members of series\n";
        ll num_memb;
        while (true) 
        {
            num_memb = cinLongL();
            if (num_memb <= 0) 
            {
                std::cout << "Incorrect input. Please, write again\n";
                continue;
            }
            else
                break;
        }

        std::cout << "Enter number of points to calculate function\n";
        ll num_x;
        while (true) 
        {
            num_x = cinLongL();
            if (num_x < 0) 
            {
                std::cout << "Incorrect input. Please, write again\n";
                continue;
            }
            else
                break;
        }

        std::cout << "Enter the points, each on a new line\n";
        for (int i = 1; i <= num_x; i++)
        {
            ld x;
            while (true) 
            {
                x = cinLongD();
                if (x < 0.1-1e-6 || x > 1) 
                {
                    std::cout << "Incorrect input. Please, write again\n";
                    continue;
                }
                else
                    break;
            }     

            ld y_stand = log(1.0 / (2.0 + 2.0 * x + 2.0 * x * x));
            ld y_series = calcSeries(x, num_memb);
            std::cout << "With standart lib: " << y_stand << " vs with series: " << y_series << "\n";
        }
    }

    return 0;
}