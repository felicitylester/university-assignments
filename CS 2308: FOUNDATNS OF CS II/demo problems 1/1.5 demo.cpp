// 06/01/2023

/*###Problem 1.5 ###*/
//Write a code snippet that creates a two dimensional array
//  of ints called allProds.
//The size of this array should be 10x10.
//Right nested for loops to store the value row*column in each
//  element of the array.

#include <iostream>
using namespace std;

int main () {
    const int SIZE = 10;
    int allProds[SIZE][SIZE];
    
    // loop to count 0 to 9 inclusive
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            // store row x coloum into each array
            // prod = product
            int prod = row*col;
            allProds[row][col] = prod;
            
            
        }
    }
}
