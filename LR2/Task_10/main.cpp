#include <iostream>

long double mySqrt(long double x)
{
    long double left = 0, right = 3 * 1e9, middle = 0;

    while (right - left > 1e-10)
    {
        middle = (left + right) / 2;
        
        if (middle * middle > x)
            right = middle;
        else
            left = middle;
    }

    return left;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    long double x1, y1, r, x2, y2, R;
    std::cout << "Введите x1, y1, r\n";
    std::cin >> x1 >> y1 >> r;
    std::cout << "Введите x2, y2, R\n";
    std::cin >> x2 >> y2 >> R;

    long double dist = mySqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    if (dist + r <= R || dist + R <= r)
    {
        if (dist + r <= R)
            std::cout << "Да\n";
        if (dist + R <= r)
            std::cout << "Да, но справедливо обратное для двух фигур\n";
    }
    else if (dist + 1e-10 < R + r)
        std::cout << "Фигуры пересекаются\n";
    else
        std::cout << "Ни одно условие не выполнено\n";
    return 0;
}