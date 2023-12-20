#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <ostream>
#include <stdexcept>

using namespace std;

template <class T>
struct Link
{
    T data;
    Link *next;
    Link()
    {
        T data = 0;
        next = nullptr;
    }

    Link(T data)
    {
        this->data = data;
        next = nullptr;
    }
};
template <class T>
class LinkedList
{
private:
    // private class member variables
    Link<T> *front; // pointer to the first element (front) of the linked list
    Link<T> *back;  // pointer to the last element (back) of the linked list

public:
    // public class member variable
    int arrSize; // int arrSize stores the number of elements in the linked list

    // default constructer for the LinkedList class
    LinkedList()
    {
        // initialize the front and back pointers to nullptr since the list is empty
        front = nullptr;
        back = nullptr;
        // initialize the arrSize to zero because there are 0 elements in the linked list, the link list is initally empty
        arrSize = 0;
    }

    // overloaded operator for [] for accessing element in the linked list by index
    int &operator[](int index)
    {
        // throw logic error if the index is out of bounds
        if (index < 0 || index >= arrSize)
            throw logic_error("index out of bounds");

        // traverse the link list to find the element at the specific index
        Link<T> *temp = front;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        // return a reference to the data of the element at the specific index
        return temp->data;
    }

    void append(T value)
    {
        if (front == nullptr)
        {
            front = new Link<T>(value);
            back = front;
        }
        else
        {
            Link<T> *temp = new Link<T>(value);
            back->next = temp;
            back = temp;
        }
        arrSize++;
        // cout << value << endl;
    }
    void prepend(T value)
    {
        if (front == nullptr)
        {
            front = new Link<T>(value);
            back = front;
        }
        else
        {
            Link<T> *temp = new Link<T>(value);
            temp->next = front;
            front = temp;
        }
        arrSize++;
    }

    T removeFirst()
    {
        if (front == nullptr){
            throw logic_error("nothing to remove");
        }
        if ( front == back){
            T value = front->data;
            delete front;
            front = back = nullptr;
            arrSize--;
            return value;
        }else{
        int value = front->data;
        Link<T> *old = front;
        front = front->next;
        delete old;
        arrSize--;
        return value;
        }
    }

    T removeLast()
    {
        if (front == nullptr)
        {
            throw logic_error("nothing to remove");
        }

        if (front == back)
        {
            T value = front->data;
            delete front;
            front = back = nullptr;
            arrSize--;
            return value;
        }
        else
        {
            Link<T> *curr = front;
            while (curr->next != back)
            {
                curr = curr->next;
            }
            Link<T> *old = back;
            T value = old->data;
            back = curr;
            back->next = nullptr;
            delete old;

            arrSize--;
            return value;
        }
    }

    template <class U>
    friend std::ostream &operator<<(std::ostream &os, const LinkedList<U> &list);

    // The following 2 friend declarations must be present so the unit tests can run
    friend struct TestTemplates;
    friend struct TestRemoveMethods;
};

template <class T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list)
{
    Link<T> *curr = list.front;
    while (curr != nullptr)
    {
        os << curr->data;
        if (curr->next != nullptr)
        {
            os << ", ";
        }
        curr = curr->next;
    }
    return os;
}

#endif