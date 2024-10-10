#include <iostream>

const long double PI = 3.14159265359;

long double mySqrt(long double x)
{
    long double left = 0, right = 3 * 1e9, middle = 0;

    while (right - left > 1e-8)
    {
        middle = (left + right) / 2;
        
        if (middle * middle > x)
            right = middle;
        else
            left = middle;
    }

    return left;
}

long double myAcos(long double x)
{
    long double res = PI / 2, fact = 1, x_pow = x;
    for (long double i = 1; i <= 1e3; i++)
    {
        res = res - fact * (x_pow / (2 * i - 1));
        fact *= (i * 2 - 1) / (i * 2);
        x_pow *= x * x;
    }

    return res;
}

long double mySin(long double x)
{
    long double res = 0, fact = 1, x_pow = x;
    for (int i = 1; i <= 1e3; i++)
    {
        if (i & 1)
            res += x_pow / fact;
        else
            res -= x_pow / fact;
        fact *= (2.0 * (long double)i) * (2.0 * (long double)i + 1.0);
        x_pow *= x * x;
    }

    return res;
}

int main()
{
    long double x1, y1, x2, y2, x3, y3;
    std::cout << "Enter x1, y1, x2, y2, x3, y3\n";
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    long double a = mySqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    long double b = mySqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    long double c = mySqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    std::cout << "1. Length of a: " << a << ", b: " << b << ", c: " << c << "\n";

    long double P = (a + b + c);
    long double p = P / 2.0;
    long double S = mySqrt(p * (p - a) * (p - b) * (p - c));

    long double h_a = 2 * S / a;
    long double h_b = 2 * S / b;
    long double h_c = 2 * S / c;
    std::cout << "2. Length of h_a: " << h_a << ", h_b: " << h_b << ", h_c: " << h_c << "\n";

    long double m_a = 0.5 * mySqrt(2 * b * b + 2 * c * c - a * a);
    long double m_b = 0.5 * mySqrt(2 * a * a + 2 * c * c - b * b);
    long double m_c = 0.5 * mySqrt(2 * a * a + 2 * b * b - c * c);
    std::cout << "3. Length of m_a: " << m_a << ", m_b: " << m_b << ", m_c: " << m_c << "\n";

    long double l_a = 2 * mySqrt(b * c * p * (p - a)) / (b + c);
    long double l_b = 2 * mySqrt(a * c * p * (p - b)) / (a + c);
    long double l_c = 2 * mySqrt(a * b * p * (p - c)) / (a + b);
    std::cout << "4. Length of l_a: " << l_a << ", l_b: " << l_b << ", l_c: " << l_c << "\n";

    long double ang_a_rad = myAcos((b * b + c * c - a * a) / (2 * b * c));
    long double ang_b_rad = myAcos((a * a + c * c - b * b) / (2 * a * c));
    long double ang_c_rad = myAcos((a * a + b * b - c * c) / (2 * a * b));
    std::cout << "5.1. Value of angle in rad opposite to a: " << ang_a_rad << ", opposite to b: " << ang_b_rad << ", opposite to c: " << ang_c_rad << "\n";
    long double ang_a_deg = ang_a_rad * 180.0 / PI;
    long double ang_b_deg = ang_b_rad * 180.0 / PI;
    long double ang_c_deg = ang_c_rad * 180.0 / PI;
    std::cout << "5.2. Value of angle in degrees opposite to a: " << ang_a_deg << ", opposite to b: " << ang_b_deg << ", opposite to c: " << ang_c_deg << "\n";
    long double R = a * b * c / (4 * S);
    long double r = S / p;
    long double len_R = 2 * PI * R, S_R = PI * R * R;
    long double len_r = 2 * PI * r, S_r = PI * r * r;
    std::cout << "6+7.1. Radius of circumscribed circle " << R << ", its length: " << len_R << ", area: " << S_R << "\n";
    std::cout << "6+7.2. Radius of inscribed circle " << r << ", its length: " << len_r << ", area: " << S_r << "\n";

    long double S_1 = S;
    long double S_2 = a * h_a / 2.0;
    long double S_3 = a * b * mySin(ang_c_rad) / 2.0;
    std::cout << "8. Perimeter of the triangle: " << P << ", area of the triangle: " << S_1 << "(first way), " << S_2 << "(second way), " << S_3 << "(third way). " << "\n";
    return 0;
}