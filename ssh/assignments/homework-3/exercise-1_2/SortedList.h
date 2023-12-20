#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include "ArrayList.h"
using namespace std;


template <typename T>

class SortedList : public ArrayList<T> {
public:

void append(T value) {
       
        this->inflate();
        int left = 0;
        int mid;
        int right = this->count;

        // Binary search for the insertion point
        while (left < right) {
            mid = left + (right - left) / 2;
            if (this->arr[mid] < value) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        //shift array to the right by 1
        for (int i = this->count; i > left; i--) {
            this->arr[i] = this->arr[i - 1];
        }

        this->arr[left] = value;
        this->count++;    
    }
    
    bool search(T value) const {
        int left = 0;
        int mid;
        int right = this->count - 1;

        while (left <= right) {
            mid = left + (right - left) / 2;

            if (this->arr[mid] == value) {
                return true;
            }

            if (this->arr[mid] < value) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;  
    }

    // This needs to be here because of the unit tests
    friend struct TestSortedList;

};

#endif