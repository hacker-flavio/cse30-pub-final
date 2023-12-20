#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Link{
    int data;
    Link* next;

    Link(){
        data = 0;
        next = nullptr;
    }

    Link(int data){
        this->data = data;
        next = nullptr;
    }
};

bool search(Link* start, int value){
    Link* curr = start;
    while(curr != nullptr){
        if (curr->data == value){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

class LinkedList{

    Link* front;
    Link* back;
    int data;
public:
    LinkedList(){
        front: nullptr;
        back: nullptr;

    }

    // append

    // prepend

    // search

}

// cout 
#endif