
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
        board.pieceList[P][square - A2] = square;
    }
    for (int square = A7; square <= H7; square++) {
        PlacePiece(&board.pawns[BLACK], square);
        PlacePiece(&board.pawns[BOTH], square);
        board.pieceList[p][square - A7] = square;
    }

    board.kingSquare[WHITE] = E1;
    board.kingSquare[BLACK] = E8;

    board.activeColour = WHITE;
    board.enPassantSquare = OFF_BOARD;
    board.fiftyMoveCount = 0;
    board.ply = 0;
    board.plyHistory = 0;

    board.positionKey = startingPositionKey();
    board.boardHistory[0] = {0, 15, OFF_BOARD, 0, board.positionKey};

    for (int piece = K; piece <= p; piece++) {
        switch(piece){
            case K: case k: case Q: case q:
                board.pieceCount[piece] = 1;
                break;
            case P: case p:
                board.pieceCount[piece] = 8;
                break;
            default:
                board.pieceCount[piece] = 2;
        }
    }

    board.nonPawns[WHITE] = 8;
    board.nonPawns[BLACK] = 8;
    board.nonPawns[BOTH] = 16;

    board.majorPieces[WHITE] = 3;
    board.majorPieces[BLACK] = 3;
    board.majorPieces[BOTH] = 6;

    board.minorPieces[WHITE] = 4;
    board.minorPieces[BLACK] = 4;
    board.minorPieces[BOTH] = 8;

    board.castlingRights = 15;

    board.pieceList[K][0] = E1;
    board.pieceList[Q][0] = D1;
    board.pieceList[R][0] = A1;
    board.pieceList[R][1] = H1;
    board.pieceList[N][0] = B1;
    board.pieceList[N][1] = G1;
    board.pieceList[B][0] = C1;
    board.pieceList[B][1] = F1;

    board.pieceList[k][0] = E8;
    board.pieceList[q][0] = D8;
    board.pieceList[r][0] = A8;
    board.pieceList[r][1] = H8;
    board.pieceList[n][0] = B8;
    board.pieceList[n][1] = G8;
    board.pieceList[b][0] = C8;
    board.pieceList[b][1] = F8;

    return board;
}

int pieceOnStartingSquare(int square) {
    if (startingEmptySquare(square)) {
        return EMPTY;
    }
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


bool startingEmptySquare(int square) {
    bool thirdRank = square >= A3 && square <= H3;
    bool fourthRank = square >= A4 && square <= H4;
    bool fifthRank = square >= A5 && square <= H5;
    bool sixthRank = square >= A6 && square <= H6;
    return thirdRank || fourthRank || fifthRank || sixthRank;
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