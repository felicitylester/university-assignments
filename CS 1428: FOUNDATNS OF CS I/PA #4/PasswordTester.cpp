
#include "PasswordManager.h"
#include <iostream>
using namespace std;

int main ()
{
    PasswordManager pwMan; 
    
    pwMan.setUsername("tom555");
    pwMan.setEncryptedPassword(",-./jklmZ[\\]JiLM");
    
    cout << "Net ID: " << pwMan.getUsername() << endl;
    cout << "Encrypted Password: " << pwMan.getEncryptedPassword() << endl;
    
    string newPassword = "ABCDabcdABCDabcd"; //does not meet criteria
    if (pwMan.setNewPassword(newPassword))
        cout << "1failed" << endl;
    else
        cout << "1passed" << endl;

    newPassword = "ABCDabcd1234***"; //meets criteria
    if (pwMan.setNewPassword(newPassword))
        cout << "2passed" << endl;
    else
        cout << "2failed" << endl;
    
    if (pwMan.authenticate(newPassword))
        cout << "3passed" << endl;
    else
        cout << "3failed" << endl;
    
    newPassword = "ABCDabcd12345**"; //wrong password
    if (pwMan.authenticate(newPassword))
        cout << "4failed" << endl;
    else
        cout << "4passed" << endl;
}

/*
 expected output:
 
 Net ID: tom555
 Encrypted Password: ,-./jklmZ[\]JiLM
 1passed
 2passed
 3passed
 4passed
 */

