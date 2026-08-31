// 06/05/2023

#include <iostream>
#include <ctime> // alloms for complete randomness
using namespace std;

/*### Problem 2.1  ###*/
//Analyze this function and count the number of operations performed.
//Use that information to determine the Big O time complexity
//  of this function.

// i is 0 runs 0 times
// i is SIZE it runs SIZE times
// nested loops multiple trun time
int funcOne(int a[], int SIZE){
    for(int i = 0; i<SIZE; i++){  //O (SIZE)
        int j = 1;
        while(j <= i){  //O (SIZE)
            cout << i << " " << j << endl;
            cout << a[i] << " * " << a[j] << " = "
                <<  a[i] * a[j] << endl;
            cout << "------------" << endl;
            j++;
        }
    }
    O(n^2);
    return 0;
}
