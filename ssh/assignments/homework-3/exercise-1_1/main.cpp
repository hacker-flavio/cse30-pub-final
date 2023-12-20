#include <iostream>
#include "SortedList.h"

using namespace std;

int main(int argc, char* argv[]){
    // You can experiment with your data structure here...
    SortedList<int> nums;
        // We know the list will be sorted
    for (int i = 1; i <= 1000000; i++){
        nums.append(i);
    }
    
    return 0;
}