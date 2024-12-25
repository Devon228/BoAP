#include "header.h"

void cinText (char* text, int size)
{
    while (true)
    {
        for (int i = 0; i < size; i++)
        {
            text[i] = getchar();

            if (text[i] == '\n')
            {
                size = i + 1;
                break;
            }
        }

        if (text[size-1] == '\n')
        {
            text[size-1] = '\0';
            break;
        }
        else
        {
            while (getchar() != '\n');
            std::cout << "Wrong input. Type again\n";
            continue;
        }
    }
}

bool inputOne (Stud &arr, int num)
{
    arr.n = num + 1;

    std::cout << "Info about student  number " << arr.n << ":\n";
    //std::cout << "Enter its number: \n";
    //cinLong(arr.n.n64);

    std::cout << "Enter full name (Last name, First name, Father name): \n";
    getchar();
    cinText(arr.fio, 255);
    if (arr.fio[0] == '0' && arr.fio[1] == '\0')
    {
        return 0;
    }

    std::cout << "Enter the study group number of the student:\n";
    //getchar(); no cin
    cinLong(arr.gr.i);

    std::cout << "Enter average mark: \n";
    cinDouble(arr.mark);

    std::cout << "Enter the average wage of students's family:\n";
    cinDouble(arr.wage);

    return 1;
}
