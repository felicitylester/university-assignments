// Author /s : Felicity Lester
// Serial Number /s : 28
// Due Date : Thursday September 7th, 2023
// Programming Assignment Number 1
// Fall 2023 - CS 3358 - 008
//
// Instructor: Husain Gholoom.
//
// This program is designed to allow the user to manipulate 2D arrays in a
// variety of ways. The best part is that you can check if your array is
// special - meaning it has a unique pattern of numbers.

#include <iostream>
#include <ctime>        // allow random time generator
#include <cstdlib>      // allow rand
#include <iomanip>      // allow setw
//#include <cmath>        // allow math

using namespace std;


//****************This is the line of 80 characters in length*******************


// Use the following formula to find the special number
// Special Number = ( n ( n^2 + 1 ) ) / 2

// function prototypes
void populateArrays(int Array_1[3][3], int Array_2[3][3]);
void displayArrays(const int Array[][3], int numRows, int numCols);
void addArrays(const int Array_1[3][3], const int Array_2[3][3], int Array_3[3][3]);
void multiplyArrays(const int Array_1[3][3], const int Array_2[3][3], int Array_4[3][3]);
void transposeArray(const int Array_1[3][3], int Transposed_Array_1[3][3]);
void sumOfRows(const int Array[][3], int numRows, int numCols);
void sumOfColumns(const int Array[][3], int numRows, int numCols);
void sumOfDiagonals(const int Array[][3], int numRows, int numCols);
bool isSpecialArray(const int Array[][3], int numRows, int numCols);
int calculateSpecialNumber(int n);


int main(int argc, const char * argv[]) {
    // variables used to avoid bugs
    // create two 3X3 arrays
    int Array_1[3][3] = {0};
    int Array_2[3][3] = {0};
    
    // populates both arrays with distinct random numbers
    // that are between 1 and 15.
    populateArrays(Array_1, Array_2);

    // displays both arrays
    cout << "Array 1: \n" << endl;
    displayArrays(Array_1, 3, 3);
    
    cout << "\n\nArray 2: \n" << endl;
    displayArrays(Array_2, 3, 3);

    // add Array_1 to Array_2 and display the result
    int Array_3[3][3] = {0};
    addArrays(Array_1, Array_2, Array_3);
    cout << "\n\nSum of Array 1 and Array 2 \n" << endl;
    displayArrays(Array_3, 3, 3); // display Array_3

    // product of Array_1 by Array_2 and display the result
    int Array_4[3][3] = {0};
    multiplyArrays(Array_1, Array_2, Array_4);
    cout << "\n\nProduct of Array 1 and Array 2 \n" << endl;
    displayArrays(Array_4, 3, 3); // display Array_4

    // display the transpose of Array_1
    int Transposed_Array_1[3][3] = {0};
    transposeArray(Array_1, Transposed_Array_1);
    cout << "\n\nTranspose of Array_1: \n" << endl;
    displayArrays(Transposed_Array_1, 3, 3);
    cout << endl;

    // sum of elements in each row of Array_1
    cout << endl;
    sumOfRows(Array_1, 3, 3);

    // sum of elements in each column of Array_1
    sumOfColumns(Array_1, 3, 3);

    // sum of both diagonal elements in Array_1
    sumOfDiagonals(Array_1, 3,3);

    // check if Array_1 is a special array
    // special checks if Array_1 is special
    bool special = isSpecialArray(Array_1, 3, 3);
    if (special) {
        // assumes first row's sum is the special number
        int specialNumber = calculateSpecialNumber(3);
        cout << "The \e[1mspecial\e[0m number for Array 1 is "
             << specialNumber << endl;
        cout << "The above is a Special Array" << endl;
    } else {
        cout << "\nThe above is not a \e[1mspecial\e[0m array." << endl;
    }
    
    cout << endl;
    cout << "\n\nThis algorithm is implemented By Felicity Lester." << endl;
    cout << "September - 2023" << endl;

    return 0;
}

//***********************************************************
// name: populateArrays
// parameters:
//          const int Array_1[3][3]
//          const int Array_2[3][3]
// return:
// side effects: displays arrays with random numbers
//***********************************************************
void populateArrays(int Array_1[3][3], int Array_2[3][3]){
    
    srand(static_cast<unsigned int>(time(0)));
    int totalNumbers = 15; // b/c the max number is 15
    int numbers[totalNumbers];

    // fills array with values 1 - 15
    for (int i = 0; i < totalNumbers; ++i) {
        numbers[i] = i + 1;
    }

    // shuffle the numbers fro random
    for (int i = totalNumbers - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(numbers[i], numbers[j]);
    }

    int index = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            Array_1[i][j] = numbers[index++];
            Array_2[i][j] = numbers[index++];
        }
    }
}


//***********************************************************
// name: displayArrays
// parameters:
//          const int Array[][3]
//          int numRows
//          int numCols
// return: displays the arrays
// characters (' ').
//***********************************************************
void displayArrays(const int Array[][3], int numRows, int numCols) {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            // Use setw to set the width for each element in the output
            cout << right << setw(5) << Array[i][j] << " ";
        }
        cout << endl << endl;   // creates seperate lines & spacing for output
    }
    
}


