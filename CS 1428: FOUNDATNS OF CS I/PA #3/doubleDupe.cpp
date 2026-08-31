// File Name: doubleDupe.cpp
// 
// Author: Felicity Lester
// Collaborators: None
// Date: 03/01/2023
// Assignment Number: 3
// CS 2308 Spring 2023
//
// doubleDupe: takes an int array and the array’s size as arguments.
// The function should create a new array that is twice as big as the 
// argument array. The new array should contain two copies of the original 
// array, both in the original order. The function should return a 
// pointer to the new array.

//****************This is the line of 80 characters in length*******************

#include <iostream>
using namespace std;

//funtion protoype 
int* doubleDupe(int, int);

//***********************************************************
// doubleDupe: takes an int array and the array’s size as 
// arguments. The function should create a new array that is 
// twice as big as the argument array. The new array should 
// contain two copies of the original array, both in the 
// original order.
// *starting: start pointing at the begining
// *end: end pointing at end of array
// array_size: size of array
// 
// returns: a pointer to the new array.
//***********************************************************
int* doubleDupe(int arr[], int size) {
    if (size < 0) 
    {
      // if a negative integer is passed as a parameter instead 
      // of the array's size
        return nullptr;
    }

    int* newArr = new int[2 * size];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
        newArr[i + size] = arr[i];
    }

    return newArr;
}

int main() {

  // integer variable used to run program
  int size;
  cin >> size;

  int* arr = new int[size];
  for (int i = 0; i < size; i++) 
  {
    cin >> arr[i];
  }

    int* result = doubleDupe(arr, size * sizeof(int));
  
    if (result != nullptr) 
    {
        for (int i = 0; i < 2 * size; i++) 
        {
            cout << result[i] << " ";
        }
      
        cout << endl;
        delete[] result;
    } 
    else 
    {
        cout << "Invalid size" << endl;
    }

    // free the dynamically allocated memory and
    // set the pointers to 0.
    delete[] arr;
    return 0;
}