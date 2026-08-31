// Author: Felicity Lester
// Date: 06/16/2023
// Collaborators: None
// Software Name: Multi-Robo Guider (MRG)
// Version: 1.1.0

#include <iostream>
#include <cstring>  // allow strings
#include <cctype>   // allow characters

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
struct Robot {
    string name;           // robot’s name
    double distance;       // total distance that the robot has traveled
    int currentSpeed;      // speed the robot is traveling
    int X;                 // current X value of the robot’s position
    int Y;                 // current Y value of the robot’s position
    int lastCommand;       // last direction that the robot moved
    
    // constructor of the Robot struct
    Robot() {
        X = 0;
        Y = 0;
        lastCommand = 0;
        currentSpeed = 1;
        distance = 0;

    }
};

// function prototypes
void printMenu();
void move(Robot* roboList[], int size);
void distance(Robot* roboList[], int size);
int findRobot(Robot* roboList[], string name, int size);
void moveRobot(Robot* r, char d);   // r = robot d = direction
Robot** makeRoboList(int numRobos);

//***********************************************************
// name: printMenu (header to show welcome message)
// parameters: none
// return: none
// side effects: none
//***********************************************************
void printMenu() {
    cout << "Welcome to MultiRobo Guider." << endl;
    cout << "Please select: " << endl;
    cout << "M- move" << endl;
    cout << "D- distance" << endl;
    cout << "Q- quit" << endl;
}

//***********************************************************
// name: move (the move options menu)
// parameters: Robot[] roboList: a list of robots
//          size: the number of robots in roboList
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
    cin >> name;
    cin >> d;
    
    int index = findRobot(roboList, name, size);
    
    if (index == -1) {
        cout << "No robot found with this identifier: " << name << endl;
    }
    else {
        moveRobot(roboList[index], d);
        cout << endl;
        cout << roboList[index]->name << "'s position is "
        << roboList[index]->X << ","
        << roboList[index]->Y << endl;
    }
}

//***********************************************************
// name: moveRobot (the move options menu)
// parameters: Robot r: a Robot pointer
//       char d: a character value representing one direction
// return: none
// side effects: none
//***********************************************************
void moveRobot(Robot* r, char d) {
    // was unsure how to prevent negative positon error
    // used suggested tip from https: //chat.openai.com/?model=text-
    // davinci-002-render-sha
    switch (toupper(d)) {       // allows capitalization
    // (so if d == ‘U’, then increase r.y by r.currentSpeed, etc.)
        case 'U':
            // prevents negative moves
            if (r->Y + r->currentSpeed >= 0) {      // increase for Y
                r->Y += r->currentSpeed;
            }
            else {
                // error message if move is invalid
                cout << "Invalid move." << endl;
                return;
            }
            break;
        case 'D':
            // prevents negative moves
            if (r->Y - r->currentSpeed >= 0) {      // decrease for Y
                r->Y -= r->currentSpeed;
            }
            else {
                cout << "Invalid move." << endl;
                return;
            }
            break;
        case 'R':
            // prevents negative moves
            if (r->X + r->currentSpeed >= 0) {      // increase for X
                r->X += r->currentSpeed;
            }
            else {
                cout << "Invalid move." << endl;
                return;
            }
            break;
        case 'L':
            // prevents negative moves
            if (r->X - r->currentSpeed >= 0) {      // decrease for X
                r->X -= r->currentSpeed;
            }
            else {
                cout << "Invalid move." << endl;
                return;
            }
            break;
        default:    // if input is not an option
            cout << "Invalid direction." << endl;
            return;
    }
    // speed increases by one unit every time it moves in
    // the same direction up to a maximum speed of four.
    if (r->lastCommand != 0) {
        r->currentSpeed = min(r->currentSpeed + 1, 4);
    }
    else {
        r->currentSpeed = 1;     // minimum
    }
    r->distance += r->currentSpeed;
    r->lastCommand = toupper(d);
}

//***********************************************************
// name: makeRoboList
// parameters:
//          numRobos: the size of the list
// return: a pointer to this array of Robot pointers
// side effects: none
//***********************************************************
Robot** makeRoboList(int numRobos) {
    // dynamically create the robot list
    Robot** roboList = new Robot*[numRobos];
    
    for (int i = 0; i < numRobos; i++) {
        roboList[i] = new Robot;
        roboList[i]->X = 0;
        roboList[i]->Y = 0;
        roboList[i]->lastCommand = ' ';
        roboList[i]->currentSpeed = 1;
        roboList[i]->distance = 0;
        cout << "Enter name for robot " << i + 1 << ": ";
        cin >> roboList[i]->name;
    }
    cout << endl;
    return roboList;
}

//***********************************************************
// name: distance
// parameters: Robot[] roboList: a list of robots
//          size: the number of robots in roboList
// return: none
// side effects: none
//***********************************************************
void distance(Robot* roboList[], int size) {
    // bubble sort - loop used to put the robots in decending order
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (roboList[j]->distance < roboList[j + 1]->distance) {
                // swap robots so furtest is at top
                Robot* temp = roboList[j];
                roboList[j] = roboList[j + 1];
                roboList[j + 1] = temp;
            }
        }
    }

    // loop that prints the sorted list
    for (int i = 0; i < size; i++) {
        cout << roboList[i]->name << "'s distance is "
             << roboList[i]->distance << endl;
    }
}

//***********************************************************
// name: findRobot
// parameters: Robot* roboList[]: a list of robots
//          string name: the target unique identifier
//          SIZE: the number of robots in roboList
// return: index of robot or -1
// side effects:
//***********************************************************
int findRobot(Robot* roboList[], string name, int size) {
    for (int i = 0; i < size; i++) {
        if (roboList[i]->name == name)
        {
            return i;   // found
        }
    }
    // robots name not found
    return -1;
}


int main() {
    // variables used to avoid bugs
    int numRobos = 0;   // initialize to 0
    Robot** myRoboList;
    
    // ask user for the number of robot(s) for array
    cout << "Enter number of robots to track: ";
    cin >> numRobos;    //accept user input for num of robots
    cout << endl;
    
    
    myRoboList = makeRoboList(numRobos);
    
    char choice;              // the users selection from printMenu
    do {
        //do-while loop to repeat the process until user chooses Q or q
        printMenu();         //call 'printMenu' to print options
        cin >> choice;
        cout << endl;
        
        switch (toupper(choice)) {
            case 'M': {
                move(myRoboList, numRobos);
                break;
            }
            case 'D':
                distance(myRoboList, numRobos);
                break;
            case 'Q':
                // exit the loop when "Q" is chosen
                cout << "Exiting the program. Goodbye..." << endl;
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
