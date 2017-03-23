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

#define WIDTH 4
#define HEIGHT 4

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
    
    // Copy constructor.
    IsoGame(const IsoGame &obj) {
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                board[i][j] = obj.board[i][j];
            }
        }
    };
    
    IsoGame(int limitNum) {
        moveValue = limitNum;
    };
    
    // New game intialize.
    void newGameInit() {
        board[0][0] = 'X';
        board[WIDTH - 1][HEIGHT - 1] = 'O';
    };
    
    // Calculate the value of the board given the number of computer moves.
    void calculateValue(char, char);
    
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
    
    // Return the move value 'heuristic'.
    int returnValue() const { return moveValue; };
    
    // Terminal function.
    std::pair<bool, char> terminalFunc();
    
    // Print the isolation game board.
    void printBoard() const;
};

#endif /* IsoGame_hpp */
