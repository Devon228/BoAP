#ifndef SORT_H
#define SORT_H

#include <ctime>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <QTableWidget>
#include <QString>
#include "heap.h"
typedef long long ll;

class Sort
{
    public:
        Sort();
        ~Sort();
        static double HeapSort(int sz, std::vector <ll> &arr);
        static double QuickSort(int sz, std::vector <ll> &arr);
        static double MergeSort(int sz, std::vector <ll> &arr);
        static double InterpolationSort(int sz, std::vector <ll> &arr, bool out, QTableWidget *w);
        static int BinSearch(int sz, std::vector <ll> &arr, ll digit);
        static ll BinPow(ll digit, ll powder, ll mod);

    private:
        static void heapSort(int sz, std::vector <ll> &arr);
        static void quickSort(int l, int r, std::vector <ll> &arr);
        static void mergeSort(int l, int r, std::vector <ll> &arr, std::vector <ll> &bufarr);
};

#endif // SORT_H
