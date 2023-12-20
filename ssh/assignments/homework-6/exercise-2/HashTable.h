#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "ArrayList.h"
#include "LinkedList.h"

void handleArray(ArrayList<LinkedList<int>> &ht, int end){
    for(;ht.size()<end;ht.append(LinkedList<int>()));
}

struct HashTable{
    ArrayList<LinkedList<int>> ht;

    HashTable(){
        handleArray(ht, 10);
    }

    HashTable(int K){
        handleArray(ht, K);
    }

    int f(int value) {
        return (ht.size() != 0 )?value % ht.size():false;
    }

    void add(int value){
        int pos = f(value);
        ht[pos].append(value);
    }

    bool search(int value){
        int pos = f(value);
        return  (pos >= 0 && pos < ht.size())?ht[pos].search(value):false;
    }

};

#endif