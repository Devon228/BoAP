#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef long long ll;
typedef long double ld;

void init(short);
ll cinLongL();
ll cinElMatr();
ll findMaxSumDiag (ll ***a, ll n);
void func (ll***, ll);

int main()
{
    init(-1);

    int* a = new int[10];
    while (true)
    {
        printf("Enter 1 to continue, 2 to exit\n");
        short option = cinLongL();
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

    
        printf("Enter n matrixes with n strings and n element in each string. All unnecessary will be ignored\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                while (true)
                {
                    bool err = 0;

                    for (int l = 0; l < n; l++)
                    {
                        ll tmp = cinElMatr(n, l);
                        if (tmp == -1)
                        {
                            err = 1;
                            printf("Incorrect input. Please, write the last string again\n");
                            break;
                        }
                        else
                            a[i][j][l] = tmp;
                    }

                    if (!err)
                        break;
                }
            }
        }

        /*
        void (*uk)(ll***, ll) = func;
        void (*uk1[1])(ll***, ll) = {func};
        uk(a, n);
        uk1[0](a, n);
        (*uk1)(a, n);
        */

        
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
        {
            printf("Diag with max sum is from (0, 0, 0) to (n-1, n-1, n-1), the sum is %lld \n", sum1);
        }
        else if (sum2 >= sum1 && sum2 >= sum3 && sum2 >= sum4)
        {
            printf("Diag with max sum is from (n-1, 0, 0) to (0, n-1, n-1), the sum is %lld \n", sum2);
        }
        else if (sum3 >= sum1 && sum3 >= sum2 && sum3 >= sum4)
        {
            printf("Diag with max sum is from (n-1, n-1, 0) to (0, 0, n-1), the sum is %lld \n", sum3);
        }
        else if (sum4 >= sum1 && sum4 >= sum2 && sum4 >= sum3)
        {
            printf("Diag with max sum is from (0, n-1, 0) to (n-1, 0, n-1), the sum is %lld \n", sum4);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                free(a[i][j]);
                a[i][j] = NULL;
            }
            
            free(a[i]);
            a[i] = NULL;
        }
        free(a);
        a = NULL;
    }
    return 0;
}

void init(short variant)
{
    printf("The task is to find diagonal with maximal sum in the cube\n");
    printf("Completed by Dzmitry Lukasnki, gr. 453502\n");
    if (variant != -1)
        printf("Variant: %hu \n",variant);
    return;
}
ll cinLongL()
{
    ll number = 0;

    while (true)
    {
        char c = getchar();
        if (c == '\n')
            break;

        if (c >= '0' && c <= '9')
            number = number * 10 + (c - '0');
        if (c < '0' || c > '9' || number >= 1e18)
        {
            printf("Incorrect input. Please, write again\n");
            number = 0;
            while (c != '\n')
                c = getchar();
        }
    }

    return number;
}
ll cinElMatr(int n, int l)
{
    ll number = 0;
    bool start = 0;

    while (true)
    {
        char c = getchar();
        if (c == ' ')
            if (l != n - 1)
                break;
            else
            {
                while (c != '\n')
                    c = getchar();
                return -1;
            }
        if (c == '\n')
            if (l == n - 1 && start)
                break;
            else
                return -1;

        if (c >= '0' && c <= '9')
        {
            number = number * 10 + (c - '0');
            start = 1;
        }
        if (c < '0' || c > '9' || number >= 1e18)
        {
            while (c != '\n')
                c = getchar();
            return -1;
        }
    }

    return number;
}
/*
void func (ll*** a, ll n)
{
    printf("%lld \n \n \n", ***a);
    return;
}
*/
