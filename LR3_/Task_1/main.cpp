#include <iostream>
#define ll long long
#define ld long double

void init(short variant)
{
    std::cout << "The task is to calculate sum (a[i] - b[i])^2 for i from 1 till 30 using while loop\nwhere a[i] = (i % 2 == 1 ? i : i / 2) and b[i] = (i % 2 == 1 ? i * i : i * i * i)\n";
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

        ll N = 0;
        int i = 1;
        while (i <= 30)
        {
            int a = (i & 1 ? i : i / 2);
            int b = (i & 1 ? i * i : i * i * i);
            N += (a - b) * (a - b);
            ++i;
        }
        std::cout << "Answer is " << N << '\n';
    }

    return 0;
}