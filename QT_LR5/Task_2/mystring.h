#ifndef MYSTRING_H
#define MYSTRING_H

#include <initializer_list>
#include "iterator.h"
#include <iostream>
#include <memory>

namespace MyCstr
{
    void* memcpy(void* s1, const void* s2, size_t n);
    void* memmove(void* s1, const void* s2, size_t n);
    char* strcpy(char* s1, const char* s2);
    char* strncpy(char* s1, const char* s2, size_t n);
    char* strcat(char* s1, const char* s2);
    char* strncat(char* s1, const char* s2, size_t n);
    int memcmp(const void* s1, const void* s2, size_t n);
    int strcmp(const char* s1, const char* s2) noexcept;
    int strncmp(const char* s1, const char* s2, size_t n) noexcept;
    size_t strcspn(const char* s1, const char* s2);
    void* memset(void* s, int c, size_t n);
    size_t strlen(const char* s);
    char* strerror(int errnum);
    int strcoll(const char* s1, const char* s2);
    size_t strxfrm(char* s1, const char* s2, size_t n);
    char* strtok(char* s1, const char* s2);
}

class MyString
{
    using it = Iterator <char>;
    using r_it = Iterator <char>;
    using c_it = Iterator <const char>;

private:
    std::unique_ptr <char[]> arr;
    size_t sz = 0;
    size_t cap = 0;
    const size_t MAX_SZ = 1000000;

public:
    explicit MyString();
    explicit MyString (std::unique_ptr<char[]> arr1 = nullptr, size_t sz1 = 0, size_t cap1 = 0);
    explicit MyString(size_t n, const char& value);
    MyString(std::initializer_list<char> l);
    MyString (const MyString& other);
    MyString (const std::string& other);

    MyString& operator= (const MyString& other);

    ~MyString() = default;


    it begin();
    it end();
    r_it rbegin();
    r_it rend();
    c_it cbegin();
    c_it cend();

    char* c_str(); //sz 0  nullptr?
    char& front() const;
    char& back() const;
    char& at (size_t pos) const;
    char& operator[] (size_t pos) const;


    inline bool empty() const;
    void assign (size_t count, const char& value);
    void resize (size_t sz1);
    void resize(size_t sz1, const char& value);


    inline size_t max_size() const;
    inline size_t size() const;
    inline size_t length() const;
    inline size_t capacity () const;

    void reserve(size_t cap1);
    void clear();


    void insert (c_it pos, const char& value);
    void insert(c_it pos, size_t count, const char& value);
    void push_back(const char& value);
    void erase(c_it pos);
    void erase(c_it first, c_it last);
    void pop_back();

    MyString substr(size_t l, size_t r) const;
    int compare (const MyString& x) const;
    size_t find (const MyString &x) const;
    MyString& operator += (const MyString &x);
    void append (const MyString& x);
    //void swap(MyString &right);
};

#endif // MYSTRING_H
