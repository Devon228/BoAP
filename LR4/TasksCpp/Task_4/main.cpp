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
        printf("Enter 1 to continue, 2 to exit\n");
        short option = (short)cinLongL();
        if (option != 1 && option != 2)
        {
            printf("Incorrect input. Please, write again\n");
            continue;
        }
        if (option == 2)
        {
            printf("Goodbye");
            break;
        }

        printf("Enter the size of cube\n");
        ll n = cinLongL();

        ll ***a = (ll***)malloc(n * sizeof(ll**));
        for (int i = 0; i < n; i++)
        {
            a[i] = (ll**)malloc(n * sizeof(ll*));
            for (int j = 0; j < n; j++)
                a[i][j] = (ll*)malloc(n * sizeof(ll));
        }
    
        printf("Enter n matrixes with n strings and n elements in each string\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                while (true)
                {
                    bool err = 0;

                    for (int l = 0; l < n; l++)
                        if (!(std::cin >> a[i][j][l]))
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
        }

        ll sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
        
        for (int i = 0, j = 0, l = 0; i < n; i++, j = i, l++)
            sum1 += a[i][j][l];
        for (int i = n-1, j = 0, l = 0; i >= 0; i--, j = (n-1)-i, l++)
            sum2 += a[i][j][l];
        for (int i = n-1, j = n-1, l = 0; i >= 0; i--, j = i, l++)
            sum3 += a[i][j][l];
        for (int i = 0, j = n-1, l = 0; i < n; i++, j = (n-1)-i, l++)
            sum4 += a[i][j][l];

        if (sum1 >= sum2 && sum1 >= sum3 && sum1 >= sum4)
            std::cout << "Diag with max sum is from (0, 0, 0) to (n-1, n-1, n-1), the sum is " << sum1 << "\n";
        else if (sum2 >= sum1 && sum2 >= sum3 && sum2 >= sum4)
            std::cout << "Diag with max sum is from (n-1, 0, 0) to (0, n-1, n-1), the sum is " << sum2 << "\n";
        else if (sum3 >= sum1 && sum3 >= sum2 && sum3 >= sum4)
            std::cout << "Diag with max sum is from (n-1, n-1, 0) to (0, 0, n-1), the sum is " << sum3 << "\n";
        else if (sum4 >= sum1 && sum4 >= sum2 && sum4 >= sum3)
            std::cout << "Diag with max sum is from (0, n-1, 0) to (n-1, 0, n-1), the sum is " << sum4 << "\n";


        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                free(a[i][j]);
                a[i][j] = nullptr;
            }
            
            free(a[i]);
            a[i] = nullptr;
        }
        free(a);
        a = nullptr;
    }
    return 0;
}

void init(short variant)
{
    std::cout << "The task is to find diagonal with maximal sum in the cube\n";
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
