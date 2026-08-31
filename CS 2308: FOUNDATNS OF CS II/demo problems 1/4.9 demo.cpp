// 06/20/2023

#include <iostream>
#include <ctime> // allows for complete randomness

using namespace std;

// ### Problem 9 ###
//Define a class called House with the following data member:
//  string address
//  float listPrice
//  float area
//Add three constructos:
//  1) Take no parameters, set all data members to default values
//  2) Pass in values for all data members
//  3) Pass in another instance of the class, copy the values of its parameters
//Add getters (not setters)

class House {
private:
    string address;
    float listPrice;
    float area;
    
public:
    House();
    House(string, float, float);    // do not have to name just give data types
    House(const House&);   // pass object to function use pass by reference &
        //using copy construstor needs const
};

int main(int argc, char** argv) {
    House h1;
    House h2("456 university Dr.", 30, 2000);
    House h3(const House&);
    
    return 0;
}

//  1) Take no parameters, set all data members to default values
House::House() {
    // in size of class so do not need string and float
    address = "123 Main St.";
    listPrice = 450000;
    area = 2000;    // sq ft.
}

//  2) Pass in values for all data members
House::House(string address, float listPrice, float area) {
    this->address = address;
    this->listPrice = listPrice;
    this->area = area;
}

//  3) Pass in another instance of the class, copy the values of its parameters
House::House(const House&) {
    
}
