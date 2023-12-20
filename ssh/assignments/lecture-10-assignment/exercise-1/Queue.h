#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"
template <class T>
class Queue;

template <class T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& q);


template <class T>
class Queue{
    LinkedList<T> elements;
public:
    void enqueue(T value){
        elements.append(value);
    }

    T dequeue(){
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

    friend std::ostream& operator<< <>(std::ostream& os, const Queue<T>& q);
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& q){
    os << q.elements;
    return os;
}

#endif