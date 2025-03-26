#pragma once

#include <iostream>
#include <fcntl.h>
#include <cstring>

typedef long long ll;

void init(short);
void cinLong(ll& number);
void cinText(char*&);
void coutText(char*&);

long long createWords(char*& str, char**& word, char*& st, char*& fin);
long long findChain(char*& st, char*& fin, long long num, long long res[]);