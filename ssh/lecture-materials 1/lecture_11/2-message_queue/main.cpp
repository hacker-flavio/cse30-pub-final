#include <iostream>
#include <sstream>
#include <string>
#include "Queue.h"

using namespace std;

struct Message{
    string text;
    int attempts;

    Message(string text = "", int attempts = 0){
        this->text = text;
        this->attempts = attempts;
    }

    bool send(){
        attempts--;
        return attempts == 0;
    }
};

ostream& operator<<(ostream& os, const Message& m){
    os << m.text << " - " << m.attempts;
    return os;
}

int main() {

    Queue<Message> q;

    string line;
    while(getline(cin, line)){
        string text;
        int attempts;
        stringstream ss(line);
        getline(ss, text, ',');
        ss >> attempts;
        // cout << "Will process " << text << " in " << attempts << endl;
        q.enqueue(Message(text, attempts));
    }
    
    while (!q.isEmpty()){
        Message temp = q.dequeue();

        if (temp.send()){
            cout << temp.text << " sent" <<endl;
        }
        else{
            cout << temp.text << " failed" << endl;
            q.enqueue(temp);
        }
    }

    cout << "Done..." << endl;
    
    return 0;
}