#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <ostream>
#include <stdexcept>

#include "ArrayList.h"
using namespace std;

template <typename T>
struct Link{
    T data;
    Link* next;

    Link(){
        T data = 0;
        next = nullptr;
    }

    Link(T data){
        this->data = data;
        next = nullptr;
    }

};
template <typename T>
class LinkedList : public ArrayList<T> {
    Link<T>* front;
    Link<T>* back;
    int arrSize;
public: 
    
    LinkedList(){
        front = nullptr;
        back = nullptr;
        arrSize = 0;
    }

    void append(T value){
        if (front == nullptr){
            // Appending to an empty list
            front = new Link<T>(value);
            back = front;
        }
        else{
            // Appending to list with elements
            Link<T>* temp = new Link<T>(value);
            back->next = temp;
            back = temp;
        }
        arrSize++;
    }

    int& operator[](int index){
        if (index < 0 || index >= arrSize){
            throw std::logic_error("Index out of bounds");
        }
        Link<T>* temp = front;
        for (int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp->data;
    }

    void prepend(T value){
        if (front == nullptr){
            // Prepending to an empty list
            front = new Link<T>(value);
            back = front;
        }
        else{
            // Prepending to a list with elements
            Link<T>* temp = new Link<T>(value);
            temp->next = front;
            front = temp;
        }
        arrSize++;
    }

    T removeFirst(){
            
        if (front == nullptr)
        {
            throw logic_error("Nothing to remove");
        }
        int value = front->data;
        Link<T> *old = front;
        front = front->next;
        delete old;
        if (front == nullptr)
        {
            back = front;
        }
        arrSize--;
        return value;
    }


    // T removeLast() {
    //     if (front == nullptr) {
    //         throw std::logic_error("List is empty. Cannot remove from an empty list.");
    //     }

    //     // if (front->next == nullptr) {
    //     //     // If there's only one element in the list, remove it
    //     //     T value = front->data;
    //     //     delete front;
    //     //     front = back = nullptr;
    //     //     this->count--;
    //     //     return value;
    //     // }
        
    //     // if (front->next == nullptr) {
    //     //     // If there's only one element in the list, remove it
    //     //     T value = front->data;

    //     //     //old pointer to front
    //     //     Link<T>* old = front;
    //     //     front = front->next;
    //     //     back = nullptr;

    //     //     this->count --;
    //     //     delete [] old;
    //     //     return value;
    //     // }

    //     if (arrSize == 1) {
    //         // If there's only one element in the list, remove it
    //         T value = front->data;

    //         front = back = nullptr;

    //         arrSize--;
    //         delete front;
    //         return value;
    //     }

    //     // // Traverse the list to find the second-to-last element
    //     // Link<T>* current = front;
    //     // while (current->next->next != nullptr) {
    //     //     current = current->next;
    //     // }

    //     // // 'current' now points to the second-to-last element
    //     // T value = current->next->data;

    //     // // Delete the last element and update 'back' pointer
    //     // delete current->next;
    //     // current->next = nullptr;
    //     // back = current;

    //     // arrSize--;
    //     // return value;

    //     // Traverse the list to find the second-to-last element
    //     Link<T>* current = front;
    //     while (current->next->next != nullptr) {
    //         current = current->next;
    //     }

    //     // 'current' now points to the second-to-last element
    //     T value = current->next->data;

    //     // Delete the last element and update 'back' pointer
    //     delete current->next;
    //     current->next = nullptr;
    //     back = current;

    //     arrSize--;
    //     return value;
                

    //     // // Traverse the list to find the second-to-last element
    //     // while (front->next->next != nullptr) {
    //     //     back = front->next;
    //     // }

              
    //     // delete back->next;
    //     // T value = front->data;
    // }
    T removeLast() {
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
            Link<T> *curr = front;
            while (curr->next != back)
            {
                curr = curr->next;
            }
            Link<T> *old = back;
            T value = old->data;
            back = curr;
            delete old;
            arrSize--;
            return value;
        }
        
    }


    int size() const {
        return arrSize;
    }


    template <typename U> // Declare operator<< as a template function

    friend std::ostream& operator<<(std::ostream& os, const LinkedList<U>& list);
    
    // The following 2 friend declarations must be present so the unit tests can run
    friend struct TestTemplates;
    friend struct TestRemoveMethods;

};
template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list){
    Link<T>* curr = list.front;
    while (curr != nullptr){
        os << curr->data;
        if (curr->next != nullptr) os << ", ";
        curr = curr->next;
    }

    return os;
}


#endif