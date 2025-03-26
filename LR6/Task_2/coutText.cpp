#include "header1.h"

void coutText(char*& text)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        char newc = text[i], c2 = '\0';

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
                //std::cout << (int)((int)newc - (-128)) << "\n";
                c2 = 0x90 + ((int)newc - (-128));
                newc = 0xD0;

                //std::cout << (int)c2 << "\n";
            }
            if ((-32 <= (int)newc && (int)newc <= -17)) // р-я
            {
                c2 = 0x80 + ((int)(newc) - (-32));
                newc = 0xD1;

            }
        }

        char temp[3] = {newc, c2, '\0'};
        std::cout << temp;
    }
}