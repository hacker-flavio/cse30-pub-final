

#include <iostream>
#include <stdexcept>
#include <string>
#include "Queue.h"

using namespace std;

struct Person {
    string name;
    int remainingTime;
};

int main() {
    Queue<Person> jobQueue;

    int count;
    cin >> count;

    for (int i = 0; i < count; i++) {
        string name;
        int time;
        cin >> name >> time;
        
        Person person;
        person.name = name;
        person.remainingTime = time;

        jobQueue.enqueue(person);
    }

    int period;
    cin >> period;

    while (!jobQueue.isEmpty()) {
        Person person = jobQueue.dequeue();
        int userTime;

        person.remainingTime <= period? 
            userTime = person.remainingTime:
            userTime = period;

        cout << person.name << " - " << userTime << endl;

        person.remainingTime -= userTime;

        person.remainingTime > 0 ? 
            jobQueue.enqueue(person): 
            void();
    }

    cout << "Done..." << endl;

    return 0;
}

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


// #include <iostream>
// #include <stdexcept>
// #include <string>
// #include "Queue.h"
// #include "Stack.h"

// using namespace std;

// struct Person {
//     string name;
//     int remainingTime;
// };

// int main() {
//     int count;
//     cin >> count;

//     Queue<Person> jobQueue;

//     for (int i = 0; i < count; i++) {
//         string name;
//         int time;
//         cin >> name;
//         cin >> time;

//         Person person;
//         person.name = name;
//         person.remainingTime = time;

//         jobQueue.enqueue(person);
//     }

//     int period;
//     cin >> period;

//     while (!jobQueue.isEmpty()) {
//         Person person = jobQueue.dequeue();
//         int timeOnMachine;

//         person.remainingTime <= period? 
//             timeOnMachine = person.remainingTime:
//             timeOnMachine = period;

//         cout << person.name << " - " << timeOnMachine << endl;

//         person.remainingTime -= timeOnMachine;

//         // if (person.remainingTime > 0) {
//         //     jobQueue.enqueue(person);
//         // }

//          // person.remainingTime > 0 ? 
//         //     jobQueue.enqueue(person): 
//         // person.remainingTime < 0 ?
//         //     void():
//         // void();
//         person.remainingTime > 0 ? 
//             jobQueue.enqueue(person): 
//             void();


//     }

//     cout << "Done..." << endl;

//     return 0;
// }
