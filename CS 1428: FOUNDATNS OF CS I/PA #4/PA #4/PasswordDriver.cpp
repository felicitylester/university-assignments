// File Name: PasswordDriver.cpp
//
// Author: Felicity Lester
// Collaborators: None
// Date: 3/20/2023
// Assignment Number: 4
// CS 2308 Spring 2023
//
// This is the main function. It will ask for a filename to store the 
// usernames and encrypted passwords in between executions of the program.
// This file simulates the stored encrypted passwords for users of a computer
// system. Ask user to enter the filename, their netID, old password, and 
// new password:

//****************This is the line of 80 characters in length*******************

#include "PasswordManager.h"
#include <iostream>
#include <cstring>      // allow strings
#include <fstream>      // allows files
using namespace std;

const int SIZE = 4;               // creates an array of 4 instances

//***********************************************************
// search: performs linear search for a username in the
// password manager list.
// pwMan: the array of PasswordManager objects
// netId; the username to find
//
// returns: the position of that username's pwManager if
// found, else -1
//***********************************************************
int search (PasswordManager pwMan[], string netID)
{
    int position = - 1;
    for (int i = 0; i < SIZE; i++)
        if (pwMan[i].getUsername() == netID)
            return i;
            return position;
}


int main() {
    
    PasswordManager pwMan[SIZE]; // Array of PasswordManager objects
    
    // variables
    string file;
    string netID;                 // stores usernames read from file
    string oldPassword;           // input passwords (unencrypted)
    string newPassword;           // input passwords (unencrypted)
    string encryptedPassword;     // stores encrypted passwords read from file
    
    ifstream infile;              // read the encrypted password from this
    
    // declare input file stream variable
    cout << "Please enter the name of the input file:" << endl;
    cin >> file;
    
    infile.open(file);            // open the input file:
    if (infile)
    {
        // successful open, read and set the usernames + encrypted passwords
        for (int i = 0; i < SIZE; i++)
        {
            infile >> netID;
            infile >> encryptedPassword;
            pwMan[i].setUsername(netID);
            pwMan[i].setEncryptedPassword(encryptedPassword);
        }
        infile.close();
    }
    else {
        // check to ensure the input file opened
        cout << file << "Could not open file. Terminating program." << endl;
        exit(0);
    }
    
    // ask the user to enter the filename, their netID, old password,
    // and new password:
    cout << "Please enter your netID:" << endl;
    cin >> netID;
    cout << "Please enter your old password:" << endl;
    cin >> oldPassword;
    cout << "Please enter your new password:" << endl;
    cin >> newPassword;
    cout << endl;
    
    // look up netID
    int position = search (pwMan, netID);
    if (position == -1)
        cout << "NetID is invalid, password not changed." << endl;
    
    else {
        // see if netID is valid
        bool authenticated = pwMan[position].authenticate(oldPassword);
        if (!authenticated)
            cout << "Old password is incorrect." << endl;
        else {
            bool passwordSet = pwMan[position].setNewPassword(newPassword);
            if (!passwordSet)
                cout << "New Password does not meet criteria." << endl;
            else
                cout << "Password has been changed for netID: ";
                cout << netID << endl;
        }
    }
    cout << endl;
    
    // output encrypted form of current passwords
    for (int i = 0; i < SIZE; i++)
    {
        cout << pwMan[i].getUsername () << " ";
        cout << pwMan[i].getEncryptedPassword() << endl;
    }
}
