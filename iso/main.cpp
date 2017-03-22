//
//  main.cpp
//  iso
//
//  Created by icbrahimc on 3/16/17.
//  Copyright © 2017 icbrahimc. All rights reserved.
//

#include <iostream>
#include "IsoGame.hpp"

// This struct represents the player. It should contain, the piece they are using, number of wins, and number of losses.
struct Player {
    char piece;
};

char compPiece(char);
char selectPiece();
std::pair<int, int> selectMove(IsoGame, char);

int main(int argc, const char * argv[]) {
    Player user, comp;
    // User selects their piece.
    user.piece = selectPiece();
    // Gives the computer its piece.
    comp.piece = compPiece(user.piece);
    
    // Start the new game.
    IsoGame game = IsoGame();
    game.newGameInit();
    
//    game.printBoard();
//    game.movesFromSpot(std::pair<int, int>(1,1));
//    game.makeMove(std::pair<int, int>(1,1), std::pair<int, int>(0,0), 'X');
//    game.printBoard();
//    game.movesFromSpot(std::pair<int, int>(0,0));
    return 0;
}

// Selects the computer's piece using the user's information.
char compPiece(char user) {
    if (user == 'X') {
        return 'O';
    }
    
    return 'X';
}

// Selects the piece that the player uses in the game.
char selectPiece() {
    char user;
    std::cout << "Please select a piece to use. Please be mindful 'X' goes first\n";
    std::cout << "Choice: ";
    std::cin >> user;
    return user;
}

// Lets the user enter the space they want to move to.
std::pair<int, int> selectMove(IsoGame game, char piece) {
    // TODO(icbrahimc): Input validation.
    game.printBoard();
    int row, column;
    std::cout << "Select the row: ";
    std::cin >> row;
    std::cout << "Select the column: ";
    std::cin >> column;
    
    return std::pair<int, int>(row, column);
}
