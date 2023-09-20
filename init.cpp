//
// Created by Fgran on 19/09/2023.
//
#include "config.h"

int lookupTable120To64[120];
int lookupTable64To120[64];
// Initialise the lookup tables between the 64 array and 120 array
void InitLookupArrays() {

    int index;
    int squareIn64 = 0;
    int squareIn120;

    for(index = 0; index < BOARD_ARRAY_SIZE; index++) {
        // Initialise the array with integers outside the range of the 64 array
        lookupTable120To64[index] = 64;
    }

    for(index = 0; index < 64; index++) {
        // Initialise the array with integers outside the range of the 120 array
        lookupTable64To120[index] = 120;
    }

    // For each valid chess position in the 120 array, store the equivalent index for that position in the 64 array,
    // and equivalently, store the index for the 120 array in the equivalent position of the 64 array
    for(int rank = RANK_1; rank <= RANK_8; rank++) {
        for(int file = FILE_A; file <= FILE_H; file++) {
            squareIn120 = CalculatePosition(file, rank);
            lookupTable64To120[squareIn64] = squareIn120;
            lookupTable120To64[squareIn120] = squareIn64;
            squareIn64++;
        }
    }

}