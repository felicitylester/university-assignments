// 06/06/2023

#include <iostream>
#include <ctime> // alloms for complete randomness
using namespace std;

/*### Problem 2.5  ###*/
//Correct this implementation of Sequential Search
//The function should return the index of the target value
//  or -1 if the target is not in the list.

// i-- update in wrong direction so must fix
int seqSearch(int a[], int SIZE, int target){
    for(int i = 0; i < SIZE; i++){
        // i is the index so it will not return where target is in list
        // index = address (like of your house)
        if(a[i] == target) // need == to do operand instead of assignment
            // a[i] is how you would find target
            return i;
    }
        return -1;
}

int main () {
    int a[] = {5, 8, 23, 76, 34, 6};
    cout << seqSearch(a, 6, 34) << endl; // index 4
    return 0;
}
