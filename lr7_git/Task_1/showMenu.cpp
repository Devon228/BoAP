#include "header.h"

void showMenu()
{
    std::cout << "Choose 1 otpion by entering 1 number.\n"
              << "Menu:\n"
              <<  "1. Input a new list of trains;\n"
              <<  "2. Display all the trains;\n"
              <<  "3. Add some trains to the current list;\n"
              <<  "4. Search for train by his field;\n"
              <<  "5. Delete trains from the list;\n"
              <<  "6. Change a train from the list;\n"
              <<  "7. Display all the trains arriving at some place;\n"
              <<  "8. Sort the list of trains by the number of free seats;\n"
              <<  "9. Load the binary file with the list of the trains;\n"
              <<  "10. Stop program;\n";
}