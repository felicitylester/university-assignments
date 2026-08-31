//
// Author : Felicity Lester
//
// Serial Number / s : 28
//
// Programming Assignment Number 4
//
// Fall 2023 - CS 3358 - Your Section Number
//
// Due Date : Monday October 16th, 2023
//
// Instructor: Husain Gholoom.
//
// This program is designed to simulate a list of menu options to create an
// ADT stack / queue using a linked List ADT with actual pointers.

#include <iostream>
#include <ctime>        // allow seeding ran num gen
#include <cstdlib>      // allow rand
#include <iomanip>      // allow setw
#include <algorithm>

using namespace std;

// for linked list
struct Node {
    char data;
    Node* link;
};

class Stack {
private:
    // pointer to the top of the stack
    Node* top;

public:
    // constructor
    Stack() {
        top = nullptr;
    }
    
    //***********************************************************
    // name: push -> pushes the argument onto the stack.
    // parameters:
    //      char element
    // return: none
    // side effects: start of stack
    //***********************************************************
    void push(char data) {
           Node* newNode = new Node{data, top};
           top = newNode;
    }
    
    //***********************************************************
    // name: pop -> pops the value at the top of the stack off,
    //       and returns it as the result.
    // parameters:
    // return: none
    // side effects: warning message if stack is empty
    //***********************************************************
    void pop() {
        if (top) {
            Node* temp = top;
            top = top->link;
            delete temp;
        } else {
            cout << "Not applicable. Stack is empty.\n" << endl;
        }
    }
    
    //***********************************************************
    // name: displayStack -> displays the current stack
    // parameters:
    // return: none
    // side effects: current stack
    //***********************************************************
    void displayStack() const {
        Node* current = top;
        cout << "Current Stack: ";
        while (current) {
            cout << current->data << " ";
            current = current->link;
        }
        cout << endl << endl << endl;
    }

    //***********************************************************
    // name: removeWFromStack -> removes W from stack
    // parameters:
    // return: none
    // side effects: Error message displayed if stack is empty.
    //***********************************************************
    void removeWFromStack() {
        Node* current = top;
        Node* prev = nullptr;

        while (current) {
            if (current->data == 'W') {
                if (prev == nullptr) {
                    pop();
                } else {
                    prev->link = current->link;
                    delete current;
                }
                return;
            }

            prev = current;
            current = current->link;
        }

        cout << "Error: 'W' not found in the stack.\n" << endl;
    }
    
    //***********************************************************
    // name: deleteStack -> empties elements in stack
    // parameters:
    // return: none
    // side effects: makes empty stack
    //***********************************************************
    void deleteStack() {
        while (top) {
            Node* temp = top;
            top = top->link;
            delete temp;
        }
    }
};


class Queue {
private:
    Node* front;
    Node* rear;
    
public:
    //***********************************************************
    // name: Queue -> constructor
    // parameters:
    // return: none
    // side effects:
    //***********************************************************
    Queue() : front(nullptr), rear(nullptr) {}
    
