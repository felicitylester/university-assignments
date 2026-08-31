// File Name: main.cpp
//
// Author: Felicity Lester
// Collaborators: None
// Date: 2/15/2023
// Assignment Number: 2
// CS 2308 Spring 2022
//
// Write a program that allow a user to access the results from a 6 hour
// time-trial bike race

//****************This is the line of 80 characters in length*******************

#include <iostream>
#include <iomanip>
#include <cstring>      // allow strings
#include <fstream>      // allows files
using namespace std;

// global variable
int i = 0;              // iterator for loops

//***********************************************************
// struct Result: struct to copy data from table
// bibNumber - the races number
// name - racer’s name
// distance - total distance covered by racer
// time - time completed in 6 hour period
// returns:
//***********************************************************
struct Result
{
    int bibNumber;     // Bib number
    string name;       // Racer’s name
    double distance;   // Distance covered by racer
    string time;       // Racer's time
};


// function prototypes
void displayMenu();
void displayHeader();
void readDataset(ifstream& in, Result results[], int &size);
void displayDataset(Result results[], int size);
int linearSearchByName(Result results[], int size, string targetName);
int binarySearchByNumber(Result results[], int size, int targetNumber);
void sortByNumber(Result results[], int size);
void sortByDistanceTime(Result results[], int size);


//shows menu options
void displayMenu()
{
    cout << "\nMenu\n\n";
    cout << "1. Display Results sorted by bib number\n";
    cout << "2. Display Results sorted by distance, then time\n";
    cout << "3. Lookup a bib number given a name\n";
    cout << "4. Lookup a result by bib number\n";
    cout << "5. Quit the Program\n\n";
    cout << "Enter your choice: ";
}


// header and columns
void displayHeader()
{
    cout << left
    << setw(7) << "BibNum"
    << setw(18) << "Name"
    << right
    << setw(8) << "Distance"
    << setw(10) << "Time  "
    << endl;
}


//***********************************************************
// readDataset: Should read results into results array from
// the "in" file stream. Updates size from each file.
// getline: tells program to read all data in the line
// size: number of elements from array
//
// returns: thearray of results
//***********************************************************
void readDataset(ifstream& in, Result results[], int &size)
{
    Result res;     // temporary variable to store the input values
    size = 0;
    
    // get the next unread Result from the file
    while (in >> res.bibNumber && size < MAX_DATASET_SIZE)
    {
        // ws - used to discard leading whitespace from an input stream.
        in >> ws;
        getline(in, res.name);
        in >> res.distance;
        in >> res.time;
        // put the Result into the array at the next free place
        results[size] = res;
        ++size;
    }
    in.close ();
}


//***********************************************************
// displayDataset: Should nicely display results array from
// data set
// size: number of results in array
//
// returns:
//***********************************************************
void displayDataset(Result results[], int size)
{
    // loop used to display table of runner's
    for(i = 0; i < size; i++)
    {
            cout << left
            << setw(7) << results[i].bibNumber
            << setw(18) << results[i].name
            << right
            << setw(8) << results[i].distance
            << setw(10) << results[i].time
            << endl;
    }
}


//***********************************************************
// linearSearchByName: Should find the index of a racer's
// result by their name using a linear search. If no such
// racer exist return -1.
// size: number of results in array
//
// returns: -1 if name not identified
//***********************************************************
int linearSearchByName(Result results[], int size, string targetName)
{
    for (i = 0; i < size; i++) {
        if (results[i].name == targetName)
        {
            return i;
        }
    }
    // racers name not found
    return -1;
}

//***********************************************************
// sortByNumber: Should sort results by bibNumber field in
// ascending order. Must use bubble sort or selection
// sort algorithm. (picking selection b/c faster and more
// efficient)
// swap: switches numbers// size: number of results in array
//
// returns: the array to sort
//***********************************************************
void sortByNumber(Result results[], int size)
{
    bool swap;          // flag, set when a swap occurs
    Result temp;

    do {
       swap = false;
       for (int i = 0; i < (size - 1); i++)
       {
          if (results[i].bibNumber > results[i + 1].bibNumber)
          {
              temp = results[i];
              results[i] = results[i + 1];
              results[i + 1] = temp;
             swap = true;
          }
       }
    } while (swap);
}

