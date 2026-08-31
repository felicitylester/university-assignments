// Author: Felicity Lester
// Date: 06/23/2023
// CS 2308.501 class and Prof. Atkinson

#include <iostream>
#include <cstring>  // allow strings
#include <cctype>   // allow characters
#include "int_List.h"

using namespace std;

//****************This is the line of 80 characters in length*******************

// Re-use the main function which you developed to test the Int_List
//      class without changes. The interface of your new class should be
//      identical to the old class.
int main() {
    Int_List myList;
    myList.store_int(3);
    myList.store_int(3);
    myList.store_int(5);
    myList.store_int(3);
    myList.store_int(5);
    
    myList.printAll();      // 5 3 5 3 3
    myList.print_int(0);    // 3
    myList.print_int(4);    // 5
    myList.delValue(3);     // removes all 3's
    myList.printAll();      // 5 5
    
    return 0;
}
//Implement your new functions and test your code.
//Submit your .cpp file

// first output
// 5 3 5 3 3    incorrect    printAll or print_int being problematic
// expect

// second output
// 5 3 5 3 3
// 5
// 3
// deleteing body or tail Node
// deleteing body or tail Node
// deleteing body or tail Node
// 5 5 3

// third output
// 5 3 5 3 3
// 5
// 3
// deleteing body or tail Node
// deleteing body or tail Node
// deleteing body or tail Node
// deleteing body or tail Node
// deleteing body or tail Node
// leaving delValue
// 5 5
