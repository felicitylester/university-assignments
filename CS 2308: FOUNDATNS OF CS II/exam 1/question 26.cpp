//Using the code below, complete the while loop so that it prints
//characters from message using the character pointer ptr until ptr
//points to a period. Use the statement ptr++ to advance ptr to the next
//character. To receive full credit both the loop condition and the loop body
//should make use of ptr. If you have completed the program correctly, it
//will only print the word Hello

 

int main(int argc, char** argv){
    char message[] = "Hello. This is a short message.";
    char* ptr = &message[0];
    while(/*Fill in this condition*/){
        //Fill in the loop body    }
    return 0;
}

//Your Answer:
#include <iostream>

#include <cstring>  // allow strings

#include <cctype>   // allow characters

using namespace std;

 

int main(int argc, char** argv){

    char message[] = "Hello. This is a short message.";

    char* ptr = &message[0];

    while(*ptr != '.') {    // this tells when to stop

        cout << *ptr;

        //cout << *ptr << endl; caused wrong output

        ptr++;  // increments

    }

    cout << endl;   // prints exit code on seperate line

    return 0;

}
