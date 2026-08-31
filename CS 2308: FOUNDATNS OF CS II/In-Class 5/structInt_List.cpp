// Author: Felicity Lester
// Date: 06/16/2023
// CS 2308.501 class and Prof. Atkinson

#include <iostream>
#include <cstring>  // allow strings
#include <cctype>   // allow characters

using namespace std;

//Re-write your code for the int_list from In-Class 4 as a class rather than a struct.
//  Store_int, print_int, and grow_list should all be member functions of the new class.
//  Enforce the maximum degree of privacy for every member of the class.
//Design a new class member function called del_value to remove every instance of one value
//  from the list. For example, if the user passes the number 7 to this function, every 7
//  will be removed from the list.
//Write a new main function that creates at least 2 instances of the int_list class.
//Design and write several test cases which will thoroughly test all of the member
//  functions of the int_list class.
//Implement your new class functions.
//Add a destructor to clean up any dynamically allocated memory that belongs to an int_list.

//****************This is the line of 80 characters in length*******************int

struct int_list {
    // data members stay private
private:
    int* arr;       // is a pointer to an array of integers,
    int size;       // represents the size of the array
    int index;      // indicates the next free location in the array
    
    //***********************************************************
    // name: grow_list: increase the size of the array belonging
    //       to an int_list
    // parameters:
    //      int_list & l:
    // return: new list size
    // side effects:
    //***********************************************************
    void grow_list() {
        size *= 2;    // add 2 every time to grow array(double space)
        // copy then delete
        int* temp = new int[size];    // allocate new array w/ new size
        for(int i = 0; i < size/2; i++){
            // copy over new values
            temp[i] = arr[i];
        }
        delete [] arr;    // delete old array
        arr = temp;
        return;
    }
    
public:
    // constructor = sets up good default values
    // everytime you create an int_list the constructor runs
    int_list() {
        size = 4;
        arr = new int[size];
        index = 0;
    }
    
    //***********************************************************
    // name: store_int: add an integer to an int_list
    // parameters:
    //      int_list & l:
    //      int num:
    // return: none
    // side effects:
    //***********************************************************
    void store_int(int num) {
        // if l is full grow l
        if(index == size) {
            grow_list();
        }
        arr[index] = num;
            index++;
    }

    //***********************************************************
    // name: print_int: print an integer at a given index of an
    //       int_list
    // parameters:
    //      int_list & l:
    //      int index: marks the next free location in the array
    // return: none
    // side effects:
    //***********************************************************
    void print_int(int i) {
        // if index is out of bounds so make sure it doesnt crash
        if(i < 0 || i >= index) {
            cout << "ERROR" << endl;
        }
        else {
            cout << arr[i] << endl;
        }
    }
    
    //***********************************************************
    // name: Print All
    // parameters: not needed cause it knows it all
    // return: none
    // side effects: none
    //***********************************************************
    void printAll() {
        for(int i = 0; i < index; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    
    //***********************************************************
    // name: Del Value
    // parameters: int target = the number to get rid off
    // return: none
    // side effects: arr will be altered, index will be altered
    //***********************************************************
    void delValue(int target) {
        // count number of non targeted values
        int count = 0;
        for (int i = 0; i < index; i++) {
            if (arr[i] != target) {
                count++;
            }
        }
        // make a new array with size given by count
        int* newArr = new int[count];
        // copy all non-target values into array
        int newi = 0;
            for (int i = 0; i < index; i++) {
                if (arr[i] != target) {
                    newArr[newi] = arr[i];
                    newi++;
                }
            }

        // destroy old array
        delete[] arr;
        // pointer arr to the new arr
        arr = newArr;
        // set size to count
        size = count;
        // set index to size
        index = count;
    }
    
};


//Write a new main function that creates at least 2 instances of the int_list class.

int main() {
    int_list myList;
    myList.store_int(3);
    myList.store_int(3);
    myList.store_int(5);
    myList.store_int(3);
    myList.store_int(5);
    
    myList.printAll();
    myList.delValue(3); // removes all 3's
    myList.printAll();

    return 0;
}

//Implement and test all 3 functions.
//Submit your .cpp file.