    //***********************************************************
    // name: enqueue -> inserts a value at the rear of the queue.
    // parameters: char element
    // return:
    // side effects:
    //***********************************************************
    void enqueue(char element) {
        Node* newNode = new Node;
        newNode->data = element;
        newNode->link = nullptr;
        
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->link = newNode;
            rear = newNode;
        }
    }
    
    //***********************************************************
    // name: dequeue -> removes the value at the front of the
    //       queue and returns the value.
    // parameters:
    // return:
    // side effects: current stack
    //***********************************************************
    void dequeue() {
        if (front) {
            Node* temp = front;
            front = front->link;
            delete temp;
        } else {
            cout << "Not applicable. Cannot dequeue.\n" << endl;
        }
    }
    
    //***********************************************************
    // name: displayQueue -> displays the current queue
    // parameters:
    // return: none
    // side effects: current queue
    //***********************************************************
    void displayQueue() const {
        Node* current = front;
        cout << "Current Queue: ";
        while (current) {
            cout << current->data << " ";
            current = current->link;
        }
        cout << endl << endl << endl;
    }
    
    //***********************************************************
    // name: removeXFromQueue -> remove an ‘X’ from the queue
    // parameters:
    // return:
    // side effects: Error message displayed if queue is empty.
    //***********************************************************
    void removeXFromQueue() {
        if (front == nullptr) {
            cout << "Error: Queue is empty. Cannot remove 'X'.\n" << endl;
            return;
        }

        if (front->data == 'X') {
            dequeue();
            return;
        }

        Node* current = front;
        Node* prev = nullptr;

        while (current) {
            if (current->data == 'X') {
                prev->link = current->link;
                delete current;
                return;
            }

            prev = current;
            current = current->link;
        }

        cout << "Error: 'X' not found in the queue.\n" << endl;
    }

    //***********************************************************
    // name: insertSecondLocation -> insert an element ‘A’ at in
    //       the 2nd location in the queue.
    // parameters: char elementA
    // return:
    // side effects: element ‘A’ in second position
    //***********************************************************
    void insertSecondLocation(char elementA) {
        Node* newNode = new Node;
        newNode->data = elementA;
        newNode->link = nullptr;

        if (front == nullptr) {
            front = rear = newNode;
        } else if (front->link == nullptr) {
            newNode->link = front;
            front = newNode;
        } else {
            newNode->link = front->link;
            front->link = newNode;
        }

        cout << "Element 'A' inserted at the 2nd location in the queue.\n" << endl;
    }
    
    //***********************************************************
    // name: getFrontElement -> return the front node.
    // parameters:
    // return: return the front node.
    // side effects:
    //***********************************************************
    Node* getFrontElement() const {
        // Return the front node.
        return front;
    }
    
    //***********************************************************
    // name: deleteQueue -> empties elements in queue
    // parameters:
    // return: none
    // side effects: makes empty queue
    //***********************************************************
    void deleteQueue() {
        while (front) {
            Node* temp = front;
            front = front->link;
            delete temp;
        }
        rear = nullptr;
    }
};


void displayStack(const Stack& stack) {
    stack.displayStack();
}

void displayQueue(const Queue& queue) {
    queue.displayQueue();
}

//***********************************************************
// name: insertXInStack -> insert 'X' into the stack
// parameters: Stack& stack
// return:
// side effects:
//***********************************************************
void insertXInStack(Stack& stack) {
    stack.push('X');
}

//***********************************************************
// name: insertXInQueue -> insert 'X' into the queue
// parameters: Queue& queue
// return:
// side effects:
//***********************************************************
void insertXInQueue(Queue& queue) {
    queue.enqueue('X');
}

//***********************************************************
// name: removeFirstFromQueue -> remove the first element
//       from the queue
// parameters: Queue& queue
// return:
// side effects:
//***********************************************************
void removeFirstFromQueue(Queue& queue) {
    queue.dequeue();
}

//***********************************************************
// name: minNumOfElements -> verifies queue has enough
//       elements(n)
// parameters: const Queue& queue, int n
// return:
// side effects: returns true of false if enough elements
//***********************************************************
bool minNumOfElements(const Queue& queue, int n) {
    Node* current = queue.getFrontElement();
    for (int i = 0; i < n; i++) {
        if (current == nullptr) {
            return false;
        }
        current = current->link;
    }
    return true;
}

//***********************************************************
// name: removeFourthFromQueue -> remove the fourth element
//       from the queue
// parameters: Queue& queue
// return:
// side effects:
//***********************************************************
void removeFourthFromQueue(Queue& queue) {
    if (!minNumOfElements(queue, 4)) {
        cout << "Not enough elements in the queue!\n" << endl;
        return;
    }

    // Use the dequeue function to remove the fourth element.
    for (int i = 0; i < 3; i++) {
        queue.dequeue();
    }
}

//***********************************************************
// name: findMinAndMax -> find Min element in the queue, and
//       Max element in the queue.
// parameters: Queue& queue, char& minElement, char& maxElement
// return:
// side effects: displayes the min and max
//***********************************************************
void findMinAndMax(Queue& queue, char& minElement, char& maxElement) {
    Node* frontNode = queue.getFrontElement();

    if (frontNode == nullptr) {
        cout << "Cannot find queue min and max.\n" << endl;
        return;
    }

    minElement = frontNode->data;
    maxElement = frontNode->data;

    Node* current = frontNode;
    while (current) {
        if (current->data < minElement) {
            minElement = current->data;
        }
        if (current->data > maxElement) {
            maxElement = current->data;
        }
        current = current->link;
    }
}


