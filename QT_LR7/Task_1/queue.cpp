nclude "queue.h"

Bitset::Bitset(size_t sz1, unsigned long long x)
{
    sz = sz1;
    bits = new unsigned long long[sz/bl+1];

    for (int i = 0; i < sz / bl + 1; i++)
        bits[i] = 0;

    for (int i = 0; i < std::min(sz, (size_t)63); i++)
        bits[0] |= (x & (1ULL << i));
}
Bitset::Bitset (const Bitset& other)
{
    *this = other;
}
Bitset::~Bitset()
{
    delete[] bits;
    bits = nullptr;
    sz = 0;
}

unsigned long long* Bitset::Bits() const
{
    return this->bits;
}

Bitset& Bitset::operator = (const Bitset& other) //*this == other - ?
{
    unsigned long long* copy = new unsigned long long[sz/bl+1];
    for (int i = 0; i < sz / bl + 1; i++)
        copy[i] = other.Bits()[i];

    sz = other.sz;
    delete[] bits;
    bits = new unsigned long long[sz/bl+1];

    for (int i = 0; i < sz / bl + 1; i++)
        bits[i] = 0;

    /*for (int i = 0; i < sz; i++)
        (*this)[i] = other[i]; */
    for (int i = 0; i < sz / bl + 1; i++)
        bits[i] = copy[i]; //?

    delete[] copy;

    return (*this);
}

bool Bitset::operator == (const Bitset& other) const //N/64
{
    if (sz != other.sz)
        return 0;

    /*for (int i = 0; i < sz; i++)
        if ((*this)[i] != other[i])
            return 0;*/

    for (int i = 0; i < sz / bl + 1; i++)
        if (bits[i] != other.Bits()[i])
            return 0;


    return 1;
}
bool Bitset::operator != (const Bitset& other) const //N/64
{
    bool eq = (*this == other);
    return (eq ^ 1);
}

Bitset Bitset::operator << (size_t pos) const //N
{
    Bitset res;
    res = *this;
    res <<= pos;

    return res;
}
Bitset Bitset::operator >> (size_t pos) const //N
{
    Bitset res;
    res = *this;
    res >>= pos;

    return res;
}
Bitset& Bitset::operator <<= (size_t pos) //N
{
    if (pos < 0)
        throw "wrong << argument";

    for (int i = sz - 1; i >= pos; i--)
        (*this)[i] = (*this)[i-pos];
    for (int i = 0; i < pos; i++)
        (*this)[i] = 0;

    return *this;
}
Bitset& Bitset::operator >>= (size_t pos) //N
{
    if (pos < 0)
        throw "wrong >> argument";

    for (int i = 0; i < sz - pos; i++)
        (*this)[i] = (*this)[i+pos];
    for (int i = sz - pos; i < sz; i++)
        (*this)[i] = 0;

    return *this;
}

Bitset Bitset::operator & (const Bitset& other) const //N/64
{
    Bitset res(*this);
    res &= other;

    return res;
}
Bitset Bitset::operator | (const Bitset& other) const //N/64
{
    Bitset res(*this);
    res |= other;

    return res;
}
Bitset Bitset::operator ^ (const Bitset& other) const //N/64
{
    Bitset res(*this);
    res ^= other;

    return res;
}
Bitset& Bitset::operator ~ () //N/64
{
    for (int i = 0; i < sz / bl; i++)
        bits[i] ^= ALL1;
    bits[sz/bl] ^= (1ull << (sz % bl)) - 1;
    return *this;
}
Bitset& Bitset::operator &= (const Bitset& other)
{
    /*
    for (int i = 0; i < std::min(sz, other.size()); i++)
        (*this)[i] &= other[i];
    if (sz > other.size())
    {
        for (int i = other.size(); i < sz; i++)
            (*this)[i] &= 0;
    }*/

    for (int i = 0; i < std::min(sz, other.size()) / bl + 1; i++)
        bits[i] &= other.Bits()[i];
    if (sz > other.size())
    {
        for (int i = std::min(sz, other.size()) / bl + 1; i < sz / bl + 1; i++)
            bits[i] = 0;
    }
    bits[sz/bl] &= (1ull << (sz % bl)) - 1;

    return *this;
}
Bitset& Bitset::operator |= (const Bitset& other)
{
    for (int i = 0; i < std::min(sz, other.size()) / bl + 1; i++)
        bits[i] |= other.Bits()[i];
    bits[sz/bl] &= (1ull << (sz % bl)) - 1;

    return *this;
}
Bitset& Bitset::operator ^= (const Bitset& other)
{
    for (int i = 0; i < std::min(sz, other.size()) / bl + 1; i++)
        bits[i] ^= other.Bits()[i];
    bits[sz/bl] &= (1ull << (sz % bl)) - 1;

    return *this;
}

bool Bitset::operator [] ( std::size_t pos) const //main
{
    if (pos < 0 || pos >= sz)
        throw "out of range";

    //std::cout << bits[pos/bl] << "l;";
    return ((bits[pos/bl] >> (pos % bl)) & 1ull);
}
Bitset::Bitref Bitset::operator [] (std::size_t pos) //main
{
    //std::cout << bits[pos/bl] << "r;";
    if (pos < 0 || pos >= sz)
        throw "out of range";

    return Bitref(&bits[pos/bl], pos%bl);
}

bool Bitset::get (size_t ind) const
{
    return (*this)[ind];
}
void Bitset::reset (size_t ind)
{
    (*this)[ind] = 0;
}
void Bitset::reset ()
{
    for (int i = 0; i < sz/ bl + 1; i++)
        bits[i] = 0;
}
void Bitset::set (size_t ind)
{
    (*this)[ind] = 1;
}
void Bitset::set ()
{
    for (int i = 0; i < sz / bl; i++)
        bits[i] = ALL1;
    bits[sz/bl] = (1ull << (sz % bl)) - 1;
}
void Bitset::flip (size_t ind)
{
    (*this)[ind] ^= 1;
}
void Bitset::flip ()
{
    for (int i = 0; i < sz / bl; i++)
        bits[i] ^= ALL1;
    bits[sz/bl] ^= (1ull << (sz % bl)) - 1;
}

bool Bitset::test (size_t ind)
{
    return (*this)[ind].value();
}
bool Bitset::all() const
{
    return (count() == sz);
}
bool Bitset::none() const
{
    return (count() == 0);
}
bool Bitset::any() const
{
    return (count() > 0);
}
size_t Bitset::count () const
{
    size_t res = 0;
    for (int i = 0; i < sz / bl + 1; i++)
    {
        res += __builtin_popcountll(bits[i]);
    }

    return res;
}
size_t Bitset::size () const
{
    return sz;
}

std::string Bitset::to_string () const
{
    std::string str = "";
    for (int i = 0; i < sz; i++)
        str = char((*this)[i] + '0') + str; //?

    return str;
}
unsigned long long Bitset::to_ullong () const
{
    return bits[0]; //?
}
unsigned long Bitset::to_ulong () const
{
    unsigned long res = 0;
    for (int i = 0; i < std::min(bl/2, sz); i++)
        res |= ((1ull & (*this)[i]) << i);

    return res;
}

std::ostream& operator << (std::ostream& os, const Bitset& l)
{
    std::string res = l.to_string();
    os << res;
    return os;
}
