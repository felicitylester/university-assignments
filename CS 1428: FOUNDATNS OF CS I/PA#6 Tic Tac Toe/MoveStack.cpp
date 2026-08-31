// File Name: MoveStack.cpp
//
// Author: Felicity Lester
// Collaborators: None
// Date: 04/17/2023
// Assignment Number: 6
// CS 2308 Spring 2023

#include <iostream>
#include <iomanip>
#include "MoveStack.h"      // specification file
using namespace std;


//***********************************************************
// conductor
// MoveStack: Initializes the stack.
//
// returns:
//***********************************************************
MoveStack::MoveStack() {
    
    stack = nullptr;
    
}

//***********************************************************
// ~MoveStack(): Cleans up the dynamically allocated memory
// (if any). Must be defined, even if empty.
// *p = pointer
// -> = struct pointer operator
//
// returns:
//***********************************************************
MoveStack::~MoveStack() {
    
    Move* p = stack;
    
    while(p != nullptr) {
        Move* temp = p->next;
        delete p;
        p = temp;
    }
}

//***********************************************************
// getSize():
//
// returns: Returns the size of the stack (number of Moves
// currently on the stack).
//***********************************************************
int MoveStack::getSize() {
    
    Move *temp = stack;
    
    int size = 0;
    while(temp != nullptr) {
        size++;
        temp = temp->next;
    }
    return size;
}


//***********************************************************
// Move top(): Returns a move on top of the stack
// (but does not remove it).
//
// returns: 
//***********************************************************
Move MoveStack::top() {

    return *stack;
    
}

//***********************************************************
// push(Move move): Adds the move to the top of the stack.
// asssert: assert will abort the program if its argument
// evaluates to false.
//
// returns:
//***********************************************************
void MoveStack::push(Move move) {
    
    Move *temp = new Move;
    temp->x = move.x;
    temp->y = move.y;
    temp->next = nullptr;
    if(stack == nullptr) {
        stack = temp;
    }
    else {
        temp->next = stack;
        stack = temp;
    }
}
    
//***********************************************************
// pop(): get value to the top then decrement that value  
// (but does not return it)
// temp: temporary variable
//
// returns:
//***********************************************************
void MoveStack::pop() {
    
    Move *temp;
    temp = stack;
    stack = stack->next;
    delete temp;
    
}
