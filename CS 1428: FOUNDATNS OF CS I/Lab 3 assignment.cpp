// Felicity Lester fml21
// September 23,2022
//CS1428 Lab
//Lab 3
//Description: this program will allow the user to play 
//Tom-And-Jerry game against a randomized computer opponent

//****************This is the line of 80 characters in length*******************
//############Your code should not exceed the length of the above line##########

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    int user_num;  //user's choice
    int comp_num;  //computer's choice

    // Generate the computer's choice randomly:
    srand(time(NULL));
    comp_num = rand() % 3 + 1;

    // Get the user's choice:
    {
    cout << "Tom-And-Jerry Game" << endl;
    cout << " 1. Spike" << endl;
    cout << " 2. Tom" << endl;
    cout << " 3. Jerry" << endl;
    cout << "Enter a number : ";
    cin >> user_num;
    cout << endl;
    }
        if (user_num == 1 && comp_num == 2)
        {
          cout << "Spike beats Tom! You won!" << endl;
        }
        
        else if (user_num == 2 && comp_num == 3)
        {
          cout << "Tom beats Jerry! You won! " << endl;
        }
          
        else if (user_num == 3 && comp_num == 1)
        {
          cout << "Jerry beats Spike! You won!" << endl;
        }

        else if (user_num == 1 && comp_num == 1)
        {
          cout << "You both chose Spike! It’s a tie!" << endl;
        } 
          
        else if (user_num == 2 && comp_num == 2)
        {
          cout << "You both chose Tom! It’s a tie!" << endl;
        } 
          
        else if (user_num == 3 && comp_num == 3)
        {
          cout << "You both chose Jerry! It’s a tie!" << endl;
        } 

        else if (user_num == 1 && comp_num == 3)
        {
          cout << "Jerry beats Spike! You loss! " << endl;
        }
        
        else if (user_num == 3 && comp_num == 2)
        {
          cout << "Jerry beats Tom! You loss! " << endl;
        }

        else if (user_num == 2 && comp_num == 1)
        {
          cout << "Tom beats Spike! You loss! " << endl;
        }
        
        else //(user_num != 1 || user_num !=2 || user_num !=3);
        {
          cout << "ERROR - Invalid Input. Terminating Program. " << endl;
        }

    // Exit the program:
    return 0;
}

    //1) The user will enter a number 1-3 to select “Spike”, “Tom”, or “Jerry”.
    //2) The computer will select a number 1-3 randomly (The code to generate a random number and the required standard libraries are already included).
    //3) Determine who wins using if/else-if/else statements.(Spike beats Tom, Tom beats jerry, and Jerry beats Spike). Print the results to the console.
    //4) NOTE: It is possible for the player to win, lose, or tie
    //5) The result should include the player’s selection and who won the match.
    //6) Make sure to check for bad numeric data. Terminate the program if the user selects an invalid number.
