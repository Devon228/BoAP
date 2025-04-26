#ifndef ITERATOR_H
#define ITERATOR_H

#include <stddef.h>

template <typename T>
class Iterator
{
private:
    T* it;

public:
    explicit Iterator() : it(nullptr)
    {}
    explicit Iterator (T* cur) : it(cur)
    {}
    //explicit Iterator (const Iterator& old) : it(old->it)
    //{}
    ~Iterator() = default;

    Iterator& operator += (int n)
    {
        this->it += n;
        return *this;
    }
    Iterator operator + (int n) const
    {
        Iterator newit(this->it + n);
        return newit;
    }
    Iterator& operator ++ ()
    {
        this->it++;
        return *this;
    }
    Iterator operator ++ (int)
    {
        Iterator copy(this->it);
        this->it++;
        return copy;
    }

    Iterator& operator -= (int n)
    {
        this->it -= n;
        return *this;
    }
    Iterator operator - (int n) const
    {
        Iterator newit(this->it - n);
        return newit;
    }
    Iterator& operator -- ()
    {
        this->it--;
        return *this;
    }
    Iterator operator -- (int)
    {
        Iterator copy(this->it);
        this->it--;
        return copy;
    }

    ptrdiff_t operator - (const Iterator& right) const
    {
        return (this->it - right.operator->());
    }

    T* operator -> () const //???????????????????????????????????
    {
        return this->it;
    }
    T operator * () const
    {
        return *(this->it);
    }

    bool operator == (const Iterator& right) const
    {
        return (this->operator->() == right.operator->());
    }
    bool operator != (const Iterator& right) const
    {
        return (this->operator->() != right.operator->());
    }
    bool operator < (const Iterator& right) const
    {
        return (this->operator->() < right.operator->());
    }
    bool operator > (const Iterator& right) const
    {
        return (this->operator->() > right.operator->());
    }
    bool operator <= (const Iterator& right) const
    {
        return (this->operator->() <= right.operator->());
    }
    bool operator >= (const Iterator& right) const
    {
        return (this->operator->() >= right.operator->());
    }

    Iterator operator [] (int n) const
    {
        return this->it[n];
    }

};

#endif // ITERATOR_H
