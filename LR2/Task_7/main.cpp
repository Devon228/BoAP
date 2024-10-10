#include <iostream>
#include <cmath>

int main()
{
    long long N;
    long double a, b, c, Y;
    std::cout << "Enter a, b, c, N\n";
    std::cin >> a >> b >> c >> N;
    switch (N)
    {
        case 2:
            Y = b * c - a * a;
            break;
        case 3:
            Y = a - b * c;
            break;
        case 7:
            Y = a * a + c;
            break;
        case 56:
            Y = b * c;
            break;
        default:
            Y = (a + b) * (a + b) * (a + b);
            break;

    }

    std::cout << Y;
    return 0;
}