#include "header.h"

int main() {
    init(-1);
    while (true)
    {
        std::cout << "Введите 1 чтобы продолжить, 2 чтобы выйти\n";
        ll option;
        cinLong(option);
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

        long long num;
        std::cout << "Введите число чтобы его протестить\n";
        cinLong(num);

        if (num < 0)
            num = -num;

        std::cout << (check3(num) ? "Делится на 3\n" : "Не делится на 3\n");
        std::cout << (check23(num) ? "Делится на 23\n" : "Не делится на 23\n");
        std::cout << (check107(num) ? "Делится на 107\n" : "Не делится на 107\n");
    }

    return 0;
}

