// Author : Felicity Lester
//
// Due Date : Monday - November 27th , 2023
//
// Programming Assignment Number 7
//
// Fall 2023 - CS 3358 - 008
//
// Instructor: Husain Gholoom.
//
// This program is designed to handle hashing and linear probing with specific constraints.
// This C++ program creates a 20-sized integer array initially filled with '#'. It then populates the first
// eighteen elements with special numbers from 164 to 169 in most of these spaces. To handle collisions, 
// it finds another space nearby for it. After populating the array, iit shows a cool message and shows the
// numbers in groups on the screen. Lastly, it tells you how many times it had to find new spaces for
// these special numbers.

#include <iostream>
#include <ctime>        // allow seeding ran num gen
#include <cstdlib>      // allow rand
#include <algorithm>    // provides a collection of useful functions
#include <iomanip>      // allows setw()
#include <set>

using namespace std;

class HashTable {
private:
    // interger size 20 is a restriction and max
    static const int TABLE_SIZE = 20;
    int array[TABLE_SIZE];
    
    int hashFunction(int key) {
        // collision occur, use linear probing to find the next available position / location
        return key % TABLE_SIZE;
    }
    
    int reHash(int key) {
        return (key + 1) % TABLE_SIZE;
    }
    
    int cumulativeProbes;
    
public:
    // populate the first eighteen elements of the array with random integer
    // values between 164 and 169 inclusive.
    // Initialize cumulative count to zero in the constructor
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            array[i] = '#';
        }
        cumulativeProbes = 0;
    }
    // Initialize cumulative count to zero in the constructor
    int getCumulativeProbes() const {
        return cumulativeProbes;
    }
    
    //***********************************************************
    // name: display - display the array populated
    // parameters:
    // return:
    // side effects: first eighteen elements of the array with
    //      random integer values between 164 and 169 inclusive.
    //***********************************************************
    void display() {
        int elementsPerLine[] = {6, 7, 7};
        int elementCount = 0;
        int lineIndex = 0;

        // populates table with numbers
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (array[i] >= 164 && array[i] <= 169) {
                cout << left << setw(6) << array[i];
            } else {
                cout << left << setw(6) << "#";
            }

            ++elementCount;

            if (elementCount >= elementsPerLine[lineIndex]) {
                cout << endl;
                elementCount = 0;
                ++lineIndex;
            } else {
                cout << " ";
            }
        }
        //cout << endl;
    }
    
    //***********************************************************
    // name: search - search for a specific number in the table
    // parameters:
    // return: the location found or a message saying number was
    //      not found
    // side effects: possible incorret location
    //***********************************************************
    void search(int key) {
        bool isFound = false;
        int index = -1;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (array[i] == key) {
                isFound = true;
                index = i;
                //break;
            }
        }
        if (isFound) {
            cout << "Searching For " << key << " in the Table." << endl;
            cout << key << " was found in location : " << index << endl;
        } else {
            cout << "Searching For " << key << " in the Table." << endl;
            cout << key << " was not found in Table.";
        }
    }
    
    //***********************************************************
    // name: insert - insert a specific number in the table
    // parameters:
    // return: the location found or a message saying number is
    //      not inserted
    // side effects:
    //***********************************************************
    void insert() {
        int hash_pos = 0;
        int count = 0;
        int key;
        
        do {
            // Generating a random number between 164 and 169
            key = rand() % 6 + 164;
            
            hash_pos = hashFunction(key);
            
            if (array[hash_pos] != '#') {
                int initial_pos = hash_pos; // Store initial position for comparison
                
                hash_pos = reHash(hash_pos);
                count++;
                
                // Linear probing until an empty slot is found or we reach the initial position
                while ((array[hash_pos] != '#' || key < 164 || key > 169) && count < TABLE_SIZE && hash_pos != initial_pos) {
                    hash_pos = reHash(hash_pos);
                    count++;
                }
                
                // If we reached the initial position without finding an empty slot
                if ((hash_pos == initial_pos && array[hash_pos] != '#') || count >= TABLE_SIZE) {
                    cout << key << " is not inserted. Table is Full!\n" << endl;
                    return;
                }
            }
            
        } while (array[hash_pos] != '#' && (key < 164 || key > 169)); // Avoid inserting values outside the range
        
        array[hash_pos] = key;
        
        // increment cumulative probes count
        cumulativeProbes += count;
        
        // Check for suppressed indices and display insertion messages accordingly
        set<int> suppressedIndices = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
        
        if (suppressedIndices.find(hash_pos) == suppressedIndices.end()) {
            cout << "Inserting " << key << " in the Table." << endl;
            cout << key << " is inserted in location : " << hash_pos << endl;
        }
    }
    
    //***********************************************************
    // name: deleteKey - delete a specific number in the table
    // parameters:
    // return: delete the number or a message displayes saying
    //      number not deleted
    // side effects:
    //***********************************************************
    void deleteKey(int key) {
        bool isFound = false;
        int index = -1;
        
        // find the first occurrence of the key
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (array[i] == key) {
                isFound = true;
                index = i;
                //break;
            }
        }
        
        if (isFound) {
            // remove the first occurrence found
            array[index] = '#'; // Assuming '#' denotes an empty cell
            cout << "Deleting " << key << " from the Table." << endl;
            cout << key << " is deleted from the Table." << endl;
        } else {
            cout << "Deleting " << key << " from the Table." << endl;
            cout << key << " was not found in Table!" << endl;
        }
    }
    
    //***********************************************************
    // name: displayArray - display the final array populated
    // parameters:
    // return:
    // side effects: first eighteen elements of the array with
    //      random integer values between 164 and 169 inclusive
    //      are displayed after insert, delete and search are
    //      completed
    //***********************************************************
    void displayArray() {
        // number of elements per line
        const int elementsPerLine[] = {6, 7, 7};
        int lineIndex = 0;
        int elementsThisLine = elementsPerLine[lineIndex];

        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (array[i] != '#') {
                cout << left << setw(6) << array[i];
            } else {
                cout << " ";
            }

            --elementsThisLine;

            // Check if it's time to move to the next line
            if (elementsThisLine == 0 && i < TABLE_SIZE - 1) {
                cout << endl;
                ++lineIndex;
                elementsThisLine = elementsPerLine[lineIndex];
            }
        }
        cout << endl;
    }

};


