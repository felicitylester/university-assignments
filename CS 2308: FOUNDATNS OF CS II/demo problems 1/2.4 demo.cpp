// 06/05/2023

#include <iostream>
#include <ctime> // alloms for complete randomness
using namespace std;


/*### Problem 2.4  ###*/
//Analyze this function and count the number of operations performed.
//Use that information to determine the Big O time complexity
//  of this function.

// nested loop -> one inside another
// 1000 * 1000
// run time will not change as it grows
int functionThree(int a[], int SIZE){
    // outer loop always run 1000 times
    for(int i = 0; i < 1000; i++){
        if(i < SIZE){
            cout << "Table for " << a[i] << endl;
            // inner loop always run 1000 times
            for(int j = 0; j < 1000; j++){
                if(j < i){
                    cout << a[i] * a[j] << ' ';
                }
            }
            cout << endl;
        }
    }
}
