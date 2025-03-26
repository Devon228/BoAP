#include "header1.h"

void cinText(char*& str)
{
    short cur = 0;
    while(true)
    {
        char newc = getchar();

        if (newc == '\n')
            break;

        if (!(('a' <= newc && newc <= 'z') || ('A' <= newc && newc <= 'Z') || (newc == ' ') || (newc == (char)0xD0) || (newc == (char)0xD1)))
        {
            std::cout << "Wrong input! Please, write the string again.\n";
            while (getchar() != '\n');
            cur = 0;
        }
        else if (!(cur <= 80))
        {
            std::cout << "Too big length! Please, write thexff string again with less than 80 symbols.\n";
            while (getchar() != '\n');
            cur = 0;
        }
        else
        {
            if (newc == (char)0xD0 || newc == (char)0xD1)
            {
                char c2 = getchar();
                if (newc == (char)0xD0 && c2 == (char)0x81)                                     // Ё
                {
                    newc = 240;
                }
                if (newc == (char)0xD0 && (char)0x90 <= c2 && c2 <= (char)0xBF) // А-п
                {
                    //std::cout << (int)(c2 - (char)0x90) << "\n";
                    if ((char)0x90 <= c2 && c2 <= (char)0xAF) //А-Я
                        newc = -128 + (c2 - (char)0x90);
                    if ((char)0xB0 <= c2 && c2 <= (char)0xBF) //а-п
                        newc = -96 + (c2 - (char)0xB0); //объединить
                }
                if (newc == (char)0xD1 && ((char)0x80 <= c2 && c2 <= (char)0x8F)) //р-я
                {
                    newc = -32 + (c2 - (char)0x80);
                }
                if (newc == (char)0xD1 && c2 == (char)0x91)                                          // ё
                {
                    newc = 241;
                }
            }
            str[cur++] = newc;
        }
    }

    str[cur] = '\0';
    return;
}