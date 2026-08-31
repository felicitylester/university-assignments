#include <iostream>
#include <iomanip>  // alows setprecision
#include <cstring>  // allow strings
#include <cctype>   // allow characters

using namespace std;

//Using the code below, finish the implementation of the Menu struct. This struct should have these members:
//
//dishList: a pointer to an array of Dishes
//menuSize: an integer to track the size of menuList.
//Following the instructions in the comments, complete the main function so that the Menu named ss2 will store these students in its dishList:

//"Apple pie", "Flour, apple, sugar", 17.99
//"Ice cream", "Milk, cream, sugar", 12.99
//"Rice pudding", "Rice, milk, raisins", 11.50
struct Dish{
    string name, ingredients;
    float price;
};

struct Menu{
    //Fill in the members of this struct
};


int main(int argc, char** argv){
    Menu ss2;
    //Point ss2.dishList to a dynamically allocated
    //  array of 3 Dishes.

    //Set the menuSize member to 3.

    //Assign the Dish information to the to each Dish in the dishList of the Menu

    //De-allocate ss2.dishList

    return 0;
}

//Your Answer:
#include <iostream>

#include <cstring>  // allow strings

#include <cctype>   // allow characters

using namespace std;

 

struct Dish{

    string name, ingredients;

    float price;

};

struct Menu{

    Dish dishList[3];   // bc 3 options

    //"Apple pie", "Flour, apple, sugar", 17.99;

    //"Ice cream", "Milk, cream, sugar", 12.99;

    //"Rice pudding", "Rice, milk, raisins", 11.50;

};

 

int main(int argc, char** argv){

    Menu ss2;

    //Point ss2.dishList to a dynamically allocated

    //  array of 3 Dishes.

    ss2.dishList = new Dish[3];

 

    //Set the menuSize member to 3.

    ss2.menuSize = 3;

 

    //Assign the Dish information to the to each Dish in the dishList of the Menu

    Dish dish1 = {"Apple pie", "Flour, apple, sugar", 17.99};

    Dish dish2 = {"Ice cream", "Milk, cream, sugar", 12.99};

    Dish dish3 = {"Rice pudding", "Rice, milk, raisins", 11.50};

    

    // allows dish info to work

    ss2.dishList[0] = dish1;

    ss2.dishList[1] = dish2;

    ss2.dishList[2] = dish3;

    

    // for loop for each item

    for(int i = 1; i < 3; i++) {    // 3 options so size 3

        cout << "Name" << ss2.dishList[i].name << endl;

        cout << "Ingredients" << ss2.dishList[i].ingredients << endl;

        cout << "Price $" << ss2.dishList[i].price << endl;

    }

    //De-allocate ss2.dishList

    delete[] ss2.dishList;

    return 0;

}
