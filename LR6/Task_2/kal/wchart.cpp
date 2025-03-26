#include <bits/stdc++.h>
using namespace std;
int main()
{
    wchar_t *s = L"Юрий Мудрогелов";
    //wcin >> s;
    //if (L'а' <= s[0] && s[0] <= L'я') wcout << L"абоба";
    wcout << s;
}
        if (newc == (char)0xD0 || newc == (char)0xD1)
        {
            char c2 = getchar();

            if (newc == (char)0xD0 && 0x90 <= c2 && c2 <= 0xBF) // А-я
            {
                newc = 'а' + (c2 - 0x90);
            }
            if (newc == (char)0xD0 && c2 == 0x81)                                     // Ё
            {
                newc = 240;
            }
            if (newc == (char)0xD1 && (0x80 <= c2 && c2 <= 0x8F)) // Ъ-Я
            {
                newc = 'Ъ' + (c2 - 0x80);
            }
            if (newc == (char)0xD1 && c2 == (char)0x91)                                          // ё
            {
                std::cout << "asf";
                newc = 128;
            }
        }
