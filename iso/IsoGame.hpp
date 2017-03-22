//
//  IsoGame.hpp
//  iso
//
//  Created by icbrahimc on 3/16/17.
//  Copyright © 2017 icbrahimc. All rights reserved.
//

/* LEGEND
    - represents empty space.
    * represents space that has already been established.
    X is the min.
    O is the max.
 
*/

#ifndef IsoGame_hpp
#define IsoGame_hpp

#define WIDTH 3
#define HEIGHT 3

#include <iostream>
#include <stdio.h>
#include <vector>

class IsoGame {
private:
    char board[WIDTH][HEIGHT];
    int compMoves;
    int userMoves;
    int moveValue;
    
public:
    // Constructor
    IsoGame();
    
    // New game intialize.
    void newGameInit() {
        board[0][0] = 'X';
        board[WIDTH - 1][HEIGHT - 1] = 'O';
    };
    
    // Find the index of a current state.
    std::pair<int, int> findIndex(char) const;
    
    // Returns whether or not the space is invalid.
    bool invalidSpace(std::pair<int, int> spot) const {
        return (board[spot.first][spot.second]) != '-';
    };
    
    // Find the places where the player can move.
    std::vector<std::pair<int, int>> movesFromSpot(std::pair<int, int>);
    
    // Make a move and replace the old spot with an asterisk.
    void makeMove(std::pair<int, int>, std::pair<int, int>, char);
    
    // Returns the character of the space on the board.
    char returnSpace(std::pair<int, int> spot) const { return board[spot.first][spot.second]; };
    
    // Terminal function.
    std::pair<bool, char> terminalFunc();
    
    // Print the isolation game board.
    void printBoard() const;
};

#endif /* IsoGame_hpp */
