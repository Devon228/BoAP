#include <iostream>

int main()
{
    long long x, y;
    std::cin >> x >> y;
    long double a, b, c, k;
    std::cin >> a >> b >> c >> k;
    
    if (x < y)
        x = 0;
    else if (y < x)
        y = 0;
    else
        x, y = 0, 0;
    std::cout << x << " " << y << '\n';
    
    if (a >= b && a >= c)
        a -= k;
    else if (b >= a && b >= c)
        b -= k;
    else
        c -= k;
    
    std::cout << a << " " << b << " " << c;
    return 0;
}

