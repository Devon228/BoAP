#include "mystring.h"

MyString::MyString() : arr(nullptr), sz(0), cap(0)
{}
MyString::MyString (std::unique_ptr<char[]> arr1, size_t sz1, size_t cap1) : sz(sz1), cap(cap1)
{
    arr = std::move(arr1);
}
MyString::MyString(size_t n, const char& value)
{
    arr = nullptr;
    cap = 0;
    sz = 0;
    reserve(n);
    sz = n;

    size_t i;
    for (i = 0; i < sz; i++)
    {
        arr[i] = value;
    }
}
MyString::MyString(std::initializer_list<char> l)
{
    arr = nullptr;
    cap = 0;
    sz = 0;
    reserve(l.size());
    sz = l.size();

    auto list_it = l.begin();
    size_t i;
    for (i = 0; i < sz; i++, list_it++)
    {
        //T tmp = *listIt;
        arr[i] = *list_it;
    }
}
MyString::MyString (const MyString& other)
{
    arr = nullptr;
    cap = 0;
    sz = other.size();
    reserve(sz);


    size_t i;
    for (i = 0; i < sz; i++)
        arr[i] = other[i];
}
MyString::MyString (const std::string& other)
{
    arr = nullptr;
    cap = 0;
    sz = 0;
    reserve(other.size());
    sz = other.size();

    size_t i;
    for (i = 0; i < sz; i++)
        arr[i] = other[i];
}

MyString& MyString::operator= (const MyString& other)
{
    arr = nullptr;
    cap = 0;
    sz = 0;
    reserve(other.size());
    sz = other.size();

    size_t i;
    for (i = 0; i < sz; i++)
        arr[i] = other[i];

    return *this;
}

MyString::it MyString::begin()
{
    return it(arr.get());
}
MyString::it MyString::end()
{
    return it(arr.get() + sz);
}
MyString::r_it MyString::rbegin()
{
    if (sz == 0)
        return Iterator<char>();
    return it(arr.get() + sz - 1);
}
MyString::r_it MyString::rend()
{
    if (sz == 0)
        return Iterator<char>();
    return it(arr.get() - 1);
}
MyString::c_it MyString::cbegin()
{
    return c_it(arr.get());
}
MyString::c_it MyString::cend()
{
    return c_it(arr.get() + sz);
}

char* MyString::c_str() //sz 0  nullptr?
{
    return arr.get();
}
char& MyString::front() const
{
    if (sz == 0)
        throw "out of range (zero MyString front)";

    return arr[0];
}
char& MyString::back() const
{
    if (sz == 0)
        throw "out of range (zero MyString back)";

    return arr[sz-1];
}
char& MyString::at (size_t pos) const
{
    if (pos >= sz || pos < 0)
        throw "out of range";

    return arr[pos];
}
char& MyString::operator[] (size_t pos) const
{
    if (pos >= sz || pos < 0)
        throw "out of range";
    return arr[pos];
}


inline bool MyString::empty() const
{
    return (sz == 0);
}
void MyString::assign (size_t count, const char& value)
{
    clear();
    resize(count, value);
}
void MyString::resize (size_t sz1)
{
    if (sz == sz1)
        return;

    if (cap < sz1)
        reserve(sz1);
    if (sz < sz1)
    {
        size_t i;
        for (i = sz; i < sz1; i++)
            arr[i] = ' ';
    }
    else
    {
        //for (size_t i = sz1; i < sz; i++)
            //(arr + i)->~char();
    }

    sz = sz1;
}
void MyString::resize(size_t sz1, const char& value)
{
    if (sz == sz1)
        return;

    if (cap < sz1)
        reserve(sz1);
    if (sz < sz1)
    {
        size_t i;
        for (i = sz; i < sz1; i++)
            arr[i] = value;
    }
    else
    {
        //for (size_t i = sz1; i < sz; i++)
            //(arr + i)->~T();
    }

    sz = sz1;
}


inline size_t MyString::max_size() const
{
    return MAX_SZ;
}
inline size_t MyString::size() const
{
    return sz;
}
inline size_t MyString::length() const
{
    return sz;
}
inline size_t MyString::capacity () const
{
    return cap;
}

