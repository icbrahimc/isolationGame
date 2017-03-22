//
//  main.cpp
//  iso
//
//  Created by icbrahimc on 3/16/17.
//  Copyright © 2017 icbrahimc. All rights reserved.
//

#include <cmath>
#include <iostream>
#include "IsoGame.hpp"

// This struct represents the player. It should contain, the piece they are using, number of wins, and number of losses.
struct Player {
    char piece;
};

IsoGame max(IsoGame, IsoGame);
IsoGame min(IsoGame, IsoGame);
IsoGame min_val(IsoGame, IsoGame, IsoGame, char);
IsoGame max_val(IsoGame, IsoGame, IsoGame);
char compPiece(char);
char selectPiece();
std::pair<int, int> selectMove(IsoGame, char);
std::pair<int, int> randMove(IsoGame, char);

int main(int argc, const char * argv[]) {
    srand(time(NULL));
    
    bool compTurn;
    
    std::pair<int, int> compMove, userMove, oldMove;
    
    Player user, comp;
    // User selects their piece.
    user.piece = selectPiece();
    // Gives the computer its piece.
    comp.piece = compPiece(user.piece);
    
    // Start the new game.
    IsoGame game = IsoGame();
    game.newGameInit();
    
    //condition ? expression1 : expression2
    (user.piece == 'X') ? (compTurn = false):(compTurn = true);
    
    while (!game.terminalFunc().first) {
        if (compTurn) {
            compMove = randMove(game, comp.piece);
            oldMove = game.findIndex(comp.piece);
            game.makeMove(oldMove, compMove, comp.piece);
            compTurn = false;
            continue;
        }
        
        else {
            userMove = selectMove(game, user.piece);
            oldMove = game.findIndex(user.piece);
            game.makeMove(oldMove, userMove, user.piece);
            compTurn = true;
            continue;
            //game.printBoard();
        }
    }
    
    std::cout << "Done\n";
    std::cout << "Win: " << game.terminalFunc().second << std::endl;
    
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

// Returns the max value game.
IsoGame max(IsoGame valOne, IsoGame valTwo) {
    if (valOne.returnValue() > valTwo.returnValue()) {
        return valOne;
    }
    
    return valTwo;
}

// Returns the min value game.
IsoGame min(IsoGame valOne, IsoGame valTwo) {
    if (valOne.returnValue() > valTwo.returnValue()) {
        return valTwo;
    }

    return valOne;
}

// Min val function for the alpha beta algorithm.
IsoGame min_val(IsoGame state, IsoGame alpha, IsoGame beta, char player) {
    std::pair<int, int> spot = state.findIndex(player);
    
    if (state.terminalFunc().first) {
        return state;
    }
    
    std::vector<std::pair<int, int>> moves = state.movesFromSpot(spot);
    return IsoGame();
}

// Returns a random move for the game.
std::pair<int, int> randMove(IsoGame game, char piece) {
    std::pair<int, int> spot = game.findIndex(piece);
    std::vector<std::pair<int, int>> moves = game.movesFromSpot(spot);
    int numOfMoves = moves.size();
    
    std::pair<int, int> randSpot = moves[rand() % numOfMoves];
    
    return randSpot;
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
