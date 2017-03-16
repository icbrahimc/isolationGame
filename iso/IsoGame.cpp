//
//  IsoGame.cpp
//  iso
//
//  Created by icbrahimc on 3/16/17.
//  Copyright © 2017 icbrahimc. All rights reserved.
//

#include "IsoGame.hpp"

IsoGame::IsoGame() {
    // Initialize the game board with '-' to denote empty spaces for moving.
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = '-';
        }
    }
}

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
