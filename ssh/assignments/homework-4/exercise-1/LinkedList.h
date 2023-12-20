// #ifndef LINKED_LIST_H
// #define LINKED_LIST_H

// #include <ostream>
// #include <stdexcept>

// #include "ArrayList.h"
// using namespace std;

// template <typename T>
// struct Link{
//     T data;
//     Link* next;

//     Link(){
//         T data = 0;
//         next = nullptr;
//     }

//     Link(T data){
//         this->data = data;
//         next = nullptr;
//     }

// };
// template <typename T>
// class LinkedList : public ArrayList<T> {
//     Link<T>* front;
//     Link<T>* back;
//     int arrSize;
// public: 
    
//     LinkedList(){
//         front = nullptr;
//         back = nullptr;
//         arrSize = 0;
//     }

//     void append(T value){
//         if (front == nullptr){
//             // Appending to an empty list
//             front = new Link<T>(value);
//             back = front;
//         }
//         else{
//             // Appending to list with elements
//             Link<T>* temp = new Link<T>(value);
//             back->next = temp;
//             back = temp;
//         }
//         arrSize++;
//     }

//     int& operator[](int index){
//         if (index < 0 || index >= arrSize){
//             throw std::logic_error("Index out of bounds");
//         }
//         Link<T>* temp = front;
//         for (int i = 0; i < index; i++){
//             temp = temp->next;
//         }
//         return temp->data;
//     }

//     void prepend(T value){
//         if (front == nullptr){
//             // Prepending to an empty list
//             front = new Link<T>(value);
//             back = front;
//         }
//         else{
//             // Prepending to a list with elements
//             Link<T>* temp = new Link<T>(value);
//             temp->next = front;
//             front = temp;
//         }
//         arrSize++;
//     }

//     T removeFirst(){
//         //grab item from front
//         if (front == nullptr){
//             throw std::logic_error("Index out of bounds");
//         }
//         int value = front->data;

//         //old pointer to front
//         Link<T>* old = front;
//         front = front->next;

//         if (front == nullptr){
//             back = front;
//         }

//         arrSize--;
//         delete [] old;
     

//         return value;
//     }


//     // T removeLast() {
//     //     if (front == nullptr) {
//     //         throw std::logic_error("List is empty. Cannot remove from an empty list.");
//     //     }

//     //     // if (front->next == nullptr) {
//     //     //     // If there's only one element in the list, remove it
//     //     //     T value = front->data;
//     //     //     delete front;
//     //     //     front = back = nullptr;
//     //     //     this->count--;
//     //     //     return value;
//     //     // }
        
//     //     // if (front->next == nullptr) {
//     //     //     // If there's only one element in the list, remove it
//     //     //     T value = front->data;

//     //     //     //old pointer to front
//     //     //     Link<T>* old = front;
//     //     //     front = front->next;
//     //     //     back = nullptr;

//     //     //     this->count --;
//     //     //     delete [] old;
//     //     //     return value;
//     //     // }

//     //     if (arrSize == 1) {
//     //         // If there's only one element in the list, remove it
//     //         T value = front->data;

//     //         front = back = nullptr;

//     //         arrSize--;
//     //         delete front;
//     //         return value;
//     //     }

//     //     // // Traverse the list to find the second-to-last element
//     //     // Link<T>* current = front;
//     //     // while (current->next->next != nullptr) {
//     //     //     current = current->next;
//     //     // }

//     //     // // 'current' now points to the second-to-last element
//     //     // T value = current->next->data;

//     //     // // Delete the last element and update 'back' pointer
//     //     // delete current->next;
//     //     // current->next = nullptr;
//     //     // back = current;

//     //     // arrSize--;
//     //     // return value;

//     //     // Traverse the list to find the second-to-last element
//     //     Link<T>* current = front;
//     //     while (current->next->next != nullptr) {
//     //         current = current->next;
//     //     }

//     //     // 'current' now points to the second-to-last element
//     //     T value = current->next->data;

//     //     // Delete the last element and update 'back' pointer
//     //     delete current->next;
//     //     current->next = nullptr;
//     //     back = current;

//     //     arrSize--;
//     //     return value;
                

//     //     // // Traverse the list to find the second-to-last element
//     //     // while (front->next->next != nullptr) {
//     //     //     back = front->next;
//     //     // }

              
//     //     // delete back->next;
//     //     // T value = front->data;
//     // }
//     T removeLast() {
//         if (front == nullptr) {
//             throw std::logic_error("List is empty. Cannot remove from an empty list.");
//         }

//         if (arrSize == 1) {
//             // If there's only one element in the list, remove it
//             T value = front->data;

//             front = back = nullptr;

//             arrSize--;
//             delete front;
//             return value;
//         }

//         // Traverse the list to find the second-to-last element
//         Link<T>* current = front;
//         while (current->next->next != nullptr) {
//             current = current->next;
//         }

//         // 'current' now points to the second-to-last element
//         T value = current->next->data;

//         // Delete the last element and update 'back' pointer
//         delete current->next;
//         current->next = nullptr;
//         back = current;

//         arrSize--;
//         return value;
        
//     }


//     int size() const {
//         return arrSize;
//     }


//     template <typename U> // Declare operator<< as a template function

