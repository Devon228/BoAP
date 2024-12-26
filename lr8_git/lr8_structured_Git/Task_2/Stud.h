struct Stud
{
    int n;

    char fio[255];

    union gr
    {
        int i;
        long long l;
    } gr;
    
    double mark;

    double wage;
};
typedef struct Stud Stud;
