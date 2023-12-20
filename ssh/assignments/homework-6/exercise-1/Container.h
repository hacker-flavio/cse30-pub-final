#ifndef CONTAINER_H
#define CONTAINER_H
#include "ArrayList.h"
struct Container{
    ArrayList<int> ht;
    Container(){}
    Container(int size) {}
    void add(int value){
            for(;ht.size()<=value;ht.append(0));
            ht[value] = 1;
    }
    bool search(int value) {return ht[value] == 1;}
};
#endif



// #ifndef CONTAINER_H
// #define CONTAINER_H
// #include "ArrayList.h"
// struct Container{
//     ArrayList<int> ht;

//     Container(){

//     }

//     Container(int size) {
//         // for (int i = 0; i < size; i++) {
//         //     ht.append(0);
//         // }
//     }

//     void add(int value){
//         if(value>=0){
//             // for (int i = ht.size(); i <= value; i++) {
//             //     ht.append(0);
//             // }
//             for(;ht.size()<=value;ht.append(0));
//             ht[value] = 1;
//         }
//     }
//     bool search(int value) {
//         // return (value >= 0 && value <= ht.size())?ht[value] == 1:false;
//         return ht[value] == 1;
//     }
// };

// #endif

