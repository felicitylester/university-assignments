// 06/05/2023

#include <iostream>
#include <ctime> // alloms for complete randomness
using namespace std;

/*### Problem 2.2  ###*/
//Analyze this function and count the number of operations performed.
//Use that information to determine the Big O time complexity
//  of this function.


// have to know how value of i works to know size
// have to double size to do one more run
// would have to make function very huge to notice it slow down
int functionTwo(int a[], int SIZE){
    int i = 1;
    while(i < SIZE){
        if(a[i]%10 == 0){
            cout << "Power of 10" << endl;
        }
        // i doubles each time loop runs
        // multiply loop by anything think of log time
        i *= 2;
    }   //O(logn)
    // 1 + O(logn)
    return 0;
}
