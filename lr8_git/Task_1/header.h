#pragma once

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <fstream>

typedef int ll;

struct Time
{
    ll hh, mm, tim;
};
typedef struct Time Time;

struct Train
{
    union num
    {
        ll n32;
        int n64;
    } n;

    char *type;
    Time start;
    Time arrive;

    char* place;

    ll seats;
};
typedef struct Train Train;

void cinLong(ll& number);

void showMenu();

void cinTime (Train&);
void cinText (char*&, int);
bool inputOne (Train&, int);
void inputTrain(Train*&, int&);

void outputOne (Train &);
void outputTrainAll(Train*&, const int&);
void outTrainToPlace(Train*&, const int&);

void addTrain(Train*&, int &);

void searchFieldTrain(Train*&, const int&);

void deleteTrain(Train*&, int&, std::string);

void changeTrain(Train*&, const int&, std::string);

void sortTrain (Train*&, const int&);

void writeTrainFile (Train &, std::ofstream &);
void writeFile (Train*&, int,  int, const std::string);

void loadFile(std::string, Train*&, int&);

