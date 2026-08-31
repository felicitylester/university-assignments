// 06/02/2023

#include <iostream>
#include <fstream>
#include <dilf
#include <ctime> // alloms for complete randomness
using namespace std;

/*###Problem 1.8 ###*/
//Write a code snippet to create a three dimensional array
//  of characters. The size of the array is 4x4x4.
//Write a loop to store a different character into every element
//  of the array.
//Use a loop or loops to print every element of the array where
//  two of the three dimensions are the same.
//Example: array[1][1][2] or array[0][3][0] but not array[1][2][3]


int main () {
    // creates 3-D arrray
    char arr[4][4][4];
    
    srand (time)
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                // rand = random character generator
                arr[i][j][k] = rand()% 93 + 33;
            }
        }
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if ((i == j && i != k) || (i == k && i != j) || (k == j && i !=k)) {
                    cout << "arr[" << i << "][" << j << "]["
                    << k << "]" << " = " << arr[i][j][k] << endl;
                }
            
        }
    }
}
                    return 0;
                    }
