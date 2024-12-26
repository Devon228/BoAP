#include "func.h"

//add
void add(Stud*& arr, int &sz)
{
    std::cout << "Menu for add\n";
    std::cout << "1. Add n new students\n";  
    std::cout << "2. Add student until a special student with type 0\n";
    std::cout << "3. Add each student after asking\n";
    
    ll option;
    cinLong(option);

    if (option == 1)
    {
        std::cout << "Enter the number of students n\n";
        ll n;
        cinLong(n);

        arr = (Stud*)realloc(arr, (sz + n) * sizeof(Stud));

        for (int i = sz; i < sz + n; i++)
        {
            inputOne(arr[i], i);
        }

        sz += n;
    }
    else if (option == 2)
    {
        int sz0 = 16;
        arr = (Stud*)realloc(arr, (sz + sz0) * sizeof(Stud));
        int i = 0;

        while (true)
        {
            if (!inputOne(arr[sz], sz))
                break;

            sz++;
            i++;
            if (sz0 == i)
            {
                sz0 *= 2;
                arr = (Stud*)realloc(arr, (sz + sz0) * sizeof(Stud));
            }
        }

        arr = (Stud*)realloc(arr, sz * sizeof(Stud));
    }
    else if (option == 3)
    {
        int sz0 = 16;
        arr = (Stud*)realloc(arr, (sz + sz0) * sizeof(Stud));
        int i = 0;

        while (true)
        {
            std::cout << "Do you want to continue input? yes : 1 | no : otherwise\n";
            ll option1;
            cinLong(option1);
            if (option1 != 1)
                break;

            inputOne(arr[sz], sz);
                
            sz++;
            i++;
            if (sz0 == i)
            {
                sz0 *= 2;
                arr = (Stud*)realloc(arr, (sz + sz0) * sizeof(Stud));
            }
        }

        arr = (Stud*)realloc(arr, sz * sizeof(Stud));
    }
    else
    {
        std::cout << "Wrong option. Type again\n";
    }

    return;
}


//change
void change(Stud*& arr, const int& sz)
{
    ll num;
    while (true)
    {
        std::cout << "Enter the number of the student to change:\n";
        cinLong(num);

        if (1 <= num)
            break;
        std::cout << "Wrong number. Type again\n";
    }

    for (int i = 0; i < sz; i++)
    {
        if (arr[i].n == num)
        {
            inputOne(arr[i], num);
            break;
        }
    }
}


//cin
void cinLong(ll& number)
{
    while (!(std::cin >> number) || (std::cin.peek() != '\n') || (number < 0))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');

        std::cout << "Wrong input. Type again\n";
    }
}

void cinDouble(double& number)
{
    while (!(std::cin >> number) || (std::cin.peek() != '\n') || (number < 0))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');

        std::cout << "Wrong input. Type again\n";
    }
}



//deleteS
void deleteS(Stud*& arr, int& sz)
{
    ll num;
    while (true)
    {
        std::cout << "Enter the number of the student to delete:\n";
        cinLong(num);

        if (1 <= num)
            break;
        std::cout << "Wrong number. Type again\n";
    }

    for (int i = 0; i < sz; i++)
    {
        if (arr[i].n == num)
        {
            for (int j = i; j < sz - 1; j++)
            {            
                arr[j] = arr[j+1];
            }

            sz--;
            arr = (Stud*)realloc(arr, sz * sizeof(Stud));
            break;
        }
    }

}


//fileSave
static void writeOneLineFile (Stud &arr, std::ofstream &out)
{
    char sep = '\t';
    char end = '\n';

    out << arr.n << sep << arr.fio << sep << arr.gr.i << sep << arr.mark << sep << arr.wage << end;
}


void writeFile (Stud*& arr, int sz, const std::string file)
{
    std::ofstream out(file, std::ios::out);
    if (!out)
    {
        std::cerr << "Error!\n";
        return;
    }

    out << "Num\tFio\tGroup\tMark\tWage\n" << std::setprecision(2) << std::fixed;
    for (int i = 0; i < sz; i++) 
    {
        writeOneLineFile(arr[i], out);
    }

    out.close();
}


