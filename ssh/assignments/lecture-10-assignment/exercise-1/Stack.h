#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"
template <class T>
class Stack;

template <class T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& q);


// We can do this with inheritance, but we will have to disable some of the 
// functionality of the parent. 
// Therefore inheritance is not a good option here
template <class T>
class Stack {
    LinkedList<T> elements;
public:
    void push(T value){
        elements.prepend(value);
    }

    T pop(){
        return elements.removeFirst();
    }

    T peek(){
        return elements.peek();
    }

    int length() const { // Instructions say to call this size(), but call it length()
        return elements.size();
    }

    bool isEmpty() const {
        return elements.isEmpty();
    }

    friend std::ostream& operator<< <>(std::ostream& os, const Stack<T>& q);
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& q){
    // Your code here
    os << q.elements;
    return os;
}

#endif