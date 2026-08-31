// 06/26/2023

#include <iostream>
#include <cstring>
#include <ctime> // allows for complete randomness
#include <vector>

using namespace std;

// ### Problem 6.4 ###
//Prompt the user to enter a list of integers which is terminated
//  with a zero. Store the user's input in a Vector.
//Print the sum of every two consecutive numbers.
//
//Example Input: 3 6 2 8 5 0
//Example Output: 9 8 10 13 5


int main(int argc, char** argv){
    vector<int> numVector;    // declare data type for all vectors
    int i;  //
    do{
        cin >> i;
        numVector.push_back(i);
    }while(i != 0);
    
    vector<int>::iterator ptr = numVector.begin();
    for(;ptr < numVector.end(); ptr++){
        cout << *ptr + *(ptr + 1) << ' ';
    }
    
    return 0;
}
