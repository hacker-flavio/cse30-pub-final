#ifndef ARRAY_LIST
#define ARRAY_LIST

#include <iostream>
#include <ostream>
#include <stdexcept>

using namespace std;

// Your array list implementation here...
template <class T>
class ArrayList{
private:
    
public:
    int count;
    int capacity;
    T *arr;
    ArrayList(){
        count = 0;
        capacity = 1;
        arr = new T[capacity];
    }
    ArrayList(const ArrayList &other){
        count = other.count;
        capacity = other.capacity;
        arr = new T[capacity];
        for(int i = 0; i<count; i++){
            this->arr[i] = other.arr[i];
        }
    }
    ArrayList& operator=(const ArrayList& other){
        count = other.count;
        for (int i = 0; i < count; i++){
            arr[i] = other.arr[i];
        }
        return *this;
    }
    ~ArrayList(){
        delete[] arr;
    }
    void inflate(){
       
        if (count == capacity){
            int newCapacity = capacity*2;
            T *temp = new T[newCapacity];
            for (int i = 0; i<count; i++){
                temp[i] = arr[i];
            }
            T*old = arr;
            arr = temp;
            delete old;
            capacity = newCapacity; 
            cout<< "inflating array" <<endl;
        }
    }
    void deflate(){
        if (count < capacity/2){
            int newCapacity = capacity/2;
            T *temp = new T[newCapacity];
            for(int i = 0; i< count; i++){
                temp[i] = arr[i];
            }
            T *old = arr;
            arr = temp;
            delete[] old;
            capacity = newCapacity;
            cout << "deflating array" <<endl;
        }
    }

    void append(T value){
        arr[count] = value;
        count++;
        inflate();

    }
    void prepend(T value){
        for(int i = count; i > 0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = value;
        count++;
        inflate();
    }

    void removeFirst(){
        if (count == 0){
            throw std::logic_error("nothing to remove");
        }
        for (int i = 1; i<count;i++){
            arr[i-1]=arr[i];
        }
        count--;
        deflate();
    }

    void removeLast(){
        if (count == 0){
            throw std::logic_error("nothing to remove");
        }
        count--;
        deflate();
    }

    bool isEmpty(){
        return count == 0;
    }

    int size() const{
        return count;
    }
    int maxSize() const{
        return capacity;
    }

    template<class U>
    friend std::ostream &operator<<(std::ostream &os, const ArrayList<U> &list);

};

template <class T>
std::ostream &operator<<(std::ostream &os, const ArrayList<T> &list){
    T *curr = list.arr;
    for(int i = 0; i< list.count; i++){
        os << list.arr[i];
        if (i<list.count-1){
            os << ", ";
        } 
    }
    return os;
}

#endif