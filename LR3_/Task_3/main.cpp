#include <iostream>
#define ld long double
#define ll long long

const ld PI = 3.14159265359;

void init(short variant)
{
    std::cout << "The task is to calculate value of y = sin(x) - cos(x) on segment [A, B] divided into M parts\nA = 0; B = PI / 2; M = 20;\n";
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

ld mySin(ld x)
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

        ld a = 0, b = PI / 2, m = 20;
        ld h = (b - a) / m;
        for (int i = 0; i <= m; i++)
        {
            ld x = a + (ld)i * h;
            ld y = mySin(x) - myCos(x);
            std::cout << "x = " << x << " |  y = " << y << "\n";
        }
    }

    return 0;
}