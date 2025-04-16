#include "heap.h"

Heap::Heap() : sz(0)
{
    tr.resize(0);
}

void Heap::insert (ll x)
{
    tr.push_back(x);
    sz++;

    int cur = sz - 1;
    while (cur > 0)
    {
        if (tr[(cur-1)/2] < tr[cur])
        {
            std::swap(tr[(cur-1)/2], tr[cur]);
            cur = (cur - 1) / 2;
        }
        else
            break;
    }
}

ll Heap::extract ()
{
    ll result = tr[0];

    std::swap(tr[0], tr[sz-1]);
    tr.pop_back();
    sz--;

    int cur = 0;
    while (2 * cur + 1 < sz)
    {
        if (tr[cur] > tr[2*cur+1] && (2 * cur + 2 >= sz || tr[cur] > tr[2*cur+2]))
            break;
        if (2 * cur + 2 < sz)
        {
            if (tr[2*cur+1] > tr[2*cur+2])
            {
                std::swap(tr[cur], tr[2*cur+1]);
                cur = 2 * cur + 1;
            }
            else
            {
                std::swap(tr[cur], tr[2*cur+2]);
                cur = 2 * cur + 2;
            }
        }
        else
        {
            std::swap(tr[cur], tr[2*cur+1]);
            cur = 2 * cur + 1;
        }
    }

    return  result;
}
