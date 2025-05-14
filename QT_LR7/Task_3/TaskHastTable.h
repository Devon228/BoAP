#ifndef TASKHASTTABLE_H
#define TASKHASTTABLE_H

#include "Hashtable.h"
#include <random>
#include <ctime>



class TaskHashTable : public HashTable
{
public:
    TaskHashTable(int sz) : HashTable(sz)
    {

    }

    ~TaskHashTable()
    { }

    void rndTable ()
    {
        std::mt19937 myrnd((int)std::time(0));
        clear();
        for (size_t i = 0; i < sz; i++)
        {
            insert(myrnd() % 1000000000);
        }
    }

    int maxKeyValue()
    {
        int ans = 0;

        for (size_t i = 0; i < sz; i++)
            if (arr[i].size())
                ans = arr[i].front().value;

        return ans;
    }
};

#endif // TASKHASTTABLE_H
