#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include "iterator.h"
#include <iostream>

template <typename T>
class Vector
{
    using it = Iterator <T>;
    using r_it = Iterator <T>;
    using c_it = Iterator <const T>;

    private:
        T* arr = nullptr;
        size_t sz = 0;
        size_t cap = 0;
        const size_t MAX_SZ = 1000000;

    public:
        //explicit Vector() : arr(nullptr), sz(0), cap(0)
        Vector (T* arr1 = nullptr, size_t sz1 = 0, size_t cap1 = 0) : arr(arr1), sz(sz1), cap(cap1)
        {}
        explicit Vector(size_t n, const T& value = T())
        {
            arr = nullptr;
            cap = 0;
            sz = 0;
            reserve(n);
            sz = n;

            size_t i;
            try
            {
                for (i = 0; i < sz; i++)
                {
                    new(arr + i) T(value);
                }
            } catch(...)
            {
                for (size_t i1 = 0; i1 < i; i1++)
                    (arr + i1)->~T();
                throw;
            }
        }
        Vector(std::initializer_list<T> l)
        {
            arr = nullptr;
            cap = 0;
            sz = 0;
            reserve(l.size());
            sz = l.size();

            auto list_it = l.begin();
            size_t i;
            try
            {
                for (i = 0; i < sz; i++, list_it++)
                {
                    //T tmp = *listIt;
                    new(arr + i) T(*list_it);
                }
            } catch(...)
            {
                for (size_t i1 = 0; i1 < i; i1++)
                {
                    (arr + i1)->~T();
                }
            }
        }
        Vector (const Vector& other)
        {
            arr = nullptr;
            cap = 0;
            sz = 0;
            reserve(other.size());
            sz = other.size();

            size_t i;
            try
            {
                for (i = 0; i < sz; i++)
                    new(arr + i) T(other[i]);
            } catch(...)
            {
                for (size_t i1 = 0; i1 < i; i1++)
                    (arr + i1)->~T();
                throw;
            }
        }
        Vector& operator= (const Vector& other)
        {
            arr = nullptr;
            cap = 0;
            sz = 0;
            reserve(other.size());
            sz = other.size();

            size_t i;
            try
            {
                for (i = 0; i < sz; i++)
                    new(arr + i) T(other[i]);
            } catch(...)
            {
                for (size_t i1 = 0; i1 < i; i1++)
                    (arr + i1)->~T();
                throw;
            }

            return *this;
        }

        ~Vector()
        {
            for (int i = 0; i < sz; i++)
                (arr + i)->~T();
            delete[] reinterpret_cast<char*>(arr);

            arr = nullptr;
            sz = 0;
            cap = 0;
        }


        it begin()
        {
            return it(arr);
        }
        it end()
        {
            return it(arr + sz);
        }
        r_it rbegin()
        {
            if (sz == 0)
                return nullptr;
            return it(arr + sz - 1);
        }
        r_it rend()
        {
            if (sz == 0)
                return nullptr;
            return it(arr - 1);
        }
        c_it cbegin()
        {
            return c_it(arr);
        }
        c_it cend()
        {
            return c_it(arr + sz);
        }


        T* data() //sz 0  nullptr?
        {
            return arr;
        }
        T& front() const
        {
            if (sz == 0)
                throw "out of range (zero vector front)";

            return arr[0];
        }
        T& back() const
        {
            if (sz == 0)
                throw "out of range (zero vector back)";

            return arr[sz-1];
        }
        T& at (size_t pos) const
        {
            if (pos >= sz || pos < 0)
                throw "out of range";

            return arr[pos];
        }
        T& operator[] (size_t pos) const
        {
            if (pos >= sz || pos < 0)
                throw "out of range";
            return arr[pos];
        }


        inline bool empty() const
        {
            return (sz == 0);
        }
        void assign (size_t count, const T& value)
        {
            clear();
            resize(count, value);
        }
        void resize (size_t sz1)
        {
            if (sz == sz1)
                return;

            if (cap < sz1)
                reserve(sz1);
            if (sz < sz1)
            {
                size_t i;
                try
                {
                    for (i = sz; i < sz1; i++)
                        new(arr + i) T();
                } catch(...) {
                    for (size_t i1 = sz; i1 < i; i++)
                        (arr + i1)->~T();
                    throw;
                }
            }
            else
            {
                for (size_t i = sz1; i < sz; i++)
                    (arr + i)->~T();
            }

            sz = sz1;
        }
        void resize(size_t sz1, const T& value)
        {
            if (sz == sz1)
                return;

            if (cap < sz1)
                reserve(sz1);
            if (sz < sz1)
            {
                size_t i;
                try
                {
                    for (i = sz; i < sz1; i++)
                        new(arr + i) T(value);
                } catch(...) {
                    for (size_t i1 = sz; i1 < i; i++)
                        (arr + i1)->~T();
                    throw;
                }
            }
            else
            {
                for (size_t i = sz1; i < sz; i++)
                    (arr + i)->~T();
            }

            sz = sz1;
        }


