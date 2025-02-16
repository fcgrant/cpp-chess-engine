
#ifndef CPP_CHESS_ENGINE_MOVE_H
#define CPP_CHESS_ENGINE_MOVE_H
#include <vector>
#include "config.h"
#include "lookup.h"

std::vector<std::vector<int>> getMoves(BOARD_STRUCTURE board);

std::vector<int> knightMoves(int square);

enum moves {
    UP = 10,
    DOWN = -10,
    LEFT = -1,
    RIGHT = 1,
};
#endif