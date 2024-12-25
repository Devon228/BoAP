#include "header.h"

void searchFieldTrain(Train*& arr, const int& sz) //поиск по каждому из 6 полей
{    
    std::cout << "Choose 1 field.\n"
              << "Fields of the structure:\n"
              << "1. Number of the train;\n"
              << "2. Type of the train (fast or slow);\n"
              << "3. Time of departure;\n"
              << "4. Time of arrival;\n"
              << "5. Place of arrival;\n"
              << "6. Number of free seats in the train;\n\n";

    ll option1;
    while (true)
    {
        cinLong(option1);
        if (1 <= option1 && option1 <= 6)
        {
            break;
        }

        std::cout << "Wrong option! Type again\n";
    }

    switch (option1)
    {
        case 1:
        {
            std::cout << "Enter the number to search for\n";
            ll num;
            cinLong(num);

            std::cout << "List of selected trains:\n";
            for (int i = 0; i < sz; i++)
            {
                if (arr[i].n.n32 == num)
                {
                    outputOne(arr[i]);
                    std::cout << "\n";
                }
            }

            break;
        }

        case 2:
        {
            std::cout << "Enter the type to search for\n";
            getchar();
            char* text = new char[5];
            cinText(text, 5);

            std::cout << "List of selected trains:\n";
            for (int i = 0; i < sz; i++)
            {
                if (strcmp(arr[i].type, text) == 0)
                {
                    outputOne(arr[i]);
                    std::cout << "\n";
                }
            }

            delete[] text;
            break;
        }

        case 3:
        {
            std::cout << "Enter the departure time to search for\n";
            getchar();
            Train t1;
            cinTime(t1);

            std::cout << "List of selected trains:\n";
            for (int i = 0; i < sz; i++)
            {
                if (arr[i].start.tim == t1.start.tim)
                {
                    outputOne(arr[i]);
                    std::cout << "\n";
                }
            }

            break;
        }

        case 4:
        {
            std::cout << "Enter the arrival time to search for\n";
            getchar();
            Train t1;
            cinTime(t1);

            std::cout << "List of selected trains:\n";
            for (int i = 0; i < sz; i++)
            {
                if ((arr[i].arrive.tim) % 1440 == t1.start.tim)
                {
                    outputOne(arr[i]);
                    std::cout << "\n";
                }
            }

            break;
        }

        case 5:
        {
            std::cout << "Enter the arrival place to search for\n";
            getchar();
            char* text = new char[255];
            cinText(text, 255);

            std::cout << "List of selected trains:\n";
            for (int i = 0; i < sz; i++)
            {
                if (strcmp(arr[i].place, text) == 0)
                {
                    outputOne(arr[i]);
                    std::cout << "\n";
                }
            }

            delete[] text;
            break;
        }

        case 6:
        {
            std::cout << "Enter the number of free seats to search for\n";
            ll seats;
            cinLong(seats);

            std::cout << "List of selected trains:\n";
            for (int i = 0; i < sz; i++)
            {
                if (arr[i].seats == seats)
                {
                    outputOne(arr[i]);
                    std::cout << "\n";
                }
            }

            break;
        }
        
        default:
        {
            std::cout << "Wrong option!n";

            break;
        }
    }

    return;
}