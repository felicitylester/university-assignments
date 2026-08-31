// 06/07/2023

#include <iostream>
#include <ctime> // alloms for complete randomness
using namespace std;


/*### Problem 2.9  ###*/
//Your co-worker believes that Binary Search could be used to quickly
// determine the maximum or minimum value of a sorted list.
//Write one function that kind find the maximum OR minimum value in an
//  oredered list which is FASTER than Binary Search according to Big O.

// Binary Search = one of the highest complexities so hard to beat
// find first and last would be constant which is faster!

int findMaxOrMin(int a[], int SIZE) {
    // need function to prefor, two ways
    bool returnMax;
    cin >> returnMax;
    
    if(returnMax) {
        // sorted smallest to biggest
        return(a[SIZE]-1);
    }
    else {
        return(a[0]);
    }
}

int main() {
    
}
