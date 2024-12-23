#include "header.h"

int main() {
    init(13);
    while (true)
    {
        std::cout << "Введите 1 чтобы продолжить, 2 чтобы выйти\n";
        ll option;
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

        long long base;
        std::cout << "Enter the base of the system\n";
        cinLong(base);
        long long len;
        std::cout << "Enter the length of the number\n";
        cinLong(len);

        int num[len];
        std::cout << "Enter the number at additional code\n";
        cinN(num, len);
        

        if (num[0] == 0)
        {
            coutN(num, len, base);
        }
        else if (num[0] == 1)
        {
            bool corr = 0;
            for (int i = 1; i < len; i++)
                if (num[i] != 0)
                    corr = 1;

            if (!corr)
            {
                std::cout << "Incorrect input\n";
                continue;
            }

            minus1(num, len, base);
            inv(num, len, base);

            coutN(num, len, base);
        }
        else
        {
            std::cout << "Incorrect input\n";
            continue;
        }
    }

    return 0;
}

