#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <ostream>
#include <stdexcept>
// using namespace std;

// Your linked list implementation here
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
// class LinkedList{
struct LinkedList{
    // private:
        // int arrSize;
        
    // public:
        Link<T>* front;
        // Link<T>* back;

        LinkedList(){
            // arrSize = 0;
            front = nullptr;
            // back = nullptr;
        }

        void append(T value){
            if (front == nullptr){
                front = new Link<T>(value);
                // back = front;
                // arrSize++;
            }
            // else{
            //       Link<T> * temp = new Link<T>(value);
            //       back->next = temp;
            //       back = temp;
            //       arrSize++;
            // }
        }
        // void removeFirst(){
        //     if (front == nullptr){
        //         throw std::logic_error("nothing to remove");
        //     }else if (front == back){
        //         delete front;
        //         back = front = nullptr;
        //         arrSize--;
        //     }else{
        //         Link<T> * temp = front;
        //         front = front->next;
        //         delete temp;
        //         arrSize--;
        //     }
        // }
        // void removeLast(){
        //     if (front == nullptr){
        //         throw std::logic_error("nothing to remove");
        //     }else if (front == back){
        //         delete front;
        //         back = front = nullptr;
        //         arrSize--;
        //     }else{
        //         Link<T>* curr = front;
        //         while (curr->next != back){
        //             curr = curr->next;
        //         }
        //         Link<T> *temp= curr->next;
        //         back = curr;
        //         curr->next = nullptr;
        //         delete temp;
        //         arrSize--;
        //     }

        // }

    ~LinkedList(){                  // We must release all the memory we are occupying, which is not necessarily one contiguous chunk
        Link<T>* temp = front;          // Start at the head
        while (front != nullptr){    // As long as there are more elements
            front = front->next;      // release the head element and make its pointer point to the next element
            delete temp;
            temp = front;
        }
    }

    //     ~LinkedList(){                  // We must release all the memory we are occupying, which is not necessarily one contiguous chunk
    //     Link<T>* temp = front;          // Start at the head
    //     while (front != nullptr){    // As long as there are more elements
    //         front = front->next;      // release the head element and make its pointer point to the next element
    //         delete temp;
    //         temp = front;
    //     }
    // }
        // template <class U>
        // friend std::ostream &operator<<(std::ostream &os, const LinkedList<U> list);
};

template <class T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> list)
{
    Link<T>* curr = list.front;
    while (curr != nullptr){
        os << curr->data;
        if (curr->next != nullptr) os << ", ";
        curr = curr->next;
    }

    return os;
}

#endif

//This file will contain part of your solution
