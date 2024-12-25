#include "header.h"

int main()
{
    std::cout << "Program for administraition of railway stations.\n"
              << "Fields of the structure:\n"
              << "1. Number of the train;\n"
              << "2. Type of the train (fast or slow);\n"
              << "3. Time of departure;\n"
              << "4. Time of arrival;\n"
              << "5. Place of arrival;\n"
              << "6. Number of free seats in the train;\n\n";
    

    Train* arr = nullptr;
    int sz = 0;

    std::string file = "/home/dimas/Documents/453502/ОАиП/LR8/Task_1/trainbase.bin";

    while (true)
    {
        showMenu();

        ll option;
        cinLong(option);
        bool wrong = 0, stop = 0; //флаг на правильност опцию и выход из цикла

        switch (option)
        {
            case 1:
                inputTrain(arr, sz);
                writeFile (arr, 0,  sz, file); //запись в файл с нуля
                break;
            case 2:
                outputTrainAll(arr, sz);
                break;
            case 3:
            {
                int sz_start = sz;
                addTrain(arr, sz);
                //std::cout << sz_start << " " << sz << "\n";
                writeFile(arr, sz_start, sz, file); //запись в файл с какого-то момента
                break;
            }
            case 4:
                searchFieldTrain(arr, sz);
                break;
            case 5:
                outputTrainAll(arr, sz);
                deleteTrain(arr, sz, file); //изменение файла внутри этой функции
                break;
            case 6:
                outputTrainAll(arr, sz);
                changeTrain(arr, sz, file); //изменение файла внутри этой внутри
                break;
            case 7:
                outTrainToPlace(arr, sz);
                break;
            case 8:
                sortTrain(arr, sz);
                writeFile (arr, 0,  sz, file); //перезапись в файл
                std::cout << "The list sorted by the number of free seats:\n";
                outputTrainAll(arr, sz); //вывод всего (очень полезно)
                break;
            case 9:
                loadFile(file, arr, sz); //загрузка из файла
                break;
            case 10:
                stop = 1;
                break;
            default:
                wrong = 1;
                break;
        }


        if (stop)
            break;

        if (wrong)
            std::cout << "Wrong option. Choose from 1 to 10\n";
        else
            std::cout << "Operation was finished successfully\n";
    }

    //очистка динамического массива
    for (int i = 0; i < sz; i++)
    {
            delete[] arr[i].type;
            delete[] arr[i].place;
    }
    free(arr);
    std::cout << "Thanks for using program. Bye!\n";
    return 0;
}
