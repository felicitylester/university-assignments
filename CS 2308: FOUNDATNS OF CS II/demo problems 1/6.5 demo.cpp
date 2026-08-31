// 06/26/2023

#include <iostream>
#include <cstring>
#include <ctime>    // allows for complete randomness
#include <vector>   // allows vectors

using namespace std;

// ### Problem 6.5 ###
//Prompt the user to enter a list of names. Store their input in
//  one or two Vectors. Stop taking input when the user enters a
//  blank line as input.
//First, print every name that starts with a vowel.
//Second, print every name that starts with a consonant.


int main(int argc, char** argv){
    vector<string> vowelNames;
    vector<string> consonantNames;
    string input;
    do{
        getline(cin, input);
        switch(input[0]){
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                vowelNames.push_back(input);
                break;
            default:
                consonantNames.push_back(input);
                break;
        }
    }while(input != "");
    cout << "Vowel Names: ";
    for(string n : vowelNames){
        cout << n << ' ';
    }
    cout << endl << "Consonant Names: ";
    // this loop style allows for you to access each element
    for(string n : consonantNames){
        cout << n << ' ';
    }
    return 0;
}
