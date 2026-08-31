// Felicity Lester
// June 08, 2023
// CS 2308.501 class and Prof. Atkinson

#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 100;

//Design a function that will read and sort the file random_students.txt.
//  Download random_students.txt .random_students.txt .
//Download random_students.txt.There are 100 students in the file.
//  Start by reading the names and ID numbers into separate arrays.
//  Then choose a sorting algorithm and sort both arrays so that the ID
//  numbers are in the correct order. Write the sorted arrays back into
//  a file called "sorted_students.txt". Sketch the function in
//  comments before writing any code.
//Write a main function that calls your function and then prints the contents
//  of sorted_students.txt to the console. Use comments to predict the
//  first and last students in the newly sorted list.


void sortStudents(string filename) {
    // read a names and ID array
    ifstream fin(filename);
    string names[SIZE];
    int IDs[SIZE];
    for(int i = 0; i < SIZE; i++) {
        fin >> names[i] >> IDs[i];
    }
    // bubble sort both arrays by ID order
    // outer loop that shrinks down from top
    for(int top = SIZE-1; top > 0; top--) {
        // set done to true
        bool done = true;
        // inner loop rises up from 0
        for(int i = 0; i < top; i++) {      // anytime it finds misordered
            // neighbors it will switch them
            // compare elements to neighnors and we swap
            if(IDs[i] > IDs[i+1]) {
                // swap misordered pairs, set done to false
                int temp = IDs[i];
                IDs[i] = IDs[i+1];
                IDs[i+1] = temp;
                string temp_name = names[i];
                names[i] = names[i+1];
                names[i+1] = temp_name;     // offset from index
                // make sure you do not look outside of array
                done = false;
                
            }
            // if done, return
            if (done) {
                
                return;
        }
    }
    // return
    // write arrays to file sorted_students.txt
    ofstream fout("sorted_students.txt");
    if (fout) {
        for (int i = 0; i < SIZE; i++) {
            fout << names[i] << " " << IDs[i] << endl;
        }
        fout.close();
        cout << "Sorting completed." << endl;
        }
        else {      // file not working
        cout << "Failed to open file for writing." << endl;
         }
     }
}

int main() {
    sortStudents("random_students.txt");    // file now sorted
    ifstream in("sorted_students.txt");
    while(!in.eof()) {      // eof = end of file
        string line;
        getline(in, line);
        cout << line;
    }
    return 0;
}
//Implement your function.
                  
