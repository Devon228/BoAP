#include <iostream>

int main()
{
    long double x;
    std::cin >> x;

    long double x_pow_2 = x * x;
    long long half_1 = x * (23 * x_pow_2 + 32);
    long long half_2 = 69 * x_pow_2 + 8;
    long double ans_1 = half_2 + half_1;
    long double ans_2 = half_2 - half_1;

    std::cout << ans_1 << " " << ans_2;
    return 0;
}