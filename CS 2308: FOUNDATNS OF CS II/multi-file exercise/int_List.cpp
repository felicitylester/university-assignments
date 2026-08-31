// Author: Felicity Lester
// Date: 06/23/2023
// CS 2308.501 class and Prof. Atkinson

#include <iostream>
#include <cstring>  // allow strings
#include <cctype>   // allow characters
#include "int_List.h"


using namespace std;

//***********************************************************
// name: Del Value
// parameters: int target = the number to get rid off
// return: none
// side effects: arr will be altered, index will be altered
//***********************************************************
void Int_List::delValue(int target){
    // cout << "in delValue" << endl;
    if(head == nullptr)
        return;
    Node* leading = head;
    Node* following = nullptr;
    
    while(leading->val == target){
        following = leading;
        leading = leading->next;
        delete following;
        following = nullptr;
        siz--;
        head = leading;
    }
    while(leading != nullptr){
        // we should never get into this loop
        cout << "deleteing body or tail Node" << endl;   //used for checking for bugs
        if(leading->val == target){
            following->next = leading->next;
            delete leading;
            leading = following->next;
            siz--;
        }
        // leading never became null. adding this to avoid infinite loop
        // need to update loop variables
        else{
            following = leading;
            leading = leading->next;
        }
    }
    cout << "leaving delValue" << endl;   //used for checking for bugs
}

//***********************************************************
// name: store_int: add an integer to an int_list
// parameters:
//      int n:
// return: none
// side effects:
//***********************************************************
void Int_List::store_int(int n){
    Node * oldHead = head;
    head = new Node(n);
    head->next = oldHead;
    siz++;
}

//***********************************************************
// name: print_int: print an integer at a given index of an
//       int_list
// parameters:
//      int i:
// return: none
// side effects:
//***********************************************************
void Int_List::print_int(int i) {
    Node* ptr = head;
    
    if (i < 0 || i >= siz) {
        cout << "ERROR! Out of bounds" << endl;
        return;
    }
    for (int j = 0; j < i; j++) {   // cannot use i
        ptr = ptr->next;
    }
    cout << ptr->val << endl;
}

//***********************************************************
// name: Print All
// parameters: none
// return: none
// side effects: none
//***********************************************************
void Int_List::printAll(){
    Node* ptr = head;
    //cout << "running printAll" << endl;       checks for error
    while (ptr != nullptr) {
        cout << ptr->val << ' ';
        ptr = ptr->next;
    }
    cout << endl;
}
