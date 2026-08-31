// Author : Felicity Lester

// Due Date : Thursday November 9th , 2023
// Programming Assignment Number 6
//
// Fall 2023 - CS 3358 - 008
//
// Serial Number / s : 26
//
// Instructor: Husain Gholoom.
//
// This program is designed to 

#include <iostream>
#include <ctime>        // allow seeding ran num gen
#include <cstdlib>      // allow rand
#include <algorithm>    // provides a collection of useful functions
#include <chrono>       // measuring time and dealing with time-related operations.

using namespace std;


// function prototypes
void displayArray(char arr[], int size);
int sequentialSearch(char arr[], int size, char value);
void sequentialSearch(char arr[], int size);
void selectionSort(char arr[], int size);
void insertionSort(char arr[], int size);
void countSort(char arr[], int size);
void quickSort(char arr[], int left, int right, int &recursiveCalls);
void displayQuickSort(char arr[], int size);
void sequentialSearchSorted(char arr[], int size, char target);


int main(int argc, const char * argv[]) {

    // initialize random seed
    srand(time(0));
  
    // create an array of size n
    int n = 20; // Your array size
    
    cout << "Searching / Sorting Benchmark\n" << endl;
    
    // while loop to validate the array size
    while (true) {
        cout << "\nEnter the size of the array: ";
        if (cin >> n && n > 4) {
            break; // V=valid input
        } else {
            cout << "\n*** Error - Invalid input - Size must be > 4 ***\n";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        }
    }

    // create an array of size n
    char arr[n];
    
    // populate the array with random character values
    for (int i = 0; i < n; ++i) {
        // random value between 100 and 5896
        arr[i] = 'A' + rand() % 58;
    }
    
    // display the array
    cout << "Array elements are : ";
    displayArray(arr, n);
    cout << endl;

    char target = '#'; // The character you're searching for

    // Perform sequential search and measure time and comparisons
    int position = sequentialSearch(arr, n, target);
    
    // sort the array using selectionSort and measure time and swaps
    selectionSort(arr, n);  // call selectionSort function

    cout << endl;
    insertionSort(arr, n);  // call insertionSort function
    cout << endl;
    countSort(arr, n);
    cout << endl;
    // Display quicksort results
    displayQuickSort(arr, n);
    cout << endl;
    // Sequential search for 'P' after sort
    sequentialSearchSorted(arr, n, 'P');

    cout << endl;
    cout << "11 - 2023" << endl;
    cout << "Sorting / Searching Benchmark by : " << endl;
    cout << "Felicity Lester :)" << endl;

    return 0;
}

//***********************************************************
// name: displayArray: display the array with characters
// parameters: (char arr[], int size)
// return:
// side effects: char not between A through } inclusive
//***********************************************************
void displayArray(char arr[], int size) {
    if (size < 4) {
        return;
    }
    
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
        // display only first 20 elements
        if (i >= 19 || i == size - 1) {
            break;
        }
    }
    cout << endl;
}

//***********************************************************
// name: sequentialSearch: display the array in reverse order
// parameters: (char arr[], int size)
// return: if int is prime & if int is not prime
// side effects:
//***********************************************************
int sequentialSearch(char arr[], int size, char value) {
    int comparisons = 0; // Initialize a counter for comparisons
    int position = -1; // Initialize position to -1

    int index = 0; // Used as a subscript to search the array
    bool found = false; // Flag to indicate if value was found

    auto start = chrono::high_resolution_clock::now(); // Record start time

    while (index < size && !found) {
        // performing a search for a specific value within the array
        if (arr[index] == value) {
            // If the value is found
            found = true; // Set the flag
            position = index; // Record the value's subscript
        }
        comparisons++; // Increment comparisons for each element checked
        index++; // Go to the next element
    }

    auto end = chrono::high_resolution_clock::now(); // Record end time
    chrono::duration<double> duration = end - start; // Calculate time duration

    // Display the results within the function
    cout << "\nSequential Search" << endl << endl;
    cout << "Searching for Char " << value << endl << endl;
    if (position != -1) {
        cout << "Char " << value << " found at position " << position << endl;
    } else {
        cout << "Char " << value << " was not found." << endl;
    }
    
    // display results
    cout << "Start Time: " << start.time_since_epoch().count() << endl;
    cout << "End Time: " << end.time_since_epoch().count() << endl;
    cout << "Actual CPU Clock time: " << duration.count() << endl;
    cout << "Total Number of Comparisons: " << comparisons << endl;
    cout << "Array Elements: ";
    displayArray(arr, size);
    cout << endl << endl;
    return position;
}


