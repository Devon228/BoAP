#include "func.h"

//cinLong
void cinLong(int& number)
{
    while (!(std::cin >> number) || (std::cin.peek() != '\n') || (number < 0))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');

        std::cout << "Wrong input. Type again\n";
    }
}

//add
void addTrain(Train*& arr, int &sz)
{
    std::cout << "Menu for add\n";
    std::cout << "1. Add n new trains\n";  
    std::cout << "2. Add trains until a special train with type 0\n";
    std::cout << "3. Add each train after asking\n";
    
    ll option;
    cinLong(option);

    if (option == 1)
    {
        std::cout << "Enter the number of trains n\n";
        ll n;
        cinLong(n);

        arr = (Train*)realloc(arr, (sz + n) * sizeof(Train));

        for (int i = sz; i < sz + n; i++)
        {
            inputOne(arr[i], i);
        }

        sz += n;
    }
    else if (option == 2)
    {
        int sz0 = 16;
        arr = (Train*)realloc(arr, (sz + sz0) * sizeof(Train));
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
                arr = (Train*)realloc(arr, (sz + sz0) * sizeof(Train));
            }
        }

        arr = (Train*)realloc(arr, sz * sizeof(Train));
    }
    else if (option == 3)
    {
        int sz0 = 16;
        arr = (Train*)realloc(arr, (sz + sz0) * sizeof(Train));
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
                arr = (Train*)realloc(arr, (sz + sz0) * sizeof(Train));
            }
        }

        arr = (Train*)realloc(arr, sz * sizeof(Train));
    }
    else
    {
        std::cout << "Wrong option. Type again\n";
    }

    return;
}


//change
void changeTrain(Train*& arr, const int& sz, std::string file)
{
    ll num;
    while (true)
    {
        std::cout << "Enter the number of the train to change:\n";
        cinLong(num);

        if (1 <= num)
            break;
        std::cout << "Wrong number. Type again\n";
    }

    int sztrain = 4 + 4 + 5 + 12 + 12 + 4 + 255 + 4;
    for (int i = 0; i < sz; i++)
    {
        if (arr[i].n.n32 == num)
        {
            delete[] arr[i].type;
            delete[] arr[i].place;

            inputOne(arr[i], num - 1);

            int pos = sizeof(sz) + i * sztrain;
            std::cout << pos << "\n";

            std::ofstream out(file, std::ios::binary | std::ios::in | std::ios::out);
            out.seekp(pos,std::ios::beg);

            writeTrainFile(arr[i], out);
            break;
        }
    }
}

//delete
void deleteTrain(Train*& arr, int& sz, std::string file)
{
    ll num;
    while (true)
    {
        std::cout << "Enter the number of the train to delete:\n";
        cinLong(num);

        if (1 <= num)
            break;
        std::cout << "Wrong number. Type again\n";
    }

    for (int i = 0; i < sz; i++)
    {
        if (arr[i].n.n32 == num)
        {
            for (int j = i; j < sz - 1; j++)
            {            
                delete[] arr[j].type;
                delete[] arr[j].place;
                arr[j] = arr[j+1];
            }

            delete[] arr[sz-1].type;
            delete[] arr[sz-1].place;
            sz--;
            arr = (Train*)realloc(arr, sz * sizeof(Train));

            writeFile(arr, i,  sz, file);
            break;
        }
    }
}

//fileLoad
static void readStrFile(std::ifstream& in, char*& text, int sz)
{
    in.read(reinterpret_cast<char*>(&sz), sizeof(sz));
    //std::cout << sz << "\n"; 
    in.read(text, sz);
}

static void loadTrainFile(Train& arr, std::ifstream& in)
{
    in.read(reinterpret_cast<char*>(&arr.n.n32), sizeof(arr.n.n32));

    arr.type = new char[5];
    readStrFile(in, arr.type, 5);

    in.read(reinterpret_cast<char*>(&arr.start.hh), sizeof(arr.start.hh));
    in.read(reinterpret_cast<char*>(&arr.start.mm), sizeof(arr.start.mm));
    in.read(reinterpret_cast<char*>(&arr.start.tim), sizeof(arr.start.tim));

    in.read(reinterpret_cast<char*>(&arr.arrive.hh), sizeof(arr.arrive.hh));
    in.read(reinterpret_cast<char*>(&arr.arrive.mm), sizeof(arr.arrive.mm));
    in.read(reinterpret_cast<char*>(&arr.arrive.tim), sizeof(arr.arrive.tim));

    arr.place = new char[255];
    readStrFile(in, arr.place, 255);

    in.read(reinterpret_cast<char*>(&arr.seats), sizeof(arr.seats));
}

