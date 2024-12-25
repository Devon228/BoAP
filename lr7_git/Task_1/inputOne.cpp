#include "header.h"

static void calcArrival(Train& arr)
{
    const char* fast = "fast";
    if (strcmp(arr.type, fast) == 0)
        arr.arrive.tim = (arr.start.tim + 120);
    else
        arr.arrive.tim = (arr.start.tim + 180);

    arr.arrive.hh = (arr.arrive.tim % 1440) / 60;
    arr.arrive.mm = (arr.arrive.tim % 1440) % 60;
}


void cinTime (Train& arr)
{
    while (true)
    {
        char h1, h2, buf, m1, m2, bufend;
        h1 = getchar();
        h2 = getchar();
        buf = getchar();
        m1 = getchar();
        m2 = getchar();
        bufend = getchar();

        //std::cout << h1 << " " << h2 << " " << buf << " " << m1 << " " << m2 << " " << bufend << '\n';

        if ('0' <= h1 && h1 <= '9' && '0' <= h2 && h2 <= '9' && '0' <= m1 && m1 <= '9' && '0' <= m2 && m2 <= '9' && buf == ':' && bufend == '\n')
        {
            arr.start = {int(h1 - '0') * 10 + int(h2 - '0'), int(m1 - '0') * 10 + int(m2 - '0'), 0};
            arr.start.tim = arr.start.hh * 60 + arr.start.mm;
            break;
        }
        else
        {
            if (bufend != '\n')
            {
                std::cin.clear();
                while (std::cin.get() != '\n');
            }

            std::cout << "Wrong input. Type again\n";
        }
    }
}


void cinText (char*& text, int size)
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

bool inputOne (Train &arr, int num)
{
    arr.n.n32 = num + 1;

    std::cout << "Info about train number " << arr.n.n32 << ":\n";
    //std::cout << "Enter its number: \n";
    //cinLong(arr.n.n64);

    std::cout << "Enter its type ('fast' or 'slow'): \n";
    arr.type = new char[5];
    getchar();
    cinText(arr.type, 5);
    if (arr.type[0] == '0' && arr.type[1] == '\0')
    {
        delete[] arr.type;
        return 0;
    }

    std::cout << "Enter its hour of departure time in format hh:mm: \n";
    //getchar(); no cin
    cinTime(arr);

    std::cout << "Enter its place of arrival: \n";
    arr.place = new char[255];
    //getchar(); no cin
    cinText(arr.place, 255);

    std::cout << "Enter its number of free seats: \n";
    cinLong(arr.seats);

    calcArrival(arr);

    return 1;
}
