#include <iostream>
#include "ArrayList.h"
#include "LinkedList.h"

using namespace std;

int f(string s){
    int result = toupper(s[0]) - 65;
    return result;
}

bool search(string s, ArrayList<LinkedList<string>>& table){
    int pos = f(s);
    if(table[pos].search(s)){
        return true;
    }
    else{
        return false;
    }
}

int main() {

    ArrayList<LinkedList<string>> ht;

    for (int i = 0; i < 26; i++){
        ht.append(LinkedList<string>());
    }

    for (int i = 0; i < 5; i++){
        string name;
        cin >> name;

        int pos = f(name); // => which position

        ht[pos].append(name);
        // store the name - O(1)
    }

    // search for a specific name - O(1)

    if (search("ALICE", ht)){
        cout << "ALICE was found" << endl;
    }
    else{
        cout << "ALICE was not found" << endl;
    }

    for (int i = 0; i < 26; i++){
        cout << (char)(i + 65) << ": " << ht[i] << endl;
    }

    return 0;
}