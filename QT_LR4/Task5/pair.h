#ifndef PAIR_H
#define PAIR_H

#include <initializer_list>

template <typename T1, typename T2>
struct Pair
{
    T1 first;
    T2 second;

    Pair ()
    {
        this->first = T1();
        this->second = T2();
    }
    Pair (T1 a, T2 b)
    {
        this->first = a;
        this->second = b;
    }
    Pair (const Pair &other)
    {
        first = other.first;
        second = other.second;
    }
    Pair& operator= (const Pair &other)
    {
        this->first = other.first;
        this->second = other.second;
        return *this;
    }

    bool operator== (const Pair &other) const
    {
        return (this->first == other.first) && (this->second == other.second);
    }

    bool operator!= (const Pair &other) const
    {
        return (this->first != other.first) || (this->second != other.second);
    }
};

#endif // PAIR_H
