// Felicity Lester
// June 12, 2023
// CS 2308.501 class and Prof. Atkinson

#include <iostream>

using namespace std;

//Implement a struct called int_list with these members: a pointer to an array
//    of ints, an integer size of that array, and an integer index that marks the
//    next free location in the array. Add a constructor to this struct that will
//    set the size int to 4, dynamically allocate a new array, and set the next
//    index to 0.


//****************This is the line of 80 characters in length*******************


struct int_list {
    int* arr;       // is a pointer to an array of integers,
    int size;       // represents the size of the array
    int index;      // indicates the next free location in the array
 
    // constructor = sets up good default values
    // everytime you create an int_list the constructor runs
    int_list() {
        size = 4;
        arr = new int[size];
        index = 0;
    }
};

//Design 3 functions using comments. You may determine what parameters and
//    returns are appropriate for these functions.


//***********************************************************
// name: grow_list: increase the size of the array belonging
//       to an int_list
// parameters:
//      int_list & l:
// return: new list size
// side effects:
//***********************************************************
void grow_list(int_list & l){
    l.size *= 2;    // add 2 every time to grow array(double space)
    // l.arr = new int[1.size];
    // copy then delete so you dont lose info
    int* temp = new int[l.size];    // allocate new array w/ new size
    for(int i = 0; i < l.size/2; i++){
        // copy over new values
        temp[i] = l.arr[i];
    }
    
    delete [] l.arr;    // delete old array
    // reassign l.arr
    l.arr = temp;       // right goes into left
    return;
}

//***********************************************************
// name: store_int: add an integer to an int_list
// parameters:
//      int_list & l:
//      int num:
// return: none
// side effects:
//***********************************************************
void store_int(int_list & l, int num){
    // if l is full grow l
    if(l.index == l.size) {
        grow_list(l);
    }
    // store num at index in l
    l.arr[l.index] = num;
        l.index++;
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
void print_int(int_list & l, int index){
    // if index is out of bounds so make sure it doesnt crash
    if(index < 0 || index >= l.size) {
        cout << "ERROR" << endl;
    }
    else {
        cout << l.arr[index] << endl;
    }
}

//Write a main function that instantiates a new int_list. Imagine several use
//    cases for the list: storing a new number in the list, printing a number
//    stored at one position in the list, reset the list.
int main() {
    int_list myList;
    store_int(myList, 7);
    store_int(myList, 78);
    store_int(myList, 1899);
    store_int(myList, 0);
    store_int(myList, 2);
    store_int(myList, 32);
    store_int(myList, 7);
    
    print_int(myList, 0);    //7
    print_int(myList, 2);    //1899
    print_int(nullptr, 0);   //error
    print_int(myList, 100);  //error
    print_int(myList, 0);    //7

    return 0;
}

//Implement and test all 3 functions.
//Submit your .cpp file.
