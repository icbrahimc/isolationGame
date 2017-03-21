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

// Figure out the amount of moves to be made.
std::vector<std::pair<int, int>> IsoGame::movesFromSpot(std::pair<int, int> spot) {
    std::vector<std::pair<int, int>> moves;
    std::vector<std::pair<int, int>> validMoves;
    std::pair<int, int> holder;
    bool valid;
    
    // Y is going up -.
    for (int count = 1; count < HEIGHT; count++) {
        holder = std::pair<int, int>(spot.first, spot.second - count);
        if (this->invalidSpace(holder)) {
            break;
        }
        moves.push_back(holder);
    }
    
    // Y is going down +.
    for (int count = 1; count < HEIGHT; count++) {
        holder = std::pair<int, int>(spot.first, spot.second + count);
        if (this->invalidSpace(holder)) {
            break;
        }
        moves.push_back(holder);
    }
    
    // X is going left -.
    for (int count = 1; count < WIDTH; count++) {
        holder = std::pair<int, int>(spot.first - count, spot.second);
        if (this->invalidSpace(holder)) {
            break;
        }
        moves.push_back(holder);
    }
    
    // Y is going right +.
    for (int count = 1; count < WIDTH; count++) {
        holder = std::pair<int, int>(spot.first + count, spot.second);
        if (this->invalidSpace(holder)) {
            break;
        }
        moves.push_back(holder);
    }
    
    // TODO(icbrahimc): Change the diagonal for loops to account. This assumes that the dimensions are equal.
    // X, Y top right.
    for (int count = 1; count < WIDTH; count++) {
        holder = std::pair<int, int>(spot.first + count, spot.second - count);
        if (this->invalidSpace(holder)) {
            break;
        }
        moves.push_back(holder);
    }
    
    // X, Y top left.
    for (int count = 1; count < WIDTH; count++) {
        holder = std::pair<int, int>(spot.first - count, spot.second - count);
        if (this->invalidSpace(holder)) {
            break;
        }
        moves.push_back(holder);
    }
    
    // X, Y bottom right.
    for (int count = 1; count < WIDTH; count++) {
        holder = std::pair<int, int>(spot.first + count, spot.second + count);
        if (this->invalidSpace(holder)) {
            break;
        }
        moves.push_back(holder);
    }
    
    // X, Y bottom left.
    for (int count = 1; count < WIDTH; count++) {
        holder = std::pair<int, int>(spot.first - count, spot.second + count);
        if (this->invalidSpace(holder)) {
            break;
        }
        moves.push_back(holder);
    }
    
    for (int count = 0; count < moves.size(); count++) {
        holder = moves[count];
        valid = true;
        if (holder.first < 0 || WIDTH <= holder.first) {
            valid = false;
        }
        
        if (holder.second < 0 || HEIGHT <= holder.second) {
            valid = false;
        }
        
        if (valid) {
            validMoves.push_back(holder);
        }
    }
    
//    for (int count = 0; count < validMoves.size(); count++) {
//        std::cout << validMoves[count].first << ", " << validMoves[count].second << std::endl;
//    }
    
    return validMoves;
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
