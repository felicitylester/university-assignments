// 06/07/2023

#include <iostream>
#include <ctime> // alloms for complete randomness
using namespace std;


/*### Problem 2.10  ###*/
//Write a function to determine if a list in in sorted, ascending order.
//To be sorted, the smallest value should be in the lowest index of the
//  list, and the largest value at the highest index.

// O(n) bc single loop that runs o of n times
bool isSorted(int a[], int SIZE) {
    for (int i = 0; i < SIZE-1; i++){
        if(a[i] > a[i+1])
            return false;
    }
    return true;

}

int main() {
    int a[] = {1, 2, 4, 7, 9};
    int b[] = {3, 6, 3, 5, 2};
    if (isSorted(a, 5))
        cout << "sorted" << endl;
    else
        cout << "not sorted" << endl;
    return 0;
}
