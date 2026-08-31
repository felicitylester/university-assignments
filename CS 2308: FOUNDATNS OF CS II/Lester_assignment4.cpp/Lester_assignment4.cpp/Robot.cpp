// Robot.cpp: the implementation file for the Robot class
// Author: Felicity Lester
// Date: 06/30/2023
// Collaborators: None
// Software Name: Multi-Robo Guider (MRG)
// Version: 1.3.0

#include <iostream>
#include <iomanip>  // allow setw()
#include <cstring>  // allow strings
#include <cctype>   // allow characters
#include "Robot.h"

using namespace std;

//****************This is the line of 80 characters in length*******************


//***********************************************************
// name: Robot (constructor)
// parameters: none
// return: none
// side effects: none
//***********************************************************
Robot::Robot() {
    X = 0;
    Y = 0;
    lastCommand = 'S';
    currentSpeed = 1;
    distance = 0;
}

Robot::Robot(const string& robotName){
    // constructor with new name
    name = robotName;
}

// getter methods
int Robot::getX() const {return X;}
int Robot::getY() const {return Y;}
int Robot::getLastCommand() const {return lastCommand;}
int Robot::getCurrentSpeed() const {return currentSpeed;}
int Robot::getDistance() const {return distance;}
string Robot::getName() const {return name;}

// setter methods
void Robot::setX(int newX) {
    X = newX;
}

void Robot::setY(int newY) {
    Y = newY;
}

void Robot::setLastCommand(int newCommand) {
    lastCommand = newCommand;
}

void Robot::setCurrentSpeed(int newSpeed) {
    currentSpeed = newSpeed;
}

void Robot::setDistance(int newDistance) {
    distance = newDistance;
}

void Robot::setName(const string& newName) {
    name = newName;
}

//***********************************************************
// name: printMenu (header to show welcome message)
// parameters: none
// return: none
// side effects: none
//***********************************************************
void Robot::printMenu() {
    cout << "Welcome to MultiRobo Guider." << endl;
    cout << "Please select: " << endl;
    cout << "M- move one robot" << endl;
    cout << "D- print the distance each robot has moved" << endl;
    cout << "U- Update robot list" << endl;
    cout << "R- rename one robot" << endl;
    cout << "Q- quit the program" << endl;
}

//***********************************************************
// name: move (the move options menu)
// parameters:
//      roboList[]: a list of pointers to robots
//      SIZE: the number of robots in roboList// return: none
// side effects: none
//***********************************************************
void Robot::move(Robot* roboList[], int SIZE) {
    string name;
    char d;
    
    cout << "Enter unique identifier (name) and direction to move." << endl;
    cout << "U- up or positive y" << endl;
    cout << "D- down or negative y" << endl;
    cout << "R- right or positive x" << endl;
    cout << "L- left or negative x" << endl;
    cout << "S- stop or start moving" << endl;
    cin >> name;
    cin >> d;

    int index = -1;
    for (int i = 0; i < SIZE; i++) {
        if (roboList[i]->getName() == name) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        cout << "Robot not in list." << endl;
    }
    else {
        roboList[index]->moveRobot(d);
        cout << endl;
        cout << roboList[index]->getName() << "'s position is "
        << roboList[index]->getX() << ","
        << roboList[index]->getY() << endl;
    }
}

//***********************************************************
// name: moveRobot (the move options menu)
// parameters:
//      char d: the direction user chooses to move a robot
// return: none
// side effects: none
//***********************************************************
void Robot::moveRobot(char d) {
    if(toupper(d) != 'S'){
        if(currentSpeed == 0){
            cout << "Cant move a stopped robot!" << endl;
            return;
        }
        // speed increases by one unit every time it moves in
        // the same direction up to a maximum speed of four.
        if(toupper(d) == toupper(lastCommand)){
            if(currentSpeed < 4)
                currentSpeed += 1;
        }
        else{
            currentSpeed = 1;
        }
    }
    // was unsure how to prevent negative positon error
    // used suggested tip from https: //chat.openai.com/?model=text-
    // davinci-002-render-sha
    switch (toupper(d)) {    // prevents letter sensitivity
        case 'U':
            // prevents negative moves
            if (Y + currentSpeed >= 0) {      // increase for Y
                Y += currentSpeed;
            }
            else {
                // error message if move is invalid
                cout << "Invalid move." << endl;
                return;
            }
            break;
        case 'D':
            // prevents negative moves
            if (Y - currentSpeed >= 0) {      // decrease for Y
                Y -= currentSpeed;
            }
            else {
                cout << "Invalid move." << endl;
                return;
            }
            break;
        case 'R':
            // prevents negative moves
            if (X + currentSpeed >= 0) {      // increase for X
                X += currentSpeed;
            }
            else {
                cout << "Invalid move." << endl;
                return;
            }
            break;
        case 'L':
            // prevents negative moves
            if (X - currentSpeed >= 0) {      // decrease for X
                X -= currentSpeed;
            }
            else {
                cout << "Invalid move." << endl;
                return;
            }
            break;
        case 'S':
            // stop or start moving
            cout << endl;
            if (lastCommand == 'S') {
                cout << name << " is now stopped." << endl;
            }
            else {
                cout << name << " cannot move while stopped." << endl;
            }
            break;
        default:    // if input is not an option
            cout << "Invalid direction." << endl;
            return;
    }
    distance += currentSpeed;
    lastCommand = toupper(d);
}

