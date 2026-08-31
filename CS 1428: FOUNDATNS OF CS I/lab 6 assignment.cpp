//TO-DO: Felicity Lester
//TO-DO: October 14, 2022
//CS1428 Lab
//Lab 6
//Description: this program will print n even or odd numbers
//****************This is the line of 80 characters in length*******************
//############Your code should not exceed the length of the above line##########
#include <iostream>
using namespace std;
int main()
{
    int choice;
  
    // Prompt the user for their choice:
    cout << "What would you like to do?\n"
         << "1. Find even numbers 0 - N\n"
         << "2. Find odd numbers 0 - N\n"
         << "3. Quit program\n"
         << "Enter your choice: ";
    cin >> choice;
    // TODO: Create a loop to perform desired operations until user chooses to exit:

  int n;
  int i;
  while (choice >= 1 && choice <= 3) //Use AND instead of OR
  {
    if (choice != 1 && choice != 2 && choice != 3)
    {
      cout << "ERROR: Invalid choice. Select a valid menu item." << endl;
    }
    
    if (choice == 1)
    {
      cout << "Enter N: ";
      cin >> n;
      cout << "Even numbers: ";
      for(i = 0; i <= n; i++)
      {
        if(i % 2 == 0)
        {
          cout << i << " ";
        }
      }
      cout << endl;
    }
    
    if (choice == 2)
    {
      cout << "Enter N: ";
      cin >> n;
      cout << "Odd numbers: ";
      for (i = 1; i <= n; i++)
      {
        if(i % 2 != 0)
        {
          cout << i << " ";
        }
      }
    cout << endl;
    }

    if (choice == 3)
    { 
      // Display end of program message:
      cout << "Terminating program...\n" << endl;
      return 0;
    }
    cout << "What would you like to do?\n"
         << "1. Find even numbers 0 - N\n"
         << "2. Find odd numbers 0 - N\n"
         << "3. Quit program\n"
         << "Enter your choice: ";
    cin >> choice;
  }
  
    return 0;
}