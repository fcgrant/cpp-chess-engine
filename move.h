
#ifndef CPP_CHESS_ENGINE_MOVE_H
#define CPP_CHESS_ENGINE_MOVE_H
#include <algorithm>
#include <unordered_map>
#include <vector>
#include "config.h"
#include "lookup.h"

std::unordered_map<int, std::vector<int>> getMoves(BOARD_STRUCTURE board);

std::vector<int> knightMoves(int position, int boardArray[BOARD_ARRAY_SIZE]);
std::vector<int> bishopMoves(int position, int boardArray[BOARD_ARRAY_SIZE], int maxDistance);
std::vector<int> rookMoves(int position, int boardArray[BOARD_ARRAY_SIZE], int maxDistance);
std::vector<int> bishopRookMoves(int position, int boardArray[BOARD_ARRAY_SIZE], int maxDistance);
std::vector<int> pawnMoves(int position, int boardArray[BOARD_ARRAY_SIZE]);
std::vector<int> availableSquares(std::vector<int> candidateMoves, int startingPosition, int boardArray[BOARD_ARRAY_SIZE]);

enum moves {
    UP = 10,
    DOWN = -10,
    LEFT = -1,
    RIGHT = 1,
};

#define isBlack(piece) (piece >= k && piece <= p)
#define sameColour(piece, otherPiece) (isBlack(piece) == isBlack(otherPiece))
#endif