//***********************************************************
// name: Update (allow user to add/ delete Robot from list)
// parameters:
//          numRobos: the size of the list
// return: none
// side effects: none
//***********************************************************
//Either option should be followed by a robot name. “Add” should add a
//robot with the new name to the list of robots. “Delete” should remove
//the robot with the matching name from the list, or do nothing if no
//robot in the list has a name which matches.
void Robot::Update(Robot* roboList[], string name) {
    char choice;
    int size = 0;
    
    // promot user with two new options
    cout << "A- add a robot" << endl;
    cout << "D- delete a robot" << endl;
    cin >> choice;

    if(choice == 'A' || choice == 'a'){
        cout << endl;
        cout << "Enter name for new Robot: ";
        cin >> name;
        cout << endl;
        
        // create a new robot with the given name and add it to the list
        Robot* newRobot = new Robot(name);
        // add new robot to the list
        roboList[size] = newRobot;
        // update size
        size++;
    }
    else if(choice == 'D' || choice == 'd'){
        cout << endl;
        cout << "Enter name for robot you want removed: ";
        cin >> name;
        cout << endl;
        
        // how the program finds if the robot is in the index
        int index = findRobot(roboList, name, size);
        if(index != -1){
            // deletes robot if found
            delete roboList[index];
            // loop fills in gap
            for(int i = index; i < size - 1; i++){
                roboList[i] = roboList[i + 1];
            }
            size--;
            // conformation of deletion
            cout << "Robot " << name << " has been deleted" << endl;
        }else{
            // conformation of deletion
            cout << "Robot not in list." << endl;
        }
    }
    else{
        cout << "Invalid command." << endl;
    }
}

//***********************************************************
// name: makeRoboList
// parameters:
//      numRobos: the size of the list
// return: a pointer to a list of Robot points
// side effects: none
//***********************************************************
Robot** Robot::makeRoboList(int numRobos) {
    // dynamically create the robot list
    Robot** roboList = new Robot*[numRobos];
    
    for (int i = 0; i < numRobos; i++) {
        roboList[i] = new Robot();
        
        string name;
        cout << "Enter name for robot " << i + 1 << ": ";
        cin.ignore();
        
        getline(cin, name);
        roboList[i]->setName(name);
    }
    cout << endl;
    return roboList;
}

//***********************************************************
// name: distance
// parameters:
//      roboList[]: a list of pointers to robots
//      SIZE: the number of robots in roboList
// return: none
// side effects: none
//***********************************************************
void Robot::Distance(Robot* roboList[], int SIZE) {
    // bubble sort - loop used to put the robots in descending order
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (roboList[j]->getDistance() < roboList[j + 1]->getDistance()) {
                // swap robots so the furthest is at the top
                Robot* temp = roboList[j];
                roboList[j] = roboList[j + 1];
                roboList[j + 1] = temp;
            }
        }
    }
    // loop that prints the sorted list
    for (int i = 0; i < SIZE; i++) {
        // was unsure how to use setw() properly
        // used suggested tip from https: //stackoverflow.com/questions
        // /15674097/output-aligned-columns
        cout << setw(20) << left << roboList[i]->getName()
             << left << setw(10) << roboList[i]->getDistance()
             << endl;
    }
}

//***********************************************************
// name: findRobot
// parameters:
//     roboList[]: a list of pointers to robots
//     name: the target unique identifier
//     SIZE: the number of robots in roboList
// return: index of robot or -1
// side effects: might alter value of robots
//***********************************************************
int Robot::findRobot(Robot* roboList[], string name, int SIZE) {
    // const string& = avoid unnecessary string copying and changes
    for (int i = 0; i < SIZE; i++) {
        if (roboList[i]->getName() == name) {
            return i;   // found
        }
    }
    // robots name not found
    return -1;
}

//***********************************************************
// name: ~Robot (destructor = deallocates all the nodes in
// the list)
// parameters: none
// return: none
// side effects: none
//***********************************************************
//Robot::~Robot() {
//    // p points to nullptr
//    Node *p = nullptr;
//    while (top->next != nullptr) {
//        p = top;            // save
//        top = top->next;    // advances
//        // remove the first node
//        delete p;
//    }
//    delete top;
//    p = nullptr;
//    top = nullptr;
//}
