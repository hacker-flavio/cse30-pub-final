// #ifndef CONTAINER_H
// #define CONTAINER_H

// #include "ArrayList.h"
// #include "LinkedList.h"

// struct Container{

//     ArrayList<int> storage;

//     Container(){
    
//     }

//     void add(int value){
//         storage.append(value);
//         storage.insertion_sort();
//     }


//     bool search(int value){
//         return storage.binary_search(value);
//     }


// };

// #endif

#ifndef CONTAINER_H
#define CONTAINER_H

#include "ArrayList.h"
#include "LinkedList.h"

struct Container{

    ArrayList<int> ht;

    Container(){
    }

    Container(int size){
        for (int i = 0; i < size; i++) {
            ht.append(0);
        }
    }

    void add(int value){
        for (int i = ht.size(); i <= value; i++){
              ht.append(0);
         }
        ht[value] = 1;
    }

    bool search(int value) {
        return ht[value] == 1;
    }
};

#endif
