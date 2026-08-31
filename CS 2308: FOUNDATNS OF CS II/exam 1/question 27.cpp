//Using the code below, complete this implementation of Sequential Search
//(also called Linear Search). The function linSearch should return true
//if the target is in the array named searchArray. Return false if the
//target value is not in the array.

bool linSearch(const string searchArray[], int SIZE, string target){
    //Fill in your code
}


int main(int argc, char** argv){
    string names[] = {"Moses", "Billie", "Ada", "Carrie"};
    if(linSearch(names, 4, "Ada"))
        cout << "Name found" << endl;
    return 0;
}

//Your Answer:
#include <iostream>

#include <cstring>  // allow strings

#include <cctype>   // allow characters

using namespace std;

 

bool linSearch(const string searchArray[], int SIZE, string target){

    for(int i = 1; i < SIZE; i++) {

        // start ar 1 bc array start at 0

        if(searchArray[i] == target) {   // test if target in array

            return true;    // in array

        }

    }

    return false; // not in array

}

 

int main(int argc, char** argv){

    string names[] = {"Moses", "Billie", "Ada", "Carrie"};

    if(linSearch(names, 4, "Ada"))

        cout << "Name found" << endl;

    return 0;

}

// output Name Found
