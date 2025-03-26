#include <bits/stdc++.h>
using namespace std;
int main()
{
    char newc, c2;
    newc = getchar();

    if (newc == (char)0xD0 || newc == (char)0xD1)
    {
        c2 = getchar();
        if (newc == (char)0xD0 && c2 == (char)0x81)                                     // Ё
        {
            newc = 240;
        }
        if (newc == (char)0xD0 && (char)0x90 <= c2 && c2 <= (char)0xBF) // А-п
        {
            std::cout << (int)(c2 - (char)0x90) << "\n";
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

    std::cout << (int)newc << " " << newc << "\n";

    if ((int)newc == -15)                                          // ё
    {
        newc = 0xD1;
        c2 = 0x91;
    }
    else
    {
        if ((int)newc == -16)                                     // Ё
        {
            newc = 0xD0;
            c2 = 0x81;
        }
        if (-128 <= (int)newc && (int)newc <= -80) // А-п
        {
            std::cout << (int)((int)newc - (-128)) << "\n";
            c2 = 0x90 + ((int)newc - (-128));
            newc = 0xD0;

            std::cout << (int)c2 << "\n";
        }
        if ((-32 <= (int)newc && (int)newc <= -17)) // р-я
        {
            c2 = 0x80 + ((int)(newc) - (-32));
            newc = 0xD1;

        }
    }


    char text[3] = {newc, c2, '\0'};
    std::cout << text;
}
