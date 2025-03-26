#include <iostream>
#include <cmath>

int main() {
    double start = 0, end = -1, step = 0;
    std::cout << "Введите начальное значение x: ";
    std::cin >> start; // Задаем исходное значение переменной
    std::cout << "Введите конечное значение x: ";
    std::cin >> end; // Задаем конечно значение переменной
    std::cout << "Введите шаг: ";
    std::cin >> step; // Задаем шаг, с которым с которым будет изменяться аргумент
    double eps = 1e-10;
    for (double x = start; x <= end + eps; x += step) {
        double y = sin(x); // функция y = sin(x)
        std::cout << x << " | " << y << std::endl; // Выводим значения функции для каждого аргумента (x | y)
    }
    return 0;
}

