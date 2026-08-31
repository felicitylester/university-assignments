// File Name: main.cpp
// 
// Author: Felicity Lester
// Collaborators: None
// Date: 2/3/2023
// Assignment Number: 1
// CS 2308 Spring 2022
// 
// Write a program that tracks the medals won by countries participating 
// at the Olympic Games using an arry of 8 countries.

//****************This is the line of 80 characters in length*******************

#include <iostream>
#include <iomanip>
#include <cstring> //allow strings
using namespace std;

// struct to call data 
  struct Country {
    string name;  //country name
    int nGold;    //country number of gold
    int nSilver;  //country number of silver
    int nBronze;  //country number of bronze
  };

// column header
void showResults(Country * countries, int n) 
  {
    cout << left
     << setw(3) << "N"
     << setw(15) << "Country"
     << right
     << setw(10) << "Gold"
     << setw (10) << "Silver"
     << setw (10) << "Bronze"
     << setw(10) << "Total"
     << endl;

    //loop used to display table of countries
    for (int i = 0; i < n; i++) {	
		//print each struct country and medals
		cout << left 
     << setw(3) << (i + 1) 
     << setw(15) << countries[i].name 
     << right 
     << setw(10) << countries[i].nGold 
		 << setw(10) << countries[i].nSilver 
     << setw(10) << countries[i].nBronze 
     << setw(10) 
     << (countries[i].nGold + countries[i].nSilver + countries[i].nBronze)
     << endl;
	}
}

//uses the countries information to adjust medal count for the country by 1
void addMedal(Country * countries, int countryNum, string medalType) {
    if (medalType.compare("G") == 0 || medalType.compare("g") == 0) {	
        //if the medal type is Gold
        countries[countryNum].nGold += 1;	
        //increase number of gold medals by 1 
    }  
	  else if (medalType.compare("S") == 0 || medalType.compare("s") == 0) {	
        //if the medal type is Silver
		    countries[countryNum].nSilver += 1;	
        //increase number of silver medals by 1
    }  
	  else if (medalType.compare("B") == 0 || medalType.compare("b") == 0) {	
        //if the medal type is Bronze
		    countries[countryNum].nBronze += 1;	
        //increase number of bronze medals by 1
	}
}

//returns the total number of medals awarded to all countries
int totalMedals(Country * countries, int n) {
    int totalMedals = 0;	  //variable to store total medal count awarded
	  for (int i = 0; i < n; i++) {	
		  totalMedals += countries[i].nGold + countries[i].nSilver + countries[i].nBronze;	
    //total medals for a country = number of gold, silver & bronze awarded
	  }
	return totalMedals;	//returns total of each medal for all countries
}

//used to determine country with max number of gold medals awarded
int mostGoldMedals(Country * countries, int n) {
	 int maxGold = countries[0].nGold;	 //store max num of gold medals
	 int maxGoldMedals = 0;  	/*variable to store the index of the country having
      the maximum number of gold medals*/
	 for (int i = 0; i < n; i++) {	
	    if (countries[i].nGold > maxGold) {	  /*determine if the current country
          has the gold medal count greater than the maximum value*/
			maxGold = countries[i].nGold;	  //if needed update the maximum gold count
			maxGoldMedals = i;    /*update the index of the country having the 
            maximum gold medal count*/
		}
	}
	return maxGoldMedals;    //return country having maximum gold medal count
}

int main() {
  
	Country countries[8];    // initialize an array of struct Country at size 8
	const int n = 8;	       // size of the array of struct Country
	int countryNum;	         // user input for country number
	string medalType;	       // user input for the medal type G, S, or B

    	//country 1 data
    	countries[0].name = "Australia";    //country name 
    	countries[0].nGold = 11;            //country number of gold
    	countries[0].nSilver = 14;          //country number of silver
    	countries[0].nBronze = 12;          //country number of bronze 
    	//country 2 data
    	countries[1].name = "Canada";       //country name 
    	countries[1].nGold = 5;             //country number of gold
    	countries[1].nSilver = 0;           //country number of silver
    	countries[1].nBronze = 1;           //country number of bronze
      //country 3 data
    	countries[2].name = "China";        //country name 
    	countries[2].nGold = 9;             //country number of gold
    	countries[2].nSilver = 14;          //country number of silver
    	countries[2].nBronze = 11;          //country number of bronze 
      //country 4 data
    	countries[3].name = "Great Britain";//country name 
    	countries[3].nGold = 8;             //country number of gold
    	countries[3].nSilver = 4;           //country number of silver
    	countries[3].nBronze = 8;           //country number of bronze
      //country 5 data
    	countries[4].name = "Japan";        //country name 
    	countries[4].nGold = 8;             //country number of gold
    	countries[4].nSilver = 10;          //country number of silver
    	countries[4].nBronze = 10;          //country number of bronze
      //country 6 data
    	countries[5].name = "Netherlands";  //country name 
    	countries[5].nGold = 7;             //country number of gold
    	countries[5].nSilver = 6;           //country number of silver
    	countries[5].nBronze = 7;           //country number of bronze
      //country 7 data
    	countries[6].name = "Russia";       //country name 
    	countries[6].nGold = 6;             //country number of gold
    	countries[6].nSilver = 10;          //country number of silver
    	countries[6].nBronze = 8;           //country number of bronze
      //country 8 data
    	countries[7].name = "USA";          //country name 
    	countries[7].nGold = 10;            //country number of gold
    	countries[7].nSilver = 6;           //country number of silver
    	countries[7].nBronze = 7;           //country number of bronze

//do-while loop to repeat the process until user chooses zero
	do {
		showResults(countries, n);	//call 'showResults' to print list of countries
		  cout << "Enter the country number (0 to quit):" << endl;
          //ask user for the country number
		  cin >> countryNum;	//accept user input for country number

//user enters 0, total gold medals print
		if (countryNum == 0) {	  //user enters 0 program quits and results print
		  cout << "Total medals Awarded: " << totalMedals(countries, n) << endl;
      //shows total medals for all countries by calling 'totalMedals'
			cout << "Country with the most Gold Medals: "
           << countries[mostGoldMedals(countries, n)].name
           << endl;
      exit(0);
      //shows country with most gold medals
		}

    while (countryNum < 1 || countryNum > 1000) {
		  cout << "Enter the country number (0 to quit):" << endl;
          //ask user for the country number
		  cin >> countryNum;	//accept user input for country number
		}

    	cout << "Enter the medal type (G,S, or B):" << endl;
      cin >> medalType;

//idek but only way to get the medalType to work properly
		while (medalType.compare("G") != 0 && medalType.compare("g") != 0 && 
      medalType.compare("S") != 0 && medalType.compare("s") != 0 &&
      medalType.compare("B") != 0 && medalType.compare("b") != 0) {
			cout << "Enter the medal type (G,S, or B):" << endl;
      cin >> medalType;
    }

		addMedal(countries, countryNum - 1, medalType);	
    //calls 'addMedal' with required parameters
    	
  } while (countryNum != 0);	//loop repeats until user enters 0

	return 0;
}