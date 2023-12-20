#include <iostream>
#include "LinkedList.h"
#include "TimeSupport.h"

using namespace std;

int main(int argc, char* argv[]){


        LinkedList<int> nums;

        // LinkedList<int> nums;
        // nums.append(5);
        // nums.append(7);
        // nums.append(2);

        // for (int i = 0; i < nums.size(); i ++){
        //     cout << nums[i] << endl;
        // }  

        // cout << nums.size() <<endl;

        // const int N = 100000;
        // LinkedList<int> nums;

        // for (int i = 0; i < N; i++){
        //     nums.append(i);
        // }

        // timestamp start = current_time();
        // while(nums.size() > 0){
            
        //     int x = nums.removeFirst();
        // }
        // timestamp end = current_time();
        // cout << nums.size() <<endl;
        // int duration = time_diff(start, end);
        // cout << "Took " << duration << " ms. to drain list of " << N << " elements" << endl; 

    return 0;
}

    // const int N = 100000;
    // LinkedList<int> nums;

    // for (int i = 0; i < N; i++){
    //     nums.append(i);
    // }

    // timestamp start = current_time();
    // while(nums.size() > 0){
    //     int x = nums.removeFirst();
    // }
    // timestamp end = current_time();

    // int duration = time_diff(start, end);
    // cout << "Took " << duration << " ms. to drain list of " << N << " elements" << endl; 