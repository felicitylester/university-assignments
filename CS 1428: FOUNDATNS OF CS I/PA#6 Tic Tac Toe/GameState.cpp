//Implementation of the GameState member functions

#include <iostream>
#include <iomanip>
#include <cstring>
#include "GameState.h"

//another sate that containes a move stack


//***********************************************************
// GameState(): Initializes the board to all underscore
// characters ('_').
//
// returns:
//***********************************************************
GameState::GameState() {

  // loop to set board state to _
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      boardState[i][j] = '_';
    }
  }
}


//***********************************************************
// getCurrentPlayer(): Hint: use the size of the stack to
// determine who's move it is. Extra hint: odd/even.
//
// returns: Return the player that has to make the next turn.
//***********************************************************
int GameState::getCurrentPlayer() {
    // defines whick player goes next    
    if (moveStack.getSize() % 2 == 0) {
        return 1;
    }
    else {
        return 2;
    }
}


//***********************************************************
// addMove(Move move): Updates the state of the board and
// stack of the past moves given a move of the current
// player. Hint: use the size of the stack to determine if
// all positions are filled.
//
//
// returns: If the turn is invalid (the target position is
// not empty) it returns -1. If all positions are filled, it
// returns 0. If the move was successfully done and there are
// moves available, it returns 1.
//***********************************************************
int GameState::addMove(Move move) {

    // sees if target move is valid
    if (boardState[move.x][move.y] != '_') {
        return -1;
    }
    // assigns person to specific letter
    char player;
    if (getCurrentPlayer() == 1) {
        player = 'x';
    } else {
        player = 'o';
    }
    boardState[move.x][move.y] = player;
      // add the move to the move stack
    moveStack.push(move);
  
    // sees if the last player who moved has won the game
    if (checkLastPlayerWin()) {
        std::cout << "Player " << getCurrentPlayer() << " wins!" << std::endl;
        return 2;   // returns the winner
    }

    // use the size of the stack to determine if
    // all positions are filled.
    if (moveStack.getSize() == 9) {
        std::cout << "Draw!" << std::endl;
        return 0;   // draw
    }

    return 1;       // move was sucessful
}


//***********************************************************
// undoLast(): Undoes the last turn by changing the board
// state to the previous one and removing the last move
// from the stack.
//
// returns: Returns true if the move was removed, false if
// there are no moves to undo.
//***********************************************************
bool GameState::undoLast() {
    // Check if there are moves to undo
    if (moveStack.getSize() == 0) {
        return false; // No moves to undo
    }

    // Remove the last move from the move stack
    Move lastMove = moveStack.top();
    moveStack.pop();

    // Update the board state by removing the last player's symbol ('x' or 'o')
    boardState[lastMove.x][lastMove.y] = '_';

    return true; // Successful undo
}


//***********************************************************
// displayBoardState(std::ostream& out): Prints the board
// state to the "out" stream
//
// returns:
//***********************************************************
void GameState::displayBoardState(std::ostream& out) {
    // Print the board state
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            out << boardState[i][j] << "";
        }
        out << std::endl;
    }
    out << std::endl;
}


//***********************************************************
// checkLastPlayerWin(): check who wins
//
// returns:
//***********************************************************
bool GameState::checkLastPlayerWin() {
    char targetSymbol = getCurrentPlayer() ? 'x' : 'o';
    int sumHorizontal, sumVertical;
    for (int i = 0; i < 3; ++i){
        sumHorizontal = 0;
        sumVertical = 0;
        for (int j = 0; j < 3; ++j){
            sumHorizontal += boardState[i][j] == targetSymbol;
            sumVertical += boardState[j][i] == targetSymbol;
        }
        if (sumHorizontal == 3 || sumVertical == 3)
            return true;
    }
    int sumDiagonal1 = 0, sumDiagonal2 = 0;
    for (int i = 0; i < 3; ++i){
        sumDiagonal1 += boardState[i][i] == targetSymbol;
        sumDiagonal2 += boardState[i][2 - i] == targetSymbol;
    }
    if (sumDiagonal1 == 3 || sumDiagonal2 == 3)
        return true;

    return false;
}
