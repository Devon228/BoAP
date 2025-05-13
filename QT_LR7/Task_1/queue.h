#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <QDebug>


template <typename T>
class Queue
{
    public: //generally private, but for the ring & cyclic view public
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
        explicit Queue()
        {
            first = nullptr;
            last = nullptr;
            sz = 0;
        }
        explicit Queue(size_t n, const T& value = T()) : Queue()
        {
            for (size_t i = 0; i < n; i++)
                push_back(value);
            std::cout << "create n*T queue" << std::endl;
        }
        Queue(std::initializer_list<T> l) : Queue()
        {
            for (auto i : l)
                push_back(i);
            std::cout << "create initializer_list queue" << std::endl;
        }
        Queue (const Queue& other) : Queue()
        {
            Queue other_tmp = other; //clears
            while (!other_tmp.empty())
            {
                push_back(other_tmp.front());
                other_tmp.pop_front();
            }
            std::cout << "create copy_other_lvalue queue" << std::endl;
        }
        Queue (Queue&& other) : Queue()
        {
            first = other.first;
            last = other.last;
            sz = other.sz;
            other.first = nullptr;
            other.last = nullptr;
            other.sz = 0;
            std::cout << "create copy_other_rvalue queue" << std::endl;
        }
        ~Queue()
        {
            clear();
            first = nullptr;
            last = nullptr;
            sz = 0;
            std::cout << "delete queue" << std::endl;
        }

        Queue& operator= (const Queue& other)
        {
            std::cout << "= lvalue queue" << std::endl;
            clear();
            Queue temp;
            while (!other.empty())
            {
                push_back(other.front());
                temp.push_back(other.front());
                other.pop_front();
            }
            swap(other, temp);

            return *this;
        }

        Queue& operator= (Queue&& other)
        {
            std::cout << "= rvalue queue" << std::endl;
            clear();
            first = other.first;
            last = other.last;
            sz = other.sz;
            other.first = nullptr;
            other.last = nullptr;
            other.sz = 0;

            return *this;
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


        void swap(Queue &right)
        {
            std::swap(first, right.first);
            std::swap(last, right.last);
            std::swap(sz, right.sz);
        }

        static void swap (Queue &left, Queue &right)
        {
            left.swap(right);
        }
};

#endif // QUEUE_H
