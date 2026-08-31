// 06/16/2023

#include <iostream>
#include <ctime> // allows for complete randomness
using namespace std;

// ### Problem 5 ###
//Write a class called Sphere with these member variables:
//  int radius
//  float volume
class Sphere {
private:
    //The member variables should be private
    int radius;
    float volume;
public:
    //Add a constructor that takes one int as a parameter.
    Sphere(int r) {
        //  Set radius to the value of the vale of that int
        //  and calculate volume as 4/3 * Pi * radius^3
        radius = r;
        volume = (4.0/3.0) * 3.14 * (radius * radius * radius);
    }
    //Add a getter for radius and volume
    int getRadius() {return radius;}
    float getVolume()  {return volume;}
};

//int main (int arg, char** argv) {
//    Sphere s(5);
//    cout << "Volume of s" << s.getVolume() << endl;
//
//    return 0;
//};


//  ### Problem 6 ###
//Write a function called willItFit that takes these parameters:
//  Sphere s1
//  Sphere s2
//Return true if s1 will fit inside of s2.
//Return false otherwise.
bool willItFit(Sphere& s1, Sphere& s2) {
    // pass by reference is best but consider potiential side effects
    return (s2.getVolume() > s1.getVolume());
}


int main (int arg, char** argv) {
    Sphere s1(5), s2(6);
    cout << "Volume of sl" << s1.getVolume() << endl;
    if(willItFit(s1, s2)) {
        cout << "s1 fits s2" << endl;
    }
        else {
            cout << "s1 does not fit" << endl;

        }
    
    return 0;
}
    
