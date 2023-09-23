//
// Created by Fgran on 23/09/2023.
//
#include "config.h"
#include "lookup.h"
#include <cstdio>
void printBitBoard(U64 bitBoard) {

    // Initialise a one bit integer to shift up to a certain position to test for piece presence
    U64 currentPosition = 1ULL;

    for (int rank = RANK_8; rank >= RANK_1; rank--) {
        for (int file = FILE_A; file <= FILE_H; file++) {
            int square = lookupTable120To64[CalculatePosition(file, rank)];

            if (file % 8 == 0) printf("\n");

            if ((currentPosition << square) & bitBoard) {
                printf("%5d", 1);
            } else {
                printf("%5d", 0);
            }

        }
    }
    printf("\n");
}