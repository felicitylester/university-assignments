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
#include "RobotList.h"

using namespace std;

// this product is being developed as a generalized
// robotic guidance platform. This product will take guidance input from
// the console and translate those values into positional data for a
// robotic platform.


int main() {
    Robot obj;  // google said this was the way to get my functions to work
    
    // to prevent bugs
    int numRobos = 0;   // initialize to 0
    
    // ask user for the number of robot(s) for array
    cout << "Enter number of robots to track: ";
    cin >> numRobos;    //accept user input for num of robots
    cout << endl;
    
    Robot** myRoboList = obj.makeRoboList(numRobos);

    char choice;              // the users selection from printMenu
    do {
        // do-while loop to repeat the process until user chooses Q or q
        obj.printMenu();         // call 'printMenu' to print options
        cin >> choice;
        cout << endl;
        
        switch (toupper(choice)) {
            case 'M':
                obj.move(myRoboList, numRobos);
                break;
            case 'D':
                obj.Distance(myRoboList, numRobos);
                break;
            case 'U': {
                // U- Update robot list
                string name;
                getline(cin, name);
                cout << endl;
                obj.Update(myRoboList, name);
                break;
            }
            case 'R': {
                cin.ignore();
                string name;
                
                cout << "Enter name you want changed: ";
                getline(cin, name);
                cout << endl;
                
                int index = obj.findRobot(myRoboList, name, numRobos);
                
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
