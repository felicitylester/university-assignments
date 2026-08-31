//The game state specification file.
//  It stores the move stack and the current state of the tic tac toe board

#include <iostream>
#include "MoveStack.h"

class GameState {
    char boardState[3][3];      // allows x & o to be used
    MoveStack moveStack;
public:
    GameState();
    int getCurrentPlayer();
    int addMove(Move move);
    bool undoLast();
    void displayBoardState(std::ostream& out);
    bool checkLastPlayerWin();
};

// char boardState[3][3]; = 3x3 array for the tik tac toe board
// MoveStack moveStack; = implement the undo
