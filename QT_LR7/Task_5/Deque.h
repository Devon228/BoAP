#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <QDebug>

template <typename T>
class Deque
{
private: //generally private, but for the ring & cyclic view public
    struct Node
    {
        T value;
        Node* next;
        Node* prev;
    };
    size_t sz;
    Node* first;
    Node* last;

public:
    class Iterator
    {
    private:
        Node* it;

    public:
        explicit Iterator() : it(nullptr)
        {}
        explicit Iterator (Node* cur) : it(cur)
        {}
        //explicit Iterator (const Iterator& old) : it(old->it)
        //{}
        ~Iterator() = default;

        Iterator& operator ++ ()
        {
            this->it = this->it->next;
            return *this;
        }
        Iterator operator ++ (int)
        {
            Iterator copy(this->it);
            this->it = this->it->next;
            return copy;
        }

        Iterator& operator -- ()
        {
            this->it = this->it->prev;
            return *this;
        }
        Iterator operator -- (int)
        {
            Iterator copy(this->it);
            this->it = this->it->prev;
            return copy;
        }

        Node* operator -> () const //???????????????????????????????????
        {
            return this->it;
        }
        T operator * () const
        {
            return (this->it)->value;
        }

        bool operator == (const Iterator& right) const
        {
            return (this->operator->() == right.operator->());
        }
        bool operator != (const Iterator& right) const
        {
            return (this->operator->() != right.operator->());
        }
    };

public:
    explicit Deque()
    {
        first = nullptr;
        last = nullptr;
        sz = 0;
    }
    explicit Deque(size_t n, const T& value = T()) : Deque()
    {
        for (size_t i = 0; i < n; i++)
            push_back(value);
        std::cout << "create n*T Deque" << std::endl;
    }
    Deque(std::initializer_list<T> l) : Deque()
    {
        for (auto i : l)
            push_back(i);
        std::cout << "create initializer_list Deque" << std::endl;
    }
    Deque (const Deque& other) : Deque()
    {
        Deque other_tmp = other; //clears
        while (!other_tmp.empty())
        {
            push_back(other_tmp.front());
            other_tmp.pop_front();
        }
        std::cout << "create copy_other_lvalue Deque" << std::endl;
    }
    Deque (Deque&& other) : Deque()
    {
        first = other.first;
        last = other.last;
        sz = other.sz;
        other.first = nullptr;
        other.last = nullptr;
        other.sz = 0;
        std::cout << "create copy_other_rvalue Deque" << std::endl;
    }
    ~Deque()
    {
        clear();
        first = nullptr;
        last = nullptr;
        sz = 0;
        std::cout << "delete Deque" << std::endl;
    }

    Deque& operator= (const Deque& other)
    {
        std::cout << "= lvalue Deque" << std::endl;
        clear();
        Deque temp;
        while (!other.empty())
        {
            push_back(other.front());
            temp.push_back(other.front());
            other.pop_front();
        }
        swap(other, temp);

        return *this;
    }

    Deque& operator= (Deque&& other)
    {
        std::cout << "= rvalue Deque" << std::endl;
        clear();
        first = other.first;
        last = other.last;
        sz = other.sz;
        other.first = nullptr;
        other.last = nullptr;
        other.sz = 0;

        return *this;
    }

    Iterator begin () const
    {
        return Iterator(first);
    }
    Iterator end () const
    {
        return ++(Iterator(last));
    }
    T& front() const
    {
        if (sz == 0)
            throw "out of range";

        return first->value;
    }
    T& back() const
    {
        if (sz == 0)
            throw "out of range";

        return last->value;
    }

    inline bool empty() const
    {
        return (sz == 0);
    }
    inline size_t size() const
    {
        return sz;
    }

    void clear()
    {
        while (!empty())
            pop_front();
    }


    template <typename ... Args>
    void emplace_back(Args&& ... args) //throw
    {
        T val(args...);
        push_back(val);
    }
    template <typename ... Args>
    void emplace_front(Args&& ... args) //throw
    {
        T val(args...);
        push_front(val);
    }
    void push_back(const T& value) //back
    {
        Node *temp = new Node;

        temp->value = value; //= operator
        if (sz == 0)
            temp->prev = nullptr;
        else
            temp->prev = last;
        temp->next = nullptr;

        if (sz == 0)
            first = temp;
        else
            last->next= temp;
        last = temp;

        sz++;
    }
    void push_front(const T& value) //front
    {
        Node *temp = new Node;

        temp->value = value; //= operator
        if (sz == 0)
            temp->next = nullptr;
        else
            temp->next = first;
        temp->prev = nullptr;

        if (sz == 0)
            last = temp;
        else
            first->prev = temp;
        first = temp;

        sz++;
    }
    void pop_front() //fornt
    {
        if (sz == 0)
            throw "out of range";

        if (sz == 1)
        {
            delete first;
            //delete last;
            first = nullptr;
            last = nullptr;
        }
        else
        {
            Node *temp = first->next;

            delete first;
            first = temp;

            first->prev = nullptr;
        }

        sz--;
    }
    void pop_back() //bcak
    {
        if (sz == 0)
            throw "out of range";

        if (sz == 1)
        {
            delete first;
            //delete last;
            first = nullptr;
            last = nullptr;
        }
        else
        {
            Node *temp = last->prev;

            delete last;
            last = temp;

            last->next = nullptr;
        }

        sz--;
    }

    T& operator [] (size_t i)
    {
        if (i < 0 || sz <= i)
            throw "out of range";

        Node* cur = first;
        for (size_t i1 = 0; i1 < i; i1++)
            cur = cur->next;

        return cur->value;
    }

    void swap(Deque &right)
    {
        std::swap(first, right.first);
        std::swap(last, right.last);
        std::swap(sz, right.sz);
    }

    static void swap (Deque &left, Deque &right)
    {
        left.swap(right);
    }
};

#endif // DEQUE_H