//***********************************************************
// name: addArrays
// parameters:
//          const int Array_1[3][3]
//          const int Array_2[3][3]
//          int Array_3[3][3] is the output of array 1 & 2
// return:
// side effects: display the results of adding Array_1 to
//          Array_2 and place the result in Array_3
//***********************************************************
void addArrays(const int Array_1[3][3], const int Array_2[3][3], int Array_3[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            Array_3[i][j] = Array_1[i][j] + Array_2[i][j];
        }
    }
}


//***********************************************************
// name: multiplyArrays
// parameters:
//          const int Array_1[3][3]
//          const int Array_2[3][3]
//          int Array_4[3][3]
// return:
// side effects: display the product of Array_1 and
//          Array_2 and place the result in Array_4
//***********************************************************
void multiplyArrays(const int Array_1[3][3], const int Array_2[3][3], int Array_4[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            Array_4[i][j] = Array_1[i][j] * Array_2[i][j];
        }
    }
}


//***********************************************************
// name: transposeArray
// parameters:
//          const int Array_1[3][3]
//          int Transposed_Array_1[3][3]
// return:
// side effects: display the transpose of Array_1
//***********************************************************
void transposeArray(const int Array_1[3][3], int Transposed_Array_1[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            Transposed_Array_1[i][j] = Array_1[j][i];
        }
    }
}


//***********************************************************
// name: sumOfColumns
// parameters:
//          const int Array[][3]
//          int numRows
//          int numCols
// return:
// side effects: display the sum of elements in each
//      column of Array_1 - Array_3
//***********************************************************
void sumOfColumns(const int Array[][3], int numRows, int numCols) {
    for (int j = 0; j < 3; ++j) {
        int colSum = 0;
        for (int i = 0; i < 3; ++i) {
            colSum += Array[i][j];
        }
        cout << "Sum of numbers in Column # " << j + 1 << " in Array 1  = "
             << colSum << endl;
    }
}

//***********************************************************
// name: sumOfRows
// parameters:
//          const int Array[][3]
//          int numRows
//          int numCols
// return:
// side effects: calculates the sum of elements in each row
//***********************************************************
void sumOfRows(const int Array[][3], int numRows, int numCols) {
    for (int i = 0; i < numRows; ++i) {
        int rowSum = 0;
        for (int j = 0; j < numCols; ++j) {
            rowSum += Array[i][j];
        }
        cout << "Sum of numbers in Row # " << i + 1 << " = " << rowSum << endl;
    }
    cout << endl;
    cout << endl;
}


//***********************************************************
// name: sumDiagonals
// parameters:
//          const int Array[][3]
//          int numRows
//          int numCols
// return:
// side effects: display the sum of elements in each
//      diagonal of Array_1 -> Array_2
//***********************************************************
void sumOfDiagonals(const int Array[][3], int numRows, int numCols){
    int diagonal1Sum = 0;
    int diagonal2Sum = 0;
    for (int i = 0; i < numRows; ++i) {
        diagonal1Sum += Array[i][i];
        diagonal2Sum += Array[i][numCols - i - 1];
    }
    
    cout << "\n\nSum of numbers in first diagonal in Array 1 =  "
         << diagonal1Sum << endl;
    cout << "Sum of numbers in second diagonal in Array 1 =  "
         << diagonal2Sum << endl;
}

// Function to calculate the special number for a given array size n
int calculateSpecialNumber(int n) {
    return (n * (n * n + 1)) / 2;
}

//***********************************************************
// name: isSpecialArray
// parameters:
//          const int Array[][3]
//          int numRows
//          int numCols
// return:
// side effects: special Array is an arrangement of numbers
//      in the array grid, where the numbers in each row,
//      and in each column, and the numbers in the main and
//      secondary diagonals, all add up to the same special
//      number.
//***********************************************************
bool isSpecialArray(const int Array[][3], int numRows, int numCols) {
    int specialSum = 0;
    
    // initialize specialSum with the sum of the first row
    for (int i = 0; i < numCols; ++i) {
        specialSum += Array[0][i];
    }
//    for (int i = 0; i < 3; ++i) {
//        specialSum += Array_1[0][i]; // assume row ones sum is a special array
//    }

    // this loop checks rows for special number
    for (int i = 0; i < 3; ++i) {
        int rowSum = 0;
        for (int j = 0; j < 3; ++j) {
            rowSum += Array[i][j];
        }
        if (rowSum != specialSum) {
            return false;
        }
    }

    // this loop checks columns for special number
    for (int j = 0; j < 3; ++j) {
        int colSum = 0;
        for (int i = 0; i < 3; ++i) {
            colSum += Array[i][j];
        }
        if (colSum != specialSum) {
            return false;
        }
    }

    // this loop checks first diagonal for special number
    int diagonal1Sum = 0;
    for (int i = 0; i < 3; ++i) {
        diagonal1Sum += Array[i][i];
    }
    if (diagonal1Sum != specialSum) {
        return false;
    }

    // this loop checks secondary diagonal for special number
    int diagonal2Sum = 0;
    for (int i = 0; i < 3; ++i) {
        diagonal2Sum += Array[i][2 - i];
    }
    if (diagonal2Sum != specialSum) {
        return false;
    }

    return true;
}
