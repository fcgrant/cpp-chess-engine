
#include "config.h"
#include "init.h"
#include "lookup.h"
#include "bitboard.h"

BOARD_STRUCTURE initStartingStructure(){
    BOARD_STRUCTURE board;

    for (int square = 0; square < BOARD_ARRAY_SIZE; square++) {
        board.boardArray[square] = pieceOnStartingSquare(square);
    }
    for (int square = A2; square <= H2; square++) {
        PlacePiece(&board.pawns[WHITE], square);
        PlacePiece(&board.pawns[BOTH], square);
    }
    for (int square = A7; square <= H7; square++) {
        PlacePiece(&board.pawns[BLACK], square);
        PlacePiece(&board.pawns[BOTH], square);
    }

    board.kingSquare[WHITE] = E1;
    board.kingSquare[BLACK] = E8;

    board.activeColour = WHITE;
    board.enPassantSquare = OFF_BOARD;
    board.fiftyMoveCount = 0;
    board.ply = 0;
    board.plyHistory = 0;

    board.boardHistory[0] = {0, 15, OFF_BOARD, 0, startingPositionKey()};
    board.positionKey = startingPositionKey();

    for (int piece = K; piece <= p; piece++) {
        switch(piece){
            case K: case k: case Q: case q:
                board.pieceCount[piece] = 1;
            case P: case p:
                board.pieceCount[piece] = 8;
            default:
                board.pieceCount[piece] = 2;
        }
    }

    board.nonPawns[WHITE] = 8;
    board.nonPawns[BLACK] = 8;
    board.nonPawns[BOTH] = 16;

    board.majorPieces[WHITE] = 3;
    board.majorPieces[BLACK] = 3;
    board.majorPieces[BOTH] = 3;

    board.majorPieces[WHITE] = 4;
    board.majorPieces[BLACK] = 4;
    board.majorPieces[BOTH] = 4;

    board.castlingRights = 15;

    return board;
}

int pieceOnStartingSquare(int square) {
    if (square >= A2 && square <= H2) {
        return P;
    }
    if (square >= A7 && square <= H7) {
        return p;
    }
    switch (square)
    {
    case A1: case H1:
        return R;
    case B1: case G1:
        return N;
    case C1: case F1:
        return B;
    case D1:
        return Q;
    case E1:
        return K;
    case A8: case H8:
        return r;
    case B8: case G8:
        return n;
    case C8: case F8:
        return b;
    case D8:
        return q;
    case E8:
        return k;
    default:
        return OFF_BOARD;
    }
}

U64 startingPositionKey() {
    U64 positionKey;
    for (int square = A1; square <= H1; square++) {
        PlacePiece(&positionKey, square);
    }
    for (int square = A2; square <= H2; square++) {
        PlacePiece(&positionKey, square);
    }
    for (int square = A7; square <= H7; square++) {
        PlacePiece(&positionKey, square);
    }
    for (int square = A8; square <= H8; square++) {
        PlacePiece(&positionKey, square);
    }
    return positionKey;
}