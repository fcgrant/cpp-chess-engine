#ifndef CPP_CHESS_ENGINE_INIT_H
#define CPP_CHESS_ENGINE_INIT_H
#include "config.h"
BOARD_STRUCTURE initStartingStructure();

int pieceOnStartingSquare(int square);

U64 startingPositionKey();
#endif