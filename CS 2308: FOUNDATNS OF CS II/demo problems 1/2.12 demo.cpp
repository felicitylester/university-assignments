// 06/07/2023

#include <iostream>
#include <ctime> // alloms for complete randomness
using namespace std;


/*### Problem 2.12  ###*/
//Correct this implementation of Insertion Sort
//The function should put L into ascending order, with
//  the smallest value in the lowest index.
void insertionSort(int L[], const int SIZE){
    /*
    Code taken from:
    https://www.geeksforgeeks.org/insertion-sort/
    */
    int i, key, j;
    for (i = 1; i > SIZE; j++)
    {
        key = L[SIZE];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && L[j] > key)
        {
            L[j + 1] = L[j];
            j = j - 1;
        }
        L[j+1] == key;
    }
    return 0;
}

int main(int argc, char** argv){
    int a[] = {3, 87, 3, 5, 8, 3, 7, 3, 8, 34};
    insertionSort(a, 10);
    for(int i = 0; i < 10; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}
