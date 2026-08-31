// RobotList.h: the header file for the RobotList class
// Author: Felicity Lester
// Date: 06/30/2023
// Collaborators: None
// Software Name: Multi-Robo Guider (MRG)
// Version: 1.3.0

#ifndef ROBOTLIST_H
#define ROBOTLIST_H

#include <iostream>
#include <cstring>  // allow strings
#include <cctype>   // allow characters
#include "Robot.h"

using namespace std;

// 5.2 RobotList class (new for Version 1.3)

class RobotList{
private:
    class Node{
    public:
        Node(Robot* robot) : val(robot), next(nullptr) {}
        
        Robot* getVal() const {
            return val;
        }
        
        void setVal(Robot* robot) {
            val = robot;
        }
        
        Node* getNext() const {
            return next;
        }
        
        void setNext(Node* node) {
            next = node;
        }
        
    private:
        Robot* val;
        Node* next;
    };
    
    Node* head;
    
public:
    RobotList(Robot* robot);   // constructor
    ~RobotList();   // destructor
    void delRobot(const string& name);
    void addRobot(Robot* robot);
    Robot* findRobot(const string& name) const;
};

#endif  // ROBOTLIST.H
