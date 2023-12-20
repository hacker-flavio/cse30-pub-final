#ifndef SORTED_LIST
#define SORTED_LIST

#include "ArrayList.h"
#include <iostream>

using namespace std;

template <class T>

class SortedList : public ArrayList<T>
{
private:
public:
    void append(T value)
    {
        int left = 0;
        int mid;
        int right = this->count;

        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (this->arr[mid] < value)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        for (int i = this->count; i > left; i--)
        {
            this->arr[i] = this->arr[i - 1];
        }

        this->arr[left] = value;
        this->count++;
        this->inflate();
    }
    bool search(T value)
    {
        int left = 0;
        int mid;
        int right = this->count - 1;

        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (this->arr[mid] < value)
            {
                left = mid + 1;
            }
            else if (this->arr[mid] == value)
            {
                return true;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }
};

#endif