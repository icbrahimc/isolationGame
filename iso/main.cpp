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

int main(int argc, const char * argv[]) {
//    IsoGame game = IsoGame();
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
