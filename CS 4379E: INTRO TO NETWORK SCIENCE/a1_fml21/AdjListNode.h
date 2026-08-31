#ifndef _ADJLISTNODE_H_
#define _ADJLISTNODE_H_
#include <iostream>

using namespace std;

struct Node {
   int nodeID;
   int edgeWeight;
   Node *next;
};

class AdjListNode{
public:
   AdjListNode() { head = nullptr; }   // Constructor
   ~AdjListNode();                     // Destructor
   Node* GetHeadNode();                // Get the first node in the list
   void Display();
   void AddNode(int x, int y);         // Append a node the end of the list

private:
   Node* head;
};

// Destructor
AdjListNode::~AdjListNode() {
   while (head != nullptr){
      Node* p = head;
      head = head->next;
      delete p;
   }
}

// Append a node to the end of the list
void AdjListNode::AddNode(int id, int weight) {
    // TODO: Implement appending a node to the end of the linked list
    Node* newNode = new Node();
    newNode->nodeID = id;
    newNode->edgeWeight = weight;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Return the head node pointer
Node* AdjListNode::GetHeadNode() {
   return head;
}

// Display all the elements in the linked list
void AdjListNode::Display() {
   if (head == nullptr) {
      cout << "NULL" << endl;
   } else {
      Node *current = head;
      while (current != nullptr) {
         cout << current->nodeID << ' ' << current->edgeWeight << " -> ";
         current = current->next;
      }
   }
   cout << "NULL"<< endl;
}

#endif
