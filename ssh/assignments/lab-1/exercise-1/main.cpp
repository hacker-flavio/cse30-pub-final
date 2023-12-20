#include <iostream>
#include <string>
#include "WordleHelper.h"

using namespace std;

int main(){

    
    string word;
    bool valid = false;

    // WordleHelper wh;
    // wh.addGreen("_o__y");
    // wh.addYellow("__tlo");
    // wh.addGray("audih");
    // wh.addGreen("g____");
    // wh.addYellow("_l__l");
    // wh.addGray("rnoth");

    cout << "Enter a valid 5 letter word" << endl;
    while (!valid) {
        cin >> word;
        if (word.length() == 5){
            WordleHelper helper;
            
            cout << "Enter another valid 5 letter word" << endl;
        }else{
            cout << "please Enter a valid 5 letter word" << endl;
        }
    }
  


    // vector<string> result = wh.possibleSolutions();

    // for (string& word: result){
    //     cout << word << endl;
    // }

    return 0;

}