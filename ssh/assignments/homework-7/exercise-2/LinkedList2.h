#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <ostream>
#include <stdexcept>
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
struct LinkedList{
    Link<T>* head;             // Keep a pointer to the head (first element) of the list

    LinkedList(){       
        head = nullptr;     // A null pointer for head means the list is empty
    }

    void prepend(T value){
        if (head == nullptr){           // If we currently have an empty list
            head = new Link<T>(value);     // Create a new Link with the given value and make that the head
        }
        else{                               // If there are already elements in the list
            Link<T>* temp = new Link<T>(value);   // Make a new Link with the given value
            temp->next = head;              // Make the current head to be the next element of the newly created Link
            head = temp;                    // Point the head to the newly created Link
        }
    }

    void append(T value){
        if (head == nullptr){               // If we have an empty list
            head = new Link<T>(value);         // Create a new Link with the given value and make that the head
        }
        else{                               // If there are already elements in the list
            Link<T>* temp = new Link<T>(value);   // Make a new Link with the given value

            Link<T>* last = head;              // Find the last element in the list
            while (last->next != nullptr){  // That is the first element whose next pointer is null
                last = last->next;
            }

            last->next = temp;              // Make the next pointer of the last element point to the newly created Link
        }
    }

    bool search(T value){
        Link<T>* temp = head;
        
        while (temp != nullptr){
            if (temp->data == value){
                return true;
            }
            temp = temp->next;
        }
        
        return false;
    }

    ~LinkedList(){                  // We must release all the memory we are occupying, which is not necessarily one contiguous chunk
        Link<T>* temp = head;          // Start at the head
        while (head != nullptr){    // As long as there are more elements
            head = head->next;      // release the head element and make its pointer point to the next element
            delete temp;
            temp = head;
        }
    }
};

template <class T>
std::ostream& operator<< (std::ostream& os, LinkedList<T>& list){ // Print out the list on one line, separating elements by a space
    Link<T>* current = list.head;
    while (current != nullptr){
        os << current->data << " ";
        current = current->next;
    }

    return os;
}



#endif