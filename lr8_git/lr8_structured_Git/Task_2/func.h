#pragma once

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <fstream>

#include "Stud.h"

typedef int ll;

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