void loadFile(std::string file, Train*& arr, int& sz)
{
    std::ifstream in(file, std::ios::binary);
    if (!in) {
        std::cerr << "Error!.\n";
        return;
    }

    for (int i = 0; i < sz; i++)
    {
        delete[] arr[i].type;
        delete[] arr[i].place;
    }
    free(arr);

    in.read(reinterpret_cast<char*>(&sz), sizeof(sz));
    arr = (Train*)malloc(sz * sizeof(Train));
    std::cout << sz << "\n";

    for (int i = 0; i < sz; i++)
    {
        loadTrainFile(arr[i], in);
    }

    in.close();
}


//fileSave
static void clearFile (const std::string file)
{
    std::ofstream out(file, std::ios::binary | std::ios::trunc);
    if (!out) {
        std::cerr << "Failed to open file!\n";
        return;
    }

    out.close();
}


static void writeStrFile(std::ofstream &out, char*& str, int len) 
{
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(str, len);
}


void writeTrainFile (Train &arr, std::ofstream &out)
{
    out.write(reinterpret_cast<const char*>(&arr.n.n32), sizeof(arr.n.n32));

    writeStrFile(out, arr.type, 5);

    out.write(reinterpret_cast<const char*>(&arr.start.hh), sizeof(arr.start.hh));
    out.write(reinterpret_cast<const char*>(&arr.start.mm), sizeof(arr.start.mm));
    out.write(reinterpret_cast<const char*>(&arr.start.tim), sizeof(arr.start.tim));

    out.write(reinterpret_cast<const char*>(&arr.arrive.hh), sizeof(arr.arrive.hh));
    out.write(reinterpret_cast<const char*>(&arr.arrive.mm), sizeof(arr.arrive.mm));
    out.write(reinterpret_cast<const char*>(&arr.arrive.tim), sizeof(arr.arrive.tim));

    writeStrFile(out, arr.place, 255);

    out.write(reinterpret_cast<const char*>(&arr.seats), sizeof(arr.seats));
}


void writeFile (Train*& arr, int sz_start,  int sz, const std::string file)
{
    if (sz_start == 0)
    {
        clearFile(file);
        //std::ofstream out(file, std::ios::binary | std::ios::ate);
        //out.write(reinterpret_cast<const char*>(&sz), sizeof(sz));
    }

    std::ofstream outsz(file, std::ios::binary | std::ios::in | std::ios::out);
    //outsz.seekp(0L,std::ios::beg);
    outsz.write(reinterpret_cast<const char*>(&sz), sizeof(sz));
    //std::cout << sz << "\n";
    outsz.close();

    std::ofstream out(file, std::ios::binary | std::ios::ate |std::ios::app);
    //out.seekp(0L,std::ios::beg);
    //out.write(reinterpret_cast<const char*>(&sz), sizeof(sz));
    //out.close();
    //out.seekp(0L,std::ios::end);

    if (!out)
    {
        std::cerr << "Error!\n";
        return;
    }

    for (int i = sz_start; i < sz; i++) 
    {
        //std::cout << "WRITE SMTH";
        //if (sz_start > 0) break;
        writeTrainFile(arr[i], out);
    }

    //out.seekp(0L,std::ios::beg);
    //std::cout << file << "\n";

    out.close();
}

//input
void inputTrain(Train*& arr, int &sz)
{
    for (int i = 0; i < sz; i++)
    {
        delete[] arr[i].type;
        delete[] arr[i].place;
    }
    free(arr);

    std::cout << "Menu for input\n";
    std::cout << "1. Input array of n trains\n";  
    std::cout << "2. Input trains until a special train with type 0\n";
    std::cout << "3. Input each train after asking\n";
    
    ll option;
    cinLong(option);

    if (option == 1)
    {
        std::cout << "Enter the number of trains n\n";
        ll n;
        cinLong(n);

        sz = n;
        arr = (Train*)malloc(sz * sizeof(Train));

        for (int i = 0; i < n; i++)
        {
            inputOne(arr[i], i);
        }
    }
    else if (option == 2)
    {
        int sz0 = 16;
        sz = 0;
        arr = (Train*)malloc(sz0 * sizeof(Train));

        while (true)
        {
            if (!inputOne(arr[sz], sz))
                break;

            sz++;
            if (sz0 == sz)
            {
                sz0 *= 2;
                arr = (Train*)realloc(arr, sz0 * sizeof(Train));
            }
        }

        arr = (Train*)realloc(arr, sz * sizeof(Train));
    }
    else if (option == 3)
    {
        int sz0 = 16;
        sz = 0;
        arr = (Train*)malloc(sz0 * sizeof(Train));

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
                arr = (Train*)realloc(arr, sz0 * sizeof(Train));
            }
        }

        arr = (Train*)realloc(arr, sz * sizeof(Train));
    }
    else
    {
        std::cout << "Wrong option. Type again\n";
    }

    return;
}


