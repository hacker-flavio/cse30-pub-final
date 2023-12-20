#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include "Stash.h"

using namespace std;

int main()
{

    Stash<int> jar;

    jar.deposit(5);
    cout << jar.getBalance() << endl;
    // jar.printHistory();
    jar.withdraw(3);
    cout << jar.getBalance() << endl;
    // jar.printHistory();
    jar.undo();
    cout << jar.getBalance() << endl;
    // jar.printHistory();
    jar.undo();
    cout << jar.getBalance() << endl;
    // jar.printHistory();

    return 0;
}