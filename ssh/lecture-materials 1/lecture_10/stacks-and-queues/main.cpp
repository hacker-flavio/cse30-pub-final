#include <cstdint>
#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include <string>
using namespace std;


int main(int argc, char* argv[]){
    

    string expression = "5 7 -";

    Stack<int> s;

    for (int i = 0; i < expression.length(); i++){
        if(expression[i] == '+'){
            int rhs = s.pop();
            int lhs = s.pop();
            int result = lhs + rhs;
            s.push(result);
        }
        else if (expression[i] == '-'){
            int rhs = s.pop();
            int lhs = s.pop();
            int result = lhs-rhs;
            s.push(result);
        }
        else if(expression[i] != ' '){
            string temp = "";
            temp += expression[i];
            s.push(stoi(temp));
        }
    }

    cout << s.peek() <<endl;


    
    return 0;
}