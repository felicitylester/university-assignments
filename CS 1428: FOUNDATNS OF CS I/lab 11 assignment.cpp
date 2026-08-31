//TO-DO: Felicity Lester A04949726
//TO-DO: November 18, 2022
//CS1428 Lab
//Lab 11
//Description: this program will track weather for several days
//****************This is the line of 80 characters in length*******************
//############Your code should not exceed the length of the above line##########
#include <iostream>
#include <iomanip>
using namespace std;
//TODO: Create your struct
struct DailyClimate
{
    string name;
    float rainfall;
    float temperature;  
};

int main()
{
    const int WEEK = 3;
      DailyClimate myweek [WEEK]; //array of DailyClimate structs
      float total = 0;
      int lowest_rainfall = 0;
      int highest_temp = 0;
      
      for(int i = 0; i < WEEK; i++)
    {
        //TODO: Prompt/read daily climate information
        cout << "Day #" << i + 1 << endl;
        cout << "Enter day name: ";
        cin >> myweek[i].name;
        cout << "Enter rainfall: ";
        cin >> myweek[i].rainfall;
        cout << "Enter temperature: ";
        cin >> myweek[i].temperature;
        
        //adds current rainfall to total rainfall
        total += myweek[i].rainfall;
      
        //TODO: Find the index of the hottest day
      if (myweek[highest_temp].temperature < myweek[i].temperature)
          highest_temp = i;
        //TODO: Find the index of the day with lowest rainfall
      if (myweek[lowest_rainfall].rainfall > myweek[i].rainfall)
          lowest_rainfall = i;
    cout << endl;
  }
  
    float avg = total/WEEK;
  
    //TODO: output the average rainfall, the day with the lowest
    //      temperature, and the day with the highest rainfall.
  cout << fixed << setprecision(2);
  cout << "Average rainfall: " << avg << endl;
  cout << "Highest temperature of " << myweek[highest_temp].temperature 
    << " on " << myweek[highest_temp].name << endl; 
  cout << "Lowest rainfall of " << myweek[lowest_rainfall].rainfall 
    << " on " << myweek[lowest_rainfall].name << endl;
   
return 0;
}