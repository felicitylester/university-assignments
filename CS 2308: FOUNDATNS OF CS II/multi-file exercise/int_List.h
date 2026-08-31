// Author: Felicity Lester
// Date: 06/23/2023
// CS 2308.501 class and Prof. Atkinson

#include <iostream>
#include <cstring>  // allow strings
#include <cctype>   // allow characters

using namespace std;

// Re-design the Int_List struct from In-Class 5 as a linked list.
// The Node class should be a private member class of the Int_List class.
// Re-design these member functions of the Int_List class to use a linked list.
// store_int: add an integer to an int_list
// print_int: print an integer at a given index of an int_list
// grow_list: increase the size of the array belonging to an int_list
// print_all: print every value stored in the list
// del_value: remove every occurrence of a particular value from the list
// Add a constructor that creates an empty linked list and a destructor to
//    clean up any dynamically allocated memory that belongs to an Int_List.
class Int_List {
private:
    class Node{
    public:
        int val;
        Node* next = nullptr;
        Node(int v) {
            val = v;
        }
    };
        Node* head = nullptr;
        Node* tail = nullptr;
        int siz = 0;
    public:
        void store_int(int n);
        void print_int(int i);
        void printAll();    //print every value stored in the list
        void delValue(int target);    // remove every occurrence of a particular value from the list
    Int_List() {    // constructor
        head = nullptr;
        tail = nullptr;
        siz = 0;
    }
    ~Int_List() {   // destructor
        Node* leading = head;
        while (leading != nullptr) {
            Node* temp = leading;
            leading = leading->next;
            delete temp;
        }
    }
};
