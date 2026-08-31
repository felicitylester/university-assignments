// Author: Felicity Lester
// Date: 06/28/2023
// CS 2308.501 class and Prof. Atkinson

#include <iostream>
#include <cstring>  // allow strings
#include <cctype>   // allow characters
#include <stack>    // allow stack

using namespace std;

// https://en.cppreference.com/w/cpp/container/stack
// Read the documentation on stacks in C++.Links to an external si
// Design a function that uses the stack data structure. The function should
//    take one string as a parameter. The function should return true if the
//    brackets in the string are balanced (i.e. every (, {, or [ must be paired
//    correctly with a ), }, or ]). Return false otherwise. Only the 3 listed
//    brackets need to be balanced.  Unbalanced can mean that a bracket is open
//    but not closed, or is closed with an incorrect bracket (e.g. [(this text}] ).
// Write a main function to test your other function.
// Implement your bracket-checking function.
// Submit your .cpp file.

bool isBalanced(string s){
    // declare a stack
    stack<char>stk;
    
    // iterate of characters in string
    for(char c : s){
        // if open bracket, push char on stack
        char old_bracket;
        switch(c){
            case '(':
            case '[':
            case '{':
                stk.push(c);
                break;
                // if closing bracket, pop the stack
            case ')':
            case ']':
            case '}':
                if(stk.empty()) return false;
                old_bracket = stk.top();
                stk.pop();
                // if stack is empty, return false
                // if they do not match return false
                if(c == ')' && old_bracket != '(') return false;
                if(c == ']' && old_bracket != '[') return false;
                if(c == '}' && old_bracket != '{') return false;
                break;
            // default: would be any other character
        }
    }
    //return stack.isEmpty();
    return stk.empty();
}


int main(int argc, const char * argv[]) {
    
    cout << isBalanced("(cat)") << endl;       // 1
    cout << isBalanced("(cat){dog}") << endl;  // 1
    cout << isBalanced("{catdog}") << endl;    // 1
    cout << isBalanced("(cat") << endl;        // 0
    cout << isBalanced("dog))") << endl;       // 0
    cout << isBalanced("[(cat])") << endl;     // 0

    return 0;
}
