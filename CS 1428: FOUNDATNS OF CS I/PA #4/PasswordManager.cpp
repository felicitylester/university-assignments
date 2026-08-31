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
// encrypt: takes a password (a string) and returns
// 
// returns: the encrypted form of the password.
//***********************************************************
string PasswordManager:: encrypt(string pw)
{
  string newPw;
  for(int index=0; index < pw.length(); index++)
  {
    int val = (pw[index]-33) + 45;
    int val2 = val % 94 + 33;
    char element = (char) val2;
    newPw = newPw + element;
    }
  return newPw;
  }

//***********************************************************
// meetsCriteria: a private function that takes a string 
// 
// returns: true if it meets the required criteria
//***********************************************************
bool PasswordManager:: meetsCriteria(string pw)
{
  bool upper_flag = 0;
  bool lower_flag = 0;
  bool digit_flag = 0;
  
  if (pw.length() < 15)
    return false;
  else
    for(int index=0; index < pw.length(); index++)
    {
      if (isupper(pw[index]))
        upper_flag = 1;
      if (islower(pw[index]))
        lower_flag = 1;
      if (isdigit(pw[index])) 
        digit_flag = 1;
      }
  if (upper_flag && lower_flag && digit_flag)
    return true;
  else
    // if the criteria are not met
    return false;
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


// returns: true. Otherwise returns false.
//***********************************************************
bool PasswordManager:: authenticate(string pw)
{
  string pwTem = encrypt(pw);
  if (pwTem == encryptedPw)
    return true;
  else
    return false;
}
