#ifndef BITSET_H
#define BITSET_H

#include <iostream>

class Bitset
{
    class Bitref
    {
        private:
            long long* a;
            size_t i;

        public:
            Bitref (long long* a1, size_t i1)
            {
                a = a1;
                i = i1;
            }
            ~Bitref() = default;
            bool value () const
            {
                return ((*(this->a)) & (1 << (this->i)));
            }
            void setA (long long *a1)
            {
                a = a1;
            }
            void setI (size_t i1)
            {
                i = i1;
            }
            long long* getA ()
            {
                return a;
            }
            size_t getI ()
            {
                return i;
            }
            void operator = (bool x)
            {
                if (this->value() == 0)
                    *(this->a) ^= (((1LL & x) << (this->i)));
                else
                    *(this->a) ^= (((1LL & (~x)) << (this->i)));
            }
            bool operator == (const Bitref& other) const
            {
                return (this->value() == other.value());
            }
            bool operator != (const Bitref& other) const
            {
                return (this->value() != other.value());
            }
            void operator &= (bool x)
            {
                *this = (this->value() & x);
            }
            void operator |= (bool x)
            {
                *this = (this->value() | x);
            }
            void operator ^= (bool x)
            {
                *this = (this->value() ^ x);
            }
    };

    private:
        static const size_t bl = 64;

        size_t sz = 0;
        long long* bits = nullptr;



    public:
        explicit Bitset(size_t sz1 = 1, unsigned long long x = 0);
        Bitset (const Bitset& other);
        ~Bitset();

        long long* Bits() const;

        Bitset& operator = (const Bitset& other);

        bool operator == (const Bitset& other) const;
        bool operator != (const Bitset& other) const;

        Bitset operator << (size_t pos) const;
        Bitset operator >> (size_t pos) const;
        Bitset& operator <<= (size_t pos);
        Bitset& operator >>= (size_t pos);

        Bitset operator & (const Bitset& other) const;
        Bitset operator | (const Bitset& other) const;
        Bitset operator ^ (const Bitset& other) const;
        Bitset& operator ~ ();
        Bitset& operator &= (const Bitset& other);
        Bitset& operator |= (const Bitset& other);
        Bitset& operator ^= (const Bitset& other);

        bool operator [] ( std::size_t pos) const;
        Bitref operator [] (std::size_t pos);

        bool get (size_t ind) const;
        void reset (size_t ind);
        void reset();
        void set (size_t ind);
        void set ();
        void flip (size_t ind);
        void flip ();

        bool test (size_t ind);
        bool all() const;
        bool none() const;
        bool any() const;
        size_t count () const;
        size_t size () const;

        std::string to_string () const;
        unsigned long long to_ullong () const;
        unsigned long to_ulong () const;

        friend std::ostream& operator << (std::ostream& os, const Bitset& l);
};

#endif // BITSET_H
