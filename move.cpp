#include "move.h"
#include <iostream>

// Vector containing each piece, and a list of possible squares they can move to
std::unordered_map<int, std::vector<int>> getMoves(BOARD_STRUCTURE board) {
    // Optimisations:
    // 1. Only consider pieces that have moved since the previous ply
    std::unordered_map<int, std::vector<int>> moves;
    for (int piece = K; piece <= p; piece++) {
        for (int pieceCount = 0; pieceCount < board.pieceCount[N]; pieceCount++) {
            int position = board.pieceList[piece][pieceCount];
            std::vector<int> candidateMoves;
            // Is this piece pinned to its king
                // If so, can it capture the piece pinning it without moving
                // out of a different pin
            switch (piece) {
                case K: case k: {
                    candidateMoves = bishopRookMoves(
                        position,
                        board.boardArray,
                        MAX_DISTANCE
                    );      
                }
                case Q: case q: {
                    candidateMoves = bishopRookMoves(
                        position,
                        board.boardArray,
                        MAX_DISTANCE
                    );
                }    
                case R: case r: {
                    candidateMoves = rookMoves(
                        position,
                        board.boardArray,
                        MAX_DISTANCE                        
                    );
                }
                case B: case b: {
                    candidateMoves = bishopMoves(
                        position,
                        board.boardArray,
                        MAX_DISTANCE
                    );
                }
                case N: case n: {
                    candidateMoves = knightMoves(
                        position,
                        board.boardArray
                    );
                }
                case P:

                case p:

                default:
                    break;
            }
            moves[position].insert(
                moves[position].end(),
                candidateMoves.begin(),
                candidateMoves.end()
            );
            // Is this move a capture?

            // Does this move put the opponent in check?


        }
    }
    return moves;
}


std::vector<int> knightMoves(int position, int boardArray[BOARD_ARRAY_SIZE]) {
    std::vector<int> knightMoves = {};
    std::vector<int> candidateMoves = {
        position + (2 * RIGHT) + UP,
        position + (2 * RIGHT) + DOWN,
        position + (2 * LEFT) + UP,
        position + (2 * LEFT) + DOWN,
        position + (2 * UP) + RIGHT,
        position + (2 * UP) + LEFT,
        position + (2 * DOWN) + RIGHT,
        position + (2 * DOWN) + LEFT
    };
    std::vector<int> moves = availableSquares(candidateMoves, position, boardArray);
    knightMoves.insert(knightMoves.end(), moves.begin(), moves.end());
    return knightMoves;
}


std::vector<int> bishopMoves(int position, int boardArray[BOARD_ARRAY_SIZE], int maxDistance) {
    std::vector<int> bishopMoves = {};
    for (int distance = 1; distance <= maxDistance; distance++) {
        std::vector<int> candidateMoves = {
            position + (distance * (UP + RIGHT)),
            position + (distance * (UP + LEFT)),
            position + (distance * (DOWN + RIGHT)),
            position + (distance * (DOWN + LEFT))
        };
        std::vector<int> moves = availableSquares(candidateMoves, position, boardArray);
        bishopMoves.insert(bishopMoves.end(), moves.begin(), moves.end());
    }
    return bishopMoves;
}


std::vector<int> rookMoves(int position, int boardArray[BOARD_ARRAY_SIZE], int maxDistance) {
    std::vector<int> rookMoves = {};
    for (int distance = 1; distance <= maxDistance; distance++) {
        std::vector<int> candidateMoves = {
            position + (distance * UP),
            position + (distance * DOWN),
            position + (distance * RIGHT),
            position + (distance * LEFT)
        };
        std::vector<int> moves = availableSquares(
            candidateMoves,
            position,
            boardArray
        );
        rookMoves.insert(rookMoves.end(), moves.begin(), moves.end());
    }
    return rookMoves;
}


std::vector<int> bishopRookMoves(
    int position,
    int boardArray[BOARD_ARRAY_SIZE],
    int maxDistance
) {
    std::vector<int> bishopRookMoves = {};
    std::vector<int> candidateRookMoves = rookMoves(
        position,
        boardArray,
        MAX_DISTANCE                      
    );
    std::vector<int> candidateBishopMoves = bishopMoves(
        position,
        boardArray,
        MAX_DISTANCE             
    );
    bishopRookMoves.insert(
        bishopRookMoves.end(),
        candidateRookMoves.begin(),
        candidateRookMoves.end()
    );
    bishopRookMoves.insert(
        bishopRookMoves.end(),
        candidateBishopMoves.begin(),
        candidateBishopMoves.end()
    );    
    return bishopRookMoves;
}

std::vector<int> pawnMoves(int position, int boardArray[BOARD_ARRAY_SIZE]) {
    std::vector<int> pawnMoves = {};
    int rookMove = UP;
    // Determine direction, + if white or - if black
    if (isBlack(boardArray[position])) {
        rookMove = DOWN;
    }
    std::vector<int> candidateMoves = {
        position + (rookMove),
        position + (2 * rookMove),
        position + (rookMove + RIGHT),
        position + (rookMove + LEFT)
    };
    std::vector<int> moves = availableSquares(
        candidateMoves,
        position,
        boardArray
    );
    pawnMoves.insert(pawnMoves.end(), moves.begin(), moves.end());
    return pawnMoves;
}


std::vector<int> availableSquares(
    std::vector<int> candidateMoves,
    int startingPosition,
    int boardArray[BOARD_ARRAY_SIZE]
) {
    std::vector<int> availableSquares = {};
    std::copy_if(
        candidateMoves.begin(),
        candidateMoves.end(),
        std::back_inserter(availableSquares),
        [startingPosition, boardArray](int square){
            return boardArray[square] != OFF_BOARD && !sameColour(boardArray[square], boardArray[startingPosition]);
        }
    );
    return availableSquares;
}