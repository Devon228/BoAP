#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>

class HashTable
{
    std::string *arr;
    bool *del;
    int step = 3;
    int sz;
    int num;
    int getHash (std::string s)
    {
        int h = 0;
        for (int i = 0; i < s.size(); i++)
            h = (h * 31 + (s[i] - 'a' + 1) % sz) % sz;

        //plotno -> nechetnie
        if (h % 2 == 0)
        {
            h++;
            if (h >= sz)
                h = 1;
        }

        return h;
    }


public:
    HashTable(int sz) : sz(sz)
    {
        arr = new std::string [sz];
        del = new bool [sz];
        for (int i = 0; i < sz; i++)
            del[i] = 1;

        num = 0;
    }
    ~HashTable()
    {
        delete[] arr;
        delete[] del;
        arr = nullptr;
        del = nullptr;
        sz = 0;
        std::cout << "del table";
    }

    size_t size () const
    {
        return sz;
    }

    std::string operator [] (int i)
    {
        return arr[i];
    }

    void clear()
    {
        for (size_t i = 0; i < sz; i++)
        {
            arr[i] = "";
            del[i] = 1;
        }
    }

    void resize (int newsz)
    {
        std::string *newarr = new std::string [newsz];
        bool *newdel = new bool [newsz];
        for (int i = 0; i < sz; i++)
            del[i] = 1;
        int oldsz = sz;
        sz = newsz;

        for (int i = 0; i < oldsz; i++)
        {
            if (del[i] == 0)
            {
                int hash = getHash(arr[i]);
                for (int i = 0; i < newsz; i++)
                    if (newdel[(hash+i*step)%newsz])
                    {
                        newarr[(hash+i*step)%newsz] = arr[i];
                        newdel[(hash+i*step)%newsz] = 0;
                    }
            }
        }

        delete[] arr;
        delete[] del;
        arr = newarr;
        del = newdel;
    }

    void insert (std::string s)
    {
        if (num == sz)
        {
            resize(2 * sz + 1);
        }

        int hash = getHash(s);
        std::cout << s << " " << hash << " " << sz << std::endl;

        for (int i = 0; i < sz; i++)
            if (del[(hash+i*step)%sz] == 1)
            {
                //if (s == "i")
                    //std::cout << "EEERERER" << (hash+i*step)%sz << std::endl;
                arr[(hash+i*step)%sz] = s;
                del[(hash+i*step)%sz] = 0;
                break;
            }

        num++;
    }

    void erase (std::string s)
    {
        int pos = find(s);

        if (pos != -1)
        {
            del[pos] = 1;
            num--;
        }
    }

    int find (std::string s)
    {
        int hash = getHash(s);

        for (int i = 0; i < sz; i++)
        {
            if (arr[(hash+i*step)%sz] == "")
                return -1;
            if (del[(hash+i*step)%sz] == 0 && arr[(hash+i*step)%sz] == s) //dolgo
            {
                return (hash+i*step)%sz;
            }
        }

        return -1;
    }
};

#endif // HASHTABLE_H
