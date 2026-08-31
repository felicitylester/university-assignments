// 06/08/2023

#include <iostream>
#include <ctime> // alloms for complete randomness
using namespace std;


/* ### Problem 3.2 ### */
//Write a function with the following parameters:
//  a:  an integer pointer
//  b:  an integer pointer
//Swap the value pointed to (referenced) by a and b

// need them as integer pointers
void swapInts(int* a, int* b) {     // int splat
    int temp = *a;
    // CANNOT int temp = a; b/c thats an address pointing to variable(?)
    *a = *b;
    *b = temp;      // can put temp into b
    
}



int main(int argc, char** argv) {
    int a = 1, b = 2;
    cout << a << " " << b << " " << endl;
    swapInts(&a, &b);
    cout << a << " " << b << " " << endl;

    
    return 0;
}
