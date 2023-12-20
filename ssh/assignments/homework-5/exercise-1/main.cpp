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
#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include "Stash.h"

using namespace std;

int main(){
    Stash jar;

    jar.deposit(5);
     cout << jar.getBalance() << endl;
    // cout << jar.getHistory() << endl;

    jar.withdraw(3);
    cout << jar.getBalance() << endl;
    //cout << jar.getHistory() << endl;

    jar.undo();
    cout << jar.getBalance() << endl;
    //cout << jar.getHistory() << endl;

    jar.undo();
    cout << jar.getBalance() << endl;
    //cout << jar.getHistory() << endl;
    // cout << "The amount of bitches you have is: "<< jar.getBalance() << endl;
    // jar.undo();
    // cout << jar.getBalance() << endl;
    return 0;
}