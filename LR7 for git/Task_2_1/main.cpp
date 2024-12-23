#include "header.h"

int main() {
    init(13);
    while (1)
    {
        std::cout << "Введите 1 чтобы продолжить, 2 чтобы выйти\n";
        long long option;
        cinLong(option);
        getchar();
        if (option != 1 && option != 2)
        {
            std::cout << "Неверный ввод. Введите заново\n";
            continue;
        }
        if (option == 2)
        {
            std::cout << "Пока";
            break;
        }

        std::string num1;
        std::string num2;

        std::cout << "Введите первое число в прямом коде (первый символ на знак): \n";
        std::cin >>  num1;

        for (int i = 0; i < num1.size(); ++i)
        {  // O(1 + n + n + 5n)=O(n)
            if (num1.empty() || (num1[i] != '0' && num1[i] != '1')) {  //
                std::cout << "Некорректный ввод" << "\n";
                continue;
            }
        }

        std::cout << "Введите второе число в прямом коде (первый символ на знак): \n";
        std::cin >> num2;

        for (int i = 0; i < num2.size(); ++i) {  // O(1 + n + n + 5n)=O(n)
            if (num2.empty() || (num2[i] != '0' && num2[i] != '1')) {
                std::cout << "Некорректный ввод" << "\n";  //
                continue;
            }
        }

        int k1 = 0, k2 = 0;
        if (num1.size() < num2.size()) {
            k1 = num2.size() - num1.size();
        }
        else if (num1.size() > num2.size()) {
            k2 = num1.size() - num2.size();
        }

        std::string a = toDop(makeEq(num1, k1)), b = toDop(makeEq(num2, k2));
        std::string c = sum(a,b);  

        std::cout << "Числа в дополнительном коде :" << "\n" << a << "\n" << b << "\n";
        std::cout << "Сумма в дополнительном коде:" << "\n" << c << "\n";
        std::cout << "Сумма в прямом коде :" << "\n" << toPr(c) << "\n";
    }
    return 0;
}