//***********************************************************
// sortByDistanceTime: Should sort results by distance (descending)
// and if two racers have the same distance they should be
// ordered by time in ascending order. Must use bubble sort
// or selection sort algorithm. (picking selection b/c
// faster and more efficient)
// size: number of results in array
//
// returns: the array to sort
//***********************************************************
void sortByDistanceTime(Result results[], int size)
{
    bool swap;          // flag, set when a swap occurs
    Result temp;
    
    //do-loop make sure puts numbers in ascending order
    do {
        swap = false;
        for (int i = 0; i < (size - 1); i++)
        {
            if (results[i].distance < results[i + 1].distance)
            {
                temp = results[i];
                results[i] = results[i + 1];
                results[i + 1] = temp;
                swap = true;
            }
            //puts time in decending order for identical distance
            else if (results[i].distance == results[i + 1].distance)
            {
                if ((results[i].time > results[i + 1].time))
                {
                    temp = results[i];
                    results[i] = results[i + 1];
                    results[i + 1] = temp;
                    swap = true;
                }
            }
        }
    } while (swap);
}


//***********************************************************
// binarySearchByNumber: Should find the index of a racer's
// result by their bib number using a binary search. If no
// such racer exist return -1.
// size: number of results in array
// number: the target value to find in the array
// returns the arrays subscript if valueis found. Otherwise,
// returns -1 if bibnumber is not identified
//***********************************************************
int binarySearchByNumber(Result results[], int size, int targetNumber)
{
    int mid;                 //index middle of search list
    int low = 0;             //index beggining of search list
    int high = size - 1;     //index end of search list
    
    while (high >= low)
    {         //calculate the mid point
        mid = (high + low) / 2;
        if (results[mid].bibNumber < targetNumber)
        {
           low = mid + 1;
        }
        else if (results[mid].bibNumber > targetNumber)
        {
           high = mid - 1;
        }
        else {
            //loop used to display runner's data
            cout << left
            << setw(7) << results[mid].bibNumber
            << setw(18) << results[mid].name
            << right
            << setw(8) << results[mid].distance
            << setw(10) << results[mid].time
            << endl;
            return mid;
        }
    }
    return -1;      // number not found
}


int main() {
    
    // variables
    Result dataset [MAX_DATASET_SIZE);      // results sorted by ID
    int size;                 // actual number of elements in the dataset
    string name;              // Racer’s name
    string targetName;        // for linearSearchByName
    
    // will include 0 after decimal point
    cout << fixed << setprecision(1);
    
    ifstream in;

    // declare input file stream variable
    string filename;
    cin >> filename;
    
    // open the input file:
    in.open(filename);
    // check to ensure the input file opened
    if (!in.is_open())
    {
        cout << "Could not open file. Terminating program." << endl;
        return -1;
    }
    
    readDataset(in, results, size);
    // close the input file
    in.close();
    // shows menu and options

    int choice;
    do
    {
        displayMenu();
        cin >> choice;
                    
        // Validate the menu selection.
        while (choice < 1 || choice > 5)
        {
            cout << "Please, enter 1, 2, 3, 4 or 5: ";
            cin >> choice;
        }
        
        // user decides to quit program
        if (choice == 5)
        {
            cout << "Exiting the program...\n";
            exit(0);
        }
        
        // Validate and process the user's choice.
        if (choice != 5)
        {
            // Respond to the user's menu selection.
            switch (choice)
            {
                case 1:    // Display Results sorted by bib number
                    cout << endl;
                    displayHeader();
                    sortByNumber(results, size);
                    displayDataset(results, size);
                    break;
                case 2:    // Display Results sorted by distance, then time
                    cout << endl;
                    
                    displayHeader();
                    sortByDistanceTime(results, size);
                    displayDataset(results, size);
                    break;
                case 3:     // Lookup a bib number given a name
                {
                    string targetName;
                    cout << "Enter name of a racer to look for: ";
                    cin.ignore();
                    getline (cin, targetName);
                    int index = linearSearchByName(results, size, targetName);
                    cout << endl;
                    if (index == -1)
                    {
                        cout << "No racer found with name: " << targetName;
                        cout << endl;
                    }
                    else
                    {
                        cout << "The number of the racer with name ";
                        cout << targetName << " is: ";
                        cout << results[index].bibNumber;
                        cout << endl;
                    }
                }
                    break;
                case 4:    // Lookup a result by bib number
                {
                    int targetNumber = 0;
                    cout << "Enter number of a racer to look for: ";
                    cout << endl;
                    cin >> targetNumber;
                    sortByNumber(results, size);
                    int index = binarySearchByNumber(results, size, targetNumber);
                    if(index == -1)
                    {
                        cout << "No racer found with number: " << targetNumber;
                        cout << endl;
                    }
                    
                    break;
                }
            }
        }
        
    } while (choice != 5);
        return 0;
}
