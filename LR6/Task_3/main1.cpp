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

        char* symb = new char[257];
        decompose(text, symb);

        std::cout << "Given text is\n";
        coutText(text);
        std::cout << "\n";
        std::cout << "Symbols of the text are:\n";
        for (int i = 0; symb[i] != '\0'; i++)
        {
            std::cout << "'";
            coutText(symb[i]);
            std::cout << "'; ";
        }
        std::cout << "\n";
        
        delete[] text;
        delete[] symb;
    }
    return 0;
}