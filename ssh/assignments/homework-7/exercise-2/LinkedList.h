#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <chrono>
#include <ostream>
#include <stdexcept>

template <class T>
class LinkedList;

template <class T>
struct Link{
    T data;
    Link* next;
    Link* prev;

    Link(){
        data = 0;
        next = nullptr;
        prev = nullptr;
    }

    Link(T data){
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list){
    Link<T>* curr = list.front;
    while (curr != nullptr){
        os << curr->data;
        if (curr->next != nullptr) os << ", ";
        curr = curr->next;
    }

    return os;
}

template<class T>
class LinkedList{
protected:
    Link<T>* front;
    Link<T>* back;
    int count;
public:
    LinkedList(){
        front = nullptr;
        back = nullptr;
        count = 0;
    }

    // Copy constructor
    LinkedList(const LinkedList& other) {
        // Initialize the new list as empty
        front = nullptr;
        back = nullptr;
        // arrSize = 0;
        count = other.count;

        // If the other list is empty, return immediately
        if (other.front == nullptr) {
            return;
        }

        // Create a new node for the first element in the other list
        front = new Link<T>(other.front->data);
        back = front;
        // arrSize = 1;

        // Initialize pointers for traversing both lists
        Link<T>* current = front;
        Link<T>* otherCurrent = other.front->next;

        // Copy the remaining elements from the other list
        while (otherCurrent) {
            current->next = new Link<T>(otherCurrent->data);
            current->next->prev = current;
            current = current->next;
            otherCurrent = otherCurrent->next;
            // count++;
        }
        back = current;
    }
LinkedList& operator=(const LinkedList& other) {
    if (this == &other) {
        return *this; // Avoid self-assignment
    }

    // Clear the current list
    while (front != nullptr) {
        Link<T>* temp = front;
        front = front->next;
        delete temp;
    }

    // Copy elements from the other list
    front = nullptr;
    back = nullptr;
    count = other.count;

    if (other.front != nullptr) {
        front = new Link<T>(other.front->data);
        back = front;

        Link<T>* current = front;
        Link<T>* otherCurrent = other.front->next;

        while (otherCurrent) {
            current->next = new Link<T>(otherCurrent->data);
            current->next->prev = current;
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
        back = current;
    }

    return *this;
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
            temp->prev = back;
            back->next = temp;
            back = temp;
        }
        count++;
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
            front->prev = temp;
            front = temp;
        }
        count++;
    }

    T removeFirst(){
        
        if (front == nullptr){
            throw std::logic_error("Can not remove from an empty list");
        }
        if (count == 1){
            T x = front->data;
            delete front;
            front = nullptr;
            back = nullptr;
            count--;
            return x;
        }
        else{
            T x = front->data;
            Link<T>* old = front;
            front = front->next;
            front->prev = nullptr;
            delete old;
            count--;
            return x;
        }
    }
    
    T removeLast(){
        // Your code goes here
        if (front == nullptr){
            throw std::logic_error("Can not remove from an empty list");
        }
        if (front == back){
            T x = front->data;
            delete front;
            front = nullptr;
            back = nullptr;
            count--;
            return x;
        } else{
            T x = back->data;
            Link<T>* old = back;
            back = back->prev;
            back->next = nullptr;
            delete old;
            count--;
            return x;
        } 
    } 

    T peek() const {
        if (front == nullptr){
            throw std::logic_error("Can not peek into an empty list");
        }
        return front->data;
    }

