#include "header1.h"

int main() {
    init(13);
    while (true)
    {
        std::cout << "Enter 1 to continue, 2 to exit\n";
        ll option;
        cinLong(option);
        getchar();
        if (option != 1 && option != 2)
        {
            std::cout << "Incorrect input. Please, write again\n";
            continue;
        }
        if (option == 2)
        {
            std::cout << "Goodbye";
            break;
        }

        std::cout << "Enter the text (maximum 80 symbols):" << "\n";
        char* text = new char[81];
        cinText(text);

        char** words = new char*[81];
        char *start = new char[81];
        char *fin = new char[81];
        for (int i = 0; i < 81; i++)
            words[i] = new char[81];

        long long num_words = createWords(text, words, start, fin);

        long long chain[81];
        long long ans = findChain(start, fin, num_words, chain);

        std::cout << "Given text is\n";
        coutText(text);
        std::cout << "\n";
        /*
        for (int i = 0; i < num_words; i++)
            std::cout << start[i] << " " << fin[i] << "\n";
        */
        std::cout << "Max chain of the words is " << ans << "\n";
        for (int i = 0; i < ans; i++)
        {
            coutText(words[chain[i]]);
            std::cout << " ";
        }
        std::cout << "\n";

        delete[] text;
        for (int i = 0; i < 81; i++)
            delete[] words[i];
        delete[] words;
        delete[] start;
        delete[] fin;
    }
    return 0;
}