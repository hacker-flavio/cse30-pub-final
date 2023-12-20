// #ifndef HASH_TABLE_H
// #define HASH_TABLE_H

// #include "ArrayList.h"
// #include "LinkedList.h"

// struct HashTable{
//      ArrayList<LinkedList<int>> ht;

//     // You can declare more instance variables here
//     int K;

//     HashTable(){
//         K = 10;
//         // If you have more instance variables, init them here
//     }

//     HashTable(int K){
//         this->K = K;
//         for (int i = 0; i < K; i++) {
//             ht.append(LinkedList<int>());
//         }
//         // If you have more instance variables, init them here
//     }

//     int f(int value) {
//         return value * 69 % ht.size();
//     }

//     void add(int value){
//         // This function must be implemented
//         int pos = f(value);
//         ht[pos].append(value);
//     }


//     bool search(int value){
//         // This function must be implemented
//         int pos = f(value);
//         if (pos < 0 || pos >= ht.size()) return false;
//         return ht[pos].search(value);
//         // return false;
//     }

//     // You can declare other functions if needed

// };

// #endif

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "ArrayList.h"
#include "LinkedList.h"

void handleArray(ArrayList<LinkedList<int>> &ht, int end){
    // for (int i = start; i <= end; i++){
    //     ht.append(LinkedList<int>());
    // }
    for(;ht.size()<end;ht.append(LinkedList<int>()));
    //for(;start<=end;ht.append(LinkedList<int>()));
}

struct HashTable{
    ArrayList<LinkedList<int>> ht;

    HashTable(){
    }

    HashTable(int K){
        // for(;ht.size()<K;ht.append(LinkedList<int>()));
        //  for (int i = 0; i <= K; i++){
        //     ht.append(LinkedList<int>());
        // }
        handleArray(ht, K);
    }

    int f(int value) {
        if (ht.size() == 0) return false;
        return value % ht.size();
    }

    void add(int value){
        for (int i = ht.size(); i <= 10; i++){
            ht.append(LinkedList<int>());
        }
        int pos = f(value);
        ht[pos].append(value);
    }


    bool search(int value){
        int pos = f(value);
        if (pos < 0 || pos >= ht.size()) return false;
        return ht[pos].search(value);
    }

};

#endif