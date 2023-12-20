#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

template <class T>
class Stack
{
private:
public:
    LinkedList<T> elements;
    void push(T value)
    {
        elements.prepend(value);
    }
    T pop()
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