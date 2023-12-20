#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <ostream>
#include <stdexcept>

#include "LinkedList.h"

#include <string>

using namespace std;

template <class T>
class Queue
{
private:
public:
    LinkedList<T> elements;
    void enqueue(T value)
    {
        elements.append(value);
    }
    T dequeue()
    {
        T value = elements.removeFirst();
        return value;
    }
    T peek(){
        T value = elements.peek();
        return value;
    }
    int length() const
    {
        return elements.size();
    }
    bool isEmpty()
    {
        return elements.isEmpty();
    }

    template <class U>
    friend std::ostream &operator<<(std::ostream &os, const Queue<U> &queue);
};

template <class T>
std::ostream &operator<<(std::ostream &os, const Queue<T> &queue)
{
    os << queue.elements;
    return os;
}

#endif