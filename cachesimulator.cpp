// Cache Simulator - Report
// Felicity Lester
// CS 3339: Computer Architecture - Homework 5
// December 6, 2024


#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

class Cache {
private:
    struct Line {
        bool valid;
        int tag;
    };

    int numEntries;
    int associativity;
    int numSets;
    vector<vector<Line> > sets;  // Fix for >> syntax

    int getSetIndex(int address) {
        return (address / associativity) % numSets;
    }

    int getTag(int address) {
        return address / (numSets * associativity);
    }

public:
    Cache(int entries, int assoc)
        : numEntries(entries), associativity(assoc), numSets(entries / assoc) {
        sets.resize(numSets, vector<Line>(associativity, Line{false, -1}));  // Fix for Line initialization
    }

    string access(int address) {
        int setIndex = getSetIndex(address);
        int tag = getTag(address);

        // Fix for the C++11 range-based for loop warning
        for (vector<Line>::reference line : sets[setIndex]) {
            if (line.valid && line.tag == tag) {
                return "HIT";
            }
        }

        // Miss: Replace the first invalid line or evict
        for (vector<Line>::reference line : sets[setIndex]) {
            if (!line.valid) {
                line.valid = true;
                line.tag = tag;
                return "MISS";
            }
        }

        // Evict the first line (FIFO replacement policy)
        sets[setIndex][0].tag = tag;
        return "MISS";
    }
};

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: ./cache_sim <num_entries> <associativity> <memory_reference_file>\n";
        return 1;
    }

    int numEntries = stoi(argv[1]);
    int associativity = stoi(argv[2]);
    string filename = argv[3];

    // Validate input
    if (numEntries <= 0 || (numEntries & (numEntries - 1)) != 0 || numEntries % associativity != 0) {
        cerr << "Invalid cache configuration. Ensure numEntries is a power of 2 and divisible by associativity.\n";
        return 1;
    }

    Cache cache(numEntries, associativity);

    // Read from file
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file: " << filename << "\n";
        return 1;
    }

    int address;
    while (inFile >> address) {
        string result = cache.access(address);
        cout << address << ": " << result << "\n";
    }

    return 0;
}
