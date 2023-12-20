#ifndef STASH_H
#define STASH_H

#include "Stack.h"
#include "Queue.h"

#include <iostream>
#include <ostream>
#include <stdexcept>

using namespace std;

struct Balance
{
    int amount;
    Balance()
    {
        amount = 0;
    }
};

template <class T>
class Stash
{
private:
    Balance balance;
    Stack<int> history;

public:
    void deposit(int value)
    {
        //cout << "you deposited: " << value << endl;
        history.push(value);
        balance.amount += value;
    }
    void withdraw(int value)
    {
        balance.amount -= value;
        history.push(-value);
        //cout << "you withdrew: " << value << endl;
    }
    void undo()
    {
        int value = history.pop();
        balance.amount -= value;

        //cout << "you undid the last transaction" << endl;
    }
    int getBalance()
    {
        return balance.amount;
    }
    void printHistory()
    {
        cout << "history: " << history.elements << endl;
    }
};

#endif
