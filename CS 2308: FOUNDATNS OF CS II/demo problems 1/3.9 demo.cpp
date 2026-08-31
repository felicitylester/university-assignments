// 06/12/2023

#include <iostream>

using namespace std;

/* ### Problem 3.9 ### */
//Add code to the main function below to dynamically allocate
// an array of 7 grades for the Student s.
struct Student{
    string name;
    string ID_num;
    int* grades;
};


int main(int argc, char** argv){
    Student s = {"Gentry", "A0123"};
    s.grades  = new int[7]; // s not pointer so dot is okay
    s.grades[0] = 90;
    delete [] s.grades;
    s.grades = new int[8];
    cout << s.grades[0] << endl;
    return 0;
}

// only way to expand array in C++ is to make whole new one and copy it
