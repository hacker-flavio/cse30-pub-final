#include <iostream>
#include <string>
#include "WordleHelper.h"

using namespace std;

int main(){

    
    WordleHelper wh;
    // wh.addGreen("_o__y");
    // wh.addYellow("__tlo");
    // wh.addGray("audih");
    wh.addGreen("g____");
    wh.addYellow("_l__l");
    wh.addGray("rnoth");

    vector<string> result = wh.possibleSolutions();

    for (string& word: result){
        cout << word << endl;
    }

    

    return 0;

}