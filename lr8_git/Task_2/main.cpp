#include "header.h"

int main()
{
    std::cout << "Program for administraition of dormitory.\n"
              << "Fields of the structure:\n"
              << "1. Full name of the person;\n"
              << "2. Group of study;\n"
              << "3. Average mark of the person;\n"
              << "4. Average wage on a memeber of the family;\n\n";
    

    Stud* arr = nullptr;
    int sz = 0;
    double minwage = 0;

    std::cout << "Current minimum wage?\n" << std::setprecision(2) << std::fixed;
    cinDouble(minwage);

    std::string file = "/home/dimas/Documents/453502/ОАиП/LR8/Task_2/studentbase.txt";

    while (true)
    {
        showMenu();

        ll option;
        cinLong(option);
        bool wrong = 0, stop = 0;

        switch (option)
        {
            case 1:
                input(arr, sz);
                writeFile(arr, sz, file);
                break;
            case 2:
                outputAll(arr, sz);
                break;
            case 3:
                add(arr, sz);
                writeFile(arr, sz, file);
                break;
            case 4:
                outputAll(arr, sz);
                deleteS(arr, sz);
                writeFile(arr, sz, file);
                break;
            case 5:
                outputAll(arr, sz);
                change(arr, sz); 
                writeFile(arr, sz, file);
                break;
            case 6:
            {
                outputOrder(arr, sz, minwage);
                writeFile(arr, sz, file);
                break;
            }
            case 7:
                stop = 1;
                break;
            default:
                wrong = 1;
                break;
        }


        if (stop)
            break;

        if (wrong)
            std::cout << "Wrong option. Choose from 1 to 7\n";
        else
            std::cout << "Operation was finished successfully\n";
    }

    free(arr);
    std::cout << "Thanks for using program. Bye!\n";
    return 0;
}
