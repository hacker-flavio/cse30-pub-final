#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

using namespace std;

template <class T>
struct Link
{
    T data;
    Link *next;
    Link *prev;

    Link()
    {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }

    Link(T value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
template <class T>
class LinkedList
{
private:
    int arrSize;

public:
    Link<T> *front;
    Link<T> *back;
    LinkedList()
    {
        arrSize = 0;
        front = nullptr;
        back = nullptr;
    }

    void append(T value)
    {
        // cout << value << endl;
        if (front == nullptr)
        {
            front = new Link<T>(value);
            back = front;
            arrSize++;
        }
        else
        {
            Link<T> *temp = new Link<T>(value);
            back->next = temp;
            temp->prev = back;
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
        T value = front->data;
        if (front == back)
        {
            delete front;
            front = back = nullptr;

            arrSize--;
        }
        else
        {
            Link<T> *temp = front;
            front = front->next;
            front->prev = nullptr;
            arrSize--;
            delete temp;
        }

        return value;
    }

    T removeLast()
    {
        if (front == nullptr)
        {
            throw logic_error("nothing to delete");
        }
        T value = back->data;
        if (front == back)
        {
            delete back;
            front = back = nullptr;
            arrSize--;
        }
        else
        {
            Link<T> *temp = back;
            back = back->prev;
            back->next = nullptr;
            arrSize--;
            delete temp;
        }
        return value;
    }

    T peek()
    {
        if (front == nullptr){
            throw std::logic_error("nothing to peek at");
        }
        T value = front->data;
        return value;
    }

    int size() const
    {
        return arrSize;
    }

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
        curr = curr->next;
        if (curr != nullptr)
        {
            os << ", ";
        }
    }
    // os << curr->data;
    return os;
}

#endif