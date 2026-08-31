// Author /s : Felicity Lester
// Serial Number /s : 28
// Due Date : Friday September 29th, 2023
// Programming Assignment Number 3
// Fall 2023 - CS 3358 - 008
//
// Instructor: Husain Gholoom.
//
// This program is designed to allow the user

#include <iostream>
#include <iomanip>      // allow setw
#include <algorithm>
#include <cmath>

using namespace std;

// function prototypes

class myInt{
private:
    int num;            // users input
    
public:
    myInt(int n){       // constructor to validate if user num is valid
        if(n >= 100){
            num = n;
        }
        else{
            num = -1;
        }
    }
    
    //***********************************************************
    // name: isMultiple: validates if number is a multiple which
    //      will be used for 7, 11, or 13
    // parameters:
    //      int multiple
    // return: none
    // side effects: progarm should say correct multiples
    //***********************************************************
    bool isMultiple(int multiple){
        if(num == -1)
            return false;
        return num % multiple == 0;
    }
    
    //***********************************************************
    // name: isSumEvenOrOdd: validates if number is even or odd
    // parameters:
    // return: even if sum is divisible by 2
    // side effects: progarm say if int is even or odd
    //***********************************************************
    bool isSumEvenOrOdd(){
        if(num == -1)
            return false;
        
        int sum = 0;
        int temp = num;
        while(temp > 0){        // validates temp num is positive
            sum += temp % 10;
            temp /= 10;
        }
        return sum % 2 == 0;    // sees if num is divisible by 2
    }
    
    //***********************************************************
    // name: squareRoot: calculates the square root of users
    //      number
    // parameters:
    // return: sqrt of users integer
    // side effects: sqrt
    //***********************************************************
    double squareRoot() {
        if (num == -1) return -1.0;
        return sqrt(num);
    }
    
    //***********************************************************
    // name: isPrime: validates if the users input is a prime
    //      number
    // parameters:
    // return: if int is prime & if int is not prime
    // side effects:
    //***********************************************************
    bool isPrime() {
        if (num == -1 || num == 1)
            return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0)
                return false;
        }
        return true;
    }
    
    //***********************************************************
    // name: isPerfectNumber; if a perfect number exist via
    //      factors add up to itself
    // parameters:
    // return: if int is perfect & if int is not perfect
    // side effects:
    //***********************************************************
    bool isPerfectNumber() {
        if (num == -1) return false;    // invalid value
        int sum = 1;        // start with 1 (every number is divisible by 1)
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                sum += i;
                if (i != num / i) {
                    // avoid adding the same factor twice for perfect squares
                    sum += num / i;
                }
            }
        }
        return sum == num;
    }
};

int main(int argc, const char * argv[]) {
        
    int userValue;
    char userChoice;
    bool isValidInput = false;
        
    cout << "Welcome to my Integer Manipulations Program." << endl;
    
    do {
        cout << "\nEnter an integer: ";
        if (cin >> userValue) {
            // user input is a valid integer
            isValidInput = true;
            cout << endl;
            
            myInt num(userValue);
            
            if(userValue < 100) {
                // error message if input out of range
                cout << "Error *** – Integer must be >= 100\n";
            } else {
                cout << endl;
                
                cout << "A      " << userValue;
                
                bool isMultipleOf7 = num.isMultiple(7);
                bool isMultipleOf11 = num.isMultiple(11);
                bool isMultipleOf13 = num.isMultiple(13);
                
                if (!isMultipleOf7 && !isMultipleOf11 && !isMultipleOf13){
                    cout << " is not multiple of 7 , not multiple of 11 , and not multiple of 13";
                }
                else if (isMultipleOf7 && !isMultipleOf11 && !isMultipleOf13) {
                    cout << " is a multiple of 7 , not multiple of 11 , and not multiple of 13";
                }
                else if (!isMultipleOf7 && isMultipleOf11 && !isMultipleOf13) {
                    cout << " is not a multiple of 7 , multiple of 11 , and not multiple of 13";
                }
                else if (!isMultipleOf7 && !isMultipleOf11 && isMultipleOf13) {
                    cout << " is not a multiple of 7 , not multiple of 11 , multiple of 13";
                }
                else {
                    cout << " is a multiple of 7 , multiple of 11 , and multiple of 13";
                }
                cout << endl;
                
                
                if(num.isSumEvenOrOdd()){
                    cout << "B      Sum of its digits is even" << endl;
                } else {
                    cout << "B      Sum of its digits is odd" << endl;
                }
                
                double sqrtValue = num.squareRoot();
                if(sqrtValue >= 0){
                    // need fixed setprecision to avoid rounding
                    if (sqrtValue == static_cast<int>(sqrtValue)) {
                        cout << "C      SQRT of " << userValue << " is " << fixed << setprecision(0) << sqrtValue << endl;
                    } else{
                        cout << "C      SQRT of " << userValue << " is " << fixed << setprecision(6) << sqrtValue << endl;
                    }
                }
                
                if(num.isPrime()){
                    cout << "D      " << userValue << " is a prime number" << endl;
                } else{
                    cout << "D      " << userValue << " is not a prime number" << endl;
                }
                
                if(num.isPerfectNumber()){
                    cout << "E      " << userValue << " is perfect number" << endl;
                } else{
                    cout << "E      " << userValue << " is not perfect number" << endl;
                }
            }
        } else {
            // user input is not a valid integer
            cout << "\nError *** – Must enter an integer\n";
            cin.clear();    // clears buffer
            cin.ignore(4000, '\n');     // ignore invalid input at max 4000
        }
        if(isValidInput) {
            cout << "\nWould you like to re-run the program again";
            cout << "\nEnter Y or N ---> ";
            cin >> userChoice;
            cout << endl;
            
            if(userChoice != 'y' && userChoice != 'Y' && userChoice != 'n' && userChoice != 'N'){
                cout << "Error *** Invalid choice - Must enter y|Y or n|N\n";
                
                cout << "\n\nWould you like to re-run the program again\n";
                cout << "Enter Y or N ---> ";
                cin >> userChoice;
                cout << endl << endl;;
            }
        }
    } while (userChoice == 'y' || userChoice == 'Y');
    
    cout << "This program is implemented by Felicity Lester" << endl;
    cout << "September - 2023" << endl;
    
    return 0;
}
