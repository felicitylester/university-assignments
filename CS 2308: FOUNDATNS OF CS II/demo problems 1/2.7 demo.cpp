// 06/06/2023

#include <iostream>
#include <ctime> // alloms for complete randomness
using namespace std;


/*### Problem 2.7  ###*/
//Consider the two funtions below
//Both functions calculate the average value of the array a.
//Use algorithmic analyses to determine which function is better.
//What is the Big O time complexity of each function?

float calcAvgOne(const int a[], const int SIZE){
    float avg = 0.0;
    for(int i = 0; i < SIZE; i++){  // runs O(n) time
        avg += a[i];
    }
    return avg/SIZE;
}

float calcAvgTwo(const int a[], const int SIZE){
    float avg = 0.0;
    for(int i = 0; i < SIZE; i++){  // runs O(n) time
        avg += a[i]/float(SIZE);
    }
    return avg;
}

int main() {
    
    return 0;
}
