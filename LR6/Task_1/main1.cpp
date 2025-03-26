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

        short num_max_word = -1, begin_max_word = -1;
        findMaxLenWord(text, num_max_word, begin_max_word);

        std::cout << "Given text is\n";
        coutText(text);
        std::cout << "\n";
        std::cout << "Number of the maximum length word is " << num_max_word << "\n";
        std::cout << "Index of the first position the maximum length word is " << begin_max_word << "\n";

        delete[] text;
    }
    return 0;
}