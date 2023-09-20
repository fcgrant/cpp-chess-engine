//
// Created by Fgran on 20/09/2023.
//
#include <cstdio>
#include "config.h"

void DisplayLookupArrays() {

    int index;

    for(index = 0; index < 64; index++) {
        if(index % 8 == 0) printf("\n");
        printf("%5d", lookupTable64To120[index]);
    }
    printf("\n");
    for(index = 0; index < BOARD_ARRAY_SIZE; index++) {
        if(index % 10 == 0) printf("\n");
        printf("%5d", lookupTable120To64[index]);
    }
}