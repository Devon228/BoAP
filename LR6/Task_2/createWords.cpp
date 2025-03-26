#include "header1.h"

long long createWords(char*& str, char**& word, char*& st, char*& fin)
{
    bool now_word = 0;
    short cur_num = -1, cur_ind = 0;
    short str_size = (short)strlen(str);

    for (int i = 0; i < str_size; i++)
    {
        //std::cout << i << " " << (int)str[i] << std::endl;

        if (str[i] == ' ' && now_word)
        {
            now_word = 0;
            cur_ind++;
            word[cur_num][cur_ind] = '\0';
            fin[cur_num] = word[cur_num][cur_ind-1];
        }

        if (!now_word && ((i > 0 && str[i-1] == ' ' && str[i] != ' ') || (i == 0 && str[i] != ' ')))
        {
            now_word = 1;

            cur_num++;
            cur_ind = 0;
            word[cur_num][cur_ind] = str[i];
            st[cur_num] = str[i];
        }
        else if (now_word)
        {
            cur_ind++;
            word[cur_num][cur_ind] = str[i];
        }

    }

    if (now_word)
    {
        now_word = 0;
        cur_ind++;
        word[cur_num][cur_ind] = '\0';
        fin[cur_num] = word[cur_num][cur_ind-1];
    }

    return cur_num + 1;
}