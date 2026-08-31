// Robot.h: the header file for the Robot class
// Author: Felicity Lester
// Date: 06/30/2023
// Collaborators: None
// Software Name: Multi-Robo Guider (MRG)
// Version: 1.3.0

#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <cstring>  // allow strings
#include <cctype>   // allow characters

using namespace std;

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
    Robot();    // default constructor
    Robot(const string& robotName);
    void printMenu();
    void move(Robot* roboList[], int SIZE);
    void moveRobot(char d);
    void Update(Robot* roboList[], string name);
    Robot** makeRoboList(int numRobos);
    void Distance(Robot* roboList[], int SIZE);
    int findRobot(Robot* roboList[], string name, int SIZE);

    // getter functions
    int getX() const;
    int getY() const;
    int getLastCommand() const;
    int getCurrentSpeed() const;
    int getDistance() const;
    string getName() const;

    // setter functions
    void setX(int newX);
    void setY(int newY);
    void setLastCommand(int newCommand);
    void setCurrentSpeed(int newSpeed);
    void setDistance(int newDistance);
    void setName(const string& newName);
    
};

#endif  // ROBOT_H
