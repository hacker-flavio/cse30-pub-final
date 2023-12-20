#ifndef ARRAY_LIST
#define ARRAY_LIST

#include <iostream>
#include <ostream>
#include <stdexcept>

template <class T>
class ArrayList
{
protected:
public:
    int count;
    int capacity;
    T *arr;

    ArrayList()
    {
        count = 0;
        capacity = 1;
        arr = new T[capacity];
    }

    ~ArrayList()
    {
        delete[] arr;
    }

    void inflate()
    {
        if (count == capacity)
        {
            int newCapacity = capacity * 2;
            T *temp = new T[newCapacity];
            for (int i = 0; i < count; i++)
            {
                temp[i] = arr[i];
            }

            T *old = arr;
            arr = temp;
            capacity = newCapacity;

            delete[] old;
        }
    }

    void deflate()
    {
        if (count < capacity / 2)
        {
            int newCapacity = capacity / 2;
            T *temp = new T[newCapacity];
            for (int i = 0; i < count; i++)
            {
                temp[i] = arr[i];
            }

            T *old = arr;
            arr = temp;

            capacity = newCapacity;

            delete[] old;
        }
    }

    void append(T value)
    {

        if (count == capacity)
        {
            throw std::runtime_error("Array capacity exceeded");
        }
        else
        {
            arr[count] = value;
            count++;
            inflate();
        }
    }

    void prepend(T value)
    {

        for (int i = count; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        count++;
        inflate();
    }

    T removeFirst()
    {
        int value = arr[0];
        for (int i = 1; i < count; i++)
        {
            arr[i - 1] = arr[i];
        }
        count--;
        deflate();
        return value;
    }

    T removeLast()
    {
        if (count == 0)
            throw std::logic_error("Can not remove from an empty list.");
        T result = arr[count - 1];
        count--;
        deflate();
        return result;
    }
};

#endif