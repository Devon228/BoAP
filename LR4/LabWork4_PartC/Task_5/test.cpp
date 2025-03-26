#include <gtest/gtest.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef long long ll;
typedef long double ld;

void transf (char **, ll, ll);

int main()
{
    ::testing::InitGoogleTest();
    RUN_ALL_TESTS();
    return 0;
}

void transf (char **a, ll n, ll m)
{
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

    return;
}

TEST(transf, SmallTest)
{
    ll n = 5, m = 6;
    char **a = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < m; i++)
        a[i] = (char*)malloc(m * sizeof(char));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
                if (j % 2 == 0)
                    a[i][j] = '.';
                else
                    a[i][j] = '*';

    transf(a, n, m);

    for (int i = 1; i < n - 1; i++)
        for (int j = 1; j < m - 1; j++)
                if (j % 2 == 0)
                    ASSERT_EQ(a[i][j], 6);
                else
                    ASSERT_EQ(a[i][j], '*');

    for (int i = 0; i < n; i++)
    {
        free(a[i]);
        a[i] = NULL;
    }
    free(a);
    a = NULL;
}