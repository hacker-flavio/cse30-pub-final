#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <ostream>
#include <stdexcept>

#include "LinkedList.h"

#include <string>

using namespace std;

template <class T>
class Stack
{
private:
    LinkedList<T> elements;

public:
    void push(T value)
    {
        elements.prepend(value);
    }
    T pop()
    {
        T value = elements.removeFirst();
        return value;
    }
    T peek(){
        T value = elements.peek();
        return value;
    }
    bool isEmpty()
    {
        return elements.isEmpty();
    }
    int length() const
    {
        return elements.size();
    }

    template <class U>
    friend std::ostream &operator<<(std::ostream &os, const Stack<U> &stack);
};

template <class T>
std::ostream &operator<<(std::ostream &os, const Stack<T> &stack)
{
    os << stack.elements;
    return os;
}

#endif