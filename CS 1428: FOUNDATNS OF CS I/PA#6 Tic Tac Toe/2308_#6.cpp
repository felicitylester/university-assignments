// File Name: main.cpp
//
// Author: Felicity Lester
// Collaborators: None
// Date: 04/17/2023
// Assignment Number: 6
// CS 2308 Spring 2023
//
// Contains the main game loop. Players should be able to enter their move in
// a format "move x y", where x and y are the coordinates of the target cell.


//****************This is the line of 80 characters in length*******************

#include <iostream>
#include <iomanip>
#include <cstring>
#include "GameState.h"      // specification file
using namespace std;

int main () {
    
    Move move;
    GameState game;
    int player, status;
    string command;
    
    while(true)
    {
        player = game.getCurrentPlayer();
        game.displayBoardState(cout);
        do{
            cout << "Player " << player << " make a turn." << endl;
            cin >> command;
            
            if(command == "move"){
                cin >> move.x >> move.y;
            }
            else if(command == "undo" && game.undoLast()==false)
                cout << "No moves to undo." << endl;
            else
                cout << "Invalid command" << endl;

            status = game.addMove(move);
            if(status!= -1)
                break;
            cout << "Incorrect move. Please try again." << endl;
        }while(true);
        if(status == 0){
             cout << "It's a draw!" << endl;
             return 0;
        }
    }
}
