// File Name: passwordManager.cpp
//
// Author: Felicity Lester
// Collaborators: None
// Date: 3/20/2023
// Assignment Number: 4
// CS 2308 Spring 2023
//
// Breaks down different functions in the PasswordManager class

#include <iostream>
#include <iomanip>
#include <cstring>      // allow strings
#include "PasswordManager.h"
using namespace std;

//***********************************************************
// encrypt: accepts a string to be encrypted. It adds 41 to
// each character in the string and if it goes past 126,
// wraps back around starting at 33
// str: the string to be encrypted
// 
// returns: the new string, with all the characters encrypted
//***********************************************************
string PasswordManager:: encrypt(string str) const
{
    const int SHIFT = 41;       // amount to shift/cycle the ascii
    string encryptedStr;        // encrypted version of a string
    
    for(int index = 0; index < str.length(); index++)
    {
        char x = ((str[index]-33) + SHIFT) % 94 + 33;
        encryptedStr.push_back(x);
    }
    return encryptedStr;
}

//***********************************************************
// meetsCriteria: tests if the argument meets the password
// criteria. It checks for length at least 15, then makes
// sure it contains at least one uppercase letter, one
// lowercase letter and one digit or symbol.
// password: the string to be tested
// 
// returns: true if it meets the required criteria
//***********************************************************
bool PasswordManager:: meetsCriteria(string password) const
{
    const int MIN_PW_LENGTH = 15;   // minimum password length
    
    // checks length
    if (password.length() < MIN_PW_LENGTH)
        return false;
    
    // check for an uppercase, lowercase, digit or symbol
    // need to have at least one of each of them
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    
    for(int i = 0; i < password.length(); i++)
    {
        char ch = password.at(i);
        if (islower(ch))
            hasLower = true;
        if (isupper(ch))
            hasLower = true;
        if ((isdigit(ch)) || (ispunct(ch)))
            hasDigit = true;
    }
    return (hasLower && hasDigit && hasUpper);
}

//***********************************************************
// setUsername: this member function takes a string and 
// stores it in the proper menber variable.
// 
// returns: 
//***********************************************************
void PasswordManager:: setUsername(string name)
{
    userID = name;
}

//***********************************************************
// getUsername: a getter function 
// 
// returns: the value of the proper member variable.
//***********************************************************
string PasswordManager:: getUsername() const
{
    return userID;
}

//***********************************************************
// setEncryptedPassword: (a setter function) takes a string 
// (an already encrypted password) and stores it in the 
// proper member variable.
// pw: the encrypyted string to store
// 
// returns:
//***********************************************************
void PasswordManager:: setEncryptedPassword(string pw)
{
    encryptedPw = pw;
}

//***********************************************************
// setEncryptedPassword: (a setter function) takes a string 
// (an already encrypted password) and stores it in the 
// proper member variable.
// 
// returns:
//***********************************************************
string PasswordManager:: getEncryptedPassword() const
{
    return encryptedPw;
}

//***********************************************************
// setNewPassword: takes a string (a proposed, unencrypted, 
// password). If it meets the criteria in meetsCriteria, it 
// encrypts the password and stores it in the member variable 
// password: the proposed new password
//
// returns: true. Otherwise returns false.
//***********************************************************
bool PasswordManager::setNewPassword(string pw)
{
    if (meetsCriteria(pw))
    {
        encryptedPw = encrypt(pw);
        return true;
    }
    else
        return false;
}


//***********************************************************
// authenticate: takes a string (a password) and returns true 
// if, once encrypted, it matches the encrypted string stored 
// in the the member variable. Else returns false.
// password: the submitted password
//
// returns: true if the encrypted argument matches the stored
// password
//***********************************************************
bool PasswordManager:: authenticate(string pw) const
{
    return (encrypt (pw) == encryptedPw);
}
