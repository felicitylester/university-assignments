// Author: Felicity Lester
// Date: 06/09/2023
// Collaborators: None
// Software Name: Multi-Robo Guider (MRG)
// Version: 1.0.0

#include <iostream>
#include <iomanip>  // alows setprecision
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
    int X = 0;             // current X value of the robot’s position
    int Y = 0;             // current Y value of the robot’s position
    int lastCommand;       // last direction that the robot moved
};

// function prototypes
void printMenu();
void move(Robot roboList[], int size);
void moveRobot(Robot& r, char d);   // r = robot d = direction
int findRobot(Robot roboList[], string name, int size);
void distance(Robot roboList[], int size);


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
void move(Robot roboList[], int size) {
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
        cout << roboList[index].name << "'s position is "
             // this will produce whole number only
             << fixed << setprecision(0) << roboList[index].X << ","
             << fixed << setprecision(0) << roboList[index].Y << endl;
    }
}

//***********************************************************
// name: moveRobot (the move options menu)
// parameters: & r: which robot selected
//          d: will represent the direction moved
// return: none
// side effects: none
//***********************************************************
void moveRobot(Robot& r, char d) {
    switch (toupper(d)) {       // allows capitalization
    // (so if d == ‘U’, then increase r.y by r.currentSpeed, etc.)
        case 'U':
            r.Y += r.currentSpeed;      // increse for Y
            break;
        case 'D':
            r.Y -= r.currentSpeed;      // decrease for Y
            break;
        case 'R':
            r.X += r.currentSpeed;      // increse for X
            break;
        case 'L':
            r.X -= r.currentSpeed;      // decrease for X
            break;
        default:        // if input is not an option
            cout << "Invalid direction." << endl;
            return;
    }
    // speed increases by one unit every time it moves in
    // the same direction up to a maximum speed of four.
    if (toupper(d) == r.lastCommand) {
        r.currentSpeed = min(r.currentSpeed + 1, 4);
    }
    else {
        r.currentSpeed = 1;     // minimum
    }
    r.distance += r.currentSpeed;
    r.lastCommand = toupper(d);
}

//***********************************************************
// name: findRobot
// parameters: Robot[] roboList: a list of robots
//          string name: the target unique identifier
//          size: the number of robots in roboList
// return: index of robot or -1
// side effects:
//***********************************************************
int findRobot(Robot roboList[], string name, int size) {

    for (int i = 0; i < size; i++) {
        if (roboList[i].name == name)
        {
            return i;   // found
        }
    }
    // robots name not found
    return -1;
}

//***********************************************************
// name: distance
// parameters: Robot[] roboList: a list of robots
//          size: the number of robots in roboList
// return: none
// side effects: none
//***********************************************************
void distance(Robot roboList[], int size) {
    string name; // Move the declaration of the name variable here
    cout << "Enter unique identifier (name) to get distance." << endl;
    cin >> name;

    int index = findRobot(roboList, name, size);
    if (index == -1) {
        cout << "No robot found with this identifier: " << name << endl;
    }
    else {
        cout << "Distance completed by " << roboList[index].name << ": "
            << roboList[index].distance << endl;
    }
}

     
int main() {
    // variables used to avoid bugs
    const int MAX_ROBOTS = 100;
    Robot roboList[MAX_ROBOTS];
    int size = 0;           // prevent garbage
    string name;
            
    //ask user for the number of robot(s)
    cout << "Enter number of robots to track:" << endl;
    cin >> size;    //accept user input for num of robots
    cout << endl;
    
    for (int i = 0; i < size; i++) {
        cout << "Enter name for robot(s) " << endl;
        cin >> roboList[i].name;
        cout << endl;
    }
    

    char choice;              // the users selection from printMenu
    do {
        //do-while loop to repeat the process until user chooses Q or q
        printMenu();         //call 'printMenu' to print list of options
        cin >> choice;
        cout << endl;
        
        // Validate the menu selection.
        // toupper = comparison is case-insensitive.
        if (toupper(choice) == 'Q') {
            cout << "Exiting the program. Goodbye..." << endl;
            break; // Exit the loop when "Q" is chosen
        }

        if (toupper(choice) == 'M') {
            move(roboList, size);
        }
        else if (toupper(choice) == 'D') {
            distance(roboList, size);
        }

        cout << endl;
    } while (true);

    return 0;
}
