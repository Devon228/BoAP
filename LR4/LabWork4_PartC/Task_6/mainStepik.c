#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef long long ll;
typedef long double ld;

ll mod (ll, ll);
void mySwap(ll *x, ll *y);

int main()
{
        ll n;
        scanf("%lld", &n);

        if (n == 2)
        {
            printf("NO");
            return 0;
        }
        ll **a = (ll**)malloc(n * sizeof(ll*));
        for (int i = 0; i < n; i++)
            a[i] = (ll*)malloc(n * sizeof(ll));

        if (n % 2 == 1)
        {
            ll x = n / 2, y = -n / 2;
            for (ll i = 0; i < n; i++)
            {
                for (ll j = 1, x1 = x, y1 = y; j <= n; j++, x1--, y1++)
                {
                    a[mod(x1,n)][mod(y1,n)] = i * n + j;
                }
                x++; y++;
            }
        }
        else
        {
            if (n % 4 == 0)
            {
                ll x = 0, y = 0;
                for (ll i = 0; i < n / 2; i++)
                {
                    if (i % 2 == 0)
                    {
                        for (ll j = 1, x1 = x, y1 = y; j <= 2 * n; j++)
                        {
                            a[mod(x1,n)][mod(y1,n)] = i * 2 * n + j;

                            if (j < n / 2) 
                            {
                                x1--; y1++;
                            }
                            else if (j == n/2) 
                            {
                                y1++;
                            }
                            else if (j < n)
                            {
                                x1++; y1++;
                            }
                            else if (j == n)
                            {
                                x1++;
                            }
                            else if (j < (3 * n) / 2)
                            {
                                x1++; y1--;
                            }
                            else if (j == (3 * n) / 2)
                            {
                                y1--;
                            }
                            else
                            {
                                x1--; y1--;
                            }
                        }
                    }
                    else
                    {
                        for (ll j = 1, x1 = x, y1 = y; j <= 2 * n; j++)
                        {
                            a[mod(x1,n)][mod(y1,n)] = i * 2 * n + j;

                            if (j < n / 2) 
                            {
                                x1--; y1--;
                            }
                            else if (j == n/2) 
                            {
                                y1--;
                            }
                            else if (j < n)
                            {
                                x1++; y1--;
                            }
                            else if (j == n)
                            {
                                x1++;
                            }
                            else if (j < (3 * n) / 2)
                            {
                                x1++; y1++;
                            }
                            else if (j == (3 * n) / 2)
                            {
                                y1++;
                            }
                            else
                            {
                                x1--; y1++;
                            }
                        }
                    }
                    x += 2; y = n - 1 - y;
                }      
            }
            else
            {
                ll x = (n / 2)/2, y = -(n / 2)/2;
                for (ll i = 0; i < n/2; i++)
                {
                    for (ll j = 1, x1 = x, y1 = y; j <= n/2; j++, x1--, y1++)
                    {
                        a[mod(x1,n/2)][mod(y1,n/2)] = i * (n/2) + j;
                        a[mod(x1,n/2)+n/2][mod(y1,n/2)] = i * (n/2) + j + (n * n * 3) / 4;
                        a[mod(x1,n/2)][mod(y1,n/2)+n/2] = i * (n/2) + j + (n * n) / 2;
                        a[mod(x1,n/2)+n/2][mod(y1,n/2)+n/2] = i * (n/2) + j + (n * n) / 4;
                    }
                    x++; y++;
                }

                for (ll i = 0; i < n / 4 - 1; i++)
                {
                    for (ll j = 0; j < n / 2; j++)
                    {
                        mySwap(&a[j][n/2-1-i], &a[j+n/2][n/2-1-i]);
                        mySwap(&a[j][n/2+i], &a[j+n/2][n/2+i]);
                    }
                }    
                mySwap(&a[0][0], &a[n/2][0]);
                mySwap(&a[n/2-1][0], &a[n-1][0]);
                for (ll i = 1; i < n / 2 - 1; i++)
                    mySwap(&a[i][1], &a[n/2+i][1]);
            }

        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%lld ", a[i][j]); 
            }
            printf("\n");
        }

    
    return 0;
}

ll mod (ll a, ll b)
{
    if (a >= 0)
        return a % b;
    else
        return (a + (-a/b + 1) * b) % b; 
}
void mySwap(ll *x, ll *y)
{
    ll tmp = *x;
    *x = *y;
    *y = tmp;
}