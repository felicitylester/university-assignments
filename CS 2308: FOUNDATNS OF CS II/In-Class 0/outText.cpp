// Felicity Lester
// May 31, 2023
// CS 2308.501 class and Prof. Atkinson

#include<iostream>
#include<fstream>

using namespace std;

//***********************************************************
// name: write kelvin to file
// parameters: float celc_temp = temp used to convert
// return: none
// side effects: writes to out.txt
//***********************************************************

// change return type to void
// use celc_temp to make parameters clear
void write_kelvin_to_file(float celc_temp) {
    
    // the name of the file used for data
    // opens file stream
    ofstream font("out.txt");
    
    // temperature plus kelvin
    font << celc_temp + 273.15;
    
}

//***********************************************************
// name: get far from celc
// parameters: float celc_temp = temp used to convert
// return: none
// side effects: writes to out.txt
//***********************************************************

float get_far_from_celc (float celc_temp) {
    // converts into celcius
    return 32.0 + (celc_temp * (9.0/5.0));
}

int main() {
    // t is not clear, using celc_temp gives clarity
    float celc_temp = 20;
    // the loop interates the data 7 times
    for (int i = 0; i < 7; i++) {
    //confusing indentation
        if (i % 2 != 1) {
            cout << get_far_from_celc(celc_temp) << endl;
            celc_temp++;
        }
    }
    //duplicated code
    //else t++;}
    
 return 0;
}
