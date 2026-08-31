// 06/09/2023

#include <iostream>
#include <ctime> // alloms for complete randomness
using namespace std;


/* ### Problem 3.6 ### */
//Write a function that takes these parameters:
//  d:          a pointer to a Dog struct
//  newName:    a string
//If d is not NULL, set the dog's name to newName.
//Use this definition for Dog
struct Dog{
    string name, breed;
    int age;
};

void nameDog(Dog* d, string name) {
    if(d != nullptr) {
        d->name = name;     // d->name easier than (*d.name) = name
        // -> = tells which goes first (gives order)
    }
}

int main(int argc, char** argv) {
    Dog* ptr = new Dog;
    nameDog(ptr, "Jimmy");
    cout << ptr->name << endl;
    
    return 0;
}
