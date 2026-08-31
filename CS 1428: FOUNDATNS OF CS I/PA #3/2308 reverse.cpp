// File Name: reverse.cpp
// 
// Author: Felicity Lester
// Collaborators: None
// Date: 03/01/2023
// Assignment Number: 3
// CS 2308 Spring 2022
//
// reverse: takes an array of integers and its size as arguments. It reverses 
// the array in place so that the elements are in reverse order. 

//****************This is the line of 80 characters in length*******************


//***********************************************************
// reverse: Should read array and array size to make sure 
// all numbers are properly arranged
// *starting: start pointing at the begining
// *end: end pointing at end of array
// array_size: size of array
// 
// returns:
//***********************************************************
void reverse(int* arr, int array_size)
{
   // start pointing at the begining
   int *starting = arr,

   // end pointing at end of array
   *end = arr + array_size - 1;

   // temporary variable used for swap
   int temp;

   // loop used for reversing array order
   while(starting < end)
   {
     // swap when necessary
     temp = *starting;
     *starting = *end;
     *end = temp;

     // start move forward
     starting++;
     // end move backwords
     end--;
   }
}

#include <iostream>
using namespace std;

int main() {

   // variable used
   int number;
 
   // input size for array
   cin >> number;

   // array size set
   int array[number];

   for(int i = 0; i < number; i++)
   {
     cin >> array[i];
   }

   // used for calling reverse function
   reverse(array, number);

   // loop to output correct order
   for(int i = 0; i < number; i++)
   {
     cout << array[i] << " ";
   }
  
   return 0;
}
