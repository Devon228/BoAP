#include <iostream>

int main()
{
    long long x, y;
    std::cout << "Enter x, y\n";
    std::cin >> x >> y;

    std::cout << 0 << ": " << x << " " << y << "\n";
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    std::cout << 1 << ": " << x << " " << y << "\n";
    for (int i = 2; x != 0 && y != 0; i++)
    {
        if (x >= y)
            x = x - y;
        else
            y = y - x;
        std::cout << i << ": " << x << " " << y << "\n";
    }
    return 0;
}
