#include <iostream>
#include <cmath>
#include <iomanip>
#define ld long double
#define ll long long

const ld INF = 1e18;
const ld PI = 3.14159265358979323846264338;
const ld LN2 = 0.69314718056;

void init(short variant)
{
    std::cout << "The task is to find minimum value from sin(x), cos(x) and ln(|x|) and write it\n";
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
    ll sign = 1;
    if (x < 0)
    {
        sign = -1;
        x = -x;
    }

    ld now = 2 * PI;
    while (now * 2 < x)
        now *= 2;
    while (x > 2 * PI)
    {
        if (x - now >= 0)
            x -= now;
        now /= 2;
        //std::cout << std::setprecision(30) << std::fixed << x << "\n";
    }
    
    ld res = 0, x_pow = x, fact = 1;
    for (ld i = 1; i <= 1000; i++)
    {
        if ((int)i % 2)
            res += x_pow / fact;
        else
            res -= x_pow / fact;
        fact *= (2 * i) * (2 * i + 1);
        x_pow *= x * x; 
    }

    return sign * res;
}
ld myCos(ld x)
{
    if (x < 0)
        x = -x;

    ld now = 2 * PI;
    while (now * 2 < x)
        now *= 2;
    while (x > 2 * PI)
    {
        if (x - now >= 0)
            x -= now;
        now /= 2;
    }

    ld res = 1, x_pow = x * x, fact = 2;
    for (ld i = 2; i <= 1000; i++)
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
ld myLn (ld x)
{
    if (x == 0)
        return -INF;

    ld kol = 0; 
    if (x >= 1)
    {
        while (x > 1)
        {
            x /= 2.0;
            kol++;
        }
    }
    else
    {
        while (x < 1)
        {
            x *= 2.0;
            kol--;
        }
    }

    ld res = 0, x_pow = x - 1;
    for (ld i = 1; i <= 1000; i++)
    {
        if ((int)i % 2)
            res += x_pow / i;
        else
            res -= x_pow / i;
        x_pow *= x - 1;
    }

    return res + kol * LN2;  
}
ld myFabs (ld x)
{
    return (x >= 0.0 ? x : -x);
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
        ld x = cinLongD();

        ld sinx = mySin(x);
        ld cosx = myCos(x);
        ld lnx = myLn(myFabs(x));

        std::cout << "My functions: " << sinx << " " << cosx << " " << lnx << '\n';
        std::cout << "Standart lib: " << sin(x) << " " << cos(x) << " " << log(fabs(x)) << '\n';
        if (sinx <= cosx && sinx <= lnx)
            std::cout << "Minimum is sin(x) = " << sinx << '\n';
        else if (cosx <= sinx && cosx <= lnx)
            std::cout << "Minimum is cos(x) = " << cosx << '\n';
        else
            std::cout << "Minimum is ln(|x|) = " << lnx << '\n';
    }

    return 0;
}


