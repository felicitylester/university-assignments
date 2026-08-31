// 06/13/2023

#include <iostream>

using namespace std;

/* ### Problem 3.12 ### */
//Predict the output of secretFunc

// what is on right goes into left
void secretFunc(){
    int SIZE = 4;
    int* a = new int[SIZE];
    // pointer stores an address
    int* p = a;
    // p is pointing at a and a is pointing to first avaliable location
    for(; p<&a[SIZE]; p++)
        // initalization already done so can just do semicolon
        // a[SIZE] is stop sign and value p gets assigned
        *p = 0;
    // indirection/ splat p says go to direection p is pointing to

    p = a;
    
    while(*p != 7){
        // p pointing at 7 then break the loop
        p = &a[rand()%SIZE];
        // a of 0 1 2 or 3 but do not know which
        if (*p != 0){
            SIZE++; // creates a larger array
            delete [] a;    // deallocates og arr so previously used memory is not wasted/taking up space
            a = new int[SIZE];
            for(; p<&a[SIZE]; p++)
                *p = 0;
        }
        else{
            *p = rand()%10; // range from 0 to 9
        }
    }
    cout << *p << endl;
    // output is 7
}
