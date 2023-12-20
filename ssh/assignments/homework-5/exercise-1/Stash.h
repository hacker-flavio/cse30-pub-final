#ifndef STASH_H
#define STASH_H

#include <iostream>
#include <stdexcept>
#include <string>
#include "Stack.h"

using namespace std;
using AmountType = int; // Create an alias for the data type
struct Balance{
    AmountType lastOperation;
    // AmountType balance = '\0';
    // AmountType balance = NULL;
    AmountType balance = 0;
};

class Stash {
Balance balance;
Stack<AmountType> history;  // Use a queue to store the history of operations

public:

    // Deposit money into the stash
    void deposit(AmountType amount) {
        balance.balance += amount;
        history.push(amount);  // Record the deposit in the history
    }

    // Withdraw money from the stash
    void withdraw(AmountType amount) {
        balance.balance < amount ? throw runtime_error("Insufficient balance"):
        balance.balance -= amount, history.push(-amount);
    }

    // Undo the last operation (either deposit or withdrawal)
    void undo() {
        history.isEmpty() ? throw runtime_error("nothing to undo"):
        balance.lastOperation = history.peek();
        history.pop();
        balance.balance -= balance.lastOperation;
    }

    // Get the current balance of the stash
    int getBalance() const {
        return balance.balance;
    }
};

#endif
/*                                                                                                                                                                                                                                                                                                                                                                                                               
***        ***        ****         ***********     ***     ****    ************  *************           ************  ***               ****    ****       ***   ***      ***********          
***        ***       *****        ****      ***    ***   ****      ***           ***       ****          ***           ***              *****     ***      ****   ***    ****      ****         
***        ***      *** ****     ***         ***   *** ****        ***           ***        ***          ***           ***             *** ***     ***     ***    ***    ***         ***        
**************     ****  ***     **                *******         ***********   ***      ****           ***********   ***            ***   ***    ***    ***     ***   ***           **        
***        ***     ***    ***    **                **** ****       ***********   *************           ***********   ***           ***     ***    ***  ***      ***   ***           **        
***        ***    ***********    ***         ***   ***   ****      ***           ***       ***           ***           ***           ***********     *** ***      ***   ****         ***        
***        ***   ***       ***   ****       ***    ***     ****    ***           ***       ***           ***           ***          ***       ***     *****       ***    ****       ***         
***        ***  ****        ***   ****** *****     ***      ****   ************  ***       ***           ***           **********  ***         ***    ****        ***     ****** ******         
                                      *****                                                                                                                                  ******                                                                                                                                                                                                                                                                                                                                                                                                                      
*/

