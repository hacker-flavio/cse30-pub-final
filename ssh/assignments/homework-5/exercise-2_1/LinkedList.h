#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <ostream>
#include <stdexcept>

using namespace std;

template <class T>
struct Link
{
    T data;
    Link<T> *next;
    Link<T> *prev;
    Link()
    {
        data = 0;
        next = nullptr;
        prev = nullptr;
    };

    Link(T value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    };
};

template <class T>
class LinkedList
{
private:
    Link<T> *front;
    Link<T> *back;
    int arrSize;

public:
    LinkedList()
    {
        front = nullptr;
        back = nullptr;
        arrSize = 0;
    }

    // Destructor
    ~LinkedList()
    {
        while (front != nullptr)
        {
            Link<T> *temp = front;
            front = front->next;
            delete temp;
        }
    }

    int &operator[](int index)
    {
        if (index < 0 || index >= arrSize)
        {
            throw std::logic_error("index out of bound");
        }
        Link<T> *curr = front;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        return curr->data;
    }

    void append(T value)
    {
        if (front == nullptr)
        {
            front = new Link<T>(value);
            back = front;
            arrSize++;
        }
        else
        {
            Link<T> *temp = new Link<T>(value);
            temp->prev = back;
            back->next = temp;
            back = temp;
            arrSize++;
        }
    }

    void prepend(T value)
    {
        if (front == nullptr)
        {
            front = new Link<T>(value);
            back = front;
            arrSize++;
        }
        else
        {
            Link<T> *temp = new Link<T>(value);
            temp->next = front;
            front->prev = temp;
            front = temp;
            arrSize++;
        }
    }
    T removeFirst()
    {
        if (front == nullptr)
        {
            throw logic_error("nothing to remove");
        }

        if (front == back)
        {
            T value = front->data;
            delete front;
            front = back = nullptr;
            arrSize--;
            return value;
        }
        else
        {
            T value = front->data;
            Link<T> *old = front;
            front = front->next;
            front->prev = nullptr;
            delete old;
            arrSize--;
            return value;
        }
    }

    T removeLast()
    {
        if (front == nullptr)
        {
            throw logic_error("nothing to remove");
        }
        else if (front == back)
        {
            T value = back->data;
            delete front;
            front = back = nullptr;

            arrSize--;
            return value;
        }
        else
        {
            T value = back->data;
            Link<T> *old = back;
            back = back->prev;
            back->next = nullptr;

            delete old;
            arrSize--;
            return value;
        }
    }

    T peek()
    {
        if (front == nullptr)
            throw logic_error("nothing to peek at");
        return front->data;
    }
    // Add a public member function to access arrSize
    int size() const
    {
        return arrSize;
    }
    // check if array is empty
    bool isEmpty()
    {
        return arrSize == 0;
    }
    template <class U>
    friend std::ostream &operator<<(std::ostream &os, const LinkedList<U> &list);
};
template <class T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list)
{
    Link<T> *curr = list.front;
    while (curr != nullptr)
    {
        os << curr->data;
        if (curr->next != nullptr)
        {
            os << ", ";
        }
        curr = curr->next;
    }
    return os;
}

#endif