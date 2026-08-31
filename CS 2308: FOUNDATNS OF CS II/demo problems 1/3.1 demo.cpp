// 06/08/2023

#include <iostream>
#include <ctime> // alloms for complete randomness
using namespace std;


/* ### Problem 3.1 ### */
//Write a function with the following parameters:
//  a:      an integer array
//  SIZE:   the size of a
//Print the ADDRESS of every 10th memory location in the

//array starting from the first

void printAddresses(int a[], int SIZE) {
    for(int i = 0; i < SIZE; i++) {
        if(i%10==0) {       // every 10th element
            cout << &a[i] << endl;
        }
    }
    
}

int main(int argc, char** argv) {
    int b[1000];
    printAddresses(b, 1000);
    return 0;
}
