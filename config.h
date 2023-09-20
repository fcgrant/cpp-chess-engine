//
// Created by Fgran on 11/09/2023.
//

#ifndef CPP_CHESS_ENGINE_CONFIG_H
#define CPP_CHESS_ENGINE_CONFIG_H

#define MAXIMUM_PLY 2048
#define BOARD_ARRAY_SIZE 120
typedef unsigned long long U64;

// Upper case represents white pieces, lower case represents black pieces
enum {EMPTY, K, Q, R, N, B, P, k, q, r, n, b, p};
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE};
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE};
enum { WHITE, BLACK, BOTH};
// This enum will be used to query the board array[120], without needing to calculate the off board indexes
enum {
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, OFF_BOARD
};

// Defines the castling rights for each side, stored as a 4 bit number in the board struct
enum { KCR = 1, QCR = 2, kCR = 4, qCR = 8, };

typedef struct {
    int move;
    int castlingRights;
    int enPassantSquare;
    int fiftyMoveCount;

    U64 positionKey;

} UNDO_MOVE;

typedef struct {
    // The entire representation of the board, including the border
    int BoardArray[BOARD_ARRAY_SIZE];

    // Positions of black, white, and all pawns
    U64 pawns[3];

    // Tracks king square for both sides
    int kingSquare[2];

    int activeColour;
    int enPassantSquare;
    int fiftyMoveCount;
    int ply;
    int plyHistory;

    // Stores each previous position from the current move
    UNDO_MOVE boardHistory[MAXIMUM_PLY];
    U64 positionKey;

    // Indexed using the piece type enum, used to count the number of each type of piece on the board
    int pieceCount[13];

    // Tracks the number of non-pawn pieces on the board for each side
    int nonPawns[3];
    int majorPieces[3];
    int minorPieces[3];

    int castlingRights;


} BOARD_STRUCTURE;

// Used to determine the index of a position when querying the board array
extern int lookupTable64To120[64];

// Used to determine the index of a position when querying a 64-bit integer
extern int lookupTable120To64[BOARD_ARRAY_SIZE  ];

// Macro for calculating the index for a given rank and file in the 120 board array
#define CalculatePosition(file, rank) ((21 + (file)) + ((rank) * 10))

void InitLookupArrays();

void DisplayLookupArrays();
#endif //CPP_CHESS_ENGINE_CONFIG_H