        inline size_t max_size() const
        {
            return MAX_SZ;
        }
        inline size_t size() const
        {
            return sz;
        }
        inline size_t capacity () const
        {
            return cap;
        }


        void reserve(size_t cap1)
        {
            if (cap >= cap1)
                return;

            T* arr1 = reinterpret_cast<T*>(new char[cap1 * sizeof(T)]); //bad_alloc
            size_t i = 0;
            try
            {
                for (i; i < sz; i++)
                    new(arr1 + i) T(arr[i]);
            } catch(...) {
                for (size_t i1 = 0; i1 < i; i++)
                    (arr + i1)->~T();
                delete[] reinterpret_cast<char*>(arr);
                throw;
            }

            for (size_t i = 0; i < sz; i++)
                (arr + i)->~T();
            delete[] reinterpret_cast<char*>(arr);

            arr = arr1;
            cap = cap1;
        }
        void clear()
        {
            resize(0);
        }


        template <typename ... Args>
        void emplace(c_it pos, Args&& ... args) //throw
        {
            if (pos - cbegin() >= sz || pos - cbegin() < 0)
                throw "out of range";

            T val(args...);
            insert(pos, val);
        }
        template <typename ... Args>
        void emplace_back(Args&& ... args) //throw
        {
            T val(args...);
            push_back(val);
        }
        void insert (c_it pos, const T& value)
        {
            int ind = pos - cbegin();

            if (ind > sz || ind < 0)
                throw "out of range";

            if (sz == cap)
                reserve(cap == 0 ? 1 : 2 * cap);

            size_t i;
            try
            {
                for (i = sz; i >= ind + 1; i--)
                {
                    new(arr + i) T(arr[i-1]);
                }
                new(arr + ind) T(value);
            }
            catch(...) {
                for (size_t i1 = sz; i1 >= i; i1--)
                    (arr + i1)->~T();
                throw;
            }

            sz++;
        }
        void insert(c_it pos, size_t count, const T& value)
        {
            int ind = pos - cbegin();

            if (ind > sz || ind < 0)
                throw "out of range";

            while (sz + count >= cap)
                reserve(cap == 0 ? 1 : 2 * cap);

            size_t i;
            try
            {
                for (i = sz + count - 1; i >= ind + count; i--)
                {
                    new(arr + i) T(arr[i-count]);
                }
                for (i = ind; i < ind + count; i++)
                {
                    new(arr + i) T(value);
                }
            } catch(...) {
                for (size_t i1 = sz + count - 1; i1 >= i; i1--)
                    (arr + i1)->~T();
                throw;
            }

            sz += count;
        }
        void push_back(const T& value)
        {
            std::cout << 1 << std::endl;
            if (sz == cap)
                reserve(cap == 0 ? 1 : 2 * cap);
            std::cout << 1 << std::endl;
            new(arr + sz) T(value);
            std::cout << 1 << std::endl;
            sz++;
        }
        void erase(c_it pos)
        {
            int ind = pos - cbegin();

            if (ind >= sz || ind < 0) //sz = 0 => "out of range"
                throw "out of range";

            size_t i;
            try
            {
                for (i = ind; i < sz - 1; i++)
                {
                    new(arr + i) T(arr[i+1]);
                }
            }
            catch(...) {
                for (size_t i1 = ind; i1 <= i; i1++)
                    (arr + i1)->~T();
                throw;
            }

            sz--;
            resize(sz);
        }
        void erase(c_it first, c_it last)
        {
            int firsti = first - cbegin();
            int lasti = last - cbegin();

            if (firsti >= sz || firsti < 0 || lasti >= sz || lasti < 0 || firsti > lasti) //sz = 0 => "out of range"
                throw "out of range";

            size_t i;
            try
            {
                for (i = firsti; lasti + 1 + i - firsti < sz; i++)
                {
                    new(arr + i) T(arr[lasti+1+i-firsti]);
                }
            }
            catch(...) {
                for (size_t i1 = firsti; i1 <= i; i1++)
                    (arr + i1)->~T();
                throw;
            }

            sz -= (lasti - firsti + 1);
            resize(sz);
        }
        void pop_back()
        {
            if (sz == 0)
                throw "out of range (pop_back from zero vector)";

            sz--;
            resize(sz);
        }


        void swap(Vector &right)
        {
            T* tmparr = arr;
            size_t tmpsz = sz;
            size_t tmpcap = cap;

            arr = right.data();
            sz = right.size();
            cap = right.capacity();

            right.arr = tmparr;
            right.sz = tmpsz;
            right.cap = tmpcap;
        }

};

#endif // VECTOR_H
