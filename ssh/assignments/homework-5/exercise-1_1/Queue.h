#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

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
        return elements.removeFirst();
    }
    T peek()
    {
        return elements.peek();
    }
    bool isEmpty()
    {
        return elements.isEmpty();
    }

    int length() const
    {
        return elements.size();
    }
};

#endif