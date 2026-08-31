// Author: Felicity Lester
// Date: 06/20/2023
// CS 2308.501 class and Prof. Atkinson

#include <iostream>
#include <cstring>  // allow strings
#include <cctype>   // allow characters

using namespace std;

//****************This is the line of 80 characters in length*******************int

//***********************************************************
// name: Crew_Member
// parameters:
//      string name: the name of the crew member
//      string nation: the crew members nation of origin
//      float daily_calories: the food intake the crew member
//      needs
//      float daily_o2_consumption: the air intake the crew
//      member needs
// return: none
// side effects:
//***********************************************************
class Crew_Member {
private:
    string name;
    string nation;
    float daily_calories;
    float daily_o2_consumption;
    
public:
    // Add a constructor that allows all data members to be set at instantiation
    Crew_Member(string name, string nation, float cal, float o2) {
        this->name = name;
        this->nation = nation;
        daily_calories = cal;
        daily_o2_consumption = o2;
    }
    // Add getters for every data member of Crew_Member
    string getName() const {return name;}    // getters do not need parameters
    string getNation() const {return nation;}
    float getDaily_calories() const {return daily_calories;}
    float getDaily_o2_consumption() const {return daily_o2_consumption;}
};

//***********************************************************
// name: Crew_Member
// parameters:
//      Crew_Member crew[]: an array representing the
//      rocket's crew
//      string name: the name of the rocket
//      int num_crew: the number of crew
//      float food_supplies: the total number of kCal worth
//      of food stored
//      float air_supplies: the total liters of oxygen stored
// return: none
// side effects: none
//***********************************************************
class Rocket {
private:
    string name;
    int num_crew;
    float food_supplies;
    float air_supplies;
    Crew_Member* crew;     // arr without definite size needs to go at the end
    
public:
    // constructor definition
    Rocket(Crew_Member* arr, int num_crew, string name) {
        crew = arr;
        this->num_crew = num_crew;
        this->name = name;
        this->food_supplies = 0;
        this->air_supplies = 0;
        
        //this->name = new Crew_Member[num_crew];
        
        for (int i = 0; i < num_crew; ++i) {
            this->crew[i] = arr[i];
        }
    }
    
    // deallocates
    ~Rocket() {
        delete[] crew;
    }
    
    //***********************************************************
    // name: printCrew (Print the names of every Crew_Member
    //                  aboard the Rocket)
    // parameters:
    // return: none
    // side effects: none
    //***********************************************************
    void printCrew() {
        for (int i = 0; i < num_crew; ++i) {
            cout << crew[i].getName() << endl;
//            cout << "Crew Member " << i + 1 << ": "
//                 << this->crew[i].getName() << endl;
        }
    }

    float getMaxDays() {
        float food_con = 0, air_con = 0;
        for (int i = 0; i < num_crew; i++) {
            food_con += crew[i].getDaily_calories();
            air_con += crew[i].getDaily_o2_consumption();
        }
        
        float food_days = food_supplies/food_con;
        float air_days = air_supplies/air_con;
        if (food_days < air_days)
            return food_days;
        else
            return air_days;
        
//        if (food days < air days)
//
//         float maxFood = food_supplies;
//         float maxAir = air_supplies;
//         for (int i = 0; i < num_crew; ++i) {
//             maxFood = min(maxFood, food_supplies /
//                 crew[i].getDaily_calories());
//             maxAir = min(maxAir, air_supplies / crew[i].getDaily_o2_consumption());
//         }
//         return min(maxFood, maxAir);
    }
    
    void setFoodSupplies(float supplies) {
        food_supplies = supplies;
    }
    
    void setAirSupplies(float supplies) {
        air_supplies = supplies;
    }
};

int main() {
    // Create 3 Crew_Members
    Crew_Member c1("Bob", "Canada", 2300, 4);
    Crew_Member c2("Lance", "America", 2000, 3.5);
    Crew_Member c3("Sally", "America", 1900, 3.2);
    Crew_Member arr[] = {c1, c2, c3};

    // Create 1 Rocket, and assign the 3 Crew_Members to its crew array
    Rocket r1(arr, 3, "Falcon");
    r1.setFoodSupplies(20000);
    r1.setAirSupplies(40);
    r1.printCrew();
    cout << "Max days in space: " << r1.getMaxDays() << endl;

    return 0;
}
// Test your code and make any corrections that are needed.
// Submit your .cpp file.
