//
//  main.cpp
//  iso
//
//  Created by icbrahimc on 3/16/17.
//  Copyright © 2017 icbrahimc. All rights reserved.
//

#include <iostream>
#include "IsoGame.hpp"

int main(int argc, const char * argv[]) {
    IsoGame game = IsoGame();
    game.printBoard();
    game.movesFromSpot(std::pair<int, int>(1,1));
    return 0;
}
