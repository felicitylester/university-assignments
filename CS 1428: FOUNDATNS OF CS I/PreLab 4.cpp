// Felicity Lester fml21
// September 28, 2022
// CS.1428.L29
// PreLab 4 Assignment

// The following is an extremely scientific personality test that can predict
// how well you will do in this course.
// Fill in the area below with the requested code.

#include <iostream>

using namespace std;

int main()
{
    char input;
    string answer;

    cout << "Is Sponge Bob better than Patrick? ('Y' or 'N')" << endl;
    cin >> input;

    // TODO - Change the following IF-ELSE statement to an
    // equivalent switch statement.

    switch (input) 
    {
    case 'y': case 'Y':
        cout << "You think Sponge Bob is better than Patrick..." << endl;
        answer = "Wrong!";
        break;
          
    case 'n': case 'N':
        cout << "You do not think think Sponge Bob is better than Patrick..." << endl;
        answer = "Correct!" ;
        break;
       
    default:
        cout << "Invalid Input." << endl;
        break;
    }
     cout << answer << endl;

     return 0;
}
