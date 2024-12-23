#include "header.h"

int main() 
{  
    init(-1);
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
        int base;
        std::cout << "Введите основание системы счисления: ";
        std::cin >> base;

        /*if (base < 2 || base > 62) {
        cout << "Неверное основание системы счисления." << endl;
        return 1;
    }*/

        std::string alphabet = makeAlpha(base);  // O(base)

        std::string num1, num2;
        char operation;

        std::cout << "Введите первое число:\n";
        std::cin >> num1;

        std::cout << "Введите операцию (+ или -):\n";
        std::cin >> operation;

        std::cout << "Введите второе число:\n";
        std::cin >> num2;

        std::string res;
        if ((operation == '+' && num1[0] != '-' && num2[0] != '-') || (operation == '-' && num1[0] != '-' && num2[0] == '-')) 
            res = add(num1, num2, alphabet);  // O(n)
        else if ((operation == '-' && num1[0] != '-' && num2[0] != '-') || (operation == '+' && num1[0] != '-' && num2[0] == '-')) 
            res = minus(num1, num2, alphabet);  // O(n)
        else if ((operation == '+' && num1[0] == '-' && num2[0] == '-') || (operation == '-' && num1[0] == '-' && num2[0] != '-')) 
            res = '-' + add(num1, num2, alphabet);  // O(n)
        else if ((operation == '-' && num1[0] == '-' && num2[0] == '-') || (operation == '+' && num1[0] == '-' && num2[0] != '-')) 
            res = minus(num2, num1, alphabet);  // O(n)
        else 
        {
            std::cout << "Неверная операция. Введите снова" << "\n";
            continue;
        }

        std::cout << "Ответ: " << res << "\n";
    }
    return 0;
}
