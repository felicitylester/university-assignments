// File Name: PasswordManager.h
//
// Author: Felicity Lester
// Collaborators: None
// Date: 3/20/2023
// Assignment Number: 4
// CS 2308 Spring 2023
//
// will manage a single password for a given username.

#include <string>
using namespace std;

//***********************************************************
// class PasswordManager: manage a single password for a 
// given username.
// userID: the users ID to verify identity
// encrypt: this takes a password (a string) and returns the 
// encrypted form of the password. 
// meetsCriteria: this takes a string and returns true if 
// it meets the following criteria:
// authenticate: takes a string (a password) and returns true
// if, once encrypted, it matches the encrypted string stored
// in the the member variable. Else returns false.
// setNewPassword: takes a string and verifys if it meets the 
// criteria in meetsCriteria, 
// setEncryptedPassword: takes a string and stores it in the 
// proper member variable.
// getEncryptedPassword: returns the value of the encrypted 
// password stored in the proper member variable.
// setUsername: takes a string and stores it in the proper 
// member variable.
// getUsername: returns the value of the proper member 
// variable.
// 
// returns: 
//***********************************************************
class PasswordManager
{
private:
string userID;          // the users identifier
string encryptedPw;     // the password string, after encryption
    
string encrypt(string) const;
bool meetsCriteria(string) const;

public:
void setUsername(string);
string getUsername() const;
void setEncryptedPassword(string);
string getEncryptedPassword() const;
bool setNewPassword(string);
bool authenticate(string) const;
};
