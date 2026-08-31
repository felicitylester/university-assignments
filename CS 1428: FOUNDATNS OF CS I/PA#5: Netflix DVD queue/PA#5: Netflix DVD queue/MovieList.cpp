// File Name: MovieList.cpp
//
// Author: Felicity Lester
// Collaborators: None
// Date: 04/06/2023
// Assignment Number: 5
// CS 2308 Spring 2023
//
// Write a program that implement a part of functionality for the Netflix
// DVD queue. It allows a user to create a list of desired movies and
// then sends DVDs with movies on top of this list to the subscriber one
// at a time.

#include <iostream>
#include <iomanip>
#include <string>          // allow strings
#include "MovieList.h"     // specification file
using namespace std;

// function prototypes
    int count();
    void display(ostream& out);
    void addToTop(string title);
    void addToBottom(string title);
    bool remove(int position);
    bool moveToTop(string title);
    string nextLarger(string title);
    void displaySorted(ostream& out);

//***********************************************************
// MovieList: it is the constructor that creates an empty
// list
//
// returns:
//***********************************************************
MovieList::MovieList() {
    // top is pointer
    top = nullptr;
}

//***********************************************************
// ~MovieList: destructor that deallocates all the nodes in
// the list, respectively.
// *p = pointer
// -> = struct pointer operator
//
// returns:
//***********************************************************
MovieList::~MovieList() {
    // p points to nullptr
    MovieNode *p = nullptr;
    while (top->next != nullptr) {
        p = top;            // save
        top = top->next;    // advances
        // remove the first node
        delete p;
    }
    delete top;
    p = nullptr;
    top = nullptr;
}

//***********************************************************
// display(ostream& out): Print movie titles from top to
// bottom, with positions numbered (put a colon and space
// between the number and the movie title) one movie per
// line. Use out << instead of cout <<.
// *t = for title
//
// returns:
//***********************************************************
void MovieList::display(ostream& out) {
    int index = 0;
    // t points to what top points to
    MovieNode *p;
    p = top;
    
    while (p != nullptr) {
        // print titles and positions in node
        out << index << ": " << p->title << endl;
        // moves to next node
        p = p->next;
        // adds to position each loop
        index++;
    }
}

//***********************************************************
// count:
//
// returns: the number of movie titles in the list
//***********************************************************
int MovieList::count() {
    int count = 0;
    // t points to what top points to
    MovieNode *p = top;
    while (p != nullptr) {
        // increments through loop
        count++;
        // moves to next node
        p = p->next;
    }
    return count;
}

//***********************************************************
// addToTop(string title): Add a movie to the top of the list
//
// returns:
//***********************************************************
void MovieList::addToTop(string title) {
    // creates new movie node
    MovieNode *newNode = new MovieNode;
    newNode->title = title;     // to point to a new node
    newNode->next = top;
    top = newNode;
}

//***********************************************************
// addToBottom(string title): Add a movie to the bottom
// of the list
//
// returns:
//***********************************************************
void MovieList::addToBottom(string title) {
    MovieNode *newNode = new MovieNode;
    newNode->title = title;     // to point to a new node
    newNode->next = nullptr;
    
    // list is empty
    if (top == nullptr) {
        top = newNode;
    }
    else {
        // adds the new node to the bottom of list
        MovieNode *p = top;
        
        while (p->next != nullptr) {
            // moves to next node
            p = p->next;
        }
        // moves to next node
        p->next = newNode;
    }
}

//***********************************************************
// moveToTop(string title): Move a movie with given title to
// position 0 (top)
//
// returns:
//***********************************************************
bool MovieList::moveToTop(string title) {
    // if already in position 0
    if (top->title == title) {
        return true;
    }
    
    MovieNode *t = top->next;
    MovieNode *p = top;
    
    while (t != nullptr) {
        if (t->title == title) {
            // p points to predecessor
            // delete a node in linked list
            p->next = t->next;
            t->next = top;
            top = t;
            return true;
        }
        p = t;
        // moves to next node
        t = t->next;
    }
    return false;
}

//***********************************************************
// remove(int n): Remove a movie at the given position.
//
// returns: true if successful, false if there is no movie
// at position n.
//***********************************************************
bool MovieList::remove(int position) {
    if (top == nullptr) {
        return false;
    }
    else if (position == 0) {
        // t points to what top points to
        MovieNode *t = top;
        top = top->next;
        delete t;
        return true;
    }
    else {
        int count = 0;
        MovieNode *p = top;
        while (p != nullptr && count < position - 1) {
            p = p->next;
            count++;
        }
        if (p == nullptr || p->next == nullptr) {
            return false;
        }
        else {
            MovieNode *t = p->next;
            p->next = p->next->next;
            delete t;
            return true;
        }
    }
}

//***********************************************************
// nextLarger(string title):
//
// returns: the move title (string t) that would come next
// after the title t in alphabetical order.
//***********************************************************
string MovieList::nextLarger(string title) {
    string nextLarger = "";
    // t points to what top points to
    MovieNode *t = top;
    
    while (t != nullptr) {
        if (t->title > title) {
            nextLarger = t->title;
            break;
        }
        t = t->next;
    }
    t = top;
    while (t != nullptr) {
        // compares title
        if (t->title < nextLarger && t->title > title) {
            // updates order if needed
            nextLarger = t->title;
        }
        // moves to next node
        t = t->next;
    }
    return nextLarger;
}
    
//***********************************************************
// displaySorted():to output the titles in sorted order with
// positions numbered. Do NOT sort the linked list, it should
// remain in the same order. Call nextLarger on the empty
// string to find the first one.
//
// returns:
//***********************************************************
void MovieList::displaySorted(ostream& out) {
    //Use (i.e. call) nextLarger(string)
    string temp = nextLarger("");
    int position = 0;
    
    while (temp != "") {
        // increment
        position++;
        // display current node using out
        out << position << ": " << temp << endl;
        temp = nextLarger(temp);
    }
}
