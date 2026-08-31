// 05/31/2023

/*### Problem 1.1  ###*/
//Write a function called biggerOfThree to determine which of
//  its three parameters is the biggest.
//Parameters:
//  int a
//  int b
//  int c
//Returns: 1 if a is the biggest, 2 if b is the biggest, 3 otherwise
//Side Effects: none

#include <iostream>
using namespace std;

int biggerOfThree (int a, int b, int c) {
    // if a is largest
    if (a > b && a > c)
        return 1;
    else if (b > a && b > c)
        return 2;
    else    //otherwise instead of "if c is largest"
        return 3;
}

int main () {
    
    int a, b, c;
    cin >> a >> b >> c;
    // arguments do not need data types
    cout << biggerOfThree (1, 2, 3) << endl;
    cout << biggerOfThree (a, b, c) << endl;
    cout << biggerOfThree (a, 5, 8) << endl;
    
    
    return 0;
}
