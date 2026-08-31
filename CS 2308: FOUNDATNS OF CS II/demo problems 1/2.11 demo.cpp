// 06/07/2023

#include <iostream>
#include <ctime> // alloms for complete randomness
using namespace std;


/*### Problem 2.11  ###*/
//Correct this implementation of Selection Sort
//The function should put L into ascending order, with
//  the smallest value in the lowest index.

void selectionSort(const int L[], const int SIZE){
    for(int i = 0; i < SIZE-1; i++){
        int smallestIndex = i;
        for (int j = i+1; j < SIZE-1; j++){
            if (L[j] < L[smallestIndex]){
                smallestIndex = j;
            }
        }
        if (smallestIndex != i){
            int temp = L[i];
            L[i] = L[smallestIndex];
            L[smallestIndex] = temp;
        }
    }
    return;
}

int main(int argc, char** argv){
    int a[] = {3, 87, 3, 5, 8, 3, 7, 3, 8, 34};
    selectionSort(a, 10);
    for(int i = 0; i < 10; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}
