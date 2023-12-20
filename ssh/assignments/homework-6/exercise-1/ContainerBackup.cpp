#ifndef CONTAINER_H
#define CONTAINER_H

#include "ArrayList.h"
#include "LinkedList.h"

struct Container{

    ArrayList<int> ht;

    Container(){
    }

    // void appendValue(int size){
    //     if (!ht.size() == size){
    //         ht.append(0);
    //         appendValue(size);
    //     }
    // }

    void appendValue(int size){
        if (ht.size() != size){
            ht.append(0);
            appendValue(size);
        }
        // (!ht.size() == size)?:ht.append(0),appendValue(size),
        // if(!ht.size() == size)appendValue(ht.append(0).size());
    }
    // void appendValue(int size){
    //     if (!ht.size() == size){
    //         ht.append(0);
    //         appendValue(size);
    //     }
    //     // (!ht.size() == size)?:ht.append(0),appendValue(size),
    //     // if(!ht.size() == size)appendValue(ht.append(0).size());
    // }

    Container(int size) {
    // for (int i = 0; i < size; i++) {
    //     ht.append(0);
    //   }
    //  ht = ArrayList<int>(size);

    // for(;ht.size()<size;ht.append(0));

    // while (ht.size() < size){
    //     ht.append(0);
    // }

    appendValue(size);

    // while(!ht.size() == size){ht.append(0);};

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


// #ifndef CONTAINER_H
// #define CONTAINER_H

// #include "ArrayList.h"
// #include "LinkedList.h"

// struct Container{

//     ArrayList<LinkedList<int>> ht;

//     Container(){
//     for (int i = 0; i < 10; i++) {
//         ht.append(LinkedList<int>());
//       }
//     }

//     // Constructor with an optional size parameter (default value is -1)
//     Container(int size) {
//     for (int i = 0; i < size; i++) {
//         ht.append(LinkedList<int>());
//       }
//     }

//     int f(int value) {
//     return value % ht.size();
//     }

//     void add(int value){
//        int pos = f(value);
//         ht[pos].append(value);
//     }
    

//     bool search(int value) {
//         int pos = f(value);
//         if (pos < 0 || pos >= ht.size()) return false;
//         return ht[pos].search(value);
//     }


// };

// #endif
// #ifndef CONTAINER_H
// #define CONTAINER_H

// #include "ArrayList.h"
// #include "LinkedList.h"

// struct Container{

//     ArrayList<int> ht;

//     Container(){
//     // for (int i = 0; i < 10; i++) {
//     //     ht.append(0);
//     //   }
//     }

//     Container(int size) {
//     for (int i = 0; i < size; i++) {
//         ht.append(0);
//       }
//     }

//     void add(int value){
//         (ht[value])?:  ht[value] = 1; 
//         for (int i = ht.size(); i < value; i++){
//               ht.append(0);
//          }
//         ht[value] = 1;
//     }

//     // void increaseSize(int value){
//     //      for (int i = ht.size(); i < value; i++){
//     //           ht.append(0);
//     //      }
//     //     ht[value] = 1;
//     // }

//     // void add(int value){
//     //     // ht[value]?  ht[value] = 1: increaseSize(value);
//     //     if (ht[value] == 0){
//     //          ht[value] = 1;
//     //     }else{
//     //         increaseSize(value);
//     //     }
//     // }
    
//     bool search(int value) {
//         // return ht[value]? 1: 0;
//         // if (ht.size() == 0){
//         //   return false;
//         // } 
//         //  return ht[value]? 1: 0;
//         return ht[value] == 1;
//     }
// };

// #endif

// #ifndef CONTAINER_H
// #define CONTAINER_H

// #include "ArrayList.h"
// #include "LinkedList.h"

// struct Container{

//     ArrayList<int> storage;

//     Container(){
        
//     }

//     // Constructor with an optional size parameter (default value is -1)
//     Container(int size) {
       
//     }

//     void add(int value){
//         storage.append(value);
//         // storage.quickSort(value,  storage.size()-1);
//         // int x = storage.partition(value, storage.size()-1);
//         // std::cout <<"partition return = " << x << std::endl;
//         storage.insertion_sort();
//     }

//     int size(){
//         return storage.size();
//     }
//     int& operator[](int index){
//         return storage[index];
//     }


//     bool search(int value){
//         return storage.binary_search(value);
//     }


// };

// #endif



// #ifndef CONTAINER_H
// #define CONTAINER_H

// #include "ArrayList.h"
// #include "LinkedList.h"

// struct Container{

//     ArrayList<int> ht;

//     Container(){
//     }

//     void appendValue(int size){
//         if (ht.size() != size){
//             ht.append(0);
//             appendValue(size);
//         }
//     }

//     Container(int size) {
//         // appendValue(size);
//         for(;ht.size()<size;ht.append(0));
//         // while (ht.size() < size){
//         //     ht.append(0);
//         // }
//         }

//     void add(int value){
//         for (int i = ht.size(); i <= value; i++){
//               ht.append(0);
//          }
//         ht[value] = 1;
//     }

//     bool search(int value) {
//         return ht[value] == 1;
//     }
// };

// #endif

