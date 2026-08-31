// 03/23/2023
//  doubleDupe.cpp
//  in class code

#include <iostream>
using namespace std;

int *doubleDupe (int *array, int size)
{
    // Validate the size
    if (size < 0)
        return NULL;
    
    // Allocate the new array.
    int *newArray = new int[2*size];
    
    // Copy the array's contents to the new array.
    for (int i = 0; i < size; i++)
    {
        newArray[i] = array[i];
    }
    
    // Copy the array's contents to the new array again
    for (int i = size; i < 2*size; i++)
    {
        newArray[i] = array[i-size];
    }
    
    // Return a pointer to the new array
    return newArray;
}
