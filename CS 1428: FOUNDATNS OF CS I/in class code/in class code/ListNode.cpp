//
//  main.cpp
//  in class code
//
//  Created by Felicity Lester on 3/23/23.
// make 5.0 point to the 1.2 first
#include <iostream>
#include <iomanip>
using namespace std;

struct ListNode     // the node data type
{
    double value;   // data
    ListNode *next; // ptr to next node
};

int main() {
    //task 1: create an empty list (named head)
    ListNode *head = nullptr;
    
    //task 2: create an anonymous new node (make newNode point to it) 10.1
    ListNode *newNode = new ListNode;   //newNode = temportaty pointer
    newNode->value = 1.2;
    newNode->next = nullptr;
    
    //task 3: add the new node to the front of the list (2 stmts)
    //newNOde->next = head;
    head = newNode;
    
    //make 2 more nodes and add to the front of the list 13.2 8.7
    newNode = new ListNode;   //newNode = temportaty pointer
    newNode->value = 5.0;
    newNode->next = nullptr;
    
    newNode->next = head;
    head = newNode;
    
    // need to copy above top lines to make new
    newNode = new ListNode;   //newNode = temportaty pointer
    newNode->value = 7.3;     // 7.3 points to 5.0
    newNode->next = nullptr;
    
    newNode->next = head;
    head = newNode;
    
    // task 4: output all the values in the list (traversal using p)
    // use head pointer only
    cout << head->value << endl;
    cout << head->next->value << endl;
    cout << head->next->next->value << endl;
    
    // then use p
    // then put in a loop
    
    ListNode *p;
    p = head;
    while (p->next != nullptr)
    {
        cout << p->value << endl;
        p = p->next;
    }
    
    return 0;
}
