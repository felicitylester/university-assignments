// Author: Felicity Lester
// Date: 06/23/2023
// Collaborators: None
// Software Name: Multi-Robo Guider (MRG)
// Version: 1.2.0

#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>  // allow setw()
#include <cstring>  // allow strings
#include <ctype.h>  // allow characters

using namespace std;

// this product is being developed as a generalized
// robotic guidance platform. This product will take guidance input from
// the console and translate those values into positional data for a
// robotic platform.

//****************This is the line of 80 characters in length*******************


//***********************************************************
// name: Robotics
// parameters:
// return: none
// side effects: should store the robot’s name, speed, and
// positional data
//***********************************************************
class Robot {
    private:                   // member variables should be private
        int X;                 // current X value of the robot’s position
        int Y;                 // current Y value of the robot’s position
        char lastCommand;      // last direction that the robot moved
        int currentSpeed;      // speed the robot is traveling
        int distance;          // total distance that the robot has traveled
        string name;           // robot’s name
    public:
        // constructor of the Robot struct
        Robot() {
            X = 0;
            Y = 0;
            lastCommand = 'Z';
            currentSpeed = 1;
            distance = 0;
        }
        void moveRobot(char d);
    
    // getters and setters
    string getName() const {return name;}
    int getDistance() const {return distance;}
    int getX() const {return X;}
    int getY() const {return Y;}
    
//    int getLastCommand() const {return lastCommand;}
//    int getCurrentSpeed() const {return currentSpeed;}

    // Setter methods
    void setName(const string& newName) {name = newName;}
    
//    void setX(int newX) {X = newX;}
//    void setY(int newY) {Y = newY;}
//    void setLastCommand(int newCommand) {lastCommand = newCommand;}
//    void setCurrentSpeed(int newSpeed) {currentSpeed = newSpeed;}
//    void setDistance(double newDistance) {distance = newDistance;}
    
};


//***********************************************************
// name: printMenu (header to show welcome message)
// parameters: none
// return: none
// side effects: none
//***********************************************************
void printMenu() {
    cout << "Welcome to MultiRobo Guider." << endl;
    cout << "Please select: " << endl;
    cout << "M- move one robot" << endl;
    cout << "D- print the distance each robot has moved" << endl;
    cout << "R- rename one robot" << endl;
    cout << "Q- quit the program" << endl;
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
int findRobot(Robot* roboList[], const string& name, int SIZE) {
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
// name: moveRobot (the move options menu)
// parameters:
//      r: a pointer to a Robot
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
    switch (toupper(d)) {       // allows capitalization
    // (so if d == ‘U’, then increase r.y by r.currentSpeed, etc.)
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
            if (currentSpeed >= 1) {
                cout << name << " is now stopped." << endl;
                currentSpeed = 0;
            }
            else {
                cout << name << " is now started." << endl;
                currentSpeed = 1;
            }
            break;
        default:    // if input is not an option
            cout << "Invalid direction." << endl;
            return;
    }
    distance += currentSpeed;
    lastCommand = toupper(d);
    return;
}

//***********************************************************
// name: move (the move options menu)
// parameters: Robot[] roboList: a list of robots
//      size: the number of robots in roboList
// return: none
// side effects: none
//***********************************************************
void move(Robot* roboList[], int size) {
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
    for (int i = 0; i < size; i++) {
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
// name: makeRoboList
// parameters:
//      numRobos: the size of the list
// return: a pointer to a list of Robot points
// side effects: none
//***********************************************************
Robot** makeRoboList(int numRobos) {
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
void distance(Robot* roboList[], int SIZE) {
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
// name: sortRoboList
// parameters:
//     roboList[]: a list of pointers to robots
//     SIZE: the number of robots in roboList
// return: none
// side effects: decending by distance
//***********************************************************
//void Robot::sortRoboList(Robot* roboList[], int SIZE) {
//    // bubble sort
//    // iterate of upperBounds for SIZE-1 to 1
//    for(int upperBound = SIZE - 1; upperBound > 0; upperBound--){
//        // iterate of all indexes from 0 to upperBound
//        for(int i = 0; i < upperBound; i++){
//            // compare every pair, swap if out of order
//            // compare list[i' to list[i + 1]
//            if(roboList[i]->getDistance() < roboList[i + 1]->getDistance()){
//                // swap
//                Robot* temp;
//                temp = roboList[i];
//                roboList[i] = roboList[i + 1];
//                roboList[i + 1] = temp;
//            }
//        }
//    }
//    return;
//}

int main() {
    // variables used to avoid bugs
    int numRobos = 0;   // initialize to 0
    
    // ask user for the number of robot(s) for array
    cout << "Enter number of robots to track: ";
    cin >> numRobos;
    cout << endl;
    
    Robot** myRoboList = makeRoboList(numRobos);

    char choice;              // the users selection from printMenu
    do {
        // do-while loop to repeat the process until user chooses Q or q
        printMenu();         // call 'printMenu' to print options
        cin >> choice;
        cout << endl;
        
        switch (toupper(choice)) {
            case 'M':
                move(myRoboList, numRobos);
                break;
            case 'D':
                distance(myRoboList, numRobos);
                break;
            case 'R': {
                cin.ignore();
                string name;
                
                cout << "Enter name you want changed: ";
                getline(cin, name);
                cout << endl;
                
                int index = findRobot(myRoboList, name, numRobos);
                
                if (index != -1) {
                    string newName;
                    cout << "Enter new name: ";
                    getline(cin, newName);
                    
                    myRoboList[index]->setName(newName);
                    cout << "\nRobot " << name << "'s new name is: " << newName << endl;
                }
                else {
                    cout << "Robot not in list." << endl;
                }
                break;
            }
            case 'Q':
                // exit the loop when "Q" is chosen
                cout << "Exiting the program. Goodbye :)" << endl;
                break;
            default:
                cout << "Invalid command!" << endl;
                break;
        }
        cout << endl;
    } while (toupper(choice) != 'Q');
    
    // deallocate each individual Robot data
    for (int i = 0; i < numRobos; i++) {
        delete myRoboList[i];
    }
    // deallocates the array of Robot*
    delete[] myRoboList;
    
    return 0;
}
