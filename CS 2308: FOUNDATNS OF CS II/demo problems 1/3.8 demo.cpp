// 06/12/2023

#include <iostream>
#include <ctime> // alloms for complete randomness
using namespace std;


/* ### Problem 3.8 ### */
//Read through the code below.
//Predict the output of secretFunc when its input is 1, 5, 9

void secretFunc(int a, int b, int c){
    int d[c];
    int e = 0;
    for(int* f = d; f < &d[c]; f++){
        *f = e;     // pointer f
        // pointer f pointing to d ewhichis an array
        // it points to this one first
        if (f == &d[a]) e++;
        // true when f pointing to &d[a] so where is &d[a]
        if (f == &d[b]) e++;
    }
    e = 0;
    for(int* g = &d[c-1]; g>=&d[0]; g--){
        e += *g;    // g pointer & starts at pointing at last position
        // keeps going until it points to left hand side
    }
    // everything g points at add up to be e
    cout << e << endl;
}
// output is 10
