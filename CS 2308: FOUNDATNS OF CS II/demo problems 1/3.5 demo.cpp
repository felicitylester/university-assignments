// 06/09/2023

#include <iostream>
#include <ctime> // alloms for complete randomness
using namespace std;

/* ### Problem 3.5 ### */
//Write a function that takes these parameters:
//  arr:    an integer array
//  SIZE:   the size of arr
//Return a pointer to the largest number stored in arr.

// array always passed by reference
// using const int arr[] = caused compiler error
int* pointToBiggest(int arr[], int SIZE) {
    // int* largest = &arr[0];     // first spot in array
    int* largest = arr;
    for(int i = 1; i < SIZE; i++) {
        // start ar 1 bc array start at 0
        if(arr[i] > *largest) {
            // is arr[i] greater than the thing at largest
            // arr[i] is the same of (arr + i)
            largest = (arr + i);
        }
    }
    return largest;
}

int main(int argc, char** argv) {
    int a[] = {1, 2, 3, 6, 4, 5};
    int* l = pointToBiggest(a, 6);
    // int* l = int* largest
    cout << l << endl;      // output 0x61fe0c + varies by computer
    cout << *l << endl;     // output = 6
    return 0;
}
