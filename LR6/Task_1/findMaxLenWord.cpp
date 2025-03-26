#include "header1.h"

void findMaxLenWord(char*& str, short& num, short& ind)
{
    bool now_word = 0;
    short cur_num = 0, cur_ind = 0, cur_len = 0, max_len = 0;
    short str_size = (short)strlen(str);

    for (int i = 0; i < str_size; i++)
    {
        //std::cout << i << " " << (int)str[i] << std::endl;

        if (str[i] == ' ' && now_word)
        {
            now_word = 0;

            if (cur_len > max_len)
            {
                max_len = cur_len;
                num = cur_num;
                ind = cur_ind;
            }
        }

        if (!now_word && ((i > 0 && str[i-1] == ' ' && str[i] != ' ') || (i == 0 && str[i] != ' ')))
        {
            now_word = 1;

            cur_num++;
            cur_ind = i;
            cur_len = 0;
        }

        if (now_word)
            cur_len++;

    }

    if (now_word)
    {
        now_word = 0;

        if (cur_len > max_len)
        {
            max_len = cur_len;
            num = cur_num;
            ind = cur_ind;
        }
    }
}