void MyString::reserve(size_t cap1)
{
    if (cap > MAX_SZ)
        throw "out of max_size";

    if (cap >= cap1)
        return;

    std::unique_ptr <char[]> arr1 = std::make_unique<char[]>(cap); //bad_alloc
    size_t i = 0;
    for (i; i < sz; i++)
        arr1[i] = arr[i];

    arr.reset();

    arr = std::move(arr1);
    cap = cap1;
}
void MyString::clear()
{
    resize(0);
}


void MyString::insert (c_it pos, const char& value)
{
    int ind = pos - cbegin();

    if (ind > sz || ind < 0)
        throw "out of range";

    if (sz == cap)
        reserve(cap == 0 ? 1 : 2 * cap);

    size_t i;
    for (i = sz; i >= ind + 1; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[ind] = value;


    sz++;
}
void MyString::insert(c_it pos, size_t count, const char& value)
{
    int ind = pos - cbegin();

    if (count == 0)
        return;
    if (ind > sz || ind < 0)
        throw "out of range";

    while (sz + count >= cap)
        reserve(cap == 0 ? 1 : 2 * cap);

    size_t i;

    for (i = sz + count - 1; i >= ind + count; i--)
    {
        arr[i] = arr[i-count];
    }
    for (i = ind; i < ind + count; i++)
    {
        arr[i] = value;
    }


    sz += count;
}
void MyString::push_back(const char& value)
{
    if (sz == cap)
        reserve(cap == 0 ? 1 : 2 * cap);

    arr[sz] = value;
    sz++;
}
void MyString::erase(c_it pos)
{
    int ind = pos - cbegin();

    if (ind >= sz || ind < 0) //sz = 0 => "out of range"
        throw "out of range";

    size_t i;
    for (i = ind; i < sz - 1; i++)
    {
        arr[i] = arr[i+1];
    }

    sz--;
    resize(sz);
}
void MyString::erase(c_it first, c_it last)
{
    int firsti = first - cbegin();
    int lasti = last - cbegin();

    if (firsti >= sz || firsti < 0 || lasti >= sz || lasti < 0 || firsti > lasti) //sz = 0 => "out of range"
        throw "out of range";

    size_t i;
    for (i = firsti; lasti + 1 + i - firsti < sz; i++)
    {
        arr[i] = arr[lasti+1+i-firsti];
    }

    sz -= (lasti - firsti + 1);
    resize(sz);
}
void MyString::pop_back()
{
    if (sz == 0)
        throw "out of range (pop_back from zero MyString)";

    sz--;
    resize(sz);
}


/*void MyString::swap(MyString &right)
{
    char* tmparr = c_str(); //unique_ptr = char*
    size_t tmpsz = sz;
    size_t tmpcap = cap;

    arr = right.c_str();
    sz = right.size();
    cap = right.capacity();

    right.arr = tmparr;
    right.sz = tmpsz;
    right.cap = tmpcap;
}*/

MyString MyString::substr(size_t l, size_t r) const
{
    if (l < 0 || this->size() <= l || r < 0 || this->size() <= r || l > r)
        throw "out of range";
    MyString res(r-l+1, ' ');
    for (size_t i = l; i <= r; i++)
        res[i-l] = at(i);

    return res;
}
int MyString::compare (const MyString& x) const
{
    for (int i = 0; i < std::min(size(), x.size()); i++)
    {
        if ((*this)[i] < x[i])
            return -1;
        if ((*this)[i] > x[i])
            return 1;
    }

    return 0;
}
size_t MyString::find (const MyString &x) const
{
    if (x.size() > size())
        return -1;

    for (int i = 0; i < size() - x.size() + 1; i++)
    {
        bool f = 1;
        for (int j = 0; j < x.size(); j++)
            if ((*this)[i+j] != x[j])
            {
                f = 0;
                break;
            }

        if (f)
            return i;
    }

    return -1;
}
MyString& MyString::operator += (const MyString &x)
{
    append(x);

    return *this;
}
void MyString::append (const MyString& x)
{
    while (sz + x.size() > cap)
        reserve(cap == 0 ? 1 : 2 * cap);

    for (int i = sz; i < sz + x.size(); i++)
        arr[i] = x[i-sz];
    sz += x.size();
}

void* MyCstr::memcpy(void* s1, const void* s2, size_t n)
{
    auto p1 = static_cast<unsigned char*>(s1);
    auto p2 = static_cast<const unsigned char*>(s2);

    for (size_t i = 0; i < n; i++)
    {
        p1[i] = p2[i];
    }

    return s1;
}
void* MyCstr::memmove(void* s1, const void* s2, size_t n)
{
    auto p2 = static_cast<unsigned char *>(s1);
    auto p1 = static_cast<const unsigned char *>(s2);

    if (p2 < p1)
    {
        for (size_t i = 0; i < n; i++)
        {
            p2[i] = p1[i];
        }
    }
    else if (p1 < p2)
    {
        for (size_t i = n - 1; i >= 0; i--)
        {
            p2[i] = p1[i];
        }
    }

    return s1;
}
char* MyCstr::strcpy(char* s1, const char* s2)
{
    for (size_t i = 0; s2[i] != '\0'; i++)
    {
        s1[i] = s2[i];
    }

    return s1;
}
char* MyCstr::strncpy(char* s1, const char* s2, size_t n)
{
    for (size_t i = 0; s2[i] != '\0' && i < n; i++)
    {
        s1[i] = s2[i];
    }

    return s1;
}
char* MyCstr::strcat(char* s1, const char* s2)
{
    char* temp = s1;
    while ((*s1) != '\0') s1++;

    for (size_t i = 0; s2[i] != '\0'; i++)
        s1[i] = s2[i];

    return temp;
}
char* MyCstr::strncat(char* s1, const char* s2, size_t n)
{
    char* temp = s1;
    while ((*s1) != '\0') s1++;

    for (size_t i = 0; s2[i] != '\0' && i < n; i++)
        s1[i] = s2[i];

    return temp;
}
int MyCstr::memcmp(const void* s1, const void* s2, size_t n)
{
    auto p1 = static_cast<const unsigned char *>(s1);
    auto p2 = static_cast<const unsigned char *>(s2);


    for (size_t i = 0; p1[i] != '\0' && p2[i] != '\0' && i < n; i++)
    {
        if (*p1 > *p2)
            return 1;
        if (*p1 < *p2)
            return -1;
    }

    return 0;
}
int MyCstr::strcmp(const char* s1, const char* s2) noexcept
{
    for (size_t i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
    {
        if (*s1 > *s2)
            return 1;
        if (*s1 < *s2)
            return -1;
    }

    return 0;
}
int MyCstr::strncmp(const char* s1, const char* s2, size_t n) noexcept
{
    for (size_t i = 0; s1[i] != '\0' && s2[i] != '\0' && i < n; i++)
    {
        if (*s1 > *s2)
            return 1;
        if (*s1 < *s2)
            return -1;
    }

    return 0;
}
size_t MyCstr::strcspn(const char* s1, const char* s2)
{
    size_t i;
    for (i = 0; s1[i] != '\0'; i++)
    {
        for (size_t j = 0; s1[j] != '\0'; j++)
            if (s1[i] == s2[j])
                return i;
    }

    return i;
}
void* MyCstr::memset(void* s, int c, size_t n)
{
    auto p = static_cast<unsigned char *>(s);

    for (size_t i = 0; i , n; i++)
        p[i] = c;
}
size_t MyCstr::strlen(const char* s)
{
    int k = 0;
    while ((*s) != '\0')
    {
        s++;
        k++;
    }

    return k;
}

char* MyCstr::strerror(int errnum)
{
    char *p = new char[9];

    int tmp = errnum, k = 0;
    while (errnum > 0)
    {
        k++;
        errnum /= 10;
    }
    errnum = tmp;
    while (errnum > 0)
    {
        k--;
        p[k] = ('0' + errnum % 10);
        errnum /= 10;
    }

    return p;
}
int MyCstr::strcoll(const char* s1, const char* s2)
{
    return MyCstr::strcmp(s1, s2);
}
size_t MyCstr::strxfrm(char* s1, const char* s2, size_t n)
{
    MyCstr::strncpy(s1, s2, n);
}
char* MyCstr::strtok(char* s1, const char* s2)
{
    size_t i;
    for (i = 0; s1[i] != '\0'; i++)
    {
        for (size_t j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
                return (s1 + i);
        }
    }

    return NULL;
}
