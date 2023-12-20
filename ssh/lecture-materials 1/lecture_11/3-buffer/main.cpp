#include <iostream>
#include <sstream>
#include <string>
#include "Queue.h"
#include <thread>
#include <chrono> 


using namespace std;

Queue<string> q;

void process(){
    while (true){
        this_thread::sleep_for(chrono::seconds(3));
        if (q.isEmpty()){
            cout << "Nothing to do" << endl;
        }
        else{
            cout << "Processing " << q.dequeue() <<endl ;
        }
    }
}

int main() {

    thread thread_obj(process);

    string s;
    while (cin >> s){
        q.enqueue(s);
    }

    thread_obj.detach();


    cout << "Done..." << endl;
    
    return 0;
}