//inputObe
static void calcArrival(Train& arr)
{
    const char* fast = "fast";
    if (strcmp(arr.type, fast) == 0)
        arr.arrive.tim = (arr.start.tim + 120);
    else
        arr.arrive.tim = (arr.start.tim + 180);

    arr.arrive.hh = (arr.arrive.tim % 1440) / 60;
    arr.arrive.mm = (arr.arrive.tim % 1440) % 60;
}


void cinTime (Train& arr)
{
    while (true)
    {
        char h1, h2, buf, m1, m2, bufend;
        h1 = getchar();
        h2 = getchar();
        buf = getchar();
        m1 = getchar();
        m2 = getchar();
        bufend = getchar();

        //std::cout << h1 << " " << h2 << " " << buf << " " << m1 << " " << m2 << " " << bufend << '\n';

        int hi = int(h1 - '0') * 10 + int(h2 - '0');
        int mi = int(m1 - '0') * 10 + int(m2 - '0');;
        if (hi <= 23 && mi <= 59 && '0' <= h1 && h1 <= '9' && '0' <= h2 && h2 <= '9' && '0' <= m1 && m1 <= '9' && '0' <= m2 && m2 <= '9' && buf == ':' && bufend == '\n')
        {
            arr.start = {int(h1 - '0') * 10 + int(h2 - '0'), int(m1 - '0') * 10 + int(m2 - '0'), 0};
            arr.start.tim = arr.start.hh * 60 + arr.start.mm;
            break;
        }
        else
        {
            if (bufend != '\n')
            {
                std::cin.clear();
                while (std::cin.get() != '\n');
            }

            std::cout << "Wrong input. Type again\n";
        }
    }
}


void cinText (char*& text, int size)
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

bool inputOne (Train &arr, int num)
{
    arr.n.n32 = num + 1;

    std::cout << "Info about train number " << arr.n.n32 << ":\n";
    //std::cout << "Enter its number: \n";
    //cinLong(arr.n.n64);

    std::cout << "Enter its type ('fast' or 'slow' or another less then 4 symbols): \n";
    arr.type = new char[5];
    getchar();
    while (true)
    {
        cinText(arr.type, 5);
        if (arr.type[0] == '0' && arr.type[1] == '\0')
        {
            delete[] arr.type;
            return 0;
        }

        const char* sf = "fast";
        const char* ss = "slow";

        if (strcmp(arr.type, sf) == 0 || strcmp(arr.type, ss) == 0)
            break;
        else
            std::cout << "Wrong type! Write again\n";
    }

    std::cout << "Enter its hour of departure time in format hh:mm: \n";
    //getchar(); no cin
    cinTime(arr);

    std::cout << "Enter its place of arrival: \n";
    arr.place = new char[255];
    //getchar(); no cin
    cinText(arr.place, 255);

    std::cout << "Enter its number of free seats: \n";
    cinLong(arr.seats);

    calcArrival(arr);

    return 1;
}


//output
void outTrainToPlace(Train*& arr, const int& sz) //вывод всех до определенного места
{
    std::cout << "Enter the place where trains go: \n";
    char *place = new char[255];
    getchar();
    cinText(place, 255);
    
    std::cout << "All the trains going to place " << place << "\n";
    for (int i = 0; i < sz; i++)
    {
        if (strcmp(arr[i].place, place) == 0)
        {
            outputOne(arr[i]);
            std::cout << "\n";
        }
    }

    delete[] place;   
}

void outputTrainAll(Train*& arr, const int& sz) //вывод вообще всех
{
    std::cout << "There are " << sz << " trains:\n";
    for (int i = 0; i < sz; i++)
    {
        outputOne(arr[i]);
        std::cout << "\n";
    }
}


