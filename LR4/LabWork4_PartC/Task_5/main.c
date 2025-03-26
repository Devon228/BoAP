#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef long long ll;
typedef long double ld;

void init(short);
ll cinLongL();
char cinElMatr();

int main()
{
    init(-1);
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

        printf("Enter the amount of strings N\n");
        ll n = cinLongL();
        printf("Enter the amount of columns M\n");
        ll m = cinLongL();

        char **a = (char**)malloc(n * sizeof(char*));
        for (int i = 0; i < m; i++)
            a[i] = (char*)malloc(m * sizeof(char));
    
        printf("Enter N strings with M elements in each. Anything unnecessary will be ignored\n");
        for (int i = 0; i < n; i++)
        {
            while (true)
            {
                bool err = 0;

                for (int j = 0; j < m; j++)
                {
                    char tmp = cinElMatr();
                    if (tmp == -1)
                    {
                        err = 1;
                        printf("Incorrect input. Please, write the last string again\n");
                        break;
                    }
                    else
                        a[i][j] = tmp;
                }

                if (!err)
                {
                    char c = getchar();
                    if (c != '\n')
                    {
                        err = 1;
                        printf("Incorrect input. Please, write the last string again\n");
                        while (c != '\n')
                            c = getchar();
                    }
                    else
                    {
                        break;
                    }
                }
            }
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
                    printf("%c", (char)a[i][j]);
                else
                    printf("%d", (int)a[i][j]); 
            }
            printf("\n");
        }

        for (int i = 0; i < n; i++)
        {
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
    printf("The task is to add numbers into Miner field\n");
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
char cinElMatr()
{
    char c = getchar();

    if (c == '*' || c == '.')
        return c;
    else
    {
        while (c != '\n')
            c = getchar();
        return -1;
    }
}
