#ifndef ARRAY_LIST
#define ARRAY_LIST

#include <iostream>
#include <ostream>
#include <stdexcept>

template <class T>
class ArrayList;

template <class T>
std::ostream& operator<<(std::ostream& os, const ArrayList<T>& container);


template <class T>
class ArrayList{
protected:
    T* arr;
    int count;
    int capacity;

    // Helper function to check if we are out of capacity,
    // in which case it doubles the capacity while preserving the data
    void inflate(){

    }

public:
    // Default constructor. Starts with capacity of 1. Will be increased if necessary.
    ArrayList(){

    }

    // Copy constructor. Needed because we store data on the heap
    ArrayList(const ArrayList& other){

    }

    // Overloaded assignment operator. Needed because we store data on the heap
    ArrayList& operator=(const ArrayList& other){

    }

    // This is so we are able to access and manipulate (read and write) any element in a valid position in the list
    T& operator[](int index){

    }

    // Appends a value (to the end of the list)
    // We guarantee that there is always space to add one more
    // But after we have added that one, we may have run out of space
    // The inflate() function increases the capacity if necessary
    void append(T value){

    }

    void prepend(T value){
        // Your code here...
    }

    T removeFirst() {
        // Your code here
        return T();
    }

    T removeLast() {
        // Your code here
        return T();
    }

    // Returns the nunber of elements in the list (not the overall capacity)
    int size() const {
        return count;
    }

    // This is for debugging purposes. Prints out the count and capacity
    void stats() const{
        
    }

    // Straightforward descructor
    ~ArrayList(){
       
    }

    // Some friendship declarations here, for the overloaded operator<< 
    // and for Unit Testing purposes. We want the test program to have access to everything
    friend std::ostream& operator<< <>(std::ostream& os, const ArrayList<T>& container);
    friend struct TestArrayList;
};


// This is for being able to cout our ArrayList
// It is a function template because we wish to be able to pass a class template as a parameter
template <class T>
std::ostream& operator<<(std::ostream& os, const ArrayList<T>& container){

}

#endif