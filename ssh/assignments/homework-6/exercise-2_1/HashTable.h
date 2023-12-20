// #ifndef HASH_TABLE_H
// #define HASH_TABLE_H

// #include "ArrayList.h"
// #include "LinkedList.h"

// struct HashTable{

//     // You can declare more instance variables here
//     int K;

//     HashTable(){
//         K = 10;
//         // If you have more instance variables, init them here
//     }

//     HashTable(int K){
//         this->K = K;
//         // If you have more instance variables, init them here
//     }

//     void add(int value){
//         // This function must be implemented
//     }


//     bool search(int value){
//         // This function must be implemented
//         return false;
//     }

//     // You can declare other functions if needed

// };

// #endif


#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "ArrayList.h"
#include "LinkedList.h"

struct HashTable{
     ArrayList<LinkedList<int>> ht;

    // You can declare more instance variables here
    int K;

    HashTable(){
        K = 10;
        // If you have more instance variables, init them here
    }

    HashTable(int K){
        this->K = K;
        for (int i = 0; i < K; i++) {
            ht.append(LinkedList<int>());
        }
        // If you have more instance variables, init them here
    }

    int f(int value) {
        return value % ht.size();
    }

    void add(int value){
        // This function must be implemented
        int pos = f(value);
        ht[pos].append(value);
    }


    bool search(int value){
        // This function must be implemented
        int pos = f(value);
        if (pos < 0 || pos >= ht.size()) return false;
        return ht[pos].search(value);
        // return false;
    }

    // You can declare other functions if needed

};

#endif