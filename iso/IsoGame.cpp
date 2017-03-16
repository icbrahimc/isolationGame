//
//  IsoGame.cpp
//  iso
//
//  Created by icbrahimc on 3/16/17.
//  Copyright © 2017 icbrahimc. All rights reserved.
//

#include "IsoGame.hpp"

// Constructor.
IsoGame::IsoGame() {
    // Initialize the game board with '-' to denote empty spaces for moving.
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = '-';
        }
    }
}

// Find the index of a player's piece.
std::pair<int, int> IsoGame::findIndex(char player) {
    // Find the index of the players piece on the board.
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j] == player) {
                return std::pair<int, int>(i, j);
            }
        }
    }
    return std::pair<int, int>(-1, -1);
}

// Make a move.
void IsoGame::makeMove(std::pair<int, int> idx, std::pair<int, int> newMove, char player) {
    int idxHeight = idx.first;
    int idxWidth = idx.second;
    int moveHeight = newMove.first;
    int moveWidth = newMove.second;
    
    board[idxHeight][idxWidth] = '*';
    board[moveHeight][moveWidth] = player;
}

// Print the game board.
void IsoGame::printBoard() const {
    std::cout << "  ";
    for (int count = 0; count < HEIGHT; count++) {
        std::cout << count << " ";
    }
    std::cout << std::endl;
    
    for (int i = 0; i < HEIGHT; i++) {
        std::cout << i << " ";
        for (int j = 0; j < WIDTH; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