//outputOne
static int to2 (int hh) //ведущие нули
{
    if (hh <= 9)
        std::cout << 0;

    return hh;
}

void outputOne (Train &arr) //вывод в строку всех полей
{
    std::cout << "Number: " << arr.n.n32 << "\t";
    std::cout << "Type: " << arr.type << "\t";
    std::cout << "Depatrure: " << to2(arr.start.hh) << ":" << to2(arr.start.mm) << "\t";
    std::cout << "Arrival: "  << to2(arr.arrive.hh) << ":" << to2(arr.arrive.mm) << "\t";
    std::cout << "Place of arrival: " << arr.place << "\t";
    std::cout << "Number of free seats: " << arr.seats;
}


//search
void searchFieldTrain(Train*& arr, const int& sz) //поиск по каждому из 6 полей
{    
    std::cout << "Choose 1 field.\n"
              << "Fields of the structure:\n"
              << "1. Number of the train;\n"
              << "2. Type of the train (fast or slow);\n"
              << "3. Time of departure;\n"
              << "4. Time of arrival;\n"
              << "5. Place of arrival;\n"
              << "6. Number of free seats in the train;\n\n";

    ll option1;
    while (true)
    {
        cinLong(option1);
        if (1 <= option1 && option1 <= 6)
        {
            break;
        }

        std::cout << "Wrong option! Type again\n";
    }

    switch (option1)
    {
        case 1:
        {
            std::cout << "Enter the number to search for\n";
            ll num;
            cinLong(num);

            std::cout << "List of selected trains:\n";
            for (int i = 0; i < sz; i++)
            {
                if (arr[i].n.n32 == num)
                {
                    outputOne(arr[i]);
                    std::cout << "\n";
                }
            }

            break;
        }

        case 2:
        {
            std::cout << "Enter the type to search for\n";
            getchar();
            char* text = new char[5];
            cinText(text, 5);

            std::cout << "List of selected trains:\n";
            for (int i = 0; i < sz; i++)
            {
                if (strcmp(arr[i].type, text) == 0)
                {
                    outputOne(arr[i]);
                    std::cout << "\n";
                }
            }

            delete[] text;
            break;
        }

        case 3:
        {
            std::cout << "Enter the departure time to search for\n";
            getchar();
            Train t1;
            cinTime(t1);

            std::cout << "List of selected trains:\n";
            for (int i = 0; i < sz; i++)
            {
                if (arr[i].start.tim == t1.start.tim)
                {
                    outputOne(arr[i]);
                    std::cout << "\n";
                }
            }

            break;
        }

        case 4:
        {
            std::cout << "Enter the arrival time to search for\n";
            getchar();
            Train t1;
            cinTime(t1);

            std::cout << "List of selected trains:\n";
            for (int i = 0; i < sz; i++)
            {
                if ((arr[i].arrive.tim) % 1440 == t1.start.tim)
                {
                    outputOne(arr[i]);
                    std::cout << "\n";
                }
            }

            break;
        }

        case 5:
        {
            std::cout << "Enter the arrival place to search for\n";
            getchar();
            char* text = new char[255];
            cinText(text, 255);

            std::cout << "List of selected trains:\n";
            for (int i = 0; i < sz; i++)
            {
                if (strcmp(arr[i].place, text) == 0)
                {
                    outputOne(arr[i]);
                    std::cout << "\n";
                }
            }

            delete[] text;
            break;
        }

        case 6:
        {
            std::cout << "Enter the number of free seats to search for\n";
            ll seats;
            cinLong(seats);

            std::cout << "List of selected trains:\n";
            for (int i = 0; i < sz; i++)
            {
                if (arr[i].seats == seats)
                {
                    outputOne(arr[i]);
                    std::cout << "\n";
                }
            }

            break;
        }
        
        default:
        {
            std::cout << "Wrong option!n";

            break;
        }
    }

    return;
}


//showMenu
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


//sortTrain
void sortTrain (Train*& arr, const int& sz) //вставками по колву свободных
{
    for (int i = 1; i < sz; i++)
    {
        for (int j = i; j - 1 >= 0; j--)
        {
            if (arr[j-1].seats < arr[j].seats) 
            {
                std::swap(arr[j-1], arr[j]);
            }
        }
    }

    return;
}