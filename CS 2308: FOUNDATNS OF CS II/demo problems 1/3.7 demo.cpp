// 06/12/2023

#include <iostream>

using namespace std;


/* ### Problem 3.7 ### */
//Update the function below to use a pointer to a Dog struct
//  rather than using C++ passing by reference.
//Rember to check to see if your function has been pass a NULL
//  pointer.
//Use the definition of Dog from 3.6

// dot operator access member of struct/class
// d is a pointer/memory address & its just an address in memory
// -> = follow d which is a pointer and select from struct
void updateName(Dog* d) {
    if (d == nullptr) return; // or if(!d)
    if (d->breed == "Poodle"){
        d->name = "Dr. " + d->name;
    }
    else if(d->breed == "Terrior"){
        d->name = "Super " + d->name;
    }
    return;
} 

int main(int argc, char** argv) {
    Dog* ptr = new Dog {"Tod", "Poodle", 7};
    updateName(ptr);    // pass pointer to Tod the dog
    // updateName(nullptr); would crash
    cout << ptr->name << endl;
    // output Dr. Tod
    return 0;
}
