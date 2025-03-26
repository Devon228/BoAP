#include <gtest/gtest.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef long long ll;
typedef long double ld;

ll findMaxSumDiag (ll ***, ll);

int main()
{
    ::testing::InitGoogleTest();
    RUN_ALL_TESTS();
    return 0;
}

ll findMaxSumDiag (ll ***a, ll n)
{
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
        printf("Diag with max sum is from (0, 0, 0) to (n-1, n-1, n-1), the sum is ");
        return sum1;
    }
    else if (sum2 >= sum1 && sum2 >= sum3 && sum2 >= sum4)
    {
        printf("Diag with max sum is from (n-1, 0, 0) to (0, n-1, n-1), the sum is ");
        return sum2;
    }
    else if (sum3 >= sum1 && sum3 >= sum2 && sum3 >= sum4)
    {
        printf("Diag with max sum is from (n-1, n-1, 0) to (0, 0, n-1), the sum is ");
        return sum3;
    }
    else if (sum4 >= sum1 && sum4 >= sum2 && sum4 >= sum3)
    {
        printf("Diag with max sum is from (0, n-1, 0) to (n-1, 0, n-1), the sum is ");
        return sum4;
    }

    return 0;
}

TEST(findSumMaxDiag, SmallTest)
{
    ll n = 5;
    ll ***a = (ll***)malloc(n * sizeof(ll**));
    for (int i = 0; i < n; i++)
    {
        a[i] = (ll**)malloc(n * sizeof(ll*));
        for (int j = 0; j < n; j++)
            a[i][j] = (ll*)malloc(n * sizeof(ll));
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                a[i][j][k] = 1;

    ASSERT_EQ(findMaxSumDiag(a, n), 5);

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