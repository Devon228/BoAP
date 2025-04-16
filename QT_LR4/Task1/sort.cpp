#include "sort.h"

Sort::Sort()
{

}
Sort::~Sort()
{

}

double Sort::HeapSort(int sz, std::vector <ll> &arr)
{
    clock_t start = clock();

    heapSort(sz, arr);
    clock_t finish = clock();

    return (double)(finish - start) / CLOCKS_PER_SEC;
}
void Sort::heapSort(int sz, std::vector <ll> &arr)
{
    Heap heap;
    for (int i  = 0; i < sz; i++)
        heap.insert(arr[i]);
    for (int i = sz - 1; i >= 0; i--)
        arr[i] = heap.extract();
}


double Sort::QuickSort(int sz, std::vector <ll> &arr)
{
    clock_t start = clock();

    quickSort(0, sz, arr);

    clock_t finish = clock();

    return (double)(finish - start) / CLOCKS_PER_SEC;
}
void Sort::quickSort(int l, int r, std::vector <ll> &arr)
{
    if (l >= r - 1)
        return;

    int m = arr[(l + r)/2];

    int i = l, j = r - 1;
    while (i <= j)
    {
        while (arr[i] < m)
            i++;
        while (m < arr[j])
            j--;
        if (i >= j)
            break;
        std::swap(arr[i++], arr[j--]);
    }

    quickSort(l, i, arr);
    quickSort(i, r, arr);
}

double Sort::MergeSort(int sz, std::vector <ll> &arr)
{
    clock_t start = clock();

    std::vector <ll> bufarr(sz);
    mergeSort(0, sz, arr, bufarr);

    clock_t finish = clock();

    return (double)(finish - start) / CLOCKS_PER_SEC;
}
void Sort::mergeSort(int l, int r, std::vector <ll> &arr, std::vector <ll> &bufarr)
{
    if (l >= r - 1)
        return;

    int m = (l + r) / 2;
    mergeSort(l, m, arr, bufarr);
    mergeSort(m, r, arr, bufarr);

    int i = l, j = m;
    while (i < m || j < r)
    {
        if (i < m && j < r)
        {
            if (arr[i] < arr[j])
                bufarr[l+i+j-l-m-1] = arr[i++];
            else
                bufarr[l+i+j-l-m-1] = arr[j++];
        }
        else if (i < m)
        {
            bufarr[l+i+j-l-m-1] = arr[i++];
        }
        else if (j < r)
        {
            bufarr[l+i+j-l-m-1] = arr[j++];
        }
    }
    for (int i = l; i < r; i++)
        arr[i] = bufarr[i];
}

double Sort::InterpolationSort(int sz, std::vector <ll> &arr, bool out, QTableWidget *w)
{
    clock_t start = clock();

    std::stack <int> partitionSz;
    partitionSz.push(sz);
    int end = sz - 1;
    if (out)
    {
        while (w->columnCount())
            w->removeColumn(w->columnCount()-1);
        while (w->rowCount())
            w->removeRow(w->rowCount()-1);
        for (int i = 0; i < sz; i++)
            w->insertColumn(i);
    }
    while (!partitionSz.empty())
    {
        if (out)
        {
            w->insertRow(w->rowCount());
            for (int i = 0; i < sz; i++)
            {
                w->setItem(w->rowCount()-1, i, new QTableWidgetItem(QString::number(arr[i])));
            }
        }

        int partitionCurSz = partitionSz.top();
        partitionSz.pop();
        int begin = end - partitionCurSz + 1;

        //std::cout << begin << " " << end << "\n";

        ll mn = 1e18 + 1, mx = -1e18 + 1;
        for (int i = begin; i <= end; i++)
        {
            mn = std::min(mn, arr[i]);
            mx = std::max(mx, arr[i]);
        }

        if (mx - mn == 0)
        {
            end = begin - 1;
            continue;
        }
        else
        {
            std::vector <std::vector <ll> > bucket(partitionCurSz);
            for (int i = begin; i <= end; i++)
            {
                int bucketNum = (double(arr[i] - mn) / double(mx - mn)) * double(partitionCurSz - 1);
                bucket[bucketNum].push_back(arr[i]);
            }
            for (auto curBucket :  bucket)
            {
                if (curBucket.size() > 0)
                {
                    for (auto now : curBucket)
                        arr[begin++] = now;
                    partitionSz.push(curBucket.size());
                }
            }
        }
    }

    clock_t finish = clock();

    return (double)(finish - start) / CLOCKS_PER_SEC;
}

int Sort::BinSearch(int sz, std::vector <ll> &arr, ll digit)
{
    ll l = -1, r = sz, m;

    while (r - l > 1)
    {
        m = (l + r) / 2;
        if (arr[m] >= digit)
            r = m;
        else
            l = m;
    }

    if (0 <= r && r < sz && arr[r] == digit)
        return r;
    else
        return -1;
}

ll Sort::BinPow(ll digit, ll powder, ll mod)
{
    if (powder == 0)
        return (1 % mod);
    if (powder == 1)
        return (digit % mod);

    if (powder & 1)
        return ((digit % mod) * BinPow(digit, powder - 1, mod)) % mod;
    else
    {
        ll pw2 = BinPow(digit, powder / 2, mod);
        return (pw2 * pw2) % mod;
    }
}