//***********************************************************
// name: selectionSort: display the orginal array in
//       ascending order
// parameters: (char arr[], int size)
// return:
// side effects: display the number of swaps
//***********************************************************
void selectionSort(char arr[], int size) {
    // Initialize variables to measure time and swaps
    auto start = chrono::high_resolution_clock::now(); // Record start time
    int swaps = 0;
    
    // Outer loop that iterates through the array
    for (int i = 0; i < size - 1; i++) {
        int min = i; // Initialize min to the current index i
        
        // Inner loop that searches for the smallest element
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                // Compare elements to get min
                min = j;
            }
        }
        
        // Check if the minimum element is different from the current index i
        if (i != min) {
            // Swapping occurs to get into the proper order
            char swap = arr[i];
            arr[i] = arr[min];
            arr[min] = swap;
            
            // Increment the swaps count
            swaps++;
        }
    }
    
    // Measure the time taken
    auto end = chrono::high_resolution_clock::now(); // Record end time
    chrono::duration<double> duration = end - start; // Calculate time duration
    
    // display results
    cout << "\nSelection Sort :" << endl;
    cout << "\nStart Time : " << start.time_since_epoch().count() << endl;
    cout << "End Time : " << end.time_since_epoch().count() << endl;
    cout << "Actual CPU Clock time : " << duration.count() << endl;
    cout << "Total Number of Swaps : " << swaps << endl;
    cout << "Sorted Elements : ";
    displayArray(arr, size);
}


//***********************************************************
// name: insertionSort: for every value, find the right
//       position
// parameters: (char arr[], int size)
// return:
// side effects: display the number of comparisons
//***********************************************************
void insertionSort(char arr[], int size) {
    int comparisons = 0;
    
    auto start = chrono::high_resolution_clock::now(); // Record start time

    for (int i = 1; i < size; i++) {
        char value = arr[i];
        int j = i - 1;
        
        // used to find the correct position
        while (j >= 0 && arr[j] > value) {
            arr[j + 1] = arr[j];
            j--;
            // increment comparisons for each comparison made
            comparisons++;
        }
        // inserts value into the correct position
        arr[j + 1] = value;
    }
    
    // Measure the time taken
    auto end = chrono::high_resolution_clock::now(); // Record end time
    chrono::duration<double> duration = end - start; // Calculate time duration
    
    // display results
    cout << "\nInsertion Sort :" << endl;
    cout << "\nStart Time : " << start.time_since_epoch().count() << endl;
    cout << "End Time : " << end.time_since_epoch().count() << endl;
    cout << "Actual CPU Clock time : " << duration.count() << endl;
    cout << "Total Number of Comparisons : " << comparisons << endl;
    cout << "Sorted Elements : ";
    displayArray(arr, size);
}

//***********************************************************
// name: countSort: display the number of times each number
//       appears in the orginal array list
// parameters: (char arr[], int size)
// return:
// side effects: display the number of comparisons
//***********************************************************
void countSort(char arr[], int size) {
    // Initialize variables to measure time and swaps
    auto start = chrono::high_resolution_clock::now(); // Record start time
    int comparisons = 0;
    
    if (size <= 1) {
        return; // No need to sort an array with 0 or 1 element
    }

    // Find the maximum and minimum characters in the input array
    char maxChar = arr[0];
    char minChar = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxChar) {
            maxChar = arr[i];
        }
        if (arr[i] < minChar) {
            minChar = arr[i];
        }
    }

    // Calculate the range of characters
    int charRange = maxChar - minChar + 1;

    // Create a count array for each character in the range
    int* count = new int[charRange];
    for (int i = 0; i < charRange; ++i) {
        count[i] = 0;
    }
    char output[size];

    // Count the occurrences of each character
    for (int i = 0; i < size; ++i) {
        count[arr[i] - minChar]++;
    }

    // Calculate the cumulative count of characters
    for (int i = 1; i < charRange; ++i) {
        count[i] += count[i - 1];
    }

    // Build the output character array
    for (int i = size - 1; i >= 0; --i) {
        output[count[arr[i] - minChar] - 1] = arr[i];
        count[arr[i] - minChar]--;
    }

    // Copy the sorted characters back to the original array
    for (int i = 0; i < size; ++i) {
        arr[i] = output[i];
    }
    
    // deallocate the dynamic array
    delete[] count;
    
    // Measure the time taken
    auto end = chrono::high_resolution_clock::now(); // Record end time
    chrono::duration<double> duration = end - start; // Calculate time duration
    
    // display results
    cout << "\nCount Sort :" << endl;
    cout << "\nStart Time : " << start.time_since_epoch().count() << endl;
    cout << "End Time : " << end.time_since_epoch().count() << endl;
    cout << "Actual CPU Clock time : " << duration.count() << endl;
    cout << "Total Number of Comparisons : " << comparisons << endl;
    cout << "Sorted Elements : ";
    displayArray(arr, size);
}

