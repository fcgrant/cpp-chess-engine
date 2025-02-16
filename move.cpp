#include "move.h"
#include <iostream>

// Vector containing each piece, and a list of possible squares they can move to 
std::vector<std::vector<int>> getMoves(BOARD_STRUCTURE board) {
    
    std::vector<std::vector<int>> allMoves;
    
    // Knight moves
    for (int pieceCount = 0; pieceCount < board.pieceCount[N]; pieceCount++) {
        std::vector<int> moves = knightMoves(board.pieceList[N][pieceCount]);
    }
    std::vector<int> moves = knightMoves(board.pieceList[N][0]);

    return allMoves;
}

// Expects move on 64 board
std::vector<int> knightMoves(int square) {
    // Possible knight moves
    std::vector<int> knightMoves = {
        square + (2 * RIGHT) + UP,
        square + (2 * RIGHT) + DOWN,
        square + (2 * LEFT) + UP,
        square + (2 * LEFT) + DOWN,
        square + (2 * UP) + RIGHT,
        square + (2 * UP) + LEFT,
        square + (2 * DOWN) + RIGHT,
        square + (2 * DOWN) + LEFT
    };


    for (int move = 0; move < 8; move++) {
        if (lookupTable120To64[knightMoves[move]] != OFF_BOARD) {
            knightMoves.erase(knightMoves.begin() + move);
        }
    }

    return knightMoves;
}