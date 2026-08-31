//Felicity Lester fml21
//October 05, 2022
//Lab 5 Pre-Lab
// Finish the following program which multiplies all integers from 1 to 
// the user's given number inclusively using a FOR loop. The total should be 
// assigned to the variable 'total'.

#include <iostream>
using namespace std;

int main()
{
  int num;
  int product;
  int i;
  int total = 1;
  
  cout << "Enter a positive integer to find the product of"
       << " all numbers from 1 to the given number." << endl;
  cin >> num;

  for(i = 1; i <= num; i++)
  {
   total = total * i;
  }

  cout << "Product : " << total << endl;
  
    return 0;
}