//***********************************************************
// name: quickSort: display the orginal array recursively
//       with the first half, and then the second half sort
// parameters: (char arr[], int left, int right)
// return:
// side effects: display the number of recursion calls
//***********************************************************
void quickSort(char arr[], int left, int right, int &recursiveCalls) {
    // Base case for recursion
    if (left < right) {
        int i = left, j = right;
        int tmp;
        char pivot = arr[(left + right) / 2];
        
        // Partition
        while (i <= j) {
            while (arr[i] < pivot)
                i++;
            while (arr[j] > pivot)
                j--;
            if (i <= j) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i++;
                j--;
            }
        };

        // Recursion
        if (left < j) {
            recursiveCalls++;
            quickSort(arr, left, j, recursiveCalls);
        }
        if (i < right) {
            recursiveCalls++;
            quickSort(arr, i, right, recursiveCalls);
        }
    }
}

void displayQuickSort(char arr[], int size) {
    // Initialize variables to measure time and recursive calls
    auto start = chrono::high_resolution_clock::now();
    int recursiveCalls = 0;

    // Call quickSort function
    quickSort(arr, 0, size - 1, recursiveCalls);

    // Measure the time taken
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    // display results
    cout << "\nQuick Sort - The middle element as a pivot :" << endl;
    cout << "\nStart Time : " << start.time_since_epoch().count() << endl;
    cout << "End Time : " << end.time_since_epoch().count() << endl;
    cout << "Actual CPU Clock time : " << duration.count() << endl;
    cout << "Total Number of Recursive calls : " << recursiveCalls << endl;
    cout << "Sorted Elements : ";
    displayArray(arr, size);
}

//***********************************************************
// name: sequentialSearchSorted: Search for a char ( P ) in 
//       the sorted array
// parameters: (char arr[], int size, char target)
// return: if int is prime & if int is not prime
// side effects: display number of times the char P appeared
//      in the array. and display the number of comparisons
//***********************************************************
void sequentialSearchSorted(char arr[], int size, char target) {
    // Initialize variables to measure time and swaps
    auto start = chrono::high_resolution_clock::now(); // Record start time
    int comparisons = 0;
    
    int count = 0; // Initialize a count for 'P'

    for (int i = 0; i < size; i++) {
        comparisons++; // Increment comparisons for each element checked
        if (arr[i] == target) {
            count++; // Increment the count if 'P' is found
        }
        if (arr[i] > target) {
            break; // Since the array is sorted, no need to continue searching
        }
    }
    
    // Measure the time taken
    auto end = chrono::high_resolution_clock::now(); // Record end time
    chrono::duration<double> duration = end - start; // Calculate time duration
    
    // display results
    cout << "\nSequential Search for Char P After Sort" << endl;
    if (count != 0) {
        cout << "\nChar P was found!" << endl;
    } else {
        cout << "\nChar P was not found." << endl;
    }
    
    // display results
    cout << "Start Time : " << start.time_since_epoch().count() << endl;
    cout << "End Time : " << end.time_since_epoch().count() << endl;
    cout << "Actual CPU Clock time : " << duration.count() << " seconds" << endl;
    cout << "Total Number of char P in the array : " << count << endl;
    cout << "Total Number of Comparisons : " << comparisons << endl;
    cout << "Sorted Elements : ";
    displayArray(arr, size);
}
