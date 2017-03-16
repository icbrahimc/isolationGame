//
//  IsoGame.hpp
//  iso
//
//  Created by icbrahimc on 3/16/17.
//  Copyright © 2017 icbrahimc. All rights reserved.
//

#ifndef IsoGame_hpp
#define IsoGame_hpp

#define WIDTH 3
#define HEIGHT 3

#include <iostream>
#include <stdio.h>

class IsoGame {
private:
    char board[WIDTH][HEIGHT];
public:
    // Constructor
    IsoGame();
    
    // Find the index of a current state.
    std::pair<int, int> findIndex(char);
};

#endif /* IsoGame_hpp */
