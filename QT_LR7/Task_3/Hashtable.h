#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Deque.h"
#include <iostream>

class HashTable
{
protected:
    struct Node
    {
        int key;
        int value;
    };

    Deque <Node> *arr;
    size_t sz;
    int getHash (int x)
    {
        return x % sz;
    }


public:
    HashTable(int sz = 1) : sz(sz)
    {
        arr = new Deque <Node> [sz];
    }
    ~HashTable()
    {
        delete[] arr;
        arr = nullptr;
        sz = 0;
        std::cout << "del table";
    }

    size_t size () const
    {
        return sz;
    }

    Deque <Node>* operator [] (int i)
    {
        return &(arr[i]);
    }

    void clear()
    {
        for (size_t i = 0; i < sz; i++)
            arr[i].clear();
    }

    void insert (int x)
    {
        Deque<Node>::Iterator it1 = arr[getHash(x)].begin();
        Deque<Node>::Iterator it2 = arr[getHash(x)].end();

        for (Deque<Node>::Iterator it = it1; it != it2; it++)
            if ((*it).value == x)
                return;

        arr[getHash(x)].push_back({getHash(x), x});
    }

    void erase (int x)
    {
        Deque<Node>::Iterator it1 = arr[getHash(x)].begin();
        Deque<Node>::Iterator it2 = arr[getHash(x)].end();

        Deque <Node> temp;
        for (Deque<Node>::Iterator it = it1; it != it2; it++)
            if ((*it).value != x)
                temp.push_back(*it);

        arr[getHash(x)] = temp;
    }

    int find (int x)
    {
        Deque<Node>::Iterator it1 = arr[getHash(x)].begin();
        Deque<Node>::Iterator it2 = arr[getHash(x)].end();

        for (Deque<Node>::Iterator it = it1; it != it2; it++)
            if ((*it).value == x)
            {
                return (*it).key;
            }

        return -1;
    }
};

#endif // HASHTABLE_H
