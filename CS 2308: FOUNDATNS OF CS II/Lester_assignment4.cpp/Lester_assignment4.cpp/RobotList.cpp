// RobotList.cpp: the implementation file for RobotList
// Author: Felicity Lester
// Date: 06/30/2023
// Collaborators: None
// Software Name: Multi-Robo Guider (MRG)
// Version: 1.3.0

#include <iostream>
#include <iomanip>  // allow setw()
#include <cstring>  // allow strings
#include <cctype>   // allow characters
#include "RobotList.h"
#include "Robot.h"

using namespace std;


//***********************************************************
// name: RobotList (constructor)
// parameters: none
// return: none
// side effects: none
//***********************************************************
RobotList::RobotList(Robot* robot) {
    head = nullptr;
}

//***********************************************************
// name: ~RobotList (destructor)
// parameters: none
// return: none
// side effects: none
//***********************************************************
RobotList::~RobotList() {
    Node* current = head;
    while(current != nullptr) {
        Node* next = current->getNext();
        delete current->getVal();
        delete current;
        current = next;
    }
}

//***********************************************************
// name: addRobot
// parameters:
//      Robot* robot: a list of robots
// return: none
// side effects: new robot not created
//***********************************************************
void RobotList::addRobot(Robot* robot) {
    Node* newNode = new Node(robot);
    
    newNode->setNext(head);
    head = newNode;
}

//***********************************************************
// name: delRobot
// parameters:
//      string name: the target unique identifier
// return:
// side effects:
//***********************************************************
void RobotList::delRobot(const string& name) {
    Node* current = head;
    Node* previous = nullptr;

    while(current != nullptr) {
        if(current->getVal()->getName() == name) {
            if(previous == nullptr) {
                // delete the head node
                head = current->getNext();
            }
            else{
                previous->setNext(current->getNext());
            }
            delete current->getVal();
            delete current;
            cout << "Robot " << name << " has been deleted." << endl;
            return;     // exit after deleting the robot
        }
        previous = current;
        current = current->getNext();
    }
    cout << "Robot not in list." << endl;
}

//***********************************************************
// name: findRobot
// parameters:
//     name: the target unique identifier
// return: nullptr if robot not found in list
// side effects: might alter value of robots
//***********************************************************
Robot* RobotList::findRobot(const string& name) const {
    Node* current = head;
    while(current != nullptr){
        if(current->getVal()->getName() == name){
            return current->getVal();
        }
        current = current->getNext();
    }
    return nullptr;     // robot not found
}
