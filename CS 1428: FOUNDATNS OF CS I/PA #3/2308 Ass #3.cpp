// File Name: main.cpp
// 
// Author: Felicity Lester
// Collaborators: None
// Date: 03/01/2023
// Assignment Number: 3
// CS 2308 Spring 2023
//
// subArray: takes an int array, a start index, and a length as arguments. 
// It creates a new array that is a copy of the elements from the original 
// array starting at the start index and has a length equal to the length 
// argument. For example, subArray(aa,5,4) would return a new array containing 
// only the elements aa[5], aa[6], aa[7], and aa[8].


//****************This is the line of 80 characters in length*******************

#include <iostream>
using namespace std;


//******************************************************************************
// duplicateArray: creates a new array that contains the elements of the
//      array argument in the same order
// array: an array of ints
// size: the number of ints in the array
// returns a pointer to the new array.
//      If an invalid size is passed the function returns null.
// NOTE: it is the caller's responsibility to delete the returned array
//      when finished with it.
//******************************************************************************

int *duplicateArray (int *array, int size) {
    
    // Validate the size
    if (size < 0)
        return NULL;
    
    // Allocate the new array.
    int *newArray = new int[size];
    
    // Copy the array's contents to the new array.
    for (int i=0; i<size; i++) {
        newArray[i] = array[i];
    }
    
    // Return a pointer to the new array
    return newArray;
    
}

//******************************************************************************
// subArray: creates a new array that is a copy of the elements from the 
// original array starting at the start index and has a length equal to the 
// length argument.
// array: an array of ints
// size: the number of ints in the array
// start: the start of the array
// length: length of array
// returns: results
//******************************************************************************
int *subArray (int *array, int start, int length) {
 int *result = duplicateArray(array + start, length);
 return result;
}

int main() {

    // integer size variable used to run program
    int size;
    cin >> size;

    // arary of the size input by the user
    int * arr = new int[size];

    // fix order store values in the array
    for(int i = 0; i < size; i++)
        cin >> arr[i];
  
    // integer start and length variables from user
    int start;
    int length;
    cin >> start >> length;

    // calls the subarray function 
    int *newArray = subArray(arr,start,length);
  
    //corrct array and print elements separated
    for(int i = 0; i < length; i++)
    {
        cout << newArray[i] << " ";
    }
        cout << endl;  // keeps loop going on same line

   return 0;
}