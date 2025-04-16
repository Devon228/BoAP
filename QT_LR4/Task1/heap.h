#ifndef HEAP_H
#define HEAP_H

#include <vector>
typedef long long ll;

class Heap
{
    public:
        Heap();
        ~Heap() = default;
        void insert(ll x);
        ll extract();

    private:
        std::vector <ll> tr;
        int sz;
};

#endif // HEAP_H
