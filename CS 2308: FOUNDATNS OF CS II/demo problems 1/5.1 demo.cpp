// 06/21/2023

#include <iostream>
#include <cstring>
#include <ctime> // allows for complete randomness

using namespace std;

// ### Problem 5.1 ###
//Use this definition of a list Node:

class Node{
    public:
      string val;
      Node* next = nullptr;
};

//Write a function to determine if a list is empty or not.
//Return true if the list is empty, false otherwise.

bool isEmpty(Node* head) {
    return (head == nullptr);
    
    //if (head==nullptr); return true;
    //else return false;
}


// ### Problem 5.2 ###
//Use the definition of a list Node above
//Write a function to count the number of node
//  in a list. Return the number of nodes from the
//  function.
int countNodes(Node* h){
    int counter = 0;
    // transverse the linear
    while(h != nullptr){
        counter++;
        h = h->next;
    }
    return counter;
}


// ### Problem 5.3 ###
//Use the definition of a list Node above
//Write a function that takes these parameters:
//  Node* list
//  Node* newNode
//Insert newNode at the tail of list.
void inseratAtTail(Node* &head, Node* newNode){
    // find the tail
    if(head == nullptr){
        head = newNode;
    }
    else{
        Node * tail = head;
        while(tail->next != nullptr) tail = tail->next;
        // point tail->next to newNode
        tail->next = newNode;
    }
    // point newNode->next to nullptr
        //newNode->next = nullptr;
        //tail->next->next = nullptr;
}


// ### Problem 5.5 ###
//Use the definition of a list Node above
//Write a function to find the middle node in a
//  linked list (i.e. size/2). Return a pointer
//  to the middle node. Return NULL if the list
//  is empty.
void printMiddle(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast != nullptr){
        slow = slow->next;
        fast = fast->next;    //fast is going twice as fast so it jumps two pointers
        // ask if it is safe to move again
        if(fast != nullptr)
            fast->next;
    }
    cout << slow->val << endl;
    
//    int count = countNodes(head);
//    int middle = count/2.0;
//    for(int i = 0; i < middle; i++){
//        head=head->next;
//    }
//    cout << head->val;
//
//    if(isEmpty == nullptr)
//        return head = nullptr;
}

int main(int argc, char** argv){
    Node* head = nullptr;
    
    if(isEmpty(head)) {
        cout << "empty" << endl;
    }
    else {
        cout << "not empty" << endl;
    }
    newNode->val = "a";
    insertAtTail(head, newNode);
    newNode = new Node;
    
    printList(head);
    
    return 0;
}
