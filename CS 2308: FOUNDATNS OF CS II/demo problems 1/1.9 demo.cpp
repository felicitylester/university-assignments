// 06/01/2023

#include <iostream>
using namespace std;

/*###Problem 1.9 ###*/
//Add this struct to your program:
struct Address{
    string streetAddress;
    int zip;
    string city;
};
//Add a for loop to the main to create an array of Addresses
//Your array should store 10
//Write a for loop to allow a user to assign values to
// the member of each Address in the array


int main () {
    Address book[10];
    
    for (int i = 0; i < 10; i++) {
        // cin >> book[i].streetAddress;
        getline(cin, book[i].streetAddress);    // needs access to variable
        cin >> book[i].zip;
        getline(cin, book[i].city);
        // getline allows string of characters/data
    }
    cout << book[0].streetAddress << endl;
}
