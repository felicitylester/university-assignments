// 06/01/2023

/*###Problem 1.6 ###*/
//Write a code snippet that creates a two dimensional array
//  of floats called smallArr
//Initialze the array with these values:
//  {{2, 4, 8},
//  {16, 32, 64},
//  {128, 256, 512}}
//Write a loop or loops to print every row of the array.
//Write a loop or loops to print every column of the array.

#include <iostream>
using namespace std;

int main () {
    float smallArr[3][3] = {{2, 4, 8}, {16, 32, 64}, {128, 256, 512}};
    // can do float smallArr[][3] but not float smallArr[][]
    
    // start with for loop
    // < 3 bc it is array of 3
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            cout << smallArr[row][col] << ' ';
        }
        cout << endl;
    }
    cout << endl << "---------------------" << endl;
    for (int col = 0; col < 3; col++) {
        for (int row = 0; row < 3; row++) {
            cout << smallArr[row][col] << ' ';
            // smallArr[col][row] reswitched it after the loops were
            // already switched could have just pasted og loop and used
            // smallArr[col][row] 
        }
        cout << endl;
    }
}
