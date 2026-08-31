// 06/05/2023

#include <iostream>
#include <ctime> // alloms for complete randomness
using namespace std;



/*### Problem 2.3  ###*/
//Analyze this function and count the number of operations performed.
//Use that information to determine the Big O time complexity
//  of this function.
int functionThree(int a[], int SIZE){
    int j;  // 1
    for(int i = 0; i < SIZE; i++){  // O(n)
        if(i==5){
            cout << a[i] << endl;
            j = i;
        }
    }
    // moved declaration of j outside of for loop ;j
    // illegal to refernce i in this for loop
    for(j = SIZE; j>=0; j--){    // O(n) = run exactly 5 time
        cout << a[j] << endl;
    }
    // for(;;) = infinite loops but do not do
}
