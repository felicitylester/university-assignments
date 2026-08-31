// Author: Felicity Lester
// Date: 06/26/2023
// CS 2308.501 class and Prof. Atkinson

#include <iostream>
#include <cstring>  // allow strings
#include <cctype>   // allow characters
#include <vector>   // allow vector
#include <map>
#include <sstream>  // string stream

using namespace std;

// https://en.cppreference.com/w/cpp/container/map
// Look up the map container for C++.inks to an external site.
// Design a function that uses the map container. Your function should allow
//      your user to type any number of words on one line. Return the most
//      common word in the user's sentence. If several words have the same
//      frequency, you can return any one of them.
// Write a main function that calls your other function.
// Implement your function.
// Submit your .cpp file.

//****************This is the line of 80 characters in length*******************


void print_map(std::string_view comment, const std::map<std::string, int>& m)
{
    std::cout << comment;
    // iterate using C++17 facilities
    for (const auto& [key, value] : m) {
        std::cout << '[' << key << "] = " << value << "; ";
    }
    cout << "\n";
}

string mostCommon(){
    // take a sentence as input
    string sentence;
    getline(cin, sentence);
    // for every word in the sentence
    stringstream word_stream(sentence);  // string extraction operator
    string word;
    
    map<string, int> word_counts;
    int highest_count = 0;
    string most_freq_word = "";
    
    while(word_stream >> word){
        // increment the count in our map for that word
        //cout << word << endl;
        word_counts[word] += 1;
        if(word_counts[word] > highest_count){
            highest_count = word_counts[word];
            most_freq_word = word;
        }
    }
    // find the key with the highest value
    print_map("word counts: ", word_counts);
    // return the key
    return most_freq_word;
}

int main(int argc, const char * argv[]) {
//    map<string, int> word_count;
//    word_count["cat"] = 2;
//    cout << word_count["cat"] << endl;  // in list
//    cout << word_count["dog"] << endl;  // not in list
    
    cout << mostCommon() << endl;
    return 0;
}
