#include "header.h"

int main() {
    init(-1);
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

        int num_barr[5][240];
        null_arr(&num_barr[0][0], 5, 240); //O(1000 = кол-во_рабов * кол-во_бочек)
        int cur_barr[5]{0};

        makeDay1(&num_barr[0][0], cur_barr); //O(1000 = кол-во_рабов * кол-во_бочек)
        bool alive_1[5]{0};
        std::cout << cur_barr[4] << "\n";
        for (int j = 0; j < 5; j++)
        {
            procAns(alive_1, j);

            cur_barr[j] = 0;
        }


        null_arr(&num_barr[0][0], 5, 240); //O(1000 = кол-во_рабов * кол-во_бочек)
        makeDay2(&num_barr[0][0], cur_barr, alive_1); //O(1000 = кол-во_рабов * кол-во_бочек)

        bool alive_2[5]{0};
        for (int j = 0; j < 5; j++)
        {
            if (alive_1[j] == 0) 
                continue;
            procAns(alive_2, j);
        }


        int ans = 0, power = 1;
        for (int j = 4; j >= 0; j--)
        {
            if (alive_1[j])
            {
                if (alive_2[j])
                    ans += 2 * power;
                else
                    ans += power;
            }
            power *= 3;
        }

        if (ans == 0 || ans > 240)
            std::cout << "Сам себя ты обманул, такого быть не может\n";
        else
            std::cout << "Номер отравленной бочки: " << ans << "\n";
    }

    return 0;
}

