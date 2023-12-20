#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include "ArrayList.h"
using namespace std;


template <typename T>

class SortedList : public ArrayList<T> {
public:


// void append(T value){
//         // Your code here
//         int point = 0;
//         this->inflate();

//    for (int i = 0; i < this->count; i++) {
//         if (value > this->arr[i]) {
//             point = i + 1;
//         }
//     }
//         for(int i = this->count; i > point; i--){
//             this->arr[i] = this->arr[i - 1];
//         }
//         this->arr[point] = value;
//         this->count++;
//     }


    // for (int i = 0; i < this->count; i++) {
    //     if (value > this->arr[i]) {
    //         point = i + 1;
    //     }
    // }

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
    
    // void append(T value) {

        

    //     if (this->count >= this->capacity) {
    //         this->inflate();
    //     }

    //     int left = 0;
    //     int mid;
    //     int right = this->count;

    //     // Binary search for the insertion point
    //     while (left < right) {
    //         mid = left + (right - left) / 2;
    //         if (this->arr[mid] < value) {
    //             left = mid + 1;
    //         } else {
    //             right = mid;
    //         }
    //     }

    //     // Shift elements 

    //     //#1
    //     // for (int i = left+1; i <= this->count; i++) {
    //     //     this->arr[i] = tempArray[i-1];
    //     // }

    //     //#2
    //     // for (int i = 0; i <= this->count; i++) {
    //     //     if (i != left && i < left){
    //     //         this->arr[i] = tempArray[i];
    //     //     }else if(i != left && i > left){
    //     //         this->arr[i] = tempArray[i-1];
    //     //     }else{
    //     //         this->arr[i] = value;
    //     //     }
    //     // }

    //     //#3
    //     for (int i = this->count; i > left; i--) {
    //         this->arr[i] = this->arr[i - 1];
    //     }

    //     //#4
    //     // int size = int(this->count) - int(1);
    //     // int *temp = new int[size];
    //     // for (int i = this->count-1; i > right; i--) {
    //     //     temp[i] = this->arr[i];
    //     // }
    //     // for (int i = 0; i <= this->count; i++) {
    //     //     // if (i <= mid){
    //     //     //     temp[i] = this->arr[i];
    //     //     // }
    //     //     // else if (i > mid){
    //     //     //     temp[i] = this->arr[i-1];
    //     //     // }
    //     //     // this->arr[i] = this->arr[i - 1];
    //     // }

    //     // temp[left] = value;
    //     // this->arr = temp;
    //     // int num = this->count;
    //     // cout << num << endl; 
    //     // cout << *tempArray[0] << endl; 

    //     // delete [] temp;


    //     // Insert the new value
    //     this->arr[left] = value;
    //     this->count++;    
    // }

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