#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;

void init(short);
ld cinLongD();
ll cinLongL();

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

        std::cout << "Enter the amount of columns N\n";
        ll n = cinLongL();
        std::cout << "Enter the amount of strings M\n";
        ll m = cinLongL();

        char **a = (char**)malloc(n * sizeof(char*));
        for (int i = 0; i < m; i++)
            a[i] = (char*)malloc(m * sizeof(char));
    
        std::cout << "Enter n strings with m elements in each\n";
        for (int i = 0; i < n; i++)
        {
            while (true)
            {
                bool err = 0;

                for (int j = 0; j < m; j++)
                    if (!(std::cin >> a[i][j]))
                    {
                        err = 1;
                        std::cin.clear();
                        while (std::cin.get() != '\n');
                        std::cout << "Incorrect input. Please, write the last string again\n";
                        break;
                    }
                
                if (std::cin.peek() != '\n')
                {
                    err = 1;
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    std::cout << "Incorrect input. Please, write the last string again\n";              
                }

                if (!err)
                    break;
            }
        }
        while (std::cin.peek() != '\n')
        {
            bool err = 1;
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "This string will be ignored\n";              
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                int kol = 0;
                if (a[i][j] == '*') continue;

                for (int k = i-1; k <= i+1; k++)
                    for (int g = j-1; g <= j+1; g++)
                    {
                        if (k == i && g == j) continue;
                        if (k < 0 || g < 0 || k >= n || g >= m) continue;

                        if (a[k][g] == '*')
                            kol++;
                    }

                if (kol == 0) 
                    a[i][j] = ' ';
                else
                    a[i][j] = kol;
            }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == '*' || a[i][j] == ' ')
                    std::cout << a[i][j];
                else
                    std::cout << (int)a[i][j]; 
            }
            std::cout << "\n";
        }
    }
    return 0;
}

void init(short variant)
{
    std::cout << "The task is to calculate the sum of some special  elements of the square matrix\n";
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