int main(int argc, const char* argv[]) {
    srand(static_cast<unsigned>(time(nullptr)));

    Stack stack;
    Queue queue;
    char userChoice;

    while (true) {
        cout << "A. Build a stack that consists of 5 random capital letters that are >= ‘C’ and <= ‘K’" << endl;
        cout << "B. Build a queue that consists of 5 capital letters that are >= ‘H’ and <= ‘S’" << endl;
        cout << "C. Insert the element ‘W’ in the stack (LIFO)." << endl;
        cout << "D. Insert the element ‘X’ in the stack (LIFO)." << endl;
        cout << "E. Remove an element from the stack (LIFO)." << endl;
        cout << "F. Insert the element ‘X’ in the queue (FIFO)." << endl;
        cout << "G. Insert an element ‘A’ at the 2nd location in the queue." << endl;
        cout << "H. Remove the first element from the queue (FIFO)." << endl;
        cout << "I. Remove the 4th element from the queue." << endl;
        cout << "J. Find the Min and Max elements in the queue." << endl;
        cout << "K. Delete the entire stack." << endl;
        cout << "L. Remove ‘W’ from the stack." << endl;
        cout << "M. Delete the entire queue." << endl;
        cout << "N. Remove an ‘X’ from the queue." << endl;
        cout << "X. Exit the program." << endl;
        
        cout << "\nEnter a letter from A - X: ";
        cin >> userChoice;
        cout << endl;
        switch (userChoice) {
            case 'A':
                for (int i = 0; i < 5; i++) {
                    char randomLetter = 'C' + rand() % 8;
                    stack.push(randomLetter);
                }
                displayStack(stack);
                //cout << "Stack built with 5 random capital letters.\n" << endl;
                break;
            case 'B':
                for (int i = 0; i < 5; i++) {
                    char randomLetter = 'H' + rand() % 8;
                    queue.enqueue(randomLetter);
                }
                queue.displayQueue(); // display the queue's contents
                //cout << "Queue built with 5 random capital letters.\n" << endl;
                break;
            case 'C':
                stack.push('W');
                cout << "Element 'W' inserted in the stack (LIFO).\n" << endl;
                displayStack(stack);
                break;
            case 'D':
                insertXInStack(stack);
                cout << "Element 'X' inserted in the stack (LIFO).\n" << endl;
                displayStack(stack);
                break;
            case 'E':
                stack.pop();
                cout << "Element removed from the stack (LIFO).\n" << endl;
                displayStack(stack);
                break;
            case 'F':
                insertXInQueue(queue);
                cout << "Element 'X' inserted in the queue (FIFO).\n" << endl;
                displayQueue(queue);
                break;
            case 'G':
                cout << "Enter the element 'A' to insert at the 2nd location in the queue: ";
                char elementA;
                cin >> elementA;
                queue.insertSecondLocation(elementA);
                displayQueue(queue);
                break;
            case 'H':
                removeFirstFromQueue(queue);
                cout << "The first element removed from the queue (FIFO).\n" << endl;
                displayQueue(queue);
                break;
            case 'I':
                removeFourthFromQueue(queue);
                cout << "The 4th element removed from the queue.\n" << endl;
                displayQueue(queue);
                break;
            case 'J':
                char minElement, maxElement;
                findMinAndMax(queue, minElement, maxElement);
                cout << "Min Element in Queue: \n" << minElement << endl;
                cout << "Max Element in Queue: \n" << maxElement << endl;
                break;
            case 'K':
                stack.deleteStack();
                cout << "Stack deleted!\n" << endl;
                displayStack(stack);
                break;
            case 'L':
                stack.removeWFromStack();
                displayStack(stack);
                break;
            case 'M':
                queue.deleteQueue();
                cout << "Queue deleted!\n" << endl;
                displayQueue(queue);
                break;
            case 'N':
                queue.removeXFromQueue();
                
                break;
            case 'X':
                // clears the elements in stack and queue
                stack.deleteStack();
                queue.deleteQueue();
                cout << "Exiting the program. \n" << endl;
                
                
                cout << "LL / Stack & Queue Program is Implemented By:" << endl;
                cout << "Felicity Lester - October 16th, 2023" << endl;

                return 0;
            default:
                cout << "Invalid choice. Try again.\n\n" << endl;
        }
    }

    return 0;
}