    int size() const {
        return count;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void reverse(){
        Link<T>* oldFront = front;
        front = back;
        back = oldFront;

        Link<T>* curr = front;
        while(curr != nullptr){
            Link<T>* temp = curr->next;
            curr->next = curr->prev;
            curr->prev = temp;
            curr = curr->next;
        }
    }
    // ~LinkedList(){                  // We must release all the memory we are occupying, which is not necessarily one contiguous chunk
    //     Link<T>* temp = front;          // Start at the head
    //     while (front != nullptr){    // As long as there are more elements
    //         front = front->next;      // release the head element and make its pointer point to the next element
    //         delete temp;
    //         temp = front;
    //     }
    // }
    ~LinkedList(){
        Link<T>* current = front;
        while (current != nullptr) {
            Link<T>* next = current->next; // Store the next node before deleting the current one
            delete current;
            current = next; // Move to the next node
        }
    }

    friend std::ostream& operator<<<>(std::ostream& os, const LinkedList& list);

    friend struct TestLinkedList;

};




#endif
// #ifndef LINKED_LIST_H
// #define LINKED_LIST_H

// #include <iostream>
// #include <ostream>
// #include <stdexcept>
// #include <string>

// using namespace std;

// template <class T>
// struct Link
// {

//     T data;
//     Link *next;
//     Link *prev;

//     Link()
//     {
//         data = 0;
//         next = nullptr;
//         prev = nullptr;
//     }
//     Link(T value)
//     {
//         data = value;
//         next = nullptr;
//         prev = nullptr;
//     }
// };

// template <class T>
// class LinkedList
// {
// private:


// public: 
//     Link<T> *front;
//     Link<T> *back;
//     int arrSize;
//     LinkedList()
//     {
//         front = nullptr;
//         back = nullptr;
//         arrSize = 0;
//     }

//     // Copy constructor
//     LinkedList(const LinkedList& other) {
//         // Initialize the new list as empty
//         front = nullptr;
//         back = nullptr;
//         // arrSize = 0;
//         arrSize = other.arrSize;

//         // If the other list is empty, return immediately
//         if (other.front == nullptr) {
//             return;
//         }

//         // Create a new node for the first element in the other list
//         front = new Link<T>(other.front->data);
//         back = front;
//         // arrSize = 1;

//         // Initialize pointers for traversing both lists
//         Link<T>* current = front;
//         Link<T>* otherCurrent = other.front->next;

//         // Copy the remaining elements from the other list
//         while (otherCurrent) {
//             current->next = new Link<T>(otherCurrent->data);
//             current->next->prev = current;
//             current = current->next;
//             otherCurrent = otherCurrent->next;
//             // count++;
//         }
//         back = current;
//     }

//     void append(T value)
//     {
//         Link<T> *temp = new Link<T>(value);
//         if (front == nullptr)
//         {
//             back = front = temp;
//         }
//         else
//         {
//             temp->prev = back;
//             back->next = temp;
//             back = temp;
//         };

//         arrSize++;
//     }
//     void prepend(T value)
//     {
//         Link<T> *temp = new Link<T>(value);
//         if (front == nullptr)
//             front = back = temp;
//         temp->next = front;
//         front->prev = temp;
//         front = temp;
//         arrSize++;
//     }

//     T removeFirst()
//     {
//         T value = (front != nullptr) ? front->data : throw logic_error("nothing to remove");
//         Link<T> *old = front;
//         if (front == back)
//         {
//             front = back = nullptr;
//         }
//         else
//         {
//             front = front->next;
//             front->prev = nullptr;
//         }
//         arrSize--;
//         delete old;
//         return value;
//     }

//     T removeLast()
//     {
//         if (back == nullptr)
//         {
//             throw std::logic_error("nothing to remove");
//         }
//         T value = back->data;
//         if (front == back)
//         {
//             delete front;
//             front = back = nullptr;
//             arrSize--;
//         }
//         else
//         {
//             Link<T> *old = back;
//             back = back->prev;
//             back->next = nullptr;
//             delete old;
//             arrSize--;
//         }

//         return value;
//     }

//     T peek()
//     {
//         if (front == nullptr)
//             throw std::logic_error("nothing to peek at");
//         return front->data;
//     }

//     int size() const
//     {
//         return arrSize;
//     }

//     void reverse(){
//         Link<T>* oldFront = front;
//         front = back;
//         back = oldFront;

//         Link<T>* curr = front;
//         while(curr != nullptr){
//             Link<T>* temp = curr->next;
//             curr->next = curr->prev;
//             curr->prev = temp;
//             curr = curr->next;
//         }
//     }

//     ~LinkedList(){                  // We must release all the memory we are occupying, which is not necessarily one contiguous chunk
//         Link<T>* temp = front;          // Start at the head
//         while (front != nullptr){    // As long as there are more elements
//             front = front->next;      // release the head element and make its pointer point to the next element
//             delete temp;
//             temp = front;
//         }
//     }

//     template <class U>
//     friend std::ostream &operator<<(std::ostream &os, const LinkedList<U> &list);
// };

// template <class T>
// std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list)
// {
//     Link<T> *curr = list.front;
//     while (curr != nullptr)
//     {
//         os << curr->data;
//         if (curr->next != nullptr)
//         {
//             os << ", ";
//         }
//         curr = curr->next;
//     }
//     return os;
// }

// #endif

// #ifndef LINKED_LIST_H
// #define LINKED_LIST_H

// #include <chrono>
// #include <ostream>
// #include <stdexcept>

// template <class T>
// class LinkedList;

// template <class T>
// struct Link{
//     T data;
//     Link* next;
//     Link* prev;

//     Link(){
//         data = 0;
//         next = nullptr;
//         prev = nullptr;
//     }

//     Link(T data){
//         this->data = data;
//         next = nullptr;
//         prev = nullptr;
//     }
// };

// template <class T>
// std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list){
//     Link<T>* curr = list.front;
//     while (curr != nullptr){
//         os << curr->data;
//         if (curr->next != nullptr) os << ", ";
//         curr = curr->next;
//     }

//     return os;
// }

// template<class T>
// class LinkedList{
// protected:
//     Link<T>* front;
//     Link<T>* back;
//     int count;
// public:
//     LinkedList(){
//         front = nullptr;
//         back = nullptr;
//         count = 0;
//     };

// // Copy constructor
// LinkedList(const LinkedList& other) {
//     // Initialize the new list as empty
//     front = nullptr;
//     back = nullptr;
//     count = 0;

//     // If the other list is empty, return immediately
//     if (other.front == nullptr) {
//         return;
//     }

//     // Create a new node for the first element in the other list
//     front = new Link<T>(other.front->data);
//     back = front;
//     count = 1;

//     // Initialize pointers for traversing both lists
//     Link<T>* current = front;
//     Link<T>* otherCurrent = other.front->next;

//     // Copy the remaining elements from the other list
//     while (otherCurrent) {
//         current->next = new Link<T>(otherCurrent->data);
//         current->next->prev = current;
//         current = current->next;
//         otherCurrent = otherCurrent->next;
//         count++;
//     }
//     back = current;
// }


//     int& operator[](int index){
//         if (index < 0 || index >= count){
//             throw std::logic_error("Index out of bounds");
//         }
//         Link<T>* temp = front;
//         for (int i = 0; i < index; i++){
//             temp = temp->next;
//         }
//         return temp->data;
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
//             temp->prev = back;
//             back->next = temp;
//             back = temp;
//         }
//         count++;
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
//             front->prev = temp;
//             front = temp;
//         }
//         count++;
//     }

//     T removeFirst(){
        
//         if (front == nullptr){
//             throw std::logic_error("Can not remove from an empty list");
//         }
//         if (count == 1){
//             T x = front->data;
//             delete front;
//             front = nullptr;
//             back = nullptr;
//             count--;
//             return x;
//         }
//         else{
//             T x = front->data;
//             Link<T>* old = front;
//             front = front->next;
//             front->prev = nullptr;
//             delete old;
//             count--;
//             return x;
//         }
//     }

//     T peek() const {
//         if (front == nullptr){
//             throw std::logic_error("Can not peek into an empty list");
//         }
//         return front->data;
//     }
    
//     T removeLast(){
//         // Your code goes here
//         if (front == nullptr){
//             throw std::logic_error("Can not remove from an empty list");
//         }
//         if (front == back){
//             T x = front->data;
//             delete front;
//             front = nullptr;
//             back = nullptr;
//             count--;
//             return x;
//         } else{
//             T x = back->data;
//             Link<T>* old = back;
//             back = back->prev;
//             back->next = nullptr;
//             delete old;
//             count--;
//             return x;
//         } 
//     } 

//     int size() const {
//         return count;
//     }

//     bool isEmpty() const {
//         return count == 0;
//     }

//     void reverse(){
//         Link<T>* oldFront = front;
//         front = back;
//         back = oldFront;

//         Link<T>* curr = front;
//         while(curr != nullptr){
//             Link<T>* temp = curr->next;
//             curr->next = curr->prev;
//             curr->prev = temp;
//             curr = curr->next;
//         }
//     }


//     friend std::ostream& operator<<<>(std::ostream& os, const LinkedList& list);

//     friend struct TestLinkedList;

// };




// #endif

// #ifndef LINKED_LIST_H
// #define LINKED_LIST_H

// #include <ostream>
// #include <stdexcept>
// // using namespace std;

// // Your linked list implementation here
// template <class T>
// struct Link{
//     T data;
//     Link* next;
//     Link(){
//         data = 0;
//         next = nullptr;
//     }
//     Link(T value){
//         data = value;
//         next = nullptr;
//     }
// };

// template <class T>
// class LinkedList{
//     private:
//         int arrSize;
        
//     public:
//         Link<T>* front;
//         Link<T>* back;

//         LinkedList(){
//             arrSize = 0;
//             front = nullptr;
//             back = nullptr;
//         }

//         void append(T value){
//             if (front == nullptr){
//                 front = new Link<T>(value);
//                 back = front;
//                 arrSize++;
//             }
//             else{
//                   Link<T> * temp = new Link<T>(value);
//                   back->next = temp;
//                   back = temp;
//                   arrSize++;
//             }
//         }
//         void removeFirst(){
//             if (front == nullptr){
//                 throw std::logic_error("nothing to remove");
//             }else if (front == back){
//                 delete front;
//                 back = front = nullptr;
//                 arrSize--;
//             }else{
//                 Link<T> * temp = front;
//                 front = front->next;
//                 delete temp;
//                 arrSize--;
//             }
//         }
//         void removeLast(){
//             if (front == nullptr){
//                 throw std::logic_error("nothing to remove");
//             }else if (front == back){
//                 delete front;
//                 back = front = nullptr;
//                 arrSize--;
//             }else{
//                 Link<T>* curr = front;
//                 while (curr->next != back){
//                     curr = curr->next;
//                 }
//                 Link<T> *temp= curr->next;
//                 back = curr;
//                 curr->next = nullptr;
//                 delete temp;
//                 arrSize--;
//             }

//         }


//     ~LinkedList(){                  // We must release all the memory we are occupying, which is not necessarily one contiguous chunk
//         Link<T>* temp = front;          // Start at the head
//         while (front != nullptr){    // As long as there are more elements
//             front = front->next;      // release the head element and make its pointer point to the next element
//             delete temp;
//             temp = front;
//         }
//     }
// };

// template <class T>
// std::ostream &operator<<(std::ostream &os, const LinkedList<T>& list)
// {
//     Link<T>* curr = list.front;
//     while (curr != nullptr){
//         os << curr->data;
//         if (curr->next != nullptr) os << ", ";
//         curr = curr->next;
//     }

//     return os;
// }

// #endif

// //This file will contain part of your solution
