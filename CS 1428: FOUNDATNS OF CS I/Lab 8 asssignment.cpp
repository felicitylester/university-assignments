//TO-DO: Felicity Lester A04949726
//TO-DO: October 28, 2022
//CS1428 Lab
//Lab 8
//Description: this program will implement a simple bank ATM system
//****************This is the line of 80 characters in length*******************
//############Your code should not exceed the length of the above line##########
#include <iostream>
using namespace std;
// Function Prototypes:
char getactInput();
void checkbalance(float);
float withdraw(float, float);
float deposit(float, float);
int main()
{
    int account, sum;
    char option, cont;
    double balance=1000;
    do{
        option = getactInput();
        switch(option)
        {
            case 'A':
            case 'a':
                    checkbalance(balance);
                    break;
            case 'B':
            case 'b':
                    cout << "Enter an ammount: ";
                    cin >> sum;
                    balance = withdraw(balance, sum);
                    checkbalance(balance);
                    break;
            case 'C':
            case 'c':
                    cout << "Enter an ammount: ";
                    cin >> sum;
                    balance = deposit(sum, balance);
                    checkbalance(balance);
                    break;
            default:
                cout << "ERROR: Invalid Option" << endl
                 << "Select a valid Option: ";
                break;
        }
        cout << "\nWould you like to continue? (Y or N): ";
        cin >> cont;
    }while(cont == 'Y' || cont == 'y');
    return 0;
}
// TODO: Add function definitions here
  char getactInput()
      {
        char option;
        cout << "Welcome to Bobcat Banking!" << endl;
        cout << "Select an option from the following: " << endl;
        cout << "a) Check Balance" << endl;
        cout << "b) Withdraw" << endl;
        cout << "c) Deposit" << endl;
        cout << "Please select an option: ";
        cin >> option;
        return option;
      }

  void checkbalance(float balance) {
    cout << "Your account balance is $" << balance << endl;
    }

  float withdraw(float balance, float sum) {
    balance = balance - sum;
    return balance;
    }

  float deposit(float sum, float balance) {
    balance = sum + balance;
    return balance;
    }
