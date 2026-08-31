// Author : Felicity Lester
//
// Due Date : Thursday February 1, 2024
//
// Instructor: Rick King

#include <iostream>
#include <cstring>
using namespace std;

void ReverseIt(char* o, char* r) {

    char *p1 = o, *r2 = r, *p2;
    // *r2 = copy of r
    // assist with reverse

    // p1 points to the first char of the name
    // increment it until it poinystothe null which
    // marks the end of the string

    while (*p1 != '\0')
    p1++;

    while (*p1 != ' ')
    // moves back from the null terminator
    p1--;

    p2 = p1;

    p1++;

    while (*p1 != '\0')
    // point to the next one
    *r2++ = *p1++;

    // increment by one and put a comma where you want it
    *r2++ = ',';
    // increment by one and put a space where you want it
    *r2++ = ' ';

    while (o != p2) (*r2++ = *o++);
    // works as loop
    // where o points to (*r2++ = *o++) r now points to and both
    // increment by one

    // make sure the output buffer gets properly null terminated

    *r2 = '\0';
    // where r2 points add a 0 to terminate program and
    // stop from showing garbage that wont be displayed

}

int main() {
    char original[] = "Conan The Barbarian\0";
    char reversed[100];

    ReverseIt(original, reversed);

    cout << original << " reversed is " << reversed << endl;
}
