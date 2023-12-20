#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(int argc, char* argv[]){

    Link* head = new Link(3);
    Link* back = new Link(7);

    Link* temp = new Link(5);


    head->next = temp;

    temp->next = back;


    Link* curr = head;

    while (curr != nullptr){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    // 3 5 7 

    cout << search(head, 7) << endl;

    delete head;
    delete temp;
    delete back;


    return 0;
}