//input
void input(Stud*& arr, int &sz)
{
    free(arr);

    std::cout << "Menu for input\n";
    std::cout << "1. Input array of n students\n";  
    std::cout << "2. Input students until a special student with full name 0\n";
    std::cout << "3. Input each student after asking\n";
    
    ll option;
    cinLong(option);

    if (option == 1)
    {
        std::cout << "Enter the number n\n";
        ll n;
        cinLong(n);

        sz = n;
        arr = (Stud*)malloc(sz * sizeof(Stud));

        for (int i = 0; i < n; i++)
        {
            inputOne(arr[i], i);
        }
    }
    else if (option == 2)
    {
        int sz0 = 16;
        sz = 0;
        arr = (Stud*)malloc(sz0 * sizeof(Stud));

        while (true)
        {
            if (!inputOne(arr[sz], sz))
                break;

            sz++;
            if (sz0 == sz)
            {
                sz0 *= 2;
                arr = (Stud*)realloc(arr, sz0 * sizeof(Stud));
            }
        }

        arr = (Stud*)realloc(arr, sz * sizeof(Stud));
    }
    else if (option == 3)
    {
        int sz0 = 16;
        sz = 0;
        arr = (Stud*)malloc(sz0 * sizeof(Stud));

        while (true)
        {
            std::cout << "Do you want to continue input? yes : 1 | no : otherwise\n";
            ll option1;
            cinLong(option1);
            if (option1 != 1)
                break;

            inputOne(arr[sz], sz);
                
            sz++;
            if (sz0 == sz)
            {
                sz0 *= 2;
                arr = (Stud*)realloc(arr, sz0 * sizeof(Stud));
            }
        }

        arr = (Stud*)realloc(arr, sz * sizeof(Stud));
    }
    else
    {
        std::cout << "Wrong option. Type again\n";
    }

    return;
}


//inputOne
void cinText (char* text, int size)
{
    while (true)
    {
        for (int i = 0; i < size; i++)
        {
            text[i] = getchar();

            if (text[i] == '\n')
            {
                size = i + 1;
                break;
            }
        }

        if (text[size-1] == '\n')
        {
            text[size-1] = '\0';
            break;
        }
        else
        {
            while (getchar() != '\n');
            std::cout << "Wrong input. Type again\n";
            continue;
        }
    }
}

bool inputOne (Stud &arr, int num)
{
    arr.n = num + 1;

    std::cout << "Info about student  number " << arr.n << ":\n";
    //std::cout << "Enter its number: \n";
    //cinLong(arr.n.n64);

    std::cout << "Enter full name (Last name, First name, Father name): \n";
    getchar();
    cinText(arr.fio, 255);
    if (arr.fio[0] == '0' && arr.fio[1] == '\0')
    {
        return 0;
    }

    std::cout << "Enter the study group number of the student:\n";
    //getchar(); no cin
    cinLong(arr.gr.i);

    std::cout << "Enter average mark: \n";
    cinDouble(arr.mark);

    std::cout << "Enter the average wage of students's family:\n";
    cinDouble(arr.wage);

    return 1;
}


//output
void outputOrder(Stud*& arr, const int& sz, const double& minwage)
{
    for (int i = 1; i < sz; i++)
    {
        for (int j = i; j - 1 >= 0; j--)
        {
            if (arr[j-1].mark < arr[j].mark) 
            {
                std::swap(arr[j-1], arr[j]);
            }
        }
    }

    std::cout << "All the correct order of students from high to low priority of getting a dormitory room" << "\n";
    std::cout << "Wage less then double minimum wage:\n";
    for (int i = 0; i < sz; i++)
    {
        if (arr[i].wage < 2 * minwage)
        {
            outputOne(arr[i]);
            std::cout << "\n";
        }
    }
    std::cout << "Other students:\n";
    for (int i = 0; i < sz; i++)
    {
        if (arr[i].wage >= 2 * minwage)
        {
            outputOne(arr[i]);
            std::cout << "\n";
        }
    }
}

void outputAll(Stud*& arr, const int& sz)
{
    std::cout << "There are " << sz << " students:\n";
    for (int i = 0; i < sz; i++)
    {
        outputOne(arr[i]);
        std::cout << "\n";
    }
}


//outputOne
void outputOne (Stud &arr)
{
    std::cout << "Number: " << arr.n << "\t";
    std::cout << "FIO: " << arr.fio << "\t";
    std::cout << "Group: " << arr.gr.i << "\t";
    std::cout << "Average mark: " << arr.mark << "\t";
    std::cout << "Average wage of the family: " << arr.wage << "\t";
}


//showMenu
void showMenu()
{
    std::cout << "Choose 1 otpion by entering 1 number.\n"
              << "Menu:\n"
              <<  "1. Input a new list of students;\n"
              <<  "2. Display all the students;\n"
              <<  "3. Add some students to the current list;\n"
              <<  "4. Delete students from the list;\n"
              <<  "5. Change a student from the list;\n"
              <<  "6. Display all the students in order of priority of getting a dorm room;\n"
              <<  "7. Stop program;\n";
}