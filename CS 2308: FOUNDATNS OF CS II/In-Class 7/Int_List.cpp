// Felicity Lester
// June 22, 2023
// CS 2308.501 class and Prof. Atkinson

#include <iostream>
#include <iomanip>  // allow setw()
#include <cstring>  // allow strings
#include <cctype>   // allow characters

using namespace std;

#include <iostream>


//****************This is the line of 80 characters in length*******************


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
        Node* head;
        Node* tail;
        int siz;
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
    
    myList.printAll();
    myList.delValue(3); // removes all 3's
    myList.printAll();
    
    return 0;
}
//Implement your new functions and test your code.
//Submit your .cpp file

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
//      int siz:
// return: none
// side effects:
//***********************************************************
void Int_List::print_int(int i) {
    if (i < 0 || i >= siz) {
        cout << "ERROR" << endl;
        return;
    }

    Node* leading = head;
    for (int j = 0; j < i; j++) {
        leading = leading->next;
    }

    cout << leading->val << endl;
}

//***********************************************************
// name: Print All
// parameters: int i
// return: none
// side effects: none
//***********************************************************
void Int_List::printAll(){
    Node* leading = head;
    while (leading != nullptr) {
        cout << leading->val << " ";
        leading = leading->next;
    }
    cout << endl;
}

//***********************************************************
// name: Del Value
// parameters: int target = the number to get rid off
// return: none
// side effects: arr will be altered, index will be altered
//***********************************************************
void Int_List::delValue(int target){
//    if(head == nullptr)
//        return;
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
        if(leading->val == target){
            following->next = leading->next;
            delete leading;
            leading = following->next;
            siz--;
        }
    }
}
