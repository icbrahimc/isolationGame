//
//  main.cpp
//  iso
//
//  Created by icbrahimc on 3/16/17.
//  Copyright © 2017 icbrahimc. All rights reserved.
//

#include <cmath>
#include <limits>
#include <iostream>
#include "IsoGame.hpp"

// This struct represents the player. It should contain, the piece they are using, number of wins, and number of losses.
struct Player {
    char piece;
};

IsoGame max(IsoGame, IsoGame);
IsoGame min(IsoGame, IsoGame);
IsoGame min_val(IsoGame, IsoGame, IsoGame, int, int, char, char);
IsoGame max_val(IsoGame, IsoGame, IsoGame, int, int, char, char);
IsoGame alphaBeta(IsoGame, char, char);
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
    IsoGame aB;
//    IsoGame huh = IsoGame(game);
//    
//    huh.makeMove(std::pair<int, int>(0,0), std::pair<int, int>(1,1), 'X');
//    game.printBoard();
//    huh.printBoard();
    
    //condition ? expression1 : expression2
    (user.piece == 'X') ? (compTurn = false):(compTurn = true);
    game.printBoard();
    
//    IsoGame holder;
//    std::pair<int, int> spot = game.findIndex(user.piece);
//    std::vector<std::pair<int, int>> moves = game.movesFromSpot(spot);
//    std::vector<IsoGame> gameMoves;
//    
//    // Generate the games, with their evaluation num.
//    for (int count = 0; count < moves.size(); count++) {
//        holder = IsoGame(game);
//        holder.makeMove(spot, moves[count], user.piece);
//        holder.calculateValue(user.piece, comp.piece);
//        gameMoves.push_back(holder);
//    }
//    
//    for (int count = 0; count < gameMoves.size(); count++) {
//        gameMoves[count].printBoard();
//        gameMoves[count].calculateValue(user.piece, comp.piece);
//        std::cout << "Move: " << gameMoves[count].returnValue() << std::endl;
//    }
    //alphaBeta(game, 'X', 'O');
    
    while (!game.terminalFunc().first) {
        if (compTurn) {
            aB = alphaBeta(game, user.piece, comp.piece);
            compMove = aB.findIndex(comp.piece);
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
    
//    std::cout << "Done\n";
//    std::cout << "Win: " << game.terminalFunc().second << std::endl;
    
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

// Alpha beta.
IsoGame alphaBeta(IsoGame state, char player, char comp) {
    IsoGame alpha = IsoGame(0);
    IsoGame beta = IsoGame(0);
    IsoGame bestMove = max_val(state, alpha, beta, 3, 0, comp, player);//max_val(state, alpha, beta, comp, player);
    
    return bestMove;
}

// Returns the max value game.
IsoGame max(IsoGame valOne, IsoGame valTwo) {
    if (valOne.returnValue() > valTwo.returnValue()) {
        return valOne;
    }
    
    return valTwo;
}

// Max val function for the alpha beta algorithm.
IsoGame max_val(IsoGame state, IsoGame alpha, IsoGame beta, int dLimit, int depth, char player, char opp) {
    IsoGame lastMove = IsoGame();
    lastMove.calculateValue(player, opp);
    IsoGame oppMove;
    IsoGame returnGame;
    if (state.terminalFunc().first == true) {
        return state;
    }
    
    if (depth > dLimit) {
        return state;
    } else {
        // Find the computer spot.
        std::pair<int, int> spot = state.findIndex(player);
        std::vector<std::pair<int, int>> gameMoves = state.movesFromSpot(spot);
        
        // Generate the game moves.
        std::vector<IsoGame> validMoves;
        for (int count = 0; count < gameMoves.size(); count++) {
            IsoGame holder = IsoGame(state);
            holder.makeMove(spot, gameMoves[count], player);
            holder.calculateValue(player, opp);
            validMoves.push_back(holder);
        }
        
        for (int count = 0; count < validMoves.size(); count++) {
            std::cout << "COMP TURN" << std::endl;
            std::cout << "Depth: " << depth << std::endl;
            validMoves[count].printBoard();
            std::cout << std::endl;
            std::cout << validMoves[count].returnValue() << std::endl << std::endl;
            
            oppMove = min_val(validMoves[count], alpha, beta, dLimit, depth + 1, opp, player);
            if (oppMove.returnValue() > lastMove.returnValue()) {
                lastMove = oppMove;
                returnGame = validMoves[count];
                alpha = oppMove;
                alpha.calculateValue(player, opp);
            }
            
            beta.calculateValue(opp, player);
            if (beta.returnValue() < alpha.returnValue()) {
                return returnGame;
            }
        }
        
        return returnGame;
    }
}

// Returns the min value game.
IsoGame min(IsoGame valOne, IsoGame valTwo) {
    if (valOne.returnValue() < valTwo.returnValue()) {
        return valOne;
    }

    return valTwo;
}

// Min val function for the alpha beta algorithm.
IsoGame min_val(IsoGame state, IsoGame alpha, IsoGame beta, int dLimit, int depth, char player, char opp) {
    IsoGame lastMove = IsoGame();
    lastMove.calculateValue(player, opp);
    IsoGame oppMove;
    IsoGame returnGame;
    if (state.terminalFunc().first == true) {
        return state;
    }
    
    if (depth > dLimit) {
        return state;
    } else {
        // Find the computer spot.
        std::pair<int, int> spot = state.findIndex(player);
        std::vector<std::pair<int, int>> gameMoves = state.movesFromSpot(spot);
        
        // Generate the game moves.
        std::vector<IsoGame> validMoves;
        for (int count = 0; count < gameMoves.size(); count++) {
            IsoGame holder = IsoGame(state);
            holder.makeMove(spot, gameMoves[count], player);
            holder.calculateValue(player, opp);
            validMoves.push_back(holder);
        }
        
        for (int count = 0; count < validMoves.size(); count++) {
            std::cout << "PLAYER TURN" << std::endl;
            std::cout << "Depth: " << depth << std::endl;
            validMoves[count].printBoard();
            std::cout << validMoves[count].returnValue() << std::endl << std::endl;
            oppMove = max_val(validMoves[count], alpha, beta, dLimit, depth + 1, opp, player);
            if (oppMove.returnValue() > lastMove.returnValue()) {
                lastMove = oppMove;
                returnGame = validMoves[count];
                beta = oppMove;
                beta.calculateValue(player, opp);
            }
            
            alpha.calculateValue(opp, player);
            if (beta.returnValue() > alpha.returnValue()) {
                return returnGame;
            }
        }
        
        return returnGame;
    }
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