int main(int argc, const char * argv[]) {
    
    srand(static_cast<unsigned>(time(nullptr)));
    HashTable hashTable;
    
    cout << "Welcome to my Hashing Program\n" << endl;
    cout << "------------------------------\n" << endl;
    cout << "A. Create an integer array of size 20. Assigning # to each\n"
         << "   location in the array indicating that the array is empty." << endl;
    cout << "B. Populate 18 elements of the array with random integer\n"
         << "   numbers." << endl;
    cout << "C. If a collision occurs, linear probing will find the next\n"
         << "   available position / location." << endl;
    cout << "D. The generated array will be displayed in 3 lines. First line\n"
         << "   contain 6 numbers separated by a tab space, Second and\n"
         << "   the Third lines contain 7 numbers separated by a tab space." << endl;
    cout << endl << endl;
    
    int count = 0;
    while (count < 18) {
        // inserts 18 random integers into the array
        hashTable.insert();
        count++;
    }

    // display the generated array
    cout << "The Generated Array.\n" << endl;
    hashTable.display();
    cout << endl << endl;

    // generating a random key between 164 and 169
    int key = rand() % 6 + 164;
    
    // searching for a specific key (e.g., 168)
    hashTable.search(key);
    cout << endl;
    
    // deleting a specific key (e.g., 165)
    hashTable.deleteKey(key);
    cout << endl;

    hashTable.search(168);
    cout << endl;
    hashTable.search(172);
    //cout << endl;
    hashTable.insert();
    cout << endl;
    hashTable.insert();
    cout << endl;
    hashTable.insert();
    //cout << endl;
    hashTable.deleteKey(163);
    cout << endl;
    hashTable.deleteKey(175);
    cout << endl;
    
    // display the generated array after all actions completed
    cout << "\nThe Final Array.\n" << endl;
    hashTable.displayArray();

    cout << "\n\nThe number of linear probes occurred when adding \n"
    << "an element in the Table is " << hashTable.getCumulativeProbes() << endl;

    cout << endl << endl;
    cout << "This Hashing Program was Implemented by" << endl;
    cout << "Felicity Lester – November 27th , 2023 :)" << endl;
    cout << endl << endl;
    
    return 0;
}
