#pragma once

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <fstream>

typedef int ll;


struct Stud
{
    int n;

    char fio[255];

    union gr
    {
        ll i;
        long long l;
    } gr;
    
    double mark;

    double wage;
};
typedef struct Person Person;


void cinLong(ll& number);
void cinDouble(double& number);

void showMenu();

void cinText (char*, int);
bool inputOne (Stud&, int);
void input(Stud*&, int&);

void outputOne (Stud&);
void outputAll(Stud*&, const int&);
void outputOrder(Stud*&, const int&, const double&);

void add(Stud*&, int &);

void deleteS(Stud*&, int&);

void change(Stud*&, const int&);

void writeFile (Stud*&, int, const std::string);

//void sortTrain (Train*&, const int&);

//void writeTrainFile (Train &, std::ofstream &);