//     friend std::ostream& operator<<(std::ostream& os, const LinkedList<U>& list);
    
//     // The following 2 friend declarations must be present so the unit tests can run
//     friend struct TestTemplates;
//     friend struct TestRemoveMethods;

// };
// template <typename T>
// std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list){
//     Link<T>* curr = list.front;
//     while (curr != nullptr){
//         os << curr->data;
//         if (curr->next != nullptr) os << ", ";
//         curr = curr->next;
//     }

//     return os;
// }


// #endif

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <ostream>
#include <stdexcept>

using namespace std;

template <class T>
struct Link
{
    T data;
    Link *next;
    Link *prev;

    Link(T value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

template <class T>
class LinkedList
{
private:
public:
    int arrSize;
    Link<T> *front;
    Link<T> *back;

    LinkedList()
    {
        arrSize = 0;
        front = nullptr;
        back = nullptr;
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


    ~LinkedList()
    {
        while (front != nullptr)
        {
            Link<T> *temp = front;
            front = front->next;
            delete temp;
        }
        front = back = nullptr;
    }

    void append(T value)
    {
        if (front == nullptr)
        {
            front = new Link<T>(value);
            back = front;
            arrSize++;
        }
        else
        {
            Link<T> *temp = new Link<T>(value);

            temp->prev = back;
            back->next = temp;
            back = temp;
            arrSize++;
        }
    }

    void prepend(T value)
    {
        if (front == nullptr)
        {
            front = new Link<T>(value);
            back = front;
            arrSize++;
        }
        else
        {
            Link<T> *temp = new Link<T>(value);
            front->prev = temp;
            temp->next = front;
            front = temp;
            arrSize++;
        }
    }

    void removeFirst()
    {
        if (front == nullptr)
        {
            throw std::logic_error("nothing to remove");
        }
        else
        {
            if (front == back)
            {
                delete front;
                front = back = nullptr;
                arrSize--;
            }
            else
            {
                Link<T> *temp = front;
                front = front->next;
                front->prev = nullptr;
                delete temp;
                arrSize--;
            }
        }
    }
    void removeLast()
    {
        if (front == nullptr)
        {
            throw std::logic_error("nothing to remove");
        }
        else if (front == back)
        {
            delete back;
            back = front = nullptr;
            arrSize--;
        }
        else
        {
            Link<T> *temp = back;

            back = back->prev;
            back->next = nullptr;
            delete temp;
            arrSize--;
        }
    }

    T peek()
    {
        if (front == nullptr)
        {
            throw std::logic_error("nothing to peek at");
        }
        return front->data;
        // return (front) ? front->data : throw std::logic_error("nothing to peek at");
    }

    int size() const{
        return arrSize;
    }

    void reverse()
    {
        Link<T> *curr = back;
        Link<T> *temp = nullptr;
        while (curr != nullptr)
        {

            temp = curr->next;
            curr->next = curr->prev;
            curr->prev = temp;

            curr = curr->next;
        }

        Link<T> *oldFront = front;
        front = back;
        back = oldFront;
    }

    void insert(T value, int index)
    {
        if (index < 0 || index > arrSize)
        {
            throw std::logic_error("out of bound");
        }
        Link<T> *curr = front;
        if (front == nullptr)
        {
            front = new Link<T>(value);
            back = front;
            arrSize++;
        }
        else
        {

            for (int i = 0; i < index - 1; i++)
            {

                curr = curr->next;
                cout << curr->data << endl;
            }
            Link<T> *temp = new Link<T>(value);
            temp->next = curr->next;
            temp->prev = curr;
            curr->next = temp;
            if (index == arrSize)
            {
                back = temp;
            }

            arrSize++;
        }
    }

    void deleteAt(int index)
    {
        if (index < 0 || index >= arrSize)
        {
            throw std::logic_error("out of bound");
        }
        Link<T> *curr = front;

        Link<T> *prev = nullptr;
        Link<T> *next = nullptr;
        if (index == 0)
        {
            Link<T> *temp = curr;
            front = front->next;
            delete temp;
        }
        else
        {

            for (int i = 0; i < index; i++)
            {

                curr = curr->next;
                prev = curr->prev;
                next = curr->next;
            }
            (prev != nullptr) ? cout << prev->data << endl : cout << "nullptr" << endl;
            cout << curr->data << endl;
            (next != nullptr) ? cout << next->data << endl : cout << "nullptr" << endl;

            Link<T> *temp = curr;
            if (next != nullptr)
            {
                prev->next = next;
                next->prev = prev;
            }
            else
            {
                prev->next = next;
                back = prev;
            }
            delete temp;
        }
        arrSize--;
    }

    template <class U>
    friend std::ostream &operator<<(std::ostream &os, const LinkedList<U> &list);
};

template <class T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list)
{
    Link<T> *curr = list.front;
    while (curr != nullptr)
    {
        os << curr->data;
        if (curr != list.back)
        {
            os << ", ";
        }
        curr = curr->next;
    }
    // Link<T> *curr = list.back;
    // while (curr != nullptr)
    // {
    //     os << curr->data;
    //     if (curr != list.front)
    //     {
    //         os << ", ";
    //     }
    //     curr = curr->prev;
    // }
    return os;
}

#endif