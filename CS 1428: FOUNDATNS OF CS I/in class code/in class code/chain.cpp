// 03/23/2023
#include <iostream>
#include <iomanip>
using namespace std;

double chain (int totalInches, int *feet, int *inches)
{
    *feet = totalInches/12;
    *inches = totalInches%12;
    return *feet*3.49 + *inches*.30;
}

int main () {
    
    cout << fixed << setprecision(2);
    int feet = 0, inches = 0;
    int totalInches;
    cin >> totalInches;
    
    double result = chain (totalInches, &feet, &inches);
    cout << feet << " feet and " << inches;
    cout << " inches. Cost: $" << result << endl;
    
    return 0;
}
