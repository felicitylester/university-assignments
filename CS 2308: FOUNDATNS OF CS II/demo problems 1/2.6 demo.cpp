// 06/06/2023

#include <iostream>
#include <ctime> // alloms for complete randomness
using namespace std;


/*### Problem 2.6  ###*/
//Correct this implementation of Binary Search
//The function should return the index of the target value
//  or -1 if the target is not in the list.

int binSearch(const int a[], const int SIZE, const int target){
    int i = 0, j = SIZE;
    // j is exclusive upper bound
    // j decided to be an invalid index
    while(j>i){
        // i and j are indexes = lower and upper bounds
        // do not care about a[i] just mid point
        int mid = (i+j)/2;
        
        if (a[mid] > target)
            // a[i] should always be smaller than target bc its lower bounds
            j = mid;
        else if (a[mid] < target)
            i = mid+1;
        else
            return i;
    }
    return -1;
}

int main () {
    int a[] = {1, 3, 7, 34, 123, 251};
    cout << binSearch(a, 6, 123) << endl; // index 4
    return 0;
}
