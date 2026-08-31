// Felicity Lester
// June 02, 2023
// CS 2308.501 class and Prof. Atkinson
//
// Design a function that will return the sum of the maximum and
// minimum values in an array of integers. You should use comments
// in your code file to "sketch" the function.
// Write a main function that includes several calls to the function
// you have designed with different inputs. You should predict the
// return of each function and make a note of your prediction in a
// comment.
// Implement the function you designed.
// Submit the .cpp file with your code.


#include <iostream>
#include <fstream>

using namespace std;


//***********************************************************
// name: minMaxSum
// parameters:
//      int[] array
//      int Size: the size of array
// return: the sun of the max(array) and min(array)
// side effects: none (saying if you use function there will
//          not be problems made by the bvalue being changed
//          by array
//***********************************************************
int minMaxSum(const int arr[], int size) {
    
    // tests if case is empty
    if(size == 0)
        return 0;
    // find max and min
    // guess that max is arr[0]
    int max = arr[0];
    // guess that min is arr[0]
    int min = arr[0];
    // loop over remining values
    // dont use 0 becaus it is assigned in array wasting time redoing
    for(int i = 1; i <= size; i++) {
        // if current number > max, update guess
        if(arr[i] > max)
            max = arr[i];
        // if current number < min, update guess
        if(arr[i] < min)
            min = arr[i];
    }
    // return max + min
    return max + min;
}


int main () {
    
    int a[] = {1, 2, 3, 4};    //5
    int b[] = {-10, -2, -3, -70};       //-72
    int c[] = {1, 2, -5, -3, 7};    //2
    int d[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};     //2
    int e[] = {};       //0
    // pass no numbers (empty case)
    
    cout << minMaxSum(a, 4) << endl;
    cout << minMaxSum(b, 4) << endl;
    cout << minMaxSum(c, 5) << endl;
    cout << minMaxSum(d, 12) << endl;
    cout << minMaxSum(e, 0) << endl;

    
    return 0;
}
