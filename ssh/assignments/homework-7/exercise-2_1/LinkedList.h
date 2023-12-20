#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Your linked list implementation here
#include <iostream>
#include <ostream>
#include <stdexcept>

using namespace std;

template <class T>
struct Link{
    T data;
    Link* next;
    
    Link(){
        data = 0;
        next = nullptr;

    }
    Link(T value){
        data = value;
        next = nullptr;
    }
};

template <class T>
class LinkedList{
private:
public:
    Link<T> *front;
    Link<T> *back;

    LinkedList(){
        front = nullptr;
        back = nullptr;
    }
    ~LinkedList(){
        while (front != nullptr){
            Link<T>* temp = front;
            front = front->next;
            delete temp;
        }
        back = front = nullptr;
    }

    void append(T value){
        if (front == nullptr){
            front = new Link<T>(value);
            back = front;
        }else{
            Link<T> *temp = new Link<T>(value);
            back->next = temp;
            back = temp;
        }
    }

    void prepend(T value){
        if (front == nullptr){
            front = new Link<T>(value);
            back = front;
        }else{
            Link<T> *temp = new Link<T>(value);
            temp->next = front;
            front = temp;
        }
    }

    T removeFirst(){
        if (front == nullptr){
            throw std::logic_error("nothing to remove");
        }
        T value = front->data;

        if (front == back){
            delete front;
            back = front = nullptr;
        }else{
            Link<T> * temp = front;
            front = front->next;
            delete temp;
        }
        return value;
    }

    T removeLast(){
        if (front == nullptr){
            throw std::logic_error("nothing to remove");
        }
        T value = back->data;

        if (front == back){
            delete front;
            front = back = nullptr;
        }else{
            Link<T> * curr = front;
            while(curr->next != back){
                curr = curr->next;
            }
            Link<T> *old = back;
            back = curr;
            back->next = nullptr;
            delete old;
        }
        return value;
    }

    template <class U>
    friend std::ostream &operator<<(std::ostream &os, const LinkedList<U> &list);

};

template <class T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list){
    Link<T>* curr = list.front;
    while(curr != nullptr){
        os << curr->data;
        if (curr != list.back){
            os << ", ";
        }
        curr = curr->next;
    }
    return os;